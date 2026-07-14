#include <iostream>

int main()
{
    std::cout << "Enter a number from 0 to 255: ";

    std::uint16_t num{};

    std::cin >> num;

    std::cout << "Number in hex is 0x" << std::uppercase << std::hex << num << "\n";


    // Compute bits
    int bit[8] = {0};
    int power{0};

    for(int i = 7; i >=0; i--)
    {
        power = 1 << i;

        if (num >= power)
        {
            bit[i] = 1;
            num -= power;
        }
    }

    
    // Print bits
    std::cout << "Number in binary is ";
    
    for(int j = 7; j >= 0; j--)
    {
        std::cout << bit[j];

        // Add space in middle for improved readibility
        if(j ==4)
            std::cout << ' ';
    }

    std::cout << '\n';

    return 0;
}
