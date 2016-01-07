//
// Created by ishfid on 1/4/16.
//

#ifndef CHOUI_INVENTORY_H
#define CHOUI_INVENTORY_H


#include <STP/Core/TileMap.hpp>
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"

class Inventory {
public:
    Inventory();
    ~Inventory();
    void addToInv(Player& player, std::vector<std::unique_ptr<Weapon>> &weaponMap, std::vector<std::unique_ptr<Armor>> &armorMap, int weaponID, int armorID, tmx::TileMap& tileMap);
};


#endif //CHOUI_INVENTORY_H
