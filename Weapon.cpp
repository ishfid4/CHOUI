//
// Created by ishfid on 12/30/15.
//

#include "Weapon.h"

Weapon::Weapon(std::string path, sf::Vector2f position) : Item(path,position) { }

Weapon::~Weapon() { }

int Weapon::getID() const {
    return ID;
}

void Weapon::setID(int ID) {
    ID = ID;
}

int Weapon::getPhysicalDMG() const {
    return physicalDMG;
}

void Weapon::setPhysicalDMG(int physicalDMG) {
    physicalDMG = physicalDMG;
}

int Weapon::getMagicDMG() const {
    return magicDMG;
}

void Weapon::setMagicDMG(int magicDMG) {
    magicDMG = magicDMG;
}

int Weapon::getIntReq() const {
    return intReq;
}

void Weapon::setIntReq(int intReq) {
    intReq = intReq;
}

int Weapon::getStrReq() const {
    return strReq;
}

void Weapon::setStrReq(int strReq) {
    strReq = strReq;
}