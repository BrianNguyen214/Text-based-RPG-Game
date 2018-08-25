#ifndef Skeleton_H
#define Skeleton_H
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include <iostream>
using namespace std;

/**
* This is the Skeleton h file, and its purpose conceptually is to create the Skeleton class/enemy
* A Skeleton's name is determined by its kind and its type (i.e. Fire Skeleton)
* Next, I created a helper method to fill in the 2D array (ability_power[][]) with the
abilities array and power array, and when it's the Skeleton's turn, it will call
on a random ability
* Besides this, I created the initial base stats of the Skeleton (i.e. health, armor, atkdmg)
*/

class Warrior;
class Mage;
class Archer;

class Skeleton
{
    public:

        Skeleton();
        Skeleton(string);

        ~Skeleton();

        void setSkeletonName(string);
        void setNameWithType();
        string getSkeletonName();
        void setRandomType();
        void check_set_EnemyAlive();
        void setAbilityPower();
        void callRandomAbility();
        void selectRandomTarget(Warrior, Mage, Archer);

        bool isWarrAlive = true;
        bool isMageAlive = true;
        bool isArchAlive = true;

        string skeletonDefaultName = "Skeleton";
        string skeletonName = "Skeleton";
        int baseAtkDmg = 135;
        int AtkDmg;
        int baseMagDmg = 135;
        int MagDmg;
        int armor = 50;
        int mag_armor = 55;
        int currentHealth = 300;
        int maxHealth = 300;
        bool isEnemyAlive = true;

        int turnsUsed = 0;
        int typesSet = 0;

        string defaultType = "Normal";
        string enemyType;
        string abilityUsed;
        int targettedHero;

        string types[5]= {"Fire", "Water", "Earth", "Lightning", "Wind"};
        string abilities[3] = {"Claw", "Scratch", "Tackle"};
        int power[3] = {15, 25, 15};
        int ability_power[3][1];
        int numAbilities = 0;

    private:
};
#endif // Skeleton_h




