//
// Created by ishfid on 12/24/15.
//

#ifndef CHOUI_INPUTHANDLER_H
#define CHOUI_INPUTHANDLER_H


#include "Command.h"

class InputHandler{
public:
    InputHandler();
    Command* handleInput(Player& player);
    virtual void execute(Player& player, sf::Time frameTime, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){}
    //sf::Vector2f movement;

private:
    UpCommand* buttonUP_;
    DownCommand* buttonDOWN_;
    RightCommand* buttonRIGHT_;
    LeftCommand* buttonLEFT_;
    NoKeyCommand* noButton_;
};


#endif //CHOUI_INPUTHANDLER_H
