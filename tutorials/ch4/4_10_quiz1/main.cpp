#include <iostream>

int main()
{
    int usernum{0};

    std::cout << "Enter a number from 0 to 9: ";
    std::cin >> usernum;
    
    switch(usernum)
    {
        case 2:
        case 3:
        case 5:
        case 7:
            std::cout << "The digit is prime.\n";
            break;
        default:
            std::cout << "The digit is not prime.\n";
            break;
    }
}
