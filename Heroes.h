#ifndef Heroes_H
#define Heroes_H
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include <iostream>

using namespace std;

/**
* This is the Heroes h file, and its purpose conceptually is to set the heroes as a team, battling
the enemy teams
* One of its methods is to check if all of the heroes are alive, and if even one of them
is still alive, then the battle sequence continues
* The other method is to level up, or increase the stats of the heroes as they progress through the journey; moreover,
the heroes' level and amount of experience they earned is kept track
* The battle sequence is a battle between heroes and enemies, and the
battle sequence will end if either the heroes defeat all the enemies or all of the
heroes are defeated
*/

class Heroes
{
    public:
        Heroes();
        Heroes(string);
        Heroes(Warrior, Mage, Archer);

        ~Heroes();

        void setWarrior(Warrior);
        Warrior getWarrior();

        void setMage(Mage);
        Mage getMage();

        void setArcher(Archer);
        Archer getArcher();

        bool areHeroesAlive(Warrior, Mage, Archer);
        void levelUpHeroes(Warrior, Mage, Archer);

        bool isHTeamAlive = true;

        int numStagesCompleted = 0;
        int heroesLevel = 1;
        int numLinesDialogue;

        string nameHeroes;
        Warrior hWarr;
        Mage hMage;
        Archer hArcher;

    private:

};
#endif // Heroes_h


