//
// Created by ishfid on 12/23/15.
//

#ifndef CHOUI_MOB_H
#define CHOUI_MOB_H


#include "Entity.h"

class Mob : public Entity{
public:
    Mob();
    Mob(std::string path, sf::Vector2f spawnCoordinates);
    ~Mob();
    int getCollidable() const;
    int setCollidable(int col);

private:
    int collidable;

};


#endif //CHOUI_MOB_H
