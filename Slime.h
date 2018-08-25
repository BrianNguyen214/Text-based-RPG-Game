#ifndef Slime_H
#define Slime_H
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include <iostream>
using namespace std;

/**
* This is the Slime h file, and its purpose conceptually is to create the Slime class/enemy
* A Slime's name is determined by its kind and its type (i.e. Fire Slime)
* Next, I created a helper method to fill in the 2D array (ability_power[3][3]) with the
abilities array and power array, and when it's the Slime's turn, it will call
on a random ability
* Besides this, I created the initial base stats of the Slime (i.e. health, armor, atkdmg)
*/

class Warrior;
class Mage;
class Archer;

class Slime
{
    public:

        Slime();

        ~Slime();

        void setSlimeName(string);
        string getSlimeName();
        void check_set_EnemyAlive();
        void setAbilityPower();
        void callRandomAbility();
        void selectRandomTarget(Warrior, Mage, Archer);

        string slimeName = "Slime";
        int baseAtkDmg = 95;
        int AtkDmg;
        int baseMagDmg = 75;
        int MagDmg;
        int armor = 25;
        int mag_armor = 25;
        int currentHealth = 150;
        int maxHealth = 150;
        bool isEnemyAlive = true;

        int turnsUsed = 0;

        string defaultType = "Normal";
        string enemyType;
        string abilityUsed;
        int targettedHero;

        string abilities[3] = {"Pound", "Tackle", "Bite"};
        int power[3] = {10, 15, 10};
        int ability_power[3][1];
        int numAbilities = 0;

    private:
};
#endif // Slime_h




