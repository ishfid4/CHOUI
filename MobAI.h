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

    void mobsMovement(std::vector<std::unique_ptr<Mob>>& mobMap, sf::Time frameTime, tmx::TileMap& tileMap, Player& player, std::string layer, std::string propertyName);

private:
    std::unique_ptr<UpCommand> UP_;
    std::unique_ptr<DownCommand> DOWN_;
    std::unique_ptr<RightCommand> RIGHT_;
    std::unique_ptr<LeftCommand> LEFT_;
    std::unique_ptr<NoKeyCommand> noButton_;
};


#endif //CHOUI_AI_H
