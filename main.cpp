#include <iostream>

#include <SFML/Graphics.hpp>
#include <STP/TMXLoader.hpp>

#include "Entity.h"
#include "Animation.h"
#include "AnimatedSprite.h"
#include "Player.h"

using namespace std;

int main() {
    tmx::TileMap tile_map("assets/maps/desert/desert.tmx");
    tile_map.ShowObjects();

    sf::Vector2i screenDimensions(800,600);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "CHOUI");
    window.setFramerateLimit(60);


    Player *player = new Player("assets/sprites/PLAYER.png", sf::Vector2f(400,300), sf::Vector2f(600,600));
/*
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("assets/sprites/PLAYER.png"))
    {
        std::cout << "Failed to load player spritesheet!" << std::endl;
        return 1;
    }


    // set up the animations for all four directions (set spritesheet and push frames)
    Animation walkingAnimationDown;
    walkingAnimationDown.setSpriteSheet(playerTexture);
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));

    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(playerTexture);
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect( 0, 32, 32, 32));

    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(playerTexture);
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

    Animation walkingAnimationUp;
    walkingAnimationUp.setSpriteSheet(playerTexture);
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));


    Animation* currentAnimation = &walkingAnimationDown;

    // set up AnimatedSprite
    AnimatedSprite animatedPlayerSprite(sf::seconds(0.2), true, false);
    animatedPlayerSprite.setPosition(sf::Vector2f(screenDimensions / 2));

    sf::Clock frameClock;

    float speed = 100.f;
    bool noKeyWasPressed = true;


    // creating player Viewport
    sf::View playerView;
    playerView.setCenter(sf::Vector2f(screenDimensions / 2));
    playerView.setSize(600,600);
*/
    bool noKeyWasPressed = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time frameTime = player->frameClock.restart();

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

        //sf::Vector2f playerPosition = animatedPlayerSprite.getPosition();
        //sf::FloatRect mapBoundingBox = tile_map.GetLayer("BoundingBox").GetTile(playerPosition.x,playerPosition.y).GetGlobalBounds();
        //sf::FloatRect playerBoundingBox = animatedPlayerSprite.getGlobalBounds();
/*
        if(playerBoundingBox.intersects(mapBoundingBox)){
            animatedPlayerSprite.stop();
        }
*/
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

        player->getPosition();

        //draw
        window.clear();
        window.setView(player->playerView);
        window.draw(tile_map);
        window.draw(player->animatedPlayerSprite);
        window.display();
    }
}