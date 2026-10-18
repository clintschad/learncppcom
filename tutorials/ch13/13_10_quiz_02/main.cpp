#include <iostream>

using std::cout;
using std::cin;

struct Fraction
{
    int numerator{0};
    int denominator{1};
};

Fraction getFract()
{
    Fraction fract{};

    cout << "Enter numerator: " << '\n';
    cin >> fract.numerator;

    cout << "Enter denominator: " << '\n';
    cin >> fract.denominator;

    return fract;
}

void getFractsTwo(Fraction& fract1, Fraction& fract2)
{
    fract1 = getFract();
    cout << '\n';
    fract2 = getFract();
}

Fraction multFracts(const Fraction& fract1, const Fraction& fract2)
{
    Fraction prod{};

    prod.numerator = fract1.numerator * fract2.numerator;
    prod.denominator = fract1.denominator * fract2.denominator;

    return prod;
}

void printFract(const Fraction& fract)
{
    cout << fract.numerator << '/' << fract.denominator << '\n';
}

int main()
{
    Fraction fract1{};
    Fraction fract2{};

    getFractsTwo(fract1, fract2);
    
    Fraction product{multFracts(fract1, fract2)};

    cout << "Your fractions multiplied together: ";
    printFract(product);

    return 0;
}
