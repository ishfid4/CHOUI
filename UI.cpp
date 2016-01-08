//
// Created by ishfid on 1/3/16.
//

#include <iostream>
#include "UI.h"

UI::UI() {
    textureId = 0;
    openedInv = false;
    secondPress = false;

    //font loading
    if (!fontHalant.loadFromFile("assets/fonts/Halant-Regular.ttf"))
        std::cout<<"Error loading Bangers.ttf\n";

    //background of inv
    invBackGround = sf::RectangleShape(sf::Vector2f(150,300));
    invBackGround.setFillColor(sf::Color(0,205,255,165));
    invBackGround.setOutlineColor(sf::Color(0,137,255,165));
    invBackGround.setOutlineThickness(2);
}

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
        for (u_int i = 0; i < mobMap.size(); ++i) {
                mobHpBar.emplace_back(new sf::RectangleShape);
                mobHpBar[mobHpBar.size()-1]->setSize(sf::Vector2f(((mobMap[i]->healthPoints/mobMap[i]->maxHealthPoints)*32),4));
                mobHpBar[mobHpBar.size()-1]->setFillColor(sf::Color(255,0,0,255));
                mobHpBar[mobHpBar.size()-1]->setPosition(mobMap[i]->getPosition().x,mobMap[i]->getPosition().y-5);
        }
    }

}

void UI::setPlayerHP(Player& player, std::vector<std::unique_ptr<sf::Texture>>& hpTiles, std::vector<std::unique_ptr<sf::Sprite>>& hpSprites){
    for (int i = (int)player.healthPoints; i > 0; i -= 100) {
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

    for (u_int j = 0; j < hpSprites.size(); ++j) {
        hpSprites[j]->setPosition(player.playerView.getCenter().x-(290-(j*32)),player.playerView.getCenter().y+250);
    }

}

void UI::setInventory(Command& command, Player& player) {
    if(typeid(command).name() == typeid(InventoryCommand).name()){
        if(secondPress && openedInv){
            openedInv = false;
            secondPress = false;
            textVector.clear();
//            for (u_int i = 0; i < player.inventory.size(); ++i) {
//                textVector.erase(textVector.begin()-i);
//            }
        }else if(!secondPress && openedInv){
            secondPress = true;
        }else if(!secondPress && !openedInv){
            for (u_int i = 0; i < player.inventory.size(); ++i) {
                std::unique_ptr<sf::Text> itemTxt(new sf::Text);
                itemTxt->setFont(fontHalant);
                itemTxt->setString(player.inventory[i]->getName());
                itemTxt->setCharacterSize(16);
                textVector.push_back(std::move(itemTxt));
            }
            openedInv = true;
        }
    }

    if((!secondPress && !openedInv)||(!secondPress && openedInv)){

    }
}