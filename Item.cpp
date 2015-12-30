//
// Created by ishfid on 12/29/15.
//

#include <iostream>
#include "Item.h"



Item::Item(std::string path, sf::Vector2f position, int id1, int typeIt) {
    if (!m_texture.loadFromFile(path)) {
        std::cout << "Failed to load entity spritesheet!" << std::endl;
    }
    setTexture(m_texture);
    setPosition(position);

    id = id1;
    itemType = typeIt;
}

Item::~Item() { }