//
// Created by ishfid on 12/24/15.
//

#include "InputHandler.h"

InputHandler::InputHandler() {
    buttonUP_ = new UpCommand;
    buttonDOWN_ = new DownCommand;
    buttonRIGHT_ = new RightCommand;
    buttonLEFT_ = new LeftCommand;
    noButton_ = new NoKeyCommand;
    buttonA_ = new PlayerAttackCommand;
    buttonZ_ = new PickCommand;
    buttonI_ = new InventoryCommand;
}

Command* InputHandler::handleInput(Player& player) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        return buttonUP_;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        return buttonDOWN_;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return buttonRIGHT_;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return buttonLEFT_;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        return buttonA_;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        return buttonZ_;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        return buttonI_;

    return noButton_;
}