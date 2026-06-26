#include <iostream>

// Main
int main()
{
    std::cout << "Enter the height of the tower in meters: ";
    double towerHeight{0};
    std::cin >> towerHeight;

    double const grav_const{9.8};
    double sec{0};
    double ballHeight{towerHeight}; // Initialize ball height

    while (ballHeight > 0)
    {
        double dist_fallen{0};
        dist_fallen = grav_const * sec * sec / 2;

        ballHeight = towerHeight - dist_fallen;

        if(ballHeight > 0)
        {
            std::cout << "At " << sec << " seconds, the ball is at height: " << ballHeight << " meters\n";
        }
        else
        {
            std::cout << "At " << sec << " seconds, the ball is on the ground.\n";
            break;
        }

        sec++;
    }

    return 0;
}

