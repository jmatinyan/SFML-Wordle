//
// Created by Julia on 11/30/22.
//
#include <iostream>
#include "LetterBank.h"

LetterBank::LetterBank()
{
    addAllLetters();
}
void LetterBank::display()
{
    for (char s : letters)
    {
        std::cout << s << " ";
    }
}
void LetterBank::markIncorrect(char letter)
{
    letters[tolower(letter)-'a'] = '_';
}
void LetterBank::markCorrect(char letter)
{
    letters[tolower(letter)-'a'] = toupper(letter);
}
void LetterBank::addAllLetters()
{
    for (char c = 'a'; c <= 'z'; c++ )
    {
        letters.push_back(c);
    }
}
void LetterBank::mark(char letter, char c)
{
    letters[tolower(letter) -'a'] = c;
}
void LetterBank::mark(Word word)
{
    std::string s = word.getWord();
    for(int i =0; i < s.size(); i++)
    {
        if(isalpha(s[i]))
            letters[tolower(s[i]) -'a'] = toupper(s[i]);
    }
}
void LetterBank::mark(std::string guess, std::string result)
{
    for(int i=0; i<guess.size(); i++)
    {

    }
}

void LetterBank::reset(){
    for (int i =0; i < 26; i++ )
    {
        letters[i] = tolower(letters[i]);
    }
}