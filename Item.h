//
// Created by ishfid on 12/29/15.
//

#ifndef CHOUI_ITEM_H
#define CHOUI_ITEM_H

#include <SFML/Graphics.hpp>

class Item : public sf::Sprite{
public:
    Item(sf::Texture* m_texture,sf::Vector2f position);
    ~Item();

    std::string getName() const;
    void setName(std::string nam);

    sf::FloatRect boundingBox;

private:
    std::string name;
    sf::VertexArray m_vertices;
    sf::Texture m_texture;
};


#endif //CHOUI_ITEM_H
