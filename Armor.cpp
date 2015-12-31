//
// Created by ishfid on 12/30/15.
//

#include "Armor.h"

Armor::Armor(sf::Texture* texture, sf::Vector2f position) : Item(texture, position) { }

Armor::~Armor() { }

int Armor::getID() const {
    return ID;
}

void Armor::setID(int Id) {
    ID = Id;
}

std::string Armor::getArmorType() const {
    return armorType;
}

void Armor::setArmorType(std::string armorTYpe) {
   armorType = armorTYpe;
}

int Armor::getMagicResist() const {
    return magicResist;
}

void Armor::setMagicResist(int magicREsist) {
    magicResist = magicREsist;
}

int Armor::getPhysicResist() const {
    return physicResist;
}

void Armor::setPhysicResist(int physicREsist) {
    physicResist = physicREsist;
}

int Armor::getStrReq() const {
    return strReq;
}

void Armor::setStrReq(int strREq) {
    strReq = strREq;
}

int Armor::getIntReq() const {
    return intReq;
}

void Armor::setIntReq(int intREq) {
    intReq = intREq;
}

int Armor::getBonusType() const {
    return bonusType;
}

void Armor::setBonusType(int bonusTYpe) {
    bonusType = bonusTYpe;
}

int Armor::getBonusVal() const {
    return bonusVal;
}

void Armor::setBonusVal(int bonusVAl) {
    bonusVal = bonusVAl;
}