//
// Created by ishfid on 12/25/15.
//

#include <iostream>
#include "Collision.h"

Collision::Collision(tmx::TileMap& tileMap, Player& player, std::string layer, std::string propertyName) {
    noKey = new NoKeyCommand;

    player.play(*player.currentAnimation); //DAFUQ??? otherwise game will crash
    playerBoundingBox = player.getGlobalBounds();

    playerPosition = player.getPosition();
    x = playerPosition.x/32;
    y = playerPosition.y/32;

    tileBoundingBoxLeftTop = tileMap.GetLayer(layer).GetTile(x,y).GetGlobalBounds();
    tileBoundingBoxRightTop = tileMap.GetLayer(layer).GetTile(x+1,y).GetGlobalBounds();
    tileBoundingBoxLeftBottom = tileMap.GetLayer(layer).GetTile(x,y+1).GetGlobalBounds();
    tileBoundingBoxRightBottom = tileMap.GetLayer(layer).GetTile(x+1,y+1).GetGlobalBounds();

    collisionLeftTop = tileMap.GetLayer(layer).GetTile(x,y).GetPropertyValue(propertyName);
    collisionRightTop = tileMap.GetLayer(layer).GetTile(x+1,y).GetPropertyValue(propertyName);
    collisionLeftBottom = tileMap.GetLayer(layer).GetTile(x,y+1).GetPropertyValue(propertyName);
    collisionRightBottom = tileMap.GetLayer(layer).GetTile(x+1,y+1).GetPropertyValue(propertyName);
}

Command* Collision::testObstructPlayerCollision(Command& command) {
    if(typeid(command).name() == typeid(UpCommand).name()){
        if((collisionLeftTop == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftTop)) || (collisionRightTop == "1" && playerBoundingBox.intersects(tileBoundingBoxRightTop)))
            return noKey;
    }

    if(typeid(command).name() == typeid(DownCommand).name()) {
        if((collisionLeftBottom == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftBottom)) || (collisionRightBottom == "1" && playerBoundingBox.intersects(tileBoundingBoxRightBottom)))
            return noKey;
    }

    if(typeid(command).name() == typeid(RightCommand).name()) {
        if((collisionRightTop == "1" && playerBoundingBox.intersects(tileBoundingBoxRightTop)) || (collisionRightBottom == "1" && playerBoundingBox.intersects(tileBoundingBoxRightBottom)))
            return noKey;
    }

    if(typeid(command).name() == typeid(LeftCommand).name()) {
        if((collisionLeftTop == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftTop)) || (collisionLeftBottom == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftBottom)))
            return noKey;
    }

    return &command;
}

Command* Collision::testCollisonWithMob(Command& command, std::vector<Mob*> mobMap){
    mobBoundingBox = mobMap[].getGlobalBounds();
}