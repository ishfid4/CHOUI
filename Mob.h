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
    void setCollidable(int col);
    int getId() const;
    void setId(int iD);
    Mob& operator--();

private:
    int collidable, id;

};


#endif //CHOUI_MOB_H
