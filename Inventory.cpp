//
// Created by ishfid on 1/4/16.
//

#include "Inventory.h"

Inventory::Inventory() { }

Inventory::~Inventory() { }

void Inventory::addToInv(Player &player, std::vector<std::unique_ptr<Weapon>> &weaponMap,
                         std::vector<std::unique_ptr<Armor>> &armorMap, int weaponID, int armorID, tmx::TileMap& tileMap) {
    if(weaponID > (-1)) {
        player.inventory.push_back(weaponMap[weaponID].get());
        tileMap.GetLayer("Weapon").GetTile((u_int)weaponMap[weaponID]->getPosition().x/32,
                                           (u_int)weaponMap[weaponID]->getPosition().y/32).visible = false;
        weaponMap.erase(weaponMap.begin() + weaponID);
    }

    if(armorID > (-1)) {
        player.inventory.push_back(armorMap[armorID].get());
        tileMap.GetLayer("Armor").GetTile((u_int)armorMap[armorID]->getPosition().x/32,
                                          (u_int)armorMap[armorID]->getPosition().y/32).visible = false;
        armorMap.erase(armorMap.begin() + armorID);
    }
}