//
// Created by ishfid on 1/2/16.
//

#include "MobAI.h"
#include "Collision.h"

MobAI::MobAI() {
    UP_ = new UpCommand;
    DOWN_ = new DownCommand;
    RIGHT_ = new RightCommand;
    LEFT_ = new LeftCommand;
    noButton_ = new NoKeyCommand;
}

void MobAI::mobsMovement(std::vector<Mob *> &mobMap, sf::Time frameTime, tmx::TileMap& tileMap, Player& player, std::string layer, std::string propertyName) {
    srand(time(NULL));
    int random;
    Collision *mobCollisions;
    Command* command;
    for (int i = 0; i < mobMap.size(); ++i) {
        mobCollisions = new Collision(tileMap, *mobMap[i], player, layer, propertyName);
        random = rand()%5;
        switch(random){
            case 0:
                command = mobCollisions->testObstructMobCollision(*UP_, mobMap);
                command->execute(*mobMap[i], frameTime, mobMap, player);
                break;
            case 1:
                command = mobCollisions->testObstructMobCollision(*DOWN_, mobMap);
                command->execute(*mobMap[i], frameTime, mobMap, player);
                break;
            case 2:
                command = mobCollisions->testObstructMobCollision(*RIGHT_, mobMap);
                command->execute(*mobMap[i], frameTime, mobMap, player);
                break;
            case 3:
                command = mobCollisions->testObstructMobCollision(*LEFT_, mobMap);
                command->execute(*mobMap[i], frameTime, mobMap, player);
                break;
            case 4:
                command = mobCollisions->testObstructMobCollision(*noButton_, mobMap);
                command->execute(*mobMap[i], frameTime, mobMap, player);
                break;
            default:
                break;
        }
    }
}