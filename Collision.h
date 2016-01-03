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
    Collision(tmx::TileMap& tileMap, Mob& mob, Player& player, std::string layer, std::string propertyName);
    Collision(tmx::TileMap& tileMap, Player& player, std::string layer, std::string propertyName, std::vector<Mob*> mobMap);
    Command* testObstructPlayerCollision(Command& command);
    Command* testObstructMobCollision(Command& command);

private:
    NoKeyCommand* noKey;
    PlayerAttackCommand* playerAtk;
    MobAttackCommand* mobAtk;

    sf::FloatRect playerBoundingBox;
    sf::FloatRect mobBoundingBox;
    sf::Vector2f playerPosition;
    sf::Vector2f mobPosition;

    float x;
    float y;
    int index; // for position in vector<Mob*>

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
