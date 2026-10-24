#include <iostream>
#include <string>

using std::cout;

enum class MonstType // scoped enumeration
{
    uninitialized = 0, // default if not specified
    ogre,
    dragon,
    orc,
    giant_spider,
    slime,
};

struct Monster
{
    // Could also place enum def here and
    // would also be out global scope
    MonstType mtype{};
    std::string mname{};
    int health{};
};

void printMonster(const Monster& monster)
{
    std::string mtypestr{};

    switch(monster.mtype)
    {
    case MonstType::uninitialized: mtypestr = "Uninitialized"; break;
    case MonstType::ogre: mtypestr = "Ogre"; break;
    case MonstType::dragon: mtypestr = "Dragon"; break;
    case MonstType::orc: mtypestr = "Orc"; break;
    case MonstType::giant_spider: mtypestr = "Giant Spider"; break;
    case MonstType::slime: mtypestr = "Slime"; break;
    default: mtypestr = "???"; break;
    }

    cout << "This " << mtypestr;
    cout << " is named " << monster.mname;
    cout << " and has " << monster.health << " health.\n";
}

int main()
{
    Monster Torq{MonstType::ogre,"Torq",100};
    printMonster(Torq);

    Monster Slime{MonstType::slime,"Blurp",23};
    printMonster(Slime);

    return 0;
}
