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
    virtual void execute(Entity& entity, sf::Time frameTime, std::vector<Mob*>& mobMap, Player& player, sf::Vector2f movement = sf::Vector2f(0.f,0.f)) = 0;
};

class UpCommand : public Command{
public:
    virtual void execute(Entity&entity, sf::Time frameTime, std::vector<Mob*>& mobMap, Player& player, sf::Vector2f movement = sf::Vector2f(0.f, 0.f)){
        entity.currentAnimation = &entity.walkingAnimationUp;
        movement.y -= entity.speed;
        entity.play(*entity.currentAnimation);
        entity.move(movement * frameTime.asSeconds());
        entity.update(frameTime);
    }
};

class DownCommand : public Command{
public:
    virtual void execute(Entity& entity, sf::Time frameTime, std::vector<Mob*>& mobMap, Player& player, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
        entity.currentAnimation = &entity.walkingAnimationDown;
        movement.y += entity.speed;
        entity.play(*entity.currentAnimation);
        entity.move(movement * frameTime.asSeconds());
        entity.update(frameTime);
    }
};

class LeftCommand : public Command{
public:
    virtual void execute(Entity&entity, sf::Time frameTime, std::vector<Mob*>& mobMap, Player& player, sf::Vector2f movement = sf::Vector2f(0.f, 0.f)){
        entity.currentAnimation = &entity.walkingAnimationLeft;
        movement.x -= entity.speed;
        entity.play(*entity.currentAnimation);
        entity.move(movement * frameTime.asSeconds());
        entity.update(frameTime);
    }
};

class RightCommand : public Command{
public:
    virtual void execute(Entity& entity, sf::Time frameTime, std::vector<Mob*>& mobMap, Player& player, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
        entity.currentAnimation = &entity.walkingAnimationRight;
        movement.x += entity.speed;
        entity.play(*entity.currentAnimation);
        entity.move(movement * frameTime.asSeconds());
        entity.update(frameTime);
    }
};

class NoKeyCommand : public Command{
public:
    virtual void execute(Entity& entity, sf::Time frameTime, std::vector<Mob*>& mobMap, Player& player, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
        entity.play(*entity.currentAnimation);
        entity.stop();
        entity.update(frameTime);
    }
};

class PlayerAttackCommand : public Command{
public:
    virtual void execute(Entity& entity, sf::Time frameTime, std::vector<Mob*>& mobMap, Player& player, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
        entity.play(*entity.currentAnimation);
        entity.stop();
        entity.update(frameTime);

        for (int i = 0; i < mobMap.size();) {
            if(mobMap[i]->getCollidable() == 1){
                if(mobMap[i]->healthPoints > 0){
                    mobMap[i]->healthPoints -= entity.strength + entity.intelligance;
                    mobMap[i]->setCollidable(0);
                    i++;
                }else{
                    mobMap.erase(mobMap.begin() + i);
                }
            }else{
                i++;
            }
        }
    }
};

class MobAttackCommand : public Command{
public:
    virtual void execute(Entity& entity, sf::Time frameTime, std::vector<Mob*>& mobMap, Player& player, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
        entity.play(*entity.currentAnimation);
        entity.stop();
        entity.update(frameTime);

        for (int i = 0; i < mobMap.size();) {
            if(mobMap[i]->getCollidable() == 1){
                if(player.healthPoints > 0){
                    player.healthPoints -= entity.strength + entity.intelligance;
                    mobMap[i]->setCollidable(0);
                    i++;
                }else{
                    player.speed = 0;
                }
            }else{
                i++;
            }
        }
    }
};

class PickCommand : public Command{
public:
    virtual void execute(Entity& entity, sf::Time frameTime, std::vector<Mob*>& mobMap, Player& player, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){}
};

#endif //CHOUI_COMMAND_H
