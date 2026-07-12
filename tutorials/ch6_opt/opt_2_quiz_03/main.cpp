#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
    // bits = bits << 1;
    bool msbWasSet = static_cast<bool>(bits.to_ullong() >> 3);
    bits = bits << 1;

    if (msbWasSet)
        bits |= 0x01;

    return bits;

    // Author solution. Computed in one line. Much more elegant
    // return (bits << 1) | (bits >> 3);
}

int main()
{
    std::bitset<4> bits1{0b0001};
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2{0b1001};
    std::cout << rotl(bits2) << '\n';

    return 0;
}
