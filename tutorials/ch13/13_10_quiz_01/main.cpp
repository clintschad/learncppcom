#include <iostream>

using std::cin;
using std::cout;

struct Ad
{
    int numWatched{0};
    double usrPct{0};
    double earnings{0};
};

Ad getAdInfo()
{
    Ad newAd{};

    cout << "Enter number of ads watched: ";
    cin >> newAd.numWatched;

    cout << "Enter pct of users clicking ad: ";
    cin >> newAd.usrPct;

    cout << "Enter avg earnings per ad: ";
    cin >> newAd.earnings;

    return newAd;
}

void printAdRevenue(const Ad& ad)
{
    cout << "Number of ads watched: " << ad.numWatched << '\n';
    cout << "Percent of users clicking on ad: " << ad.usrPct << '\n';
    cout << "Average earnings per ad: " << ad.earnings << '\n';
    cout << "Total revenue: " << ad.numWatched * ad.usrPct * ad.earnings << '\n';
}

int main()
{
    Ad ad1{getAdInfo()};
    printAdRevenue(ad1);

    return 0;
}

