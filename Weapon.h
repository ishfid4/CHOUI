//
// Created by ishfid on 12/30/15.
//

#ifndef CHOUI_WEAPON_H
#define CHOUI_WEAPON_H


#include "Item.h"

class Weapon : public Item{
public:
    Weapon(sf::Texture* texture, sf::Vector2f position);
    ~Weapon();

    int getID() const;
    void setID(int Id);
    int getPhysicalDMG() const;
    void setPhysicalDMG(int physicalDmg);
    int getMagicDMG() const;
    void setMagicDMG(int magicDmg);
    int getStrReq() const;
    void setStrReq(int strREq);
    int getIntReq() const;
    void setIntReq(int intREq);

private:
    int ID;
    int physicalDMG, magicDMG;
    int strReq, intReq;
};


#endif //CHOUI_WEAPON_H
