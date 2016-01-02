//
// Created by ishfid on 12/25/15.
//

#include <iostream>
#include "Collision.h"

Collision::Collision(tmx::TileMap& tileMap, Player& player, std::string layer, std::string propertyName, std::vector<Mob*> mobMap) {
    noKey = new NoKeyCommand;
    atk = new AttackCommand;

    player.play(*player.currentAnimation); //DAFUQ??? otherwise game will crash
    playerBoundingBox = player.getGlobalBounds();

    playerPosition = player.getPosition();
    x = playerPosition.x/32;
    y = playerPosition.y/32;

    float dist1 = 0, dist2 = 0;
    int index = 0;
    if(!mobMap.empty()) {
        dist1 = sqrt((playerPosition.x - mobMap[0]->getPosition().x) * (playerPosition.x - mobMap[0]->getPosition().x) +
                     (playerPosition.y - mobMap[0]->getPosition().y) * (playerPosition.y - mobMap[0]->getPosition().y));

        for (int i = 1; i < mobMap.size(); ++i) {
            dist2 = sqrt(
                    (playerPosition.x - mobMap[i]->getPosition().x) * (playerPosition.x - mobMap[i]->getPosition().x) +
                    (playerPosition.y - mobMap[i]->getPosition().y) * (playerPosition.y - mobMap[i]->getPosition().y));
            if ((dist2 < dist1) && (dist2 > 32)) {
                dist1 = dist2;
                index = i;
            }
        }

        mobBoundingBox = mobMap[index]->getGlobalBounds();
        mobMap[index]->setCollidable(1);
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

Command* Collision::testObstructPlayerCollision(Command& command, std::vector<Mob*> mobMap) {
    if(typeid(command).name() == typeid(UpCommand).name()){
        if((collisionLeftTop == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftTop)) || (collisionRightTop == "1" && playerBoundingBox.intersects(tileBoundingBoxRightTop)) || playerBoundingBox.intersects(mobBoundingBox) || mobBoundingBox.contains(playerPosition.x,playerPosition.y) || mobBoundingBox.contains(playerPosition.x+32,playerPosition.y))
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

    if(typeid(command).name() == typeid(AttackCommand).name()){
        if(playerBoundingBox.intersects(mobBoundingBox)){
            return atk;
        }
    }

    return &command;
}