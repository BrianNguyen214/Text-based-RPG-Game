#include <iostream>
#include "Heroes.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"

using namespace std;

/** These are the constructors and the destructor
*/

Heroes::Heroes()
{

}

Heroes::Heroes(string nameTeam)
{
    nameHeroes = nameTeam;
}

Heroes::Heroes(Warrior newWarr, Mage newMage, Archer newArch)
{
    hWarr = newWarr;
    hMage = newMage;
    hArcher = newArch;
}

Heroes::~Heroes()
{

}

/** These are the getters and setters for the different heroes
*/

void Heroes::setWarrior(Warrior newWarr)
{
    hWarr = newWarr;
}
Warrior Heroes::getWarrior()
{
    return hWarr;
}

void Heroes::setMage(Mage newMage)
{
    hMage = newMage;
}
Mage Heroes::getMage()
{
    return hMage;
}

void Heroes::setArcher(Archer newArch)
{
    hArcher = newArch;
}
Archer Heroes::getArcher()
{
    return hArcher;
}

/** This methods checks if the heroes are still alive, and if they
are, the battle sequence continues
*/

bool Heroes::areHeroesAlive(Warrior warr, Mage mage, Archer arch)
{
    if (warr.isHeroAlive == false && mage.isHeroAlive == false && arch.isHeroAlive == false)
        isHTeamAlive = false;
    return isHTeamAlive;
}

