//
// Created by ishfid on 12/30/15.
//

#ifndef CHOUI_WEAPON_H
#define CHOUI_WEAPON_H


#include "Item.h"

class Weapon : public Item{
public:
    Weapon(std::string path, sf::Vector2f position);
    ~Weapon();

    int getID() const;
    void setID(int ID);
    int getPhysicalDMG() const;
    void setPhysicalDMG(int physicalDMG);
    int getMagicDMG() const;
    void setMagicDMG(int magicDMG);
    int getStrReq() const;
    void setStrReq(int strReq);
    int getIntReq() const;
    void setIntReq(int intReq);

private:
    int ID;
    int physicalDMG, magicDMG;
    int strReq, intReq;
};


#endif //CHOUI_WEAPON_H
