//
// Created by ishfid on 12/25/15.
//

#include <iostream>
#include "Collision.h"

Collision::Collision() {
    noKey = new NoKeyCommand;
}

Command* Collision::testPlayerCollision(tmx::TileMap& tileMap, Player& player, Command* command) {
    sf::Vector2f playerPosition = player.getPosition();
    std::string collidable;
    int x,y;
    x = (int)(floor(playerPosition.x))/32;
    y = (int)(floor(playerPosition.y))/32;

    //std::cout<<typeid(command).name()<<" "<<typeid(NoKeyCommand).name()<<std::endl;
    //if(typeid(command).name() == typeid(UpCommand).name())
    if(typeid(command).name() == typeid(UpCommand).name()){
        collidable = tileMap.GetLayer("Ground").GetTile(x,y+1).GetPropertyValue("Collidable");
        std::cout<<"UP"<<std::endl;
        if(collidable == "1"){
            //return command;
            return noKey;
        }
    }
    if(typeid(command).name() == typeid(DownCommand).name()) {
        collidable = tileMap.GetLayer("Ground").GetTile(x, y - 1).GetPropertyValue("Collidable");
        std::cout<<"Down"<<std::endl;
        if (collidable == "1") {
            return noKey;
            //return command;
        }
    }

    if(typeid(command).name() == typeid(RightCommand).name()) {
        collidable = tileMap.GetLayer("Ground").GetTile(x + 1, y).GetPropertyValue("Collidable");
        std::cout<<"Right"<<std::endl;
        if (collidable == "1") {
            return noKey;
            //return command;
        }
    }

    if(typeid(command).name() == typeid(LeftCommand).name()) {
        collidable = tileMap.GetLayer("Ground").GetTile(x - 1, y).GetPropertyValue("Collidable");
        std::cout<<"Left"<<std::endl;
        if (collidable == "1") {
            return noKey;
            //return command;
        }
    }
    std::cout<<"Last"<<std::endl;
    return command;
}