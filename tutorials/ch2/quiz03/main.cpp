#include "io.h"

int main()
{
    // Get numbers from user
    int num1{readNumber()}; // First num
    int num2{readNumber()}; // Second num

    // Compute and display sum
    writeAnswer(num1 + num2);

    return 0;
}
