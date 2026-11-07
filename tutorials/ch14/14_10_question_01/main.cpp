#include <iostream>
#include <string>

using std::string;
using std::cout;

class Ball
{
private:
    string m_color{""};
    double m_radius{0};

public:
    Ball(string_view clr, double r)
    : m_color{clr}, m_radius{r}
    {}
    
    const string& getBallColor(void) const
    {
       return m_color;
    }

    double getBallRadius(void) const
    {
       return m_radius;
    }

};

void print(const Ball& b)
{
    cout << "Ball(" << b.getBallColor() << ", " << b.getBallRadius() << ")\n";
}


int main()
{
    Ball blue { "blue", 10.0 };
    print(blue);

    Ball red { "red", 12.0 };
    print(red);

    return 0;
}

