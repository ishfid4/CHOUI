//
// Created by ishfid on 12/24/15.
//

#include "InputHandler.h"

Command* InputHandler::handleInput(Player& player) {/*
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        buttonUP_->execute(player, movement, frameTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        buttonDOWN_->execute(player, movement, frameTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        buttonRIGHT_->execute(player, movement, frameTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        buttonLEFT_->execute(player, movement, frameTime);

    noButton_->execute(player, frameTime);
*/
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        return buttonUP_;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        return buttonDOWN_;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return buttonRIGHT_;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return buttonLEFT_;

    return noButton_;
}