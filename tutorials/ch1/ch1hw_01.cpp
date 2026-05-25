#include <iostream> // for std::cout and std::cin

// Get 3 integers from user and print them
int main()
{
    int x{}; // define variable x to hold user input
    int y{};
    int z{};

    std::cout << "Enter three numbers: ";   // ask user for 3 numbers
    
    std::cin >> x >> y >> z;                // get numbers from keyboard and store them in x, y, and z
    std::cout << "You entered " << x << ", " << y << ", and " << z << ".\n";

    return 0;
}
