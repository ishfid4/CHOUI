//
// Created by ishfid on 1/4/16.
//

#include "Inventory.h"

Inventory::Inventory() { }

Inventory::~Inventory() { }

void Inventory::addToInv(Player &player, std::vector<Weapon*> &weaponMap, std::vector<Armor*> &armorMap, int weaponID, int armorID, tmx::TileMap& tileMap) {
    if(weaponID > (-1)) {
        player.inventory.push_back(weaponMap[weaponID]);
        tileMap.GetLayer("Weapon").GetTile(weaponMap[weaponID]->getPosition().x/32,weaponMap[weaponID]->getPosition().y/32).visible = false;
        weaponMap.erase(weaponMap.begin() + weaponID);
    }

    if(armorID > (-1)) {
        player.inventory.push_back(armorMap[armorID]);
        tileMap.GetLayer("Armor").GetTile(armorMap[armorID]->getPosition().x/32,armorMap[armorID]->getPosition().y/32).visible = false;
        armorMap.erase(armorMap.begin() + armorID);
    }
}