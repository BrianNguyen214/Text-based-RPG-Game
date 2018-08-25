#ifndef Archer_H
#define Archer_H
#include "Skeleton.h"
#include "The_Bahamut.h"
#include <iostream>

using namespace std;

/**
* This is the Archer h file, and its purpose conceptually is to create the hero/class Archer
* The Archer's base/initial stats are stored here, including their attack damage (AtkDmg), magic damage
(MagDmg), health, mana, limit, etc.
* Furthermore, the user can set the Archer's name and call on the Archer's abilities, which is
a set of moves or spells that can deal additional/unique damage to enemies
*/

class Bahamut;
class Skeleton;
class Warrior;
class Mage;

class Archer
{
    public:

        Archer();
        Archer(string);

        ~Archer();

        void setArchName(string);
        string getArchName();
        void check_set_HeroAlive();

        void setAllies(Warrior, Mage);
        void checkIfHealed(Mage);
        void checkIfRevived(Mage);

        void stablizeStats();
        void callBattleMenu();
        void callAbilities();
        void checkIfBarrierOn();
        void turnOffBarrier();
        bool usedPhysAtk = false;
        bool usedMagAtk = false;
        void determineTypeEnemyAttacked(Skeleton, Skeleton, Skeleton);
        void determineTypeOfBahamut(Bahamut);

        void levelUpHero();
        void finishLevelUp();

        int level = 1;
        int newLevel;
        int numLevelsGained = 0;
        int totalNumLevelsGained;
        bool atFinalStage = false;

        string archName;
        string defaultArchName = "Archer";
        int baseAtkDmg = 95;
        int AtkDmg;
        int newBaseAtkDmg;

        int baseMagDmg = 95;
        int MagDmg;
        int newBaseMagDmg;

        int armor = 45;
        int newArmor;
        int mag_armor = 45;
        int newMagArmor;

        int currentHealth = 300;
        int maxHealth = 300;
        int newMaxHealth;
        int healthRegen = (maxHealth * 0.06);

        int currentMana = 150;
        int maxMana = 150;
        int newMaxMana = 0;
        int manaRegen = (maxMana * 0.08);

        int currentLimit = 0;
        int minLimit = 0;
        int maxLimit = 100;
        string abilityType;
        bool barrierBuffOn = false;
        int barrierBuffTurns = 0;
        bool defendStatus = false;
        int numAbilities = 0;
        bool isHeroAlive = true;
        int enemyAttackedTemp = 0;
        int enemyAttacked;
        string moveUsed;
        string listOfAbilites[6] = {"Fireshot", "Iceshot", "Doubleshot", "Powershot", "Barrier", "Deadly Salvo"};

    private:

};
#endif // Archer_h




