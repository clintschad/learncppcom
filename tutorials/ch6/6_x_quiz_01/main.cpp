#include <iostream>
#include <string_view>

std::string_view getQuantityPhrase(int x);
std::string_view getApplesPluralized(int x);


int main()
{
    constexpr int maryApples{3};
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}


std::string_view getQuantityPhrase(int x)
{
    if (x < 0)
        return "negative";
    else if (x == 0)
        return "no";
    else if (x == 1)
        return "a single";
    else if (x == 2)
        return "a couple of";
    else if (x == 3)
        return "a few";
    // Below they just use "else" for this case,
    // and have no "error" case, which makes sense.
    else if (x > 3)
        return "many";
    else
        return "error";
}

std::string_view getApplesPluralized(int x)
{
    if (x == 1)
        return "apple";
    else
        return "apples";

    // Their solution which is more elegant:
    // return (num == 1) ? "apple" : "apples";
}
