#include <iostream>

int main()
{
    std::cout << "How tall are you? (cm)\n";

    double height{};
    std::cin >> height;

    if (height >= 140.0)
        std::cout << "Have fun!\n";
    else
        std::cout << "Sorry, you're too short.\n";

    return 0;
}
