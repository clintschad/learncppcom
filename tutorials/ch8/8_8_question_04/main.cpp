#include <iostream>

int main()
{
    int outer{5};
    int innerStart{1};
    while (outer > 0)
    {
        int inner{5};
        while (inner > 0)
        {
            if (inner <= innerStart)
                std::cout << inner << ' ';
            else
                std::cout << ' ' << ' ';
            --inner;
        }

        std::cout << '\n';
        --outer;
        ++innerStart;
    }

    return 0;
}
