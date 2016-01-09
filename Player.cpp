//
// Created by ishfid on 12/23/15.
//

#include "Player.h"

Player::Player(std::string path, sf::Vector2f startingCoordinates, sf::Vector2f viewCoordinates) : Entity(path, startingCoordinates) {
    // creating player Viewport
    playerView.setCenter(sf::Vector2f(startingCoordinates));
    playerView.setSize(viewCoordinates);
    healthPoints = 300;
    strength = 3;
    intelligance = 2;
    magicResist = 0;
    defence = 0;
    basicAttackSpeed = 1;
    inventory.reserve(8);
    openedInv = false;
}

Player::~Player() {}
