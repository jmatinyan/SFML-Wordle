//
// Created by Julia on 11/30/22.
//

#ifndef CLASSWORDLE_LETTERBANK_H
#define CLASSWORDLE_LETTERBANK_H
#include <iostream>
#include <string>
#include "Word.h"

class LetterBank
{
private:
    std::string letters;
    void addAllLetters();
public:
    LetterBank();
    void display();
    void markIncorrect(char letter);
    void markCorrect(char letter);
    void mark(char letter, char c);
    void mark(Word word);
    void mark(std::string guess, std::string result);

    void reset();
};


#endif //CLASSWORDLE_LETTERBANK_H
