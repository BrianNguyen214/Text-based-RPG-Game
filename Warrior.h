#ifndef Warrior_H
#define Warrior_H
#include "Skeleton.h"
#include "The_Bahamut.h"
#include <iostream>

using namespace std;

/**
* This is the Warrior h file, and its purpose conceptually is to create the hero/class Warrior
* The Warrior's base/initial stats are stored here, including their attack damage (AtkDmg), magic damage
(MagDmg), health, mana, limit, etc.
* Furthermore, the user can set the Warrior's name and call on the Warrior's abilities, which is
a set of moves or spells that can deal additional/unique damage to enemies
*/

class Bahamut;
class Skeleton;
class Mage;
class Archer;

class Warrior
{
    public:

        Warrior();
        Warrior(string);

        ~Warrior();

        void setWarName(string);
        string getWarName();
        void check_set_HeroAlive();

        void setAllies(Mage, Archer);
        void checkIfHealed(Mage);
        void checkIfRevived(Mage);

        void stablizeStats();
        void callBattleMenu();
        void callAbilities();
        void checkEnragedBeforeMenu();
        void checkIfEnraged();
        void determineTypeEnemyAttacked(Skeleton, Skeleton, Skeleton);
        void determineTypeOfBahamut(Bahamut);
        string typeEnemyAttacked;

        void levelUpHero();
        void finishLevelUp();

        int level = 1;
        int newLevel;
        int numLevelsGained = 0;
        int totalNumLevelsGained;
        bool atFinalStage = false;

        string warName;
        string defaultWarName = "Warrior";
        string tempWarName = "Enraged Warrior";

        int baseAtkDmg = 95;
        int newBaseAtkDmg;
        int tempBaseAtkDmg;
        int AtkDmg;

        int baseMagDmg = 15;
        int newBaseMagDmg;
        int MagDmg;

        int armor = 50;
        int newArmor;
        int mag_armor = 50;
        int newMagArmor;

        int currentHealth = 350;
        int maxHealth = 350;
        int newMaxHealth = 0;
        int healthRegen = (maxHealth * 0.08);

        int currentMana = 120;
        int maxMana = 120;
        int newMaxMana;
        int manaRegen = (maxMana * 0.02);

        int currentLimit = 0;
        int minLimit = 0;
        int maxLimit = 100;
        string abilityType;
        int enrageBuffTurns = 0;
        bool enrageBuffOn = false;
        int barrierBuffTurns;
        bool barrierBuffOn = false;
        bool defendStatus = false;
        int numAbilities = 0;
        bool isHeroAlive = true;
        int enemyAttackedTemp = 0;
        int enemyAttacked;
        string moveUsed;
        string listOfAbilites[5] = {"Erupt", "Geyser", "Tremor", "Enrage","Relentless Assault"};

    private:

};
#endif // Warrior_h



