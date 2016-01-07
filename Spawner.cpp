//
// Created by ishfid on 1/4/16.
//

#include "Spawner.h"

Spawner::Spawner(int maxMobs, int xPos, int yPos, int hp, int str, int intel, float speedMob, int id) {
    maxMobSpawned = maxMobs;
    xPosition = xPos;
    yPosition = yPos;
    mobhp = hp;
    mobstr = str;
    mobint = intel;
    speed = speedMob;
    mobid = id;
}

Spawner::~Spawner() { }

void Spawner::spawnMob(std::vector<std::unique_ptr<Mob>>& mobMap){
    int count = 0;
    std::string path;
    if(!mobMap.empty()){
        for (int i = 0; i < mobMap.size(); ++i) {
            if(mobMap[i]->getId() == mobid)
                count++;
        }
    }

    switch(mobid){
        case 0:
            path = "assets/sprites/mobs/smallAnaconda.png";
        break;
    }

    if(count < maxMobSpawned){
        for (int i = 0; i < (maxMobSpawned-count); ++i) {
            mobMap.emplace_back(new Mob(path, sf::Vector2f(xPosition,yPosition)));
            mobMap[mobMap.size()-1]->setId(mobid);
            mobMap[mobMap.size()-1]->healthPoints = mobhp;
            mobMap[mobMap.size()-1]->maxHealthPoints = mobhp;
            mobMap[mobMap.size()-1]->strength = mobstr;
            mobMap[mobMap.size()-1]->intelligance = mobint;
            mobMap[mobMap.size()-1]->speed = speed;
            mobMap[mobMap.size()-1]->play(*mobMap[mobMap.size()-1]->currentAnimation);
        }
    }
}