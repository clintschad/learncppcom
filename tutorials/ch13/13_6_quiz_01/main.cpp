#include <iostream>
#include <string_view>

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animal animal)
{
    // using enum Animal; // Not working with -std=c++20 for some reason

    switch(animal)
    {
    case Animal::pig: return "pig";
    case Animal::chicken: return "chicken";
    case Animal::goat: return "goat";
    case Animal::cat: return "cat";
    case Animal::dog: return "dog";
    case Animal::duck: return "duck";
    default: return "???";
    }
}

constexpr int printNumberOfLegs(Animal animal)
{
    // using enum Animal;

    switch(animal)
    {
    case Animal::pig:
    case Animal::goat:
    case Animal::cat:
    case Animal::dog: return 4;
    case Animal::chicken:
    case Animal::duck: return 2;
    default: return -1;
    }
}

int main()
{
    Animal cat {Animal::cat};
    Animal chicken {Animal::chicken};

    std::cout << "A " << getAnimalName(cat) << " has " << printNumberOfLegs(cat) << " legs.\n";
    std::cout << "A " << getAnimalName(chicken) << " has " << printNumberOfLegs(chicken) << " legs.\n";
    
    return 0;
}
