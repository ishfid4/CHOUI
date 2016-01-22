//
// Created by ishfid on 12/24/15.
//

#ifndef CHOUI_INPUTHANDLER_H
#define CHOUI_INPUTHANDLER_H


#include "Command.h"
#include <memory>

class InputHandler{
public:
    InputHandler();
    Command* handleInput(Player& player);
    virtual void execute(Player& player, sf::Time frameTime, sf::Vector2f movement = sf::Vector2f(0.f,0.f)){}

private:
    std::unique_ptr<UpCommand> buttonUP_;
    std::unique_ptr<DownCommand> buttonDOWN_;
    std::unique_ptr<RightCommand> buttonRIGHT_;
    std::unique_ptr<LeftCommand> buttonLEFT_;
    std::unique_ptr<NoKeyCommand> noButton_;
    std::unique_ptr<PlayerAttackCommand> buttonA_;
    std::unique_ptr<PickCommand> buttonZ_;
    std::unique_ptr<InventoryCommand> buttonI_;
    bool wasIPressed = false;
    bool wasZPressed = false;
};


#endif //CHOUI_INPUTHANDLER_H
