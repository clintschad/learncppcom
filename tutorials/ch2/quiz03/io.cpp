#include <iostream>
#include "io.h"

// Function definitions
int readNumber()
{
    std::cout << "Please enter an integer: ";
    int userNum{};
    std::cin >> userNum;
    return userNum;
}

void writeAnswer(int x)
{
    std::cout << "The sum of the two integers is " << x << "\n";
}
