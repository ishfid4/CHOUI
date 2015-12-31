//
// Created by ishfid on 12/25/15.
//


#ifndef CHOUI_COLLISION_H
#define CHOUI_COLLISION_H

#include <STP/Core/TileMap.hpp>
#include "Player.h"
#include "Command.h"

class Collision{
public:
    Collision(tmx::TileMap& tileMap, Player& player, std::string layer, std::string propertyName);
    Command* testObstructPlayerCollision(Command& command);
    Command* testCollisonWithMob(Command& command, std::vector<Mob*> mobMap);

private:
    NoKeyCommand* noKey;

    sf::FloatRect playerBoundingBox;
    sf::FloatRect mobBoundingBox;
    sf::Vector2f playerPosition;
    float x;
    float y;

    sf::FloatRect tileBoundingBoxLeftTop;
    sf::FloatRect tileBoundingBoxRightTop;
    sf::FloatRect tileBoundingBoxLeftBottom;
    sf::FloatRect tileBoundingBoxRightBottom;

    std::string collisionLeftTop;
    std::string collisionRightTop;
    std::string collisionLeftBottom;
    std::string collisionRightBottom;
};


#endif //CHOUI_COLLISION_H
