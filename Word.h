//
// Created by Julia on 12/1/22.
//

#ifndef CLASSWORDLE_WORD_H
#define CLASSWORDLE_WORD_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Word
{
private:
    sf::RectangleShape box;
    std::string targetWord, guess, result;
    int letterCount[26] = {};
    void init();
    void loadLetterCount();
    void generateResult();
    int convertToIndex(char letter);
    bool inWord(int index);
    bool hasASpot(int index);
    int getResultLetterCount(int index);
    bool inCorrectSpot(int index);
    void updateResult(char letter, int index);
    void putback(int index);
public:
    Word();
    Word(std::string target, std::string userGuess);
    std::string getWord();
};

#endif //CLASSWORDLE_WORD_H
