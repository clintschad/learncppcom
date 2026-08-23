#include "Random.h" // defines Random::mt, Random::get(), and Random::generate()
#include <limits>   // for std::numeric_limits
#include <iostream>

void hiLo(int lo, int hi, int numGuesses);
int getUserGuess(int lo, int hi, int guessNum);
bool continuePlay();


int main()
{
    std::cout << "Welcome to the Hi-Lo game.\n";

    std::cout << "Enter the lower limit: ";
    int lowerLim{};
    std::cin >> lowerLim;

    std::cout << "Enter the upper limit: ";
    int upperLim{};
    std::cin >> upperLim;

    std::cout << "Enter the number of guesses: ";
    int playerNumGuesses{};
    std::cin >> playerNumGuesses;

    do
    {
        hiLo(lowerLim, upperLim, playerNumGuesses);
    } while (continuePlay());

    std::cout << "Thank you for playing.\n";

    return 0;
}



void hiLo(int lo, int hi, int numGuesses)
{
    int computerNum = Random::get(lo, hi);

    std::cout << "Let's play a game. I'm thinking of a number between " << lo << " and " << hi << ". ";
    std::cout << "You have " << numGuesses << " tries to guess what it is.\n";

    for (int i{1}; i <= numGuesses; ++i)
    {
        int userNum{getUserGuess(lo, hi, i)};

        // If valid guess
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

    std::cout << "Sorry, you lose. The correct number was " << computerNum << ".\n";
    return;
}


int getUserGuess(int lo, int hi, int guessNum)
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Guess #" << guessNum << ": ";
        int guess{};
        std::cin >> guess;

        bool success{std::cin}; // Remember whether we had a successful extraction
        std::cin.clear();       // Put us back in 'normal' operation mode (in case we failed)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove any extra input

        if (success)  // If we actually extracted a value
        {
            if (guess < lo || guess > hi) // Verify guess is within bounds
                std::cout << "Guess is out of bounds.\n";
            else
                return guess; // Return it (otherwise, we go back to top of loop)
        }
    }
}


bool continuePlay()
{
    while (true) // Loop until user enters a valid input of 'y' or 'n'
    {
        std::cout << "Would you like to play again (y/n)?";
        char choice{};
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove any extra input

        switch(choice)
        {
            case 'y': return true;
            case 'n': return false;
        }
    }
}
