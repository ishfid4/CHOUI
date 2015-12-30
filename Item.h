//
// Created by ishfid on 12/29/15.
//

#ifndef CHOUI_ITEM_H
#define CHOUI_ITEM_H

#include <SFML/Graphics.hpp>

class Item : public sf::Sprite{
public:
    Item(std::string path,sf::Vector2f position);
    ~Item();

    sf::FloatRect boundingBox;

private:

    sf::VertexArray m_vertices;
    sf::Texture m_texture;
};


#endif //CHOUI_ITEM_H
