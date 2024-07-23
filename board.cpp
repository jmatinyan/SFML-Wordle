//
// Created by Julia on 11/30/22.
//

#include "board.h"

Board::Board()
        : Board(6, 5)
{
}
Board::Board(int rows, int cols)
        : board(rows,std::string(cols, '?'))
{
}
void Board::display()
{
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void Board::addWord(std::string word)
{
    if(counter < board.size())
    {
        board[counter] = word;
        counter++;
    }
}
void Board::addWord(Word word)
{
    addWord(word.getWord());
}
std::string Board::getWord(int index) const
{
    return board[index];
}
void Board::reset()
{

    for(int i=0; i<board.size();i++){
        for(int j=0; j<board[i].size(); j++){
            board[i][j]='?';
        }
    }
    counter=0;
}