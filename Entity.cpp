//
// Created by ishfid on 12/23/15.
//

#include <iostream>
#include "Entity.h"

Entity::Entity(std::string path, sf::Vector2f startingCoordinates) : AnimatedSprite(sf::seconds(0.2), true, false){
    if (!entityTexture.loadFromFile(path)) {
        std::cout << "Failed to load entity spritesheet!" << std::endl;
    }


    walkingAnimationDown.setSpriteSheet(entityTexture);
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));

    walkingAnimationLeft.setSpriteSheet(entityTexture);
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect( 0, 32, 32, 32));

    walkingAnimationRight.setSpriteSheet(entityTexture);
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

    walkingAnimationUp.setSpriteSheet(entityTexture);
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));

    currentAnimation = &walkingAnimationDown;

    // set up coordinates for AnimatedSprite
    setPosition(startingCoordinates);

    speed = 100.f;
}

Entity::~Entity() { }
//
//void Entity::setHP(float hp){
//    healthPoints = hp;
//}
//
//float Entity::getHP() const{
//    return healthPoints;
//}
//
//void Entity::setMana(float mana){
//    manaPoints = mana;
//}
//
//float Entity::getMana() const{
//    return manaPoints;
//}
//
//void Entity::setDefence(float def){
//    defence = def;
//}
//
//float Entity::getDefence() const{
//    return defence;
//}
//
//void Entity::setMgResist(float mr){
//    magicResist = mr;
//}
//
//float Entity::getMgResist() const{
//    return magicResist;
//}
//
//void Entity::setLevel(int lvl){
//    level = lvl;
//}
//
//int Entity::getLevel() const{
//    return level;
//}
//
//void Entity::setExp(int exp){
//    experiance = exp;
//}
//
//int Entity::getExp() const{
//    return experiance;
//}
//
//void Entity::setSTR(int str){
//    strength = str;
//}
//
//int Entity::getSTR() const{
//    return strength;
//}
//
//void Entity::setINT(int INT){
//    intelligance = INT;
//}
//
//int Entity::getINT() const{
//    return intelligance;
//}
