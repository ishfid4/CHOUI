//
// Created by ishfid on 12/25/15.
//

#include <iostream>
#include "Collision.h"

Collision::Collision() {
    noKey = new NoKeyCommand;
}

Command* Collision::testPlayerCollision(tmx::TileMap& tileMap, Player& player, Command& command) {
    player.play(*player.currentAnimation); //DAFUQ??? otherwise game will crash
    sf::FloatRect playerBoundingBox = player.getGlobalBounds();

    sf::Vector2f playerPosition = player.getPosition();
    float x = playerPosition.x/32;
    float y = playerPosition.y/32;

    sf::FloatRect tileBoundingBoxLeftTop = tileMap.GetLayer("Ground").GetTile(x,y).GetGlobalBounds();
    sf::FloatRect tileBoundingBoxRightTop = tileMap.GetLayer("Ground").GetTile(x+1,y).GetGlobalBounds();
    sf::FloatRect tileBoundingBoxLeftBottom = tileMap.GetLayer("Ground").GetTile(x,y+1).GetGlobalBounds();
    sf::FloatRect tileBoundingBoxRightBottom = tileMap.GetLayer("Ground").GetTile(x+1,y+1).GetGlobalBounds();

    std::string collidableLeftTop = tileMap.GetLayer("Ground").GetTile(x,y).GetPropertyValue("Collidable");
    std::string collidableRightTop = tileMap.GetLayer("Ground").GetTile(x+1,y).GetPropertyValue("Collidable");
    std::string collidableLeftBottom = tileMap.GetLayer("Ground").GetTile(x,y+1).GetPropertyValue("Collidable");
    std::string collidableRightBottom = tileMap.GetLayer("Ground").GetTile(x+1,y+1).GetPropertyValue("Collidable");

    if(typeid(command).name() == typeid(UpCommand).name()){
        if((collidableLeftTop == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftTop)) || (collidableRightTop == "1" && playerBoundingBox.intersects(tileBoundingBoxRightTop)))
            return noKey;
    }

    if(typeid(command).name() == typeid(DownCommand).name()) {
        if((collidableLeftBottom == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftBottom)) || (collidableRightBottom == "1" && playerBoundingBox.intersects(tileBoundingBoxRightBottom)))
            return noKey;
    }

    if(typeid(command).name() == typeid(RightCommand).name()) {
        if((collidableRightTop == "1" && playerBoundingBox.intersects(tileBoundingBoxRightTop)) || (collidableRightBottom == "1" && playerBoundingBox.intersects(tileBoundingBoxRightBottom)))
            return noKey;
    }

    if(typeid(command).name() == typeid(LeftCommand).name()) {
        if((collidableLeftTop == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftTop)) || (collidableLeftBottom == "1" && playerBoundingBox.intersects(tileBoundingBoxLeftBottom)))
            return noKey;
    }

    return &command;
}