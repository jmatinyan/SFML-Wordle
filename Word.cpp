//
// Created by Julia on 12/1/22.
//

#include "Word.h"


Word::Word()
{

}
Word::Word(std::string target, std::string userGuess)
        : targetWord(target), guess(userGuess), result("_____")
{
    init();
}
std::string Word::getWord()
{
    return result;
}
void Word::init()
{
    loadLetterCount();
    generateResult();
}
void Word::loadLetterCount()
{
    for(int i =0; i<targetWord.size(); i++)
        letterCount[convertToIndex(targetWord[i])]++;
}
void Word::generateResult()
{
    for(int i=0; i<guess.size(); i++)
    {
        if(inWord(i))
            if(hasASpot(i))
                if(inCorrectSpot(i))
                {
                    updateResult(toupper(guess[i]), i);
                    box.setFillColor(sf::Color::Green);
                }
                else
                {
                    updateResult(tolower(guess[i]), i);
                    box.setFillColor(sf::Color::Yellow);
                }
            else if(inCorrectSpot(i))
            {
                putback(i);
                updateResult(toupper(guess[i]), i);
            }
    }
}
int Word::convertToIndex(char letter)
{
    return tolower(letter) -'a';
}
bool Word::inWord(int index)
{
    return letterCount[convertToIndex(guess[index])] > 0;
}
bool Word::hasASpot(int index)
{
    return getResultLetterCount(index) < letterCount[convertToIndex(guess[index])];
}
int Word::getResultLetterCount(int index)
{
    int count = 0;
    for(int i =0; i<result.size(); i++)
    {
        if(tolower(result[i])== tolower(guess[index]))
            count++;
    }
    return count;
}
bool Word::inCorrectSpot(int index)
{
    return tolower(targetWord[index]) == tolower(guess[index]);

}
void Word::updateResult(char letter, int index)
{
    result[index] = letter;
}
void Word::putback(int index)
{
    int idx = result.find(tolower(guess[index]));
    if(std::string::npos != idx)
        result[idx] = '_';
}
