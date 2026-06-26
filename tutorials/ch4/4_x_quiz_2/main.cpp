#include <iostream>

int main()
{
    double x{};
    double y{};
    char op{};

    std::cout << "Enter a double value: ";
    std::cin >> x;

    std::cout << "Enter a double value: ";
    std::cin >> y;

    std::cout << "Enter +, -, *, or /: ";
    std::cin >> op;

    double ans{};

    switch(op)
    {
        case '+':
            ans = x + y;
            break;
        case '-':
            ans = x - y;
            break;
        case '*':
            ans = x * y;
            break;
        case '/':
            ans = x / y;
            break;
        default:
            std::cout << "Unknown operator. Please enter +, -, *, or /.\n";
            return 0;
            break;
    }

    std::cout << x << " " << op << " " << y << " is " << ans << "\n";

    return 0;
}
