//
// Created by ishfid on 1/3/16.
//

#ifndef CHOUI_UI_H
#define CHOUI_UI_H


#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Mob.h"
#include <memory>

class UI {
public:
    UI();
    ~UI();
    void loadHpTiles(std::vector<std::unique_ptr<sf::Texture>>& hpTiles);
    void setPlayerHP(Player& player, std::vector<std::unique_ptr<sf::Texture>>& hpTiles, std::vector<std::unique_ptr<sf::Sprite>>& hpSprites);
    void setMobsHpBar(std::vector<std::unique_ptr<Mob>> &mobMap, std::vector<sf::RectangleShape*>& mobHpBar);
};


#endif //CHOUI_UI_H
