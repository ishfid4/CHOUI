//
// Created by ishfid on 12/30/15.
//

#include "Armor.h"

Armor::Armor(std::string path, sf::Vector2f position) : Item(path, position) { }

Armor::~Armor() { }

int Armor::getID() const {
    return ID;
}

void Armor::setID(int ID) {
    ID = ID;
}

int Armor::getArmorType() const {
    return armorType;
}

void Armor::setArmorType(int armorType) {
   armorType = armorType;
}

int Armor::getMagicResist() const {
    return magicResist;
}

void Armor::setMagicResist(int magicResist) {
    magicResist = magicResist;
}

int Armor::getPhysicResist() const {
    return physicResist;
}

void Armor::setPhysicResist(int physicResist) {
    physicResist = physicResist;
}

int Armor::getStrReq() const {
    return strReq;
}

void Armor::setStrReq(int strReq) {
    strReq = strReq;
}

int Armor::getIntReq() const {
    return intReq;
}

void Armor::setIntReq(int intReq) {
    intReq = intReq;
}

int Armor::getBonusType() const {
    return bonusType;
}

void Armor::setBonusType(int bonusType) {
    bonusType = bonusType;
}

int Armor::getBonusVal() const {
    return bonusVal;
}

void Armor::setBonusVal(int bonusVal) {
    bonusVal = bonusVal;
}