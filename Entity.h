//
// Created by ishfid on 12/23/15.
//

#ifndef CHOUI_PLAYER_H
#define CHOUI_PLAYER_H


#include "AnimatedSprite.h"
#include <SFML/Graphics.hpp>

class Entity : public AnimatedSprite{
public:
    Entity(std::string path, sf::Vector2f startingCoordinates);
    ~Entity();

    Animation walkingAnimationUp;
    Animation walkingAnimationRight;
    Animation walkingAnimationLeft;
    Animation walkingAnimationDown;
    Animation* currentAnimation;
    float speed;
    sf::Texture entityTexture;

    float healthPoints, manaPoints;
    int level, experiance;
    int strength, intelligance;
    float defence, magicResist;
};


#endif //CHOUI_PLAYER_H
