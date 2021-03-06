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
#include "Settings.h"

using namespace std;
int main() {
    //load settings from file
    Settings settings("settings.conf");
    settings.load();
    cout<<settings.x<<"x"<<settings.y<<" "<<settings.hz<<"\n";

    //Setting window and renderer
    sf::Vector2i screenDimensions(settings.x,settings.y);
    sf::RenderWindow window(sf::VideoMode((u_int)screenDimensions.x, (u_int)screenDimensions.y), "CHOUI");
    window.setFramerateLimit(settings.hz);
    Renderer renderer;

    //setting map
    tmx::TileMap tileMap("assets/maps/desert/desert.tmx");
    tileMap.ShowObjects();

    //creating player
    Player player("assets/sprites/PLAYER.png", sf::Vector2f(400, 300), sf::Vector2f(600, 600));
    sf::Clock frameClock; //for animation sync

    //Inventory *inventory = new Inventory;
    vector<std::unique_ptr<Weapon>> weaponsMap = loadWeaponsFromMap(tileMap);
    vector<std::unique_ptr<Armor>> armorMap = loadArmorFromMap(tileMap);

    //Setting mob spawners
    Spawner snakeSpawner(2,300,400,150,1,0,50.f,0);
    vector<std::unique_ptr<Mob>> mobMap;

    MobAI mobAI;

    tileMap.GetLayer("Weapon").GetTile(17,8).visible = false;
    InputHandler inputHandler;

    while (window.isOpen()) {
        snakeSpawner.spawnMob(mobMap);
        Collision obstructCollision(tileMap, player, "Ground", "Collidable", mobMap);
        Collision itemCollision(tileMap, player, "Ground", "Collidable", mobMap);
        sf::Time frameTime = frameClock.restart();
        Command* command = inputHandler.handleInput(player);

        if(!player.openedInv){
            command = obstructCollision.testObstructPlayerCollision(*command,mobMap);
            itemCollision.testItemPlayerCollision(*command,player,weaponsMap,armorMap,tileMap);
            command->execute(player,frameTime, mobMap, player);
            mobAI.mobsMovement(mobMap, frameTime, tileMap, player, "Ground", "Collidable");
        }


        renderer.renderWindow(window,tileMap,mobMap,weaponsMap,armorMap,player,*command);
    }
}

