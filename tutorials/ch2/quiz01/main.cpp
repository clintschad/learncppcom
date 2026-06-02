#include <iostream>

// Function declarations
int readNumber();
void writeAnswer(int x);

int main()
{
    // Get numbers from user
    int num1{readNumber()};   // First num
    int num2{readNumber()};   // Second num

    // Compute and display sum
    writeAnswer(num1 + num2);

    return 0;
}

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
