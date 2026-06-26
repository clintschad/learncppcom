#include <iostream>

int main()
{
    std::cout << "Enter a single character: ";

    char usrChar{};
    std::cin >> usrChar;

    int charNum{usrChar};

    std::cout << "You entered '" << usrChar << "', which has ASCII code " << charNum << ".\n";

    return 0;
}
