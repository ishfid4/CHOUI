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
#include "Spawner.h"
#include "Inventory.h"

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

    Inventory *inventory = new Inventory;
    vector<Weapon*> weaponsMap = loadWeaponsFromMap(tileMap);
    vector<Armor*> armorMap = loadArmorFromMap(tileMap);

    //Setting mob spawners
    Spawner snakeSpawner(2,300,400,150,1,0,50.f,0);
    vector<Mob*> mobMap;

    MobAI *mobAI = new MobAI();

    tileMap.GetLayer("Weapon").GetTile(17,8).visible = false;

    while (window.isOpen()) {
        snakeSpawner.spawnMob(mobMap);
        Collision obstructCollision(tileMap, *player, "Ground", "Collidable", mobMap);
        Collision itemCollision(tileMap, *player, "Ground", "Collidable", mobMap);
        InputHandler inputHandler;
        sf::Time frameTime = frameClock.restart();
        Command* command = inputHandler.handleInput(*player);
        command = obstructCollision.testObstructPlayerCollision(*command,mobMap);
        itemCollision.testItemPlayerCollision(*command,*player,weaponsMap,armorMap,tileMap);
        command->execute(*player,frameTime, mobMap, *player);

        mobAI->mobsMovement(mobMap, frameTime, tileMap, *player, "Ground", "Collidable");

        renderer->renderWindow(window,tileMap,mobMap,weaponsMap,armorMap,*player);
    }
}

