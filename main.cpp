#include <iostream>

#include <SFML/Graphics.hpp>
#include <STP/TMXLoader.hpp>

#include "Entity.h"
#include "Player.h"
#include "InputHandler.h"
#include "Collision.h"

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
    //bool noKeyWasPressed = true;
    sf::Clock frameClock; //for animation sync

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Collision collision;
        InputHandler inputHandler;
        sf::Time frameTime = frameClock.restart();
        Command* command = inputHandler.handleInput(*player);
        command = collision.testPlayerCollision(tileMap, *player, *command);
        command->execute(*player,frameTime);

        //test
        //sf::Vector2f plcoor = player->getPosition();
        //cout<<plcoor.x<<" "<<plcoor.y<<"\n";
//        cout<<x<<" "<<y<<endl;

        //draw
        window.clear();
        window.setView(player->playerView);
        window.draw(tileMap);
        window.draw(*player);
        window.display();
    }
}

