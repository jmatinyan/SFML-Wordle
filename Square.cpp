//
// Created by Julia on 12/7/22.
//

#include "Square.h"
#include "Word.h"

sf::Font Square::font;
Square::Square()
: Square("A")
{

}
Square::Square(const std::string& letter)
{
    init(letter);
}
void Square::setPosition(sf::Vector2f position)
{
    box.setPosition(position);
    center();
}
sf::FloatRect Square::getGlobalBounds() const
{
    return box.getGlobalBounds();
}

void Square::init(const std::string& letter)
{
    setupBox(letter);
    setupText(letter);
    center();
}
void Square::setupBox(const std::string& _letter)
{
    box.setSize({50.f, 50.f});
    box.setFillColor(sf::Color::White);
    if(isupper(_letter[0]))
    {
        box.setFillColor(sf::Color::Green);
    }
    else if(islower(_letter[0]))
    {
        box.setFillColor(sf::Color::Yellow);
    }
}
void Square::setupText(const std::string& _letter)
{
    if(!font.loadFromFile("Helvetica Neue W01 66 Medium It.ttf"))
    {
        exit(45);
    }
    letter.setFont(font);
    letter.setString(_letter);
    letter.setFillColor(sf::Color(125, 125, 125));
}
void Square::center()
{
    sf::FloatRect textRect = letter.getGlobalBounds();
    sf::FloatRect tRect = box.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + letter.getLocalBounds().left, center.y + letter.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    letter.setOrigin(rounded);
    letter.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});
}
void Square::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(box);
    target.draw(letter);
}