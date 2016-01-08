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
#include "Command.h"
#include "UI.h"

class Renderer{
public:
    Renderer();
    ~Renderer();
    void renderWindow(sf::RenderWindow& window, tmx::TileMap& tileMap, std::vector<std::unique_ptr<Mob>>& mobMap, std::vector<std::unique_ptr<Weapon>>& weaponsMap, std::vector<std::unique_ptr<Armor>>& armorMap, Player& player, Command& command);

private:
    UI ui;

    std::vector<std::unique_ptr<sf::Text>> textVector;

    sf::Font fontBangers,fontRaleway;
    sf::RectangleShape rectangleFilter;
};


#endif //CHOUI_RENDER_H
