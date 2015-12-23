//
// Created by ishfid on 12/23/15.
//

#ifndef CHOUI_PLAYER_H
#define CHOUI_PLAYER_H


#include "AnimatedSprite.h"
#include <SFML/Graphics.hpp>

class Player : public AnimatedSprite{
public:
    Player(std::string path, sf::Vector2f startingCoordinates, sf::Vector2f viewCoordinates);
    ~Player();

    Animation walkingAnimationUp;
    Animation walkingAnimationRight;
    Animation walkingAnimationLeft;
    Animation walkingAnimationDown;
    Animation* currentAnimation;
    AnimatedSprite animatedPlayerSprite;
    sf::View playerView;
    float speed;
    sf::Texture playerTexture;
};


#endif //CHOUI_PLAYER_H
