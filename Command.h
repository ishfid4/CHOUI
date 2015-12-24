//
// Created by ishfid on 12/24/15.
//

#ifndef CHOUI_COMMAND_H
#define CHOUI_COMMAND_H

#include "Player.h"

class Command{
public:
    Command();
    virtual ~Command(){};
    virtual void execute(Player& player, sf::Time frameTime, sf::Vector2f movement = sf::Vector2f(0.f,0.f)) = 0;
    sf::Vector2f movement;
};

class UpCommand : public Command{
public:
    virtual void execute(Player& player, sf::Time frameTime, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
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
    virtual void execute(Player& player, sf::Time frameTime, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
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
    virtual void execute(Player& player, sf::Time frameTime,  sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
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
    virtual void execute(Player& player, sf::Time frameTime,  sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
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
    virtual void execute(Player& player, sf::Time frameTime,  sf::Vector2f movement = sf::Vector2f(0.f,0.f)){
        player.play(*player.currentAnimation);
        player.stop();
        player.update(frameTime);
    }
};

#endif //CHOUI_COMMAND_H
