#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter a larger integer: ";
    int y{};
    std::cin >> y;

    if(x > y)
    {
        int temp{y};    // temp variable created
        y = x;
        x = temp;
        std::cout << "Swapping the values\n";
    }                   // temp variable destroyed

    std::cout << "The smaller value is " << x << '\n';
    std::cout << "The larger value is "  << y << '\n';

    return 0;
}                       // x and y variables destroyed
