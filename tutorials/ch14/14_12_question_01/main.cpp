#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::string_view;

class Ball
{
private:
    string m_color{"???"};
    double m_radius{-1};

public:
    Ball() 
        : Ball{"black", 10.0}
    {}

    Ball(string_view clr) 
        : Ball{clr, 10.0}
    {}

    Ball(double r) 
        : Ball{"black", r}
    {}

    Ball(string_view clr, double r) 
        : m_color{clr}, m_radius{r}
    {
        cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }

};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}
