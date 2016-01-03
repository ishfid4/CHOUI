//
// Created by ishfid on 1/3/16.
//

#ifndef CHOUI_UI_H
#define CHOUI_UI_H


#include <SFML/Graphics.hpp>
#include "Player.h"

class UI {
public:
    UI();
    ~UI();
    void loadHpTiles(std::vector<sf::Texture*>& hpTiles);
    void setPlayerHP(Player& player, std::vector<sf::Texture*>& hpTiles, std::vector<sf::Sprite*>& hpSprites);
};


#endif //CHOUI_UI_H
