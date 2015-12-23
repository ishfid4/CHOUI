//
// Created by ishfid on 12/23/15.
//

#include "Player.h"

Player::Player(std::string path, sf::Vector2f startingCoordinates, sf::Vector2f viewCoordinates) : Entity(path, startingCoordinates) {
    // creating player Viewport
    playerView.setCenter(sf::Vector2f(startingCoordinates));
    playerView.setSize(viewCoordinates);


}