//
// Created by ishfid on 1/3/16.
//

#include <STP/Core/TileMap.hpp>
#include <iostream>
#include "Renderer.h"
#include "UI.h"


Renderer::Renderer(){
    if (!fontBangers.loadFromFile("assets/fonts/Bangers.ttf"))
        std::cout<<"Error loading Bangers.ttf\n";
    if (!fontRaleway.loadFromFile("assets/fonts/Raleway-Regular.ttf"))
        std::cout<<"Error loading Bangers.ttf\n";

    //DeadText
    textVector.push_back(new sf::Text);
    textVector[0]->setFont(fontBangers);
    textVector[0]->setString("Game Over");
    textVector[0]->setCharacterSize(42);
    textVector.push_back(new sf::Text);
    textVector[1]->setFont(fontRaleway);
    textVector[1]->setString("Press ESC to exit");
    textVector[1]->setCharacterSize(12);

    //DeadRedFilter
    rectangleFilter = sf::RectangleShape(sf::Vector2f(1920,1080));
    rectangleFilter.setFillColor(sf::Color(225,0,120,95));
}

Renderer::~Renderer(){}

void Renderer::renderWindow(sf::RenderWindow& window, tmx::TileMap& tileMap, std::vector<Mob*>& mobMap, std::vector<Weapon*>& weaponsMap, std::vector<Armor*>& armorMap, Player& player){
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    std::vector<sf::Texture*> hpTiles;
    std::vector<sf::Sprite*> hpSprites;
    std::vector<sf::RectangleShape*> mobHpBar;

    UI *ui = new UI();
    ui->loadHpTiles(hpTiles);
    ui->setPlayerHP(player,hpTiles,hpSprites);
    ui->setMobsHpBar(mobMap,mobHpBar);

    window.clear();
    window.draw(tileMap);
    window.draw(*weaponsMap[0]);

    if(!mobMap.empty()){
        for (int i = 0; i < mobMap.size(); i++) {
            window.draw(*mobMap[i]);
        }
    }

    if(!hpSprites.empty()) {
        for (int i = 0; i < hpSprites.size(); ++i) {
            window.draw(*hpSprites[i]);
        }
    }

    if(!mobHpBar.empty()) {
        for (int i = 0; i < mobHpBar.size(); ++i) {
            window.draw(*mobHpBar[i]);
        }
    }

    if(player.healthPoints > 0){
        player.playerView.setCenter(player.getPosition());
        window.setView(player.playerView);
        window.draw(player);
        window.display();
    }else{
        rectangleFilter.setPosition(player.playerView.getCenter().x-800, player.playerView.getCenter().y-500);
        textVector[0]->setPosition(player.playerView.getCenter().x-75, player.playerView.getCenter().y-45);
        textVector[1]->setPosition(player.playerView.getCenter().x-35, player.playerView.getCenter().y);
        window.draw(rectangleFilter);
        window.draw(*textVector[0]);
        window.draw(*textVector[1]);
        window.display();
    }

}