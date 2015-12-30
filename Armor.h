//
// Created by ishfid on 12/30/15.
//

#ifndef CHOUI_ARMOR_H
#define CHOUI_ARMOR_H


#include "Item.h"

class Armor : public Item{
public:
    Armor(std::string path, sf::Vector2f position);
    ~Armor();

    int getID() const;
    void setID(int ID);
    int getArmorType() const;
    void setArmorType(int armorType);
    int getMagicResist() const;
    void setMagicResist(int magicResist);
    int getPhysicResist() const;
    void setPhysicResist(int physicResist);
    int getStrReq() const;
    void setStrReq(int strReq);
    int getIntReq() const;
    void setIntReq(int intReq);
    int getBonusType() const;
    void setBonusType(int bonusType) ;
    int getBonusVal() const;
    void setBonusVal(int bonusVal);

private:
    int ID, armorType;
    int magicResist, physicResist;
    int strReq, intReq;
    int bonusType, bonusVal;
};


#endif //CHOUI_ARMOR_H
