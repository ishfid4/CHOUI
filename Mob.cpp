//
// Created by ishfid on 12/23/15.
//

#include "Mob.h"

Mob::Mob(std::string path, sf::Vector2f spawnCoordinates) : Entity(path, spawnCoordinates) { }

Mob::~Mob() { }

void Mob::setHP(float hp){
    healthPoints = hp;
}

float Mob::getHP() const{
    return healthPoints;
}

void Mob::setMana(float mana){
    manaPoints = mana;
}

float Mob::getMana() const{
    return manaPoints;
}

void Mob::setDefence(float def){
    defence = def;
}

float Mob::getDefence() const{
    return defence;
}

void Mob::setMgResist(float mr){
    magicResist = mr;
}

float Mob::getMgResist() const{
    return magicResist;
}

void Mob::setLevel(int lvl){
    level = lvl;
}

int Mob::getLevel() const{
    return level;
}