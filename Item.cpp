//
// Created by ishfid on 12/29/15.
//

#include <iostream>
#include "Item.h"



Item::Item(sf::Texture* m_texture, sf::Vector2f position) {

    setTexture(*m_texture);
    setPosition(position);

    boundingBox = getGlobalBounds();
}

Item::~Item() { }