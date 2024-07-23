//
// Created by Julia on 12/7/22.
//

#ifndef CLASSWORDLE_DRAWBOARD_H
#define CLASSWORDLE_DRAWBOARD_H

#include "board.h"
#include <SFML/Graphics.hpp>
#include "Square.h"

class DrawBoard {
private:
    Square squares[6][5];
    void right(const Square& contSquare, Square& square, float spacing = 5);
    void bottom(const Square& conSquare, Square& square, float spacing = 5);
public:
    sf::RectangleShape rectShape;
    DrawBoard();
    DrawBoard(const Board& board);
    void draw(sf::RenderWindow& window, const Board &board);
};


#endif //CLASSWORDLE_DRAWBOARD_H
