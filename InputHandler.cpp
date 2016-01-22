//
// Created by ishfid on 12/24/15.
//

#include "InputHandler.h"

InputHandler::InputHandler() :
        buttonUP_(new UpCommand),
        buttonDOWN_(new DownCommand),
        buttonRIGHT_(new RightCommand),
        buttonLEFT_(new LeftCommand),
        noButton_(new NoKeyCommand),
        buttonA_(new PlayerAttackCommand),
        buttonZ_(new PickCommand),
        buttonI_(new InventoryCommand)
{

}

Command* InputHandler::handleInput(Player& player) {
    Command* nextCommand = noButton_.get();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        nextCommand = buttonUP_.get();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        nextCommand = buttonDOWN_.get();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        nextCommand = buttonRIGHT_.get();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        nextCommand = buttonLEFT_.get();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        nextCommand = buttonA_.get();
    else if(!wasZPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        nextCommand = buttonZ_.get();
    else if(!wasIPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        nextCommand = buttonI_.get();

    wasIPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::I);
    wasZPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);

    return nextCommand;
}