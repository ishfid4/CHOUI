//
// Created by ishfid on 12/30/15.
//

#ifndef CHOUI_ITEMSFROMMAP_H
#define CHOUI_ITEMSFROMMAP_H

#include <STP/Core/TileMap.hpp>
#include "Weapon.h"
#include "Armor.h"

std::vector<std::unique_ptr<Weapon>> loadWeaponsFromMap(tmx::TileMap& tileMap);
std::vector<std::unique_ptr<Armor>> loadArmorFromMap(tmx::TileMap& tileMap);

#endif //CHOUI_ITEMSFROMMAP_H
