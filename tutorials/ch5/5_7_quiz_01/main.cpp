#include <iostream>
#include <string>

int main()
{
    std::string name{};
    std::cout << "Enter your full name: ";
    std::getline(std::cin >> std::ws, name); // ws means ignore leading whitespace

    int age{};
    std::cout << "Enter your age: ";
    std::cin >> age;

    // string.length() is uint. Make int to be same type as age.
    std::cout << "Your age + length of name is: " << (static_cast<int>(name.length()) + age) << '\n';

    return 0;
}
