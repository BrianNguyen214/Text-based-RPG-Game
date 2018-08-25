#ifndef Mage_H
#define Mage_H
#include "Skeleton.h"
#include "The_Bahamut.h"
#include <iostream>

using namespace std;

/**
* This is the Mage h file, and its purpose conceptually is to create the hero/class Mage
* The Mage's base/initial stats are stored here, including their attack damage (AtkDmg), magic damage
(MagDmg), health, mana, limit, etc.
* Furthermore, the user can set the Mage's name and call on the Mage's abilities, which is
a set of moves or spells that can deal additional/unique damage to enemies
*/

class Bahamut;
class Skeleton;
class Warrior;
class Archer;

class Mage
{
    public:

        Mage();
        Mage(string);

        ~Mage();

        void setMageName(string);
        string getMageName();
        void check_set_HeroAlive();

        void setAllies(Warrior, Archer);
        void checkIfAlliesAlive(Warrior, Archer);
        bool isWarrAlive = true;
        bool isArchAlive = true;

        void stablizeStats();
        void callBattleMenu();
        void callAbilities();
        void determineTypeEnemyAttacked(Skeleton, Skeleton, Skeleton);
        void determineTypeOfBahamut(Bahamut);

        void levelUpHero();
        void finishLevelUp();

        int level = 1;
        int newLevel;
        int numLevelsGained = 0;
        int totalNumLevelsGained;
        bool atFinalStage = false;

        string mageName;
        string defaultMageName = "Mage";
        int baseAtkDmg = 15;
        int AtkDmg;
        int newBaseAtkDmg;

        int baseMagDmg = 95;
        int MagDmg;
        int newBaseMagDmg;

        int armor = 40;
        int newArmor;
        int mag_armor = 35;
        int newMagArmor;

        int currentHealth = 250;
        int maxHealth = 250;
        int newMaxHealth = 0;
        int healthRegen = (maxHealth * 0.05);

        int currentMana = 170;
        int maxMana = 170;
        int newMaxMana;
        int manaRegen = (maxMana * 0.10);

        int currentLimit = 0;
        int minLimit = 0;
        int maxLimit = 100;
        string abilityType;
        int barrierBuff;

        bool healedWarr = false;
        int amtHealedWarr;
        bool healedArch = false;
        int amtHealedArch;
        bool healedMage = false;
        int amtHealedMage;

        bool revivedWarr = false;
        bool revivedArch = false;

        bool defendStatus = false;
        int numAbilities = 0;
        bool isHeroAlive = true;
        int enemyAttackedTemp = 0;
        int enemyAttacked;
        string moveUsed;
        string listOfAbilites[8] = {"Fireball", "Splash", "Spark", "Gust", "Heal", "Healmore", "Revive", "Arcane Devastation"};

    private:

};
#endif // Mage_h




