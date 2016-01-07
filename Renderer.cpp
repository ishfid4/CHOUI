//
// Created by ishfid on 1/3/16.
//

#include <STP/Core/TileMap.hpp>
#include <iostream>
#include "Renderer.h"



Renderer::Renderer(){
    if (!fontBangers.loadFromFile("assets/fonts/Bangers.ttf"))
        std::cout<<"Error loading Bangers.ttf\n";
    if (!fontRaleway.loadFromFile("assets/fonts/Raleway-Regular.ttf"))
        std::cout<<"Error loading Bangers.ttf\n";

    //DeadText
    std::unique_ptr<sf::Text> txt1(new sf::Text);
    txt1->setFont(fontBangers);
    txt1->setString("Game Over");
    txt1->setCharacterSize(42);
    textVector.push_back(std::move(txt1));
    std::unique_ptr<sf::Text> txt(new sf::Text);
    txt->setFont(fontRaleway);
    txt->setString("Press ESC to exit");
    txt->setCharacterSize(12);
    textVector.push_back(std::move(txt));

    //DeadRedFilter
    rectangleFilter = sf::RectangleShape(sf::Vector2f(1920,1080));
    rectangleFilter.setFillColor(sf::Color(225,0,120,95));

    openedInv = false;
    secondPress = false;
    invBackGround = sf::RectangleShape(sf::Vector2f(150,300));
    invBackGround.setFillColor(sf::Color(0,205,255,165));
    invBackGround.setOutlineColor(sf::Color(0,137,255,165));
    invBackGround.setOutlineThickness(2);
}

Renderer::~Renderer(){}

void Renderer::showInventory(Command& command, Player &player, sf::RenderWindow& window) {
    if(typeid(command).name() == typeid(InventoryCommand).name()){
        if(secondPress){
            openedInv = false;
            secondPress = false;
            for (int i = 0; i < player.inventory.size(); ++i) {
                textVector.erase(textVector.begin()-1);
            }
        }else if(!secondPress){
            if(!openedInv) {
                invBackGround.setPosition(player.getPosition().x - 200, player.getPosition().y - 200);
                if(player.inventory.size()>0){
                    window.draw(invBackGround);
                    for (int i = 0; i < player.inventory.size(); ++i) {
                        std::unique_ptr<sf::Text> itemTxt(new sf::Text);
                        itemTxt->setFont(fontBangers);
                        itemTxt->setString(player.inventory[i]->getName());
                        itemTxt->setCharacterSize(16);
                        itemTxt->setPosition(player.getPosition().x - 197, player.getPosition().y - 200 + (i * 18));
                        textVector.push_back(std::move(itemTxt));
                    }
                    openedInv = true;
                    secondPress = true;
                }
            }
        }
    }
}

void Renderer::renderWindow(sf::RenderWindow& window, tmx::TileMap& tileMap, std::vector<std::unique_ptr<Mob>>& mobMap, std::vector<std::unique_ptr<Weapon>>& weaponsMap, std::vector<std::unique_ptr<Armor>>& armorMap, Player& player, Command& command){
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    std::vector<std::unique_ptr<sf::Texture>> hpTiles;
    std::vector<std::unique_ptr<sf::Sprite>> hpSprites;
    std::vector<sf::RectangleShape*> mobHpBar;

    ui.loadHpTiles(hpTiles);
    ui.setPlayerHP(player,hpTiles,hpSprites);
    ui.setMobsHpBar(mobMap,mobHpBar);

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

    showInventory(command,player,window);

    for (int j = 2; j < textVector.size(); ++j) {
        window.draw(*textVector[j]);
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