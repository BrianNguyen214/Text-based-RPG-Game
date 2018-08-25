#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Skeleton.h"
#include <cstdlib>
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"

using namespace std;

/** This is the constructor and destructor
*/

Skeleton::Skeleton()
{

}

Skeleton::~Skeleton()
{

}

/** These are the setters and getters for the name
of the enemy
*/

void Skeleton::setSkeletonName(string)
{
    skeletonName = "Skeleton";
}

void Skeleton::setNameWithType()
{
    skeletonName = enemyType + " " + skeletonName;
}

string Skeleton::getSkeletonName()
{
    return skeletonName;
}

/** This selects a random type by using the
random time seed generator
*/

void Skeleton::setRandomType()
{
    srand(time(NULL));
    int randomTypeE1;
    int randomTypeE2;
    int randomTypeE3;

    if (typesSet == 0)
    {
        randomTypeE1 = (rand()%5);
        enemyType = types[randomTypeE1];
    }

    else if (typesSet == 1)
    {
        randomTypeE2 = ((rand()%7)*(randomTypeE1%3)+1) % 5;
        enemyType = types[randomTypeE2];
    }

    else if (typesSet == 2)
    {
        randomTypeE3 = ((rand()%7)*(randomTypeE2%3)+1) % 5;
        enemyType = types[randomTypeE3];
    }
}

/** This method check is the enemy is still alive
*/

void Skeleton::check_set_EnemyAlive()
{
    if (currentHealth <= 0)
    {
        isEnemyAlive = false;
        currentHealth = 0;
    }
}

/** This sets the corresponding ability to its power
*/

void Skeleton::setAbilityPower()
{
    for (int i = 0; i < 3; i++)
    {
        ability_power[i][0] = power[i];
    }
}

/** This selects a random ability by using the
random time seed generator
*/

void Skeleton::callRandomAbility()
{
    srand(time(NULL));

    int randomAbilityT1;
    int randomAbilityT2;
    int randomAbilityT3;

    if (turnsUsed == 0)
    {
        randomAbilityT1 = (rand() % 3);
        abilityUsed = abilities[randomAbilityT1];
        AtkDmg = baseAtkDmg + power[randomAbilityT1];
    }
    else if (turnsUsed == 1)
    {
        randomAbilityT2 = ((rand()%3)*(randomAbilityT1%3)+1) % 3;
        abilityUsed = abilities[randomAbilityT2];
        AtkDmg = baseAtkDmg + power[randomAbilityT2];
    }
    else if (turnsUsed == 2)
    {
        randomAbilityT3 = ((rand()%3)*(randomAbilityT2%3)+1) % 3;
        abilityUsed = abilities[randomAbilityT3];
        AtkDmg = baseAtkDmg + power[randomAbilityT3];
    }
}

/** This selects a random target that is still alive
using the random time seed generator
*/

void Skeleton::selectRandomTarget(Warrior enemyWarr, Mage enemyMage, Archer enemyArcher)
{
    srand(time(NULL));

    if (enemyWarr.isHeroAlive == true && enemyMage.isHeroAlive == true && enemyArcher.isHeroAlive == true)
    {
        int RN1 = (rand() % 3) + 1;
        int RN2 = (((rand()%3)*(RN1%3)) % 3) + 1;
        int RN3 = (((rand()%3)*(RN2%3)) % 3) + 1;

        if (turnsUsed == 0)
        {
            targettedHero = RN1;
        }
        else if (turnsUsed == 1)
        {
            targettedHero = RN2;
        }
        else if (turnsUsed == 2)
        {
            targettedHero = RN3;
        }
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



