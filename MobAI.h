//
// Created by ishfid on 1/2/16.
//

#ifndef CHOUI_AI_H
#define CHOUI_AI_H


#include <STP/Core/TileMap.hpp>
#include "Entity.h"
#include "Command.h"

class MobAI {
public:
    MobAI();

    void mobsMovement(std::vector<Mob*>& mobMap, sf::Time frameTime, tmx::TileMap& tileMap, Player& player, std::string layer, std::string propertyName);

private:
    UpCommand* UP_;
    DownCommand* DOWN_;
    RightCommand* RIGHT_;
    LeftCommand* LEFT_;
    NoKeyCommand* noButton_;
};


#endif //CHOUI_AI_H
