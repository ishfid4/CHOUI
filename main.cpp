#include <iostream>

#include <SFML/Graphics.hpp>
#include <STP/TMXLoader.hpp>

#include "Entity.h"
#include "Player.h"
#include "InputHandler.h"

using namespace std;

int main() {
    tmx::TileMap tile_map("assets/maps/desert/desert.tmx");
    tile_map.ShowObjects();

    sf::Vector2i screenDimensions(800,600);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "CHOUI");
    window.setFramerateLimit(60);


    Player *player = new Player("assets/sprites/PLAYER.png", sf::Vector2f(400, 300), sf::Vector2f(600, 600));

    bool noKeyWasPressed = true;
    sf::Clock frameClock; //for animation sync

    InputHandler inputHandler;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time frameTime = frameClock.restart();
        Command* command = inputHandler.handleInput(*player);
        if(command)
            command->execute(*player,frameTime);

/*
        // if a key was pressed set the correct animation and move correctly
        sf::Vector2f movement(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player->currentAnimation = &player->walkingAnimationUp;
            movement.y -= player->speed;
            noKeyWasPressed = false;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player->currentAnimation = &player->walkingAnimationDown;
            movement.y += player->speed;
            noKeyWasPressed = false;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player->currentAnimation = &player->walkingAnimationLeft;
            movement.x -= player->speed;
            noKeyWasPressed = false;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player->currentAnimation = &player->walkingAnimationRight;
            movement.x += player->speed;
            noKeyWasPressed = false;
        }
*/
/*
        sf::Vector2f playerPosition = animatedPlayerSprite.getPosition();
        sf::FloatRect mapBoundingBox = tile_map.GetLayer("BoundingBox").GetTile(playerPosition.x,playerPosition.y).GetGlobalBounds();
        sf::FloatRect playerBoundingBox = animatedPlayerSprite.getGlobalBounds();

        if(playerBoundingBox.intersects(mapBoundingBox)){
            animatedPlayerSprite.stop();
        }
*/

        /*
        player->play(*player->currentAnimation);
        player->move(movement * frameTime.asSeconds());
        player->playerView.move(movement * frameTime.asSeconds());

        // if no key was pressed stop the animation
        if (noKeyWasPressed)
        {
            player->stop();
        }
        noKeyWasPressed = true;

        // update AnimatedSprite
        player->update(frameTime);
*/
        //test
        sf::Vector2f plcoor = player->getPosition();
        cout<<plcoor.x<<" "<<plcoor.y<<"\n";

        //draw
        window.clear();
        window.setView(player->playerView);
        window.draw(tile_map);
        window.draw(*player);
        window.display();
    }
}

