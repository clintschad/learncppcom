#include "Random.h" // defines Random::mt, Random::get(), and Random::generate()
#include <iostream>

void hiLo(int hi, int lo, int numGuesses);

int main()
{
    char playerChoice{'y'};

    std::cout << "Welcome to the Hi-Lo game.\n";

    std::cout << "Enter the upper limit: ";
    int upperLim{};
    std::cin >> upperLim;

    std::cout << "Enter the lower limit: ";
    int lowerLim{};
    std::cin >> lowerLim;

    std::cout << "Enter the number of guesses: ";
    int playerNumGuesses{};
    std::cin >> playerNumGuesses;

    while (playerChoice == 'y')
    {
        hiLo(lowerLim, upperLim, playerNumGuesses);

        // Keep looping if player enters invalid letter choice
        do
        {
            std::cout << "Would you like to play again (y/n)?";
            std::cin >> playerChoice;
        }
        while (playerChoice != 'y' && playerChoice != 'n');
    }

    std::cout << "Thank you for playing.\n";

    return 0;
}

void hiLo(int hi, int lo, int numGuesses)
{
    int userNum{0};
    int computerNum = Random::get(hi, lo);

    std::cout << "Let's play a game. I'm thinking of a number between " << hi << " and " << lo << " . ";
    std::cout << "You have " << numGuesses << " tries to guess what it is.\n";

    for (int i{1}; i <= numGuesses; ++i)
    {
        std::cout << "Guess #" << i << ": ";
        std::cin >> userNum;

        if (userNum < computerNum)
            std::cout << "Your guess is too low.\n";
        else if (userNum > computerNum)
            std::cout << "Your guess is too high.\n";
        else
        { // User guessed correctly.
            std::cout << "Correct! You win!\n";
            return;
        }
    }

    std::cout << "Sorry, you lose. The correct number was " << computerNum << '\n';
    return;
}
