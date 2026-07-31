#include <iostream>

int calculate(char op, int x, int y)
{
    int answer{};

    switch(op)
    {
    case '+':
        answer = x + y;
        break;
    case '-':
        answer = x - y;
        break;
    case '*':
        answer = x * y;
        break;
    case '/':
        answer = x / y;
        break;
    default:
        std::cout << "Please enter a valid operation: +, -, *, or /.\n";
        return 0;
    }

    std::cout << x << " " << op << " " << y << " = " << answer << '\n';
    return answer;
}

int main()
{
    // Get operation type
    std::cout << "Enter operation: +, -, *, or /: ";
    char operation{};
    std::cin >> operation;

    // Get first operand
    std::cout << "Enter first operand: ";
    int op1{};
    std::cin >> op1;

    // Get second operand
    std::cout << "Enter second operand: ";
    int op2{};
    std::cin >> op2;

    // Calculate result
    calculate(operation, op1, op2);

    return 0;
}
