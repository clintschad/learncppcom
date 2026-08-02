#include <iostream>

int main()
{
    std::cout << "ASCII Char\tASCII Dec#\n";

    int letterNum{97};

    while (letterNum <= 122)
    {
        char letterChar{static_cast<char>(letterNum)};
        std::cout << letterChar << "\t\t" << letterNum << '\n';
        letterNum++;
    }
    
    return 0;
}
