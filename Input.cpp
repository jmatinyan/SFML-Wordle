//
// Created by Julia on 11/30/22.
//

#include "Input.h"

std::string Input::getInput(std::string message)
{
    std::cout << message << std::endl;
    std::string s;
    std::cin >> s;
    return s;
}