//
// Created by ishfid on 12/30/15.
//

#include "Weapon.h"

Weapon::Weapon(sf::Texture* texture, sf::Vector2f position) : Item(texture,position) { }

Weapon::~Weapon() { }

int Weapon::getID() const {
    return ID;
}

void Weapon::setID(int Id) {
    ID = Id;
}

int Weapon::getPhysicalDMG() const {
    return physicalDMG;
}

void Weapon::setPhysicalDMG(int physicalDmg) {
    physicalDMG = physicalDmg;
}

int Weapon::getMagicDMG() const {
    return magicDMG;
}

void Weapon::setMagicDMG(int magicDmg) {
    magicDMG = magicDmg;
}

int Weapon::getIntReq() const {
    return intReq;
}

void Weapon::setIntReq(int intREq) {
    intReq = intREq;
}

int Weapon::getStrReq() const {
    return strReq;
}

void Weapon::setStrReq(int strREq) {
    strReq = strREq;
}