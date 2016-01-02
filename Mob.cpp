//
// Created by ishfid on 12/23/15.
//

#include "Mob.h"

Mob::Mob() { }

Mob::Mob(std::string path, sf::Vector2f spawnCoordinates) : Entity(path, spawnCoordinates) {
    collidable = 0;
}

Mob::~Mob() { }

int Mob::getCollidable() const{
    return collidable;
}

int Mob::setCollidable(int col){
    collidable = col;
}