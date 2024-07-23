//
// Created by Julia on 11/30/22.
//

#ifndef CLASSWORDLE_BOARD_H
#define CLASSWORDLE_BOARD_H
#include <iostream>
#include <vector>
#include <string>
#include "Word.h"

class Board
{
private:
    std::vector<std::string> board;
    int counter = 0;
public:
    Board();
    Board(int rows, int cols);
    void display();
    void addWord(std::string word);
    void addWord(Word word);
    std::string getWord(int index) const;
    void reset();
};


#endif //CLASSWORDLE_BOARD_H
