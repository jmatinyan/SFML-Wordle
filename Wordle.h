//
// Created by Julia on 12/7/22.
//

#ifndef CLASSWORDLE_WORDLE_H
#define CLASSWORDLE_WORDLE_H

#include "board.h"
#include <iostream>
#include "LetterBank.h"
#include "Input.h"
#include "Word.h"
#include "WordBank.h"
#include <SFML/Graphics.hpp>
#include "Square.h"
#include "DrawBoard.h"


class Wordle
{
private:
    sf::RectangleShape box;
    Board board;
    WordBank wordBank;
    LetterBank letterBank;
    Input input;
    Word word;
    bool areStringsEqual(std::string target, std::string guess);
public:
    Wordle();
    Wordle(std::string fillename);
    void draw();
    void run();
};

#endif //CLASSWORDLE_WORDLE_H
