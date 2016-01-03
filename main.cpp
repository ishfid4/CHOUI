#include <iostream>

#include <SFML/Graphics.hpp>
#include <STP/TMXLoader.hpp>

#include "Entity.h"
#include "Player.h"
#include "InputHandler.h"
#include "Collision.h"
#include "ItemsFromMap.h"
#include "MobAI.h"
#include "Renderer.h"

using namespace std;

int main() {
    //Setting window and renderer
    sf::Vector2i screenDimensions(800,600);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "CHOUI");
    window.setFramerateLimit(60);
    Renderer *renderer = new Renderer();

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
    mob->healthPoints = 100;
    mob->maxHealthPoints = 100;
    mob->strength = 1;
    mob->intelligance = 0;
    mob->speed = 50.f;
    vector<Mob*> mobMap;
    mobMap.push_back(mob);
    mob->play(*mob->currentAnimation);
   // Item *it1 = new Item("assets/sprites/items/sword.png",sf::Vector2f(400,200));
    NoKeyCommand *noKey = new NoKeyCommand;
    MobAI *mobAI = new MobAI();


    while (window.isOpen()) {
        Collision obstructCollision(tileMap, *player, "Ground", "Collidable", mobMap);
        InputHandler inputHandler;
        sf::Time frameTime = frameClock.restart();
        Command* command = inputHandler.handleInput(*player);
        command = obstructCollision.testObstructPlayerCollision(*command);
        command->execute(*player,frameTime, mobMap, *player);

        mobAI->mobsMovement(mobMap, frameTime, tileMap, *player, "Ground", "Collidable");

        renderer->renderWindow(window,tileMap,mobMap,weaponsMap,armorMap,*player);
    }
}

