//
// Created by Julia on 12/7/22.
//

#include "DrawBoard.h"

void DrawBoard::right(const Square& contSquare, Square& square, float spacing)
{
    sf::FloatRect csb = contSquare.getGlobalBounds();
    square.setPosition({csb.left + csb.width + spacing, csb.top});
}
void DrawBoard::bottom(const Square& contSquare, Square& square, float spacing)
{
    sf::FloatRect csb = contSquare.getGlobalBounds();
    square.setPosition({csb.left, csb.top + csb.height + spacing});
}
void DrawBoard::draw(sf::RenderWindow& window, const Board &board)
{
    for(int i=0; i<6; i++)
    {
        for (int j=0; j<5; j++)
        {
            window.draw(squares[i][j]);
        }
    }
}
DrawBoard::DrawBoard(){}
DrawBoard::DrawBoard(const Board& board)
{
    float x=0, y=0;
    for(int i=0; i<6; i++)
    {
        std::string word = board.getWord(i);
        x=0;
        for(int j=0; j<word.size(); j++)
        {
            Square s(std::string(1, word[j]));
            squares[i][j] = s;
            squares[i][j].setPosition({x, y});
            x += 55;
        }
        y += 55;
    }
}