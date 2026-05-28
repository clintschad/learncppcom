#include <iostream>

int doubleNumber(int num)
{
    return num*2;
}

int main()
{
    int usernum{};
    std::cout << "Enter a number: ";
    std::cin >> usernum;
    std::cout << "Double your number is " << doubleNumber(usernum) << ".\n";

    return 0;
}
