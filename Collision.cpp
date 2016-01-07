//
// Created by ishfid on 12/25/15.
//

#include <iostream>
#include "Collision.h"
#include "Inventory.h"

Collision::Collision(tmx::TileMap& tileMap, Mob& mob, Player& player, std::string layer, std::string propertyName) {
    noKey = new NoKeyCommand;
    mobAtk = new MobAttackCommand;

    playerBoundingBox = player.getGlobalBounds();
    mobBoundingBox = mob.getGlobalBounds();

    mobPosition = mob.getPosition();
    x = (u_int)mobPosition.x/32;
    y = (u_int)mobPosition.y/32;

    tileBoundingBoxLeftTop = tileMap.GetLayer(layer).GetTile(x,y).GetGlobalBounds();
    tileBoundingBoxRightTop = tileMap.GetLayer(layer).GetTile(x+1,y).GetGlobalBounds();
    tileBoundingBoxLeftBottom = tileMap.GetLayer(layer).GetTile(x,y+1).GetGlobalBounds();
    tileBoundingBoxRightBottom = tileMap.GetLayer(layer).GetTile(x+1,y+1).GetGlobalBounds();

    collisionLeftTop = tileMap.GetLayer(layer).GetTile(x,y).GetPropertyValue(propertyName);
    collisionRightTop = tileMap.GetLayer(layer).GetTile(x+1,y).GetPropertyValue(propertyName);
    collisionLeftBottom = tileMap.GetLayer(layer).GetTile(x,y+1).GetPropertyValue(propertyName);
    collisionRightBottom = tileMap.GetLayer(layer).GetTile(x+1,y+1).GetPropertyValue(propertyName);
}

Collision::Collision(tmx::TileMap &tileMap, Player &player, std::string layer, std::string propertyName,
                     std::vector<std::unique_ptr<Mob>> &mobMap) {
    noKey = new NoKeyCommand;
    playerAtk = new PlayerAttackCommand;

    player.play(*player.currentAnimation); //DAFUQ??? otherwise game will crash
    playerBoundingBox = player.getGlobalBounds();

    playerPosition = player.getPosition();
    x = (u_int)playerPosition.x/32;
    y = (u_int)playerPosition.y/32;

    double dist1 = 0, dist2 = 0;
    int index = 0;
    if(!mobMap.empty()) {
        dist1 = sqrt((playerPosition.x - mobMap[0]->getPosition().x) * (playerPosition.x - mobMap[0]->getPosition().x) +
                     (playerPosition.y - mobMap[0]->getPosition().y) * (playerPosition.y - mobMap[0]->getPosition().y));

        for (u_int i = 1; i < mobMap.size(); ++i) {
            dist2 = sqrt(
                    (playerPosition.x - mobMap[i]->getPosition().x) * (playerPosition.x - mobMap[i]->getPosition().x) +
                    (playerPosition.y - mobMap[i]->getPosition().y) * (playerPosition.y - mobMap[i]->getPosition().y));
            if (dist2 < dist1) {
                dist1 = dist2;
                index = i;
            }
        }

        mobBoundingBox = mobMap[index]->getGlobalBounds();
        mobPosition = mobMap[index]->getPosition();
    }

    tileBoundingBoxLeftTop = tileMap.GetLayer(layer).GetTile(x,y).GetGlobalBounds();
    tileBoundingBoxRightTop = tileMap.GetLayer(layer).GetTile(x+1,y).GetGlobalBounds();
    tileBoundingBoxLeftBottom = tileMap.GetLayer(layer).GetTile(x,y+1).GetGlobalBounds();
    tileBoundingBoxRightBottom = tileMap.GetLayer(layer).GetTile(x+1,y+1).GetGlobalBounds();

    collisionLeftTop = tileMap.GetLayer(layer).GetTile(x,y).GetPropertyValue(propertyName);
    collisionRightTop = tileMap.GetLayer(layer).GetTile(x+1,y).GetPropertyValue(propertyName);
    collisionLeftBottom = tileMap.GetLayer(layer).GetTile(x,y+1).GetPropertyValue(propertyName);
    collisionRightBottom = tileMap.GetLayer(layer).GetTile(x+1,y+1).GetPropertyValue(propertyName);
}

Command* Collision::testObstructPlayerCollision(Command& command, std::vector<std::unique_ptr<Mob>>& mobMap) {
    for (u_int i = 0; i < mobMap.size(); ++i) {
        if(mobMap[i]->getPosition() == mobPosition)
            index = i;
    }

    if(typeid(command).name() == typeid(UpCommand).name()){
        if((collisionLeftTop == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftTop)) || (collisionRightTop == "1" && playerBoundingBox.intersects(tileBoundingBoxRightTop)) || mobBoundingBox.contains(playerPosition.x,playerPosition.y) || mobBoundingBox.contains(playerPosition.x+32,playerPosition.y))
            return noKey;
    }

    if(typeid(command).name() == typeid(DownCommand).name()) {
        if((collisionLeftBottom == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftBottom)) || (collisionRightBottom == "1" && playerBoundingBox.intersects(tileBoundingBoxRightBottom)) || mobBoundingBox.contains(playerPosition.x,playerPosition.y+32) || mobBoundingBox.contains(playerPosition.x+32,playerPosition.y+32))
            return noKey;
    }

    if(typeid(command).name() == typeid(RightCommand).name()) {
        if((collisionRightTop == "1" && playerBoundingBox.intersects(tileBoundingBoxRightTop)) || (collisionRightBottom == "1" && playerBoundingBox.intersects(tileBoundingBoxRightBottom)) || mobBoundingBox.contains(playerPosition.x+32,playerPosition.y) || mobBoundingBox.contains(playerPosition.x+32,playerPosition.y+32))
            return noKey;
    }

    if(typeid(command).name() == typeid(LeftCommand).name()) {
        if((collisionLeftTop == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftTop)) || (collisionLeftBottom == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftBottom)) || mobBoundingBox.contains(playerPosition.x,playerPosition.y+32) || mobBoundingBox.contains(playerPosition.x,playerPosition.y))
            return noKey;
    }

    if(typeid(command).name() == typeid(PlayerAttackCommand).name()){
        if(playerBoundingBox.intersects(mobBoundingBox)){
            mobMap[index]->setCollidable(1);
            return playerAtk;
        }
    }

    return &command;
}

Command* Collision::testObstructMobCollision(Command& command, std::vector<std::unique_ptr<Mob>>& mobMap) {
    for (u_int i = 0; i < mobMap.size(); ++i) {
        if(mobMap[i]->getPosition() == mobPosition)
            index = i;
    }

    if(typeid(command).name() == typeid(UpCommand).name()){
        if((collisionLeftTop == "1" && mobBoundingBox.intersects(tileBoundingBoxLeftTop)) || (collisionRightTop == "1" && mobBoundingBox.intersects(tileBoundingBoxRightTop)))
            return noKey;
        if(playerBoundingBox.contains(mobPosition.x,mobPosition.y) || playerBoundingBox.contains(mobPosition.x+32,mobPosition.y)){
            mobMap[index]->setCollidable(1);
            return mobAtk;
        }
    }

    if(typeid(command).name() == typeid(DownCommand).name()) {
        if((collisionLeftBottom == "1" && mobBoundingBox.intersects(tileBoundingBoxLeftBottom)) || (collisionRightBottom == "1" && mobBoundingBox.intersects(tileBoundingBoxRightBottom)))
            return noKey;
        if(playerBoundingBox.contains(mobPosition.x,mobPosition.y+32) || playerBoundingBox.contains(mobPosition.x+32,mobPosition.y+32)){
            mobMap[index]->setCollidable(1);
            return mobAtk;
        }
    }

    if(typeid(command).name() == typeid(RightCommand).name()) {
        if((collisionRightTop == "1" && mobBoundingBox.intersects(tileBoundingBoxRightTop)) || (collisionRightBottom == "1" && mobBoundingBox.intersects(tileBoundingBoxRightBottom)))
            return noKey;
        if(playerBoundingBox.contains(mobPosition.x+32,mobPosition.y) || playerBoundingBox.contains(mobPosition.x+32,mobPosition.y+32)){
            mobMap[index]->setCollidable(1);
            return mobAtk;
        }
    }

    if(typeid(command).name() == typeid(LeftCommand).name()) {
        if((collisionLeftTop == "1" && mobBoundingBox.intersects(tileBoundingBoxLeftTop)) || (collisionLeftBottom == "1" && mobBoundingBox.intersects(tileBoundingBoxLeftBottom)))
            return noKey;
        if(playerBoundingBox.contains(mobPosition.x,mobPosition.y+32) || playerBoundingBox.contains(mobPosition.x,mobPosition.y)){
            mobMap[index]->setCollidable(1);
            return mobAtk;
        }
    }

    return &command;
}

void Collision::testItemPlayerCollision(Command& command, Player& player, std::vector<std::unique_ptr<Weapon>> &weaponMap, std::vector<std::unique_ptr<Armor>> &armorMap, tmx::TileMap& tileMap){
    Inventory *inventory = new Inventory;
    if(typeid(command).name() == typeid(PickCommand).name()){
        for (u_int i = 0; i < weaponMap.size(); ++i) {
            if(weaponMap[i]->getGlobalBounds().intersects(playerBoundingBox))
                inventory->addToInv(player, weaponMap, armorMap, i, -1, tileMap);
        }
        for (u_int j = 0; j < armorMap.size(); ++j) {
            if(armorMap[j]->getGlobalBounds().intersects(playerBoundingBox))
                inventory->addToInv(player, weaponMap, armorMap, -1, j, tileMap);
        }
    }
}