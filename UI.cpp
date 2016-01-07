//
// Created by ishfid on 1/3/16.
//

#include <iostream>
#include "UI.h"

UI::UI() { }

UI::~UI() { }

void UI::loadHpTiles(std::vector<std::unique_ptr<sf::Texture>>& hpTiles) {
    for (int i = 0; i < 5; ++i) {
        hpTiles.emplace_back(new sf::Texture);
    }

    if (!hpTiles[0]->loadFromFile("assets/sprites/ui/hpempty.png"))
        std::cout<<"Error loading hp tile\n";

    if (!hpTiles[1]->loadFromFile("assets/sprites/ui/hp1.png"))
        std::cout<<"Error loading hp tile\n";

    if (!hpTiles[2]->loadFromFile("assets/sprites/ui/hp2.png"))
        std::cout<<"Error loading hp tile\n";

    if (!hpTiles[3]->loadFromFile("assets/sprites/ui/hp3.png"))
        std::cout<<"Error loading hp tile\n";

    if (!hpTiles[4]->loadFromFile("assets/sprites/ui/hpfull.png"))
        std::cout<<"Error loading hp tile\n";
}

void UI::setMobsHpBar(std::vector<std::unique_ptr<Mob>> &mobMap, std::vector<sf::RectangleShape*>& mobHpBar){
    if(!mobMap.empty()){
        for (int i = 0; i < mobMap.size(); ++i) {
                mobHpBar.emplace_back(new sf::RectangleShape);
                mobHpBar[mobHpBar.size()-1]->setSize(sf::Vector2f(((mobMap[i]->healthPoints/mobMap[i]->maxHealthPoints)*32),4));
                mobHpBar[mobHpBar.size()-1]->setFillColor(sf::Color(255,0,0,255));
                mobHpBar[mobHpBar.size()-1]->setPosition(mobMap[i]->getPosition().x,mobMap[i]->getPosition().y-5);
        }
    }

}

void UI::setPlayerHP(Player& player, std::vector<std::unique_ptr<sf::Texture>>& hpTiles, std::vector<std::unique_ptr<sf::Sprite>>& hpSprites){
    for (int i = player.healthPoints; i > 0; i -= 100) {
        int textureId;
        if(i >= 85){
            textureId = 4;
        }else if(i > 65){
            textureId = 3;
        }else if(i > 35) {
            textureId = 2;
        }else if(i > 0) {
            textureId = 1;
        }
        std::unique_ptr<sf::Sprite> sprite(new sf::Sprite);
        sprite->setTexture(*hpTiles[textureId]);
        hpSprites.push_back(std::move(sprite));
    }

    for (int j = 0; j < hpSprites.size(); ++j) {
        hpSprites[j]->setPosition(player.playerView.getCenter().x-(290-(j*32)),player.playerView.getCenter().y+250);
    }

}
