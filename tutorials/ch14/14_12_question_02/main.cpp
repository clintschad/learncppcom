#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::string_view;

class Ball
{
private:
    string m_color{"black"};
    double m_radius{10.0};

public:
    Ball(string_view clr = "black", double r = 10.0) 
        : m_color{clr}, m_radius{r}
    {
        print();
    }

    Ball(double r)
        : Ball{"black", r}
    {}

    void print()
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
