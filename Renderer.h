//
// Created by ishfid on 1/3/16.
//

#ifndef CHOUI_RENDER_H
#define CHOUI_RENDER_H


#include <SFML/Graphics.hpp>
#include "Mob.h"
#include "Weapon.h"
#include "Armor.h"
#include "Player.h"

class Renderer{
public:
    Renderer();
    ~Renderer();
    void renderWindow(sf::RenderWindow& window, tmx::TileMap& tileMap, std::vector<Mob*>& mobMap, std::vector<Weapon*>& weaponsMap, std::vector<Armor*>& armorMap, Player& player);

private:
    std::vector<sf::Text*> textVector;

    sf::Font fontBangers,fontRaleway;
    sf::RectangleShape rectangleFilter;
};


#endif //CHOUI_RENDER_H
