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
    ATK_ = new AttackCommand;
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
                //UP_->execute(*mobMap[i], frameTime, mobMap);
                command = mobCollisions->testObstructMobCollision(*UP_);
                command->execute(*mobMap[i], frameTime, mobMap);
                break;
            case 1:
                //DOWN_->execute(*mobMap[i], frameTime, mobMap);
                command = mobCollisions->testObstructMobCollision(*DOWN_);
                command->execute(*mobMap[i], frameTime, mobMap);
                break;
            case 2:
                //RIGHT_->execute(*mobMap[i], frameTime, mobMap);
                command = mobCollisions->testObstructMobCollision(*RIGHT_);
                command->execute(*mobMap[i], frameTime, mobMap);
                break;
            case 3:
                //LEFT_->execute(*mobMap[i], frameTime, mobMap);
                command = mobCollisions->testObstructMobCollision(*LEFT_);
                command->execute(*mobMap[i], frameTime, mobMap);
                break;
            case 4:
                //noButton_->execute(*mobMap[i], frameTime, mobMap);
                command = mobCollisions->testObstructMobCollision(*noButton_);
                command->execute(*mobMap[i], frameTime, mobMap);
                break;
        }
    }
}