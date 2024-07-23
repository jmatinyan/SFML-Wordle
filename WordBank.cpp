//
// Created by Julia on 12/7/22.
//

#include "WordBank.h"

WordBank::WordBank()
{
    getWords("5LetterNouns.txt");
}
WordBank::WordBank(std::string filename)
{
    getWords(filename);
}
std::string WordBank::getWord()
{
    return words[getNumber()];
}
void WordBank::getWords(std::string filename)
{
    std::ifstream fin;
    std::string temp;
    if(open(fin, filename))
    {
        while(fin >> temp)
        {
            words.push_back(temp);
        }
    }
    close(fin);
}
int WordBank::getNumber()
{
    return rand() % words.size();
}
bool WordBank::open(std::ifstream& fin, std::string filename)
{
    fin.open(filename);
    return !fin.fail();
}
void WordBank::close(std::ifstream& fin)
{
    fin.close();
}