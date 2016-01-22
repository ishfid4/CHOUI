//
// Created by ishfid on 12/23/15.
//

#include "Mob.h"

Mob::Mob() { }

Mob::Mob(std::string path, sf::Vector2f spawnCoordinates) : Entity(path, spawnCoordinates) {
    collidable = 0;
    basicAttackSpeed = 0.5;
}

Mob::~Mob() { }

int Mob::getCollidable() const{
    return collidable;
}

void Mob::setCollidable(int col){
    collidable = col;
}

int Mob::getId() const {
    return id;
}

void Mob::setId(int iD) {
    id = iD;
}

Mob& Mob::operator--(){
    healthPoints-=8;
    return *this;
}