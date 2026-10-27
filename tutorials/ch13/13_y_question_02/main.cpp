#include <iostream>
#include <string>

using std::string;
using std::cout;

int main()
{
    string str{"I saw a red car yesterday."}; 

    // swap substring red with blue
    str.replace(8, 3, "blue");

    cout << str << '\n';

    return 0;
}

