#include <iostream>

#include <SFML/Graphics.hpp>
#include <STP/TMXLoader.hpp>

#include "Entity.h"
#include "Player.h"
#include "InputHandler.h"

using namespace std;

int main() {
    //Setting window
    sf::Vector2i screenDimensions(800,600);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "CHOUI");
    window.setFramerateLimit(60);

    //setting map
    tmx::TileMap tileMap("assets/maps/desert/desert.tmx");
    tileMap.ShowObjects();

    Player *player = new Player("assets/sprites/PLAYER.png", sf::Vector2f(400, 300), sf::Vector2f(600, 600));

    bool noKeyWasPressed = true;
    sf::Clock frameClock; //for animation sync

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        InputHandler inputHandler;
        sf::Time frameTime = frameClock.restart();
        Command* command = inputHandler.handleInput(*player);
        if(command)
            command->execute(*player,frameTime);

/*
        sf::Vector2f playerPosition = player->getPosition();
        sf::FloatRect mapBoundingBox = tileMap.GetLayer("BoundingBox").;
        sf::FloatRect playerBoundingBox = player->getGlobalBounds();

        if(playerBoundingBox.intersects(mapBoundingBox)){
            player->stop();
        }
*/
        //test
        sf::Vector2f plcoor = player->getPosition();
        cout<<plcoor.x<<" "<<plcoor.y<<"\n";

        //draw
        window.clear();
        window.setView(player->playerView);
        window.draw(tileMap);
        window.draw(*player);
        window.display();
    }
}

