//
// Created by ishfid on 12/30/15.
//

#ifndef CHOUI_ARMOR_H
#define CHOUI_ARMOR_H


#include "Item.h"

class Armor : public Item{
public:
    Armor(sf::Texture* texture, sf::Vector2f position);
    ~Armor();

    int getID() const;
    void setID(int Id);
    std::string getArmorType() const;
    void setArmorType(std::string armorTYpe);
    int getMagicResist() const;
    void setMagicResist(int magicREsist);
    int getPhysicResist() const;
    void setPhysicResist(int physicREsist);
    int getStrReq() const;
    void setStrReq(int strREq);
    int getIntReq() const;
    void setIntReq(int intREq);
    int getBonusType() const;
    void setBonusType(int bonusTYpe) ;
    int getBonusVal() const;
    void setBonusVal(int bonusVAl);

private:
    int ID;
    std::string armorType;
    int magicResist, physicResist;
    int strReq, intReq;
    int bonusType, bonusVal;
};


#endif //CHOUI_ARMOR_H
