//
// Created by ishfid on 12/30/15.
//

#include <iostream>
#include "ItemsFromMap.h"

std::vector<std::unique_ptr<Weapon>> loadWeaponsFromMap(tmx::TileMap& tileMap){
    std::vector <std::unique_ptr<Weapon>> weaponsOnMap;

    for (u_int i = 1; i < tileMap.GetWidth(); i++) {
        for (u_int j = 1; j < tileMap.GetHeight(); j++) {
            if(!tileMap.GetLayer("Weapon").GetTile(i,j).empty()){
                int ID = std::stoi(tileMap.GetLayer("Weapon").GetTile(i,j).GetPropertyValue("ID"));
                weaponsOnMap.emplace_back(new Weapon(const_cast<sf::Texture*>(tileMap.GetTileSet("Weapons").GetTile((u_int)ID).GetTexture()),sf::Vector2f(i*32,j*32)));
                unsigned long vectorLength = weaponsOnMap.size();

                weaponsOnMap[vectorLength-1]->setID(ID);
                weaponsOnMap[vectorLength-1]->setName(tileMap.GetLayer("Weapon").GetTile(i,j).GetPropertyValue("name"));
                weaponsOnMap[vectorLength-1]->setIntReq(std::stoi(tileMap.GetLayer("Weapon").GetTile(i,j).GetPropertyValue("intReq")));
                weaponsOnMap[vectorLength-1]->setStrReq(std::stoi(tileMap.GetLayer("Weapon").GetTile(i,j).GetPropertyValue("strReq")));
                weaponsOnMap[vectorLength-1]->setPhysicalDMG(std::stoi(tileMap.GetLayer("Weapon").GetTile(i,j).GetPropertyValue("physicalDMG")));
                weaponsOnMap[vectorLength-1]->setMagicDMG(std::stoi(tileMap.GetLayer("Weapon").GetTile(i,j).GetPropertyValue("magicDMG")));
            }
        }
    }
    return weaponsOnMap;
}

std::vector<std::unique_ptr<Armor>> loadArmorFromMap(tmx::TileMap& tileMap){
    std::vector <std::unique_ptr<Armor>> armorOnMap;

    for (u_int i = 0; i < tileMap.GetWidth() ; ++i) {
        for (u_int j = 0; j < tileMap.GetHeight(); ++j) {
            if(!tileMap.GetLayer("Armor").GetTile(i,j).empty()){
                int ID = std::stoi(tileMap.GetLayer("Armor").GetTile(i,j).GetPropertyValue("ID"));
                armorOnMap.emplace_back(new Armor(const_cast<sf::Texture*>(tileMap.GetTileSet("Armor").GetTile((u_int)ID).GetTexture()),sf::Vector2f(i*32,j*32)));
                unsigned long vectorLength = armorOnMap.size();

                armorOnMap[vectorLength-1]->setID(ID);
                armorOnMap[vectorLength-1]->setName(tileMap.GetLayer("Armor").GetTile(i,j).GetPropertyValue("name"));
                armorOnMap[vectorLength-1]->setArmorType(tileMap.GetLayer("Armor").GetTile(i,j).GetPropertyValue("armorType"));
                armorOnMap[vectorLength-1]->setIntReq(std::stoi(tileMap.GetLayer("Armor").GetTile(i,j).GetPropertyValue("intReq")));
                armorOnMap[vectorLength-1]->setStrReq(std::stoi(tileMap.GetLayer("Armor").GetTile(i,j).GetPropertyValue("strReq")));
                armorOnMap[vectorLength-1]->setMagicResist(std::stoi(tileMap.GetLayer("Armor").GetTile(i,j).GetPropertyValue("physicalRes")));
                armorOnMap[vectorLength-1]->setPhysicResist(std::stoi(tileMap.GetLayer("Armor").GetTile(i,j).GetPropertyValue("magicRes")));
            }
        }
    }
    return armorOnMap;
}