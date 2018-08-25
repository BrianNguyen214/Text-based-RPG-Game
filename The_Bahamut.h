#ifndef Bahamut_H
#define Bahamut_H

#include <iostream>
using namespace std;

/**
* This is the Bahamut h file, and its purpose conceptually is to create the Demon class/enemy
* I created a helper method to fill in the 2D array (ability_power[][]) with the
abilities array and power array, and when it's the Demon's turn, it will call
on a random ability
* The Bahamut is the final boss, and as such it will be difficult to defeat;
it will cast very high damage and debilitating abilities on the heroes
* Besides this, I created the initial base stats of the Bahamut (i.e. health, armor, atkdmg)
*/

class Warrior;
class Mage;
class Archer;

class Bahamut
{
    public:

        Bahamut();
        Bahamut(string);

        ~Bahamut();

        void setBahamutName(string);
        void setNameWithType();
        string getBahamutName();
        void setRandomType();
        void check_set_EnemyAlive();
        void setAbilityPower();
        void callRandomAbility();
        void selectRandomTarget(Warrior, Mage, Archer);

        string bahamutDefaultName = "Bahamut";
        string bahamutName = "Bahamut";
        int baseAtkDmg = 245;
        int AtkDmg;
        int baseMagDmg = 185;
        int MagDmg;
        int armor = 195;
        int mag_armor = 195;
        int currentHealth = 3750;
        int maxHealth = 3750;
        bool isEnemyAlive = true;

        bool isWarrAlive = true;
        bool isMageAlive = true;
        bool isArchAlive = true;

        string defaultType = "Normal";
        string types[5]= {"Fire", "Water", "Earth", "Lightning", "Wind"};
        string enemyType;
        string abilities[5] = {"Cataclysmic Event", "Rend", "Apocalypse", "Utter Annihilation", "Despotic Catastrophe"};
        int power[5] = {285, 135, 120, 130, 275};
        int ability_power[5][1];
        string abilityUsed;
        int numAbilities = 0;

        int turnsUsed = 0;
        int typesSet = 0;

        int targettedHero;

    private:
};
#endif // Bahamut_h






