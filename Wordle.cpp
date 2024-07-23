//
// Created by Julia on 12/7/22.
//

#include "Wordle.h"

Wordle::Wordle()
{

}
Wordle::Wordle(std::string filename)
        : wordBank(filename) {
}

bool Wordle::areStringsEqual(std::string target, std::string guess)
{
    for (int i = 0; i < guess.size(); i++)
    {
        if (target[i] != guess[i])
        {
            return false;
        }
    }
    std::cout << "Good job, you won!\n";
    std::cout << "The word was: " << target << std::endl;
    return true;
}

void Wordle::run()
{
    srand(time(0));
    int guessCount = 6;
    char userInput;
    std::string target = wordBank.getWord();
    board.display();
    std::cout << "" << std::endl;
    letterBank.display();
    std::cout << "" << std::endl;

    do
    {
        for (int i = 0; i < 6; i++)
        {
            std::cout << "" << std::endl;
            std::string guess = input.getInput("Enter your guess: ");
            Word word(target, guess);
            letterBank.mark(word);
            board.addWord(word);
            board.display();
            letterBank.display();
            std::cout << "" << std::endl;

            if (target == guess)
            {
                std::cout << "Good job, you won!\n";
                std::cout << "The word was: " << target << std::endl;
                break;
            }
            else if (!areStringsEqual(target, guess) && i == 5)
            {
                std::cout << "You lose!\n";
                std::cout << "The word was: " << target << std::endl;
                break;
            }
        }
        std::cout << "Do you want to play again? y/n\n";
        std::cin >> userInput;
        if(tolower(userInput == 'y'))
        {
            letterBank.reset();
            board.reset();
            target = wordBank.getWord();
            board.display();
            letterBank.display();
        }
    }
    while(tolower(userInput == 'y'));
}

void Wordle::draw()
{
    srand(time(0));
    sf::VideoMode videoMode(728, 428, 32);
    sf::RenderWindow window(videoMode, "Wordle");
    window.setFramerateLimit(60);

    sf::Thread thread(&Wordle::run, this);
    thread.launch();

    while(window.isOpen())
    {
        DrawBoard db(board);
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        db.draw(window, board);
        window.display();
    }
}