#include <iostream>

using std::cout;

template<typename T>
struct Triad
{
    T x{};
    T y{};
    T z{};
};

// Deduction guide
template<typename T>
Triad(T, T, T) -> Triad<T>;

template<typename T>
void print(const Triad<T>& t)
{
    cout << "[" << t.x;
    cout << ", " << t.y;
    cout << ", " << t.z;
    cout << "]";
}

int main()
{
    Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
    print(t1);

    Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
    print(t2);

    cout << '\n';

    return 0;
}

