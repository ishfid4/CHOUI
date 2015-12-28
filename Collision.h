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
    Collision();
    Command* testPlayerCollision(tmx::TileMap& tileMap, Player& player, Command& command);

private:
    NoKeyCommand* noKey;
};


#endif //CHOUI_COLLISION_H
