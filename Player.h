//
// Created by ishfid on 12/23/15.
//

#ifndef CHOUI_NPC_H
#define CHOUI_NPC_H


#include "Entity.h"
#include "Item.h"

class Player : public Entity{
public:
    Player(std::string path, sf::Vector2f startingCoordinates, sf::Vector2f viewCoordinates);
    ~Player();

    sf::View playerView;
    std::vector<Item*> inventory;
};

#endif //CHOUI_NPC_H
