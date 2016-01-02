//
// Created by ishfid on 12/24/15.
//

#ifndef CHOUI_COMMAND_H
#define CHOUI_COMMAND_H

#include <iostream>
#include "Player.h"
#include "Mob.h"

class Command{
public:
    Command();
    virtual ~Command(){};
    virtual void execute(Player& player, sf::Time frameTime, std::vector<Mob*>& mobMap, sf::Vector2f movement = sf::Vector2f(0.f,0.f)) = 0;
    sf::Vector2f movement;
};

class UpCommand : public Command{
public:
    virtual void execute(Player& player, sf::Time frameTime, std::vector<Mob*>& mobMap, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
        player.currentAnimation = &player.walkingAnimationUp;
        movement.y -= player.speed;
        player.play(*player.currentAnimation);
        player.move(movement * frameTime.asSeconds());
        player.playerView.move(movement * frameTime.asSeconds());
        player.update(frameTime);
    }
};

class DownCommand : public Command{
public:
    virtual void execute(Player& player, sf::Time frameTime, std::vector<Mob*>& mobMap, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
        player.currentAnimation = &player.walkingAnimationDown;
        movement.y += player.speed;
        player.play(*player.currentAnimation);
        player.move(movement * frameTime.asSeconds());
        player.playerView.move(movement * frameTime.asSeconds());
        player.update(frameTime);
    }
};

class LeftCommand : public Command{
public:
    virtual void execute(Player& player, sf::Time frameTime, std::vector<Mob*>& mobMap, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
        player.currentAnimation = &player.walkingAnimationLeft;
        movement.x -= player.speed;
        player.play(*player.currentAnimation);
        player.move(movement * frameTime.asSeconds());
        player.playerView.move(movement * frameTime.asSeconds());
        player.update(frameTime);
    }
};

class RightCommand : public Command{
public:
    virtual void execute(Player& player, sf::Time frameTime, std::vector<Mob*>& mobMap, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
        player.currentAnimation = &player.walkingAnimationRight;
        movement.x += player.speed;
        player.play(*player.currentAnimation);
        player.move(movement * frameTime.asSeconds());
        player.playerView.move(movement * frameTime.asSeconds());
        player.update(frameTime);
    }
};

class NoKeyCommand : public Command{
public:
    virtual void execute(Player& player, sf::Time frameTime, std::vector<Mob*>& mobMap, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
        player.play(*player.currentAnimation);
        player.stop();
        player.update(frameTime);
    }
};

class AttackCommand : public Command{
public:
    virtual void execute(Player& player, sf::Time frameTime, std::vector<Mob*>& mobMap, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
        player.play(*player.currentAnimation);
        player.stop();
        player.update(frameTime);

        for (int i = 0; i < mobMap.size(); ++i) {
            if(mobMap[i]->getCollidable() == 1){
                if(mobMap[i]->healthPoints > 0)
                    mobMap[i]->healthPoints -= player.strength + player.intelligance;
                if(mobMap[i]->healthPoints <= 0){
                    //delete mobMap[i];
                    std::cout<<mobMap[i]->healthPoints<<"\n";
                    mobMap.erase(std::remove(mobMap.begin(), mobMap.end(), mobMap[i]), mobMap.end());
                }
                std::cout<<mobMap[i]->healthPoints<<"\n";
            }
        }
    }
};

#endif //CHOUI_COMMAND_H
