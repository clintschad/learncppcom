#include <iostream>

int sumTo(int num)
{
    int sum{0};

    for(int i{0}; i <= num; i++)
        sum += i;

    return sum;
}

int main()
{
    int x{};
    std::cout << "Enter a number to sum up to: ";
    std::cin >> x;

    std::cout << "The sum of the numbers from 1 to " << x << " is " << sumTo(x) << '\n';

    return 0;
}
