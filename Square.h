//
// Created by Julia on 12/7/22.
//

#ifndef CLASSWORDLE_SQUARE_H
#define CLASSWORDLE_SQUARE_H
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

class Square : public sf::Drawable
        {
private:
    static sf::Font font;
    sf::RectangleShape box;
    sf::Text letter;
    void init(const std::string& letter);
    void setupBox(const std::string& _letter);
    void setupText(const std::string& letter);
    void center();
public:
    Square();
    Square(const std::string& letter);
    void setPosition(sf::Vector2f position);
    sf::FloatRect getGlobalBounds() const;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::RectangleShape rectShape;
};


#endif //CLASSWORDLE_SQUARE_H
