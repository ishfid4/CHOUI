#include <iostream>

#include <SFML/Graphics.hpp>
#include <STP/TMXLoader.hpp>

#include "Entity.h"
#include "Player.h"
#include "InputHandler.h"
#include "Collision.h"
#include "Item.h"

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

    Item *it1 = new Item("assets/sprites/items/sword.png",sf::Vector2f(400,200),0,0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Collision obstructCollision(tileMap, *player, "Ground", "Collidable");
        InputHandler inputHandler;
        sf::Time frameTime = frameClock.restart();
        Command* command = inputHandler.handleInput(*player);
        command = obstructCollision.testObstructPlayerCollision(*command);
        command->execute(*player,frameTime);

        //draw
        window.clear();
        window.setView(player->playerView);
        window.draw(tileMap);
        window.draw(*it1);
        window.draw(*player);
        window.display();
    }
}

