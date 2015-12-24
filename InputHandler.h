//
// Created by ishfid on 12/24/15.
//

#ifndef CHOUI_INPUTHANDLER_H
#define CHOUI_INPUTHANDLER_H


#include "Command.h"

class InputHandler : public Command{
public:
    Command* handleInput(Player& player);
    sf::Vector2f movement;

private:
    UpCommand* buttonUP_;
    DownCommand* buttonDOWN_;
    RightCommand* buttonRIGHT_;
    LeftCommand* buttonLEFT_;
    NoKeyCommand* noButton_;
};


#endif //CHOUI_INPUTHANDLER_H
