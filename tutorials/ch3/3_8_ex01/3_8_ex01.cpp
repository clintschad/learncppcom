#include <iostream>

int main()
{
    int x{1};
    std::cout << x << '\n';

    x = x + 2;
    std::cout << x << '\n';

    x = x + 3;
    std::cout << x << '\n';

    return 0;
}
