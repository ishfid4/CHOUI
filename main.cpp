#include <iostream>

#include <SFML/Graphics.hpp>
#include <STP/TMXLoader.hpp>

#include "Entity.h"
#include "Player.h"
#include "InputHandler.h"
#include "Collision.h"
#include "ItemsFromMap.h"

using namespace std;

int main() {
    //Setting window
    sf::Vector2i screenDimensions(800,600);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "CHOUI");
    window.setFramerateLimit(60);

    //setting map
    tmx::TileMap tileMap("assets/maps/desert/desert.tmx");
    tileMap.ShowObjects();

    //creating player
    Player *player = new Player("assets/sprites/PLAYER.png", sf::Vector2f(400, 300), sf::Vector2f(600, 600));
    sf::Clock frameClock; //for animation sync

    vector<Weapon*> weaponsMap = loadWeaponsFromMap(tileMap);
    vector<Armor*> armorMap = loadArmorFromMap(tileMap);

    tileMap.GetLayer("Weapon").SetOpacity(100);

    Mob *mob = new Mob("assets/sprites/mobs/smallAnaconda.png", sf::Vector2f(300,300));
    mob->healthPoints = 1000;
    vector<Mob*> mobMap;
    mobMap.push_back(mob);
    mob->play(*mob->currentAnimation);
   // Item *it1 = new Item("assets/sprites/items/sword.png",sf::Vector2f(400,200));
    NoKeyCommand *noKey = new NoKeyCommand;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Collision obstructCollision(tileMap, *player, "Ground", "Collidable", mobMap);
        InputHandler inputHandler;
        sf::Time frameTime = frameClock.restart();
        Command* command = inputHandler.handleInput(*player);
        command = obstructCollision.testObstructPlayerCollision(*command, mobMap);

        command->execute(*player,frameTime, mobMap);

        //draw
        sf::VertexArray va0(sf::Quads, 4);
        va0[0].position = sf::Vector2f(0,0);
        va0[1].position = sf::Vector2f(0,32);
        va0[2].position = sf::Vector2f(32,32);
        va0[3].position = sf::Vector2f(32,0);

        window.clear();
        window.setView(player->playerView);
        window.draw(tileMap);
        window.draw(*weaponsMap[0]);
        if(!mobMap.empty())
            window.draw(*mobMap[0]);
        window.draw(*player);
        window.display();
    }
}

