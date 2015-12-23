//
// Created by ishfid on 12/23/15.
//

#include <iostream>
#include "Player.h"

Player::Player(std::string path, sf::Vector2f startingCoordinates, sf::Vector2f viewCoordinates) {
    if (!playerTexture.loadFromFile(path)) {
        std::cout << "Failed to load player spritesheet!" << std::endl;
    }

    walkingAnimationDown.setSpriteSheet(playerTexture);
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));

    walkingAnimationLeft.setSpriteSheet(playerTexture);
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect( 0, 32, 32, 32));

    walkingAnimationRight.setSpriteSheet(playerTexture);
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

    walkingAnimationUp.setSpriteSheet(playerTexture);
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));

    currentAnimation = &walkingAnimationDown;

    // set up AnimatedSprite
    animatedPlayerSprite = AnimatedSprite(sf::seconds(0.2), true, false);
    animatedPlayerSprite.setPosition(startingCoordinates); //Add coordinates in different way

    speed = 100.f;

    // creating player Viewport
    playerView.setCenter(sf::Vector2f(startingCoordinates));
    playerView.setSize(viewCoordinates);
}
