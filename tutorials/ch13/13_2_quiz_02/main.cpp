#include <iostream>

namespace Monster
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
}

int main()
{
    Monster::MonsterType monster01{Monster::troll};

    return 0;
}

