//
// Created by ishfid on 1/3/16.
//

#include <STP/Core/TileMap.hpp>
#include <iostream>
#include "Renderer.h"

Renderer::Renderer(){
    if (!fontBangers.loadFromFile("assets/fonts/Bangers.ttf"))
        std::cout<<"Error loading Bangers.ttf\n";

    //DeadText
    textVector.push_back(new sf::Text);
    textVector[0]->setFont(fontBangers);
    textVector[0]->setString("Game Over Bitch");
    textVector[0]->setCharacterSize(42);
}

Renderer::~Renderer(){}

void Renderer::renderWindow(sf::RenderWindow& window, tmx::TileMap& tileMap, std::vector<Mob*>& mobMap, std::vector<Weapon*>& weaponsMap, std::vector<Armor*>& armorMap, Player& player){
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.clear();
    window.draw(tileMap);
    window.draw(*weaponsMap[0]);
    if(!mobMap.empty())
        window.draw(*mobMap[0]);
    if(player.healthPoints > 0){
        player.playerView.setCenter(player.getPosition());
        window.setView(player.playerView);
        window.draw(player);
        window.display();
    }else{
        window.clear(sf::Color(255,20,147,255));
        textVector[0]->setPosition(player.getPosition());
        window.draw(*textVector[0]);
        window.display();
    }

}