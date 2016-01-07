//
// Created by ishfid on 1/4/16.
//

#ifndef CHOUI_SPAWNER_H
#define CHOUI_SPAWNER_H


#include "Mob.h"
#include <memory>

class Spawner {
public:
    Spawner(int maxMobs, int xPos, int yPos, int hp, int str, int intel, float speedMob, int id);
    ~Spawner();
    void spawnMob(std::vector<std::unique_ptr<Mob>>& mobMap);

private:
    int maxMobSpawned, mobid;
    int xPosition, yPosition;
    int mobhp, mobstr, mobint;
    float speed;
};


#endif //CHOUI_SPAWNER_H
