//
// Created by Julia on 12/7/22.
//

#ifndef CLASSWORDLE_WORDBANK_H
#define CLASSWORDLE_WORDBANK_H
#include <fstream>
#include <iostream>
#include <vector>

class WordBank
{
private:
    std::vector<std::string> words;
    void getWords(std::string filename);
    int getNumber();
    bool open(std::ifstream& fin, std::string filename);
    void close(std::ifstream& fin);
public:
    WordBank();
    WordBank(std::string filename);
    std::string getWord();
};

#endif //CLASSWORDLE_WORDBANK_H
