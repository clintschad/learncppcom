#include <iostream>

int main()
{
    std::cout << "Enter a single character: ";

    char usrChar{};
    std::cin >> usrChar;

    std::cout << "You entered '" << usrChar << "', which has ASCII code " << static_cast<int>(usrChar) << ".\n";

    return 0;
}
