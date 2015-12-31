//
// Created by ishfid on 12/23/15.
//

#ifndef CHOUI_MOB_H
#define CHOUI_MOB_H


#include "Entity.h"

class Mob : public Entity{
public:
    Mob(std::string path, sf::Vector2f spawnCoordinates);
    ~Mob();

    void setHP(float hp);
    float getHP() const;
    void setMana(float mana);
    float getMana() const;
    void setDefence(float def);
    float getDefence() const;
    void setMgResist(float mr);
    float getMgResist() const;
    void setLevel(int lvl);
    int getLevel() const;

};


#endif //CHOUI_MOB_H
