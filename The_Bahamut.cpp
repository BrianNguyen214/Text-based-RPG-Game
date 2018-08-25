#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "The_Bahamut.h"
#include <cstdlib>
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"

using namespace std;

/** This is the constructor and destructor
*/

Bahamut::Bahamut()
{

}

Bahamut::~Bahamut()
{

}

/** These are the setters and getters for the name and type
of the enemy
*/

void Bahamut::setBahamutName(string)
{
    bahamutName = "Bahamut";
}

void Bahamut::setNameWithType()
{
    bahamutName = enemyType + " " + bahamutName;
}

string Bahamut::getBahamutName()
{
    return bahamutName;
}


void Bahamut::setRandomType()
{
    srand(time(NULL));
    int randomType;

    randomType = (rand()%5);
    enemyType = types[randomType];
}

/** This checks if the enemy is still alive
*/

void Bahamut::check_set_EnemyAlive()
{
    if (currentHealth <= 0)
    {
        isEnemyAlive = false;
        currentHealth = 0;
    }
}

/** This sets the corresponding ability to its power
*/

void Bahamut::setAbilityPower()
{
    for (int i = 0; i < 3; i++)
    {
        ability_power[i][0] = power[i];
    }
}

/** This selects a random ability by using the
random time seed generator
*/

void Bahamut::callRandomAbility()
{
    srand(time(NULL));

    int randomAbility;

    randomAbility = (rand() % 5);
    abilityUsed = abilities[randomAbility];
    AtkDmg = baseAtkDmg + power[randomAbility];
}

/** This selects a random target that is still alive
using the random time seed generator
*/

void Bahamut::selectRandomTarget(Warrior enemyWarr, Mage enemyMage, Archer enemyArcher)
{
    srand(time(NULL));

    if (enemyWarr.isHeroAlive == true && enemyMage.isHeroAlive == true && enemyArcher.isHeroAlive == true)
    {
        int randomTarget = (rand() % 3) + 1;

        targettedHero = randomTarget;
    }
    else if (enemyWarr.isHeroAlive == true && enemyMage.isHeroAlive == true && enemyArcher.isHeroAlive == false)
    {
        int randomTarget = (rand() % 2) + 1;
        if (randomTarget == 1)
            targettedHero = 1;
        else if (randomTarget == 2)
            targettedHero = 2;
    }
    else if (enemyWarr.isHeroAlive == true && enemyMage.isHeroAlive == false && enemyArcher.isHeroAlive == true)
    {
        int randomTarget = (rand() % 2) + 1;
        if (randomTarget == 1)
            targettedHero = 1;
        else if (randomTarget == 2)
            targettedHero = 3;
    }
    else if (enemyWarr.isHeroAlive == true && enemyMage.isHeroAlive == false && enemyArcher.isHeroAlive == false)
    {
        targettedHero = 1;
    }
    else if (enemyWarr.isHeroAlive == false && enemyMage.isHeroAlive == true && enemyArcher.isHeroAlive == true)
    {
        int randomTarget = (rand() % 2) + 1;
        if (randomTarget == 1)
            targettedHero = 2;
        else if (randomTarget == 2)
            targettedHero = 3;
    }
    else if (enemyWarr.isHeroAlive == false && enemyMage.isHeroAlive == true && enemyArcher.isHeroAlive == false)
    {
        targettedHero = 2;
    }
    else if (enemyWarr.isHeroAlive == false && enemyMage.isHeroAlive == false && enemyArcher.isHeroAlive == true)
    {
        targettedHero = 3;
    }
}



