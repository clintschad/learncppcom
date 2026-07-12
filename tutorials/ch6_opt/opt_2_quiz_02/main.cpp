#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
    // bits = bits << 1;
    // const bool msbWasSet{bits.test(3)}; // Author solution: more elegant and better with const
    bool msbWasSet = bits.test(3);
    bits = bits << 1;
    // bits <<= 1; // Author solution

    if (msbWasSet)
        bits = bits.set(0);

    return bits;
}

int main()
{
    std::bitset<4> bits1{0b0001};
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2{0b1001};
    std::cout << rotl(bits2) << '\n';

    return 0;
}
