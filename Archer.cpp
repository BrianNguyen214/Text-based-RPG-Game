#include <iostream>
#include "Heroes.h"
#include "Archer.h"
#include "Warrior.h"
#include "Mage.h"

using namespace std;

/** These are the constructors and the destructor
*/

Archer::Archer()
{

}

Archer::Archer(string newName)
{
    archName = newName;
}

Archer::~Archer()
{

}

Warrior allyWarrior_A;
Mage allyMage_A;

void Archer::setAllies(Warrior WarriorAlly, Mage MageAlly)
{
    allyWarrior_A = WarriorAlly;
    allyMage_A = MageAlly;
}

/** This method just checks if the hero is alive
*/

void Archer::check_set_HeroAlive()
{
    if (currentHealth <= 0)
    {
        isHeroAlive = false;
        currentHealth = 0;
    }
}

/** This method checks if the mage used Heal on him
* The hero's current health is increased based on how much the
mage healed him for
*/

void Archer::checkIfHealed(Mage allyMage)
{
    if (allyMage.healedArch == true)
    {
        currentHealth = currentHealth + allyMage.amtHealedArch;
        if (currentHealth > maxHealth)
            currentHealth = maxHealth;
    }
}

/** This method checks if the mage used Revive on him
* The hero's current health is increased based off the
amount of magic damage of the mage, and the status
of the hero is now alive
*/

void Archer::checkIfRevived(Mage allyMage)
{
    if (allyMage.revivedArch == true)
    {
        currentHealth = currentHealth + allyMage.MagDmg;
        isHeroAlive = true;
    }
    if (currentHealth > maxHealth)
        currentHealth = maxHealth;
}

/** This method just ensures that the current health/limit
doesn't exceed the max health/limit
*/

void Archer::stablizeStats()
{
    if (currentHealth > maxHealth)
        currentHealth = maxHealth;
    if (currentLimit > maxLimit)
        currentLimit = maxLimit;
}

/** This method is the battle menu for the warrior
* If the hero selects Attack, the the hero chooses who to attack
* If the hero selects Abilities, then the Abilities screen, or
the callAbilities method is called
*/

void Archer::callBattleMenu()
{
    usedPhysAtk = false;
    usedMagAtk = false;
    abilityType = "";
    moveUsed = "";
    string decision = "";
    enemyAttackedTemp = 0;
    string enemyTarget = "0";

    cout << "(Archer) " << archName << "'s Turn" << endl;
    cout << "Type a decision" << endl;
    cout << " ______________________________" << endl;
    cout << "[_________Battle Menu:_________]" << endl;
    cout << "|| Attack (or type f)         ||" << endl;
    cout << "|| Abilities (or type d)      ||" << endl;
    cout << "|| SkipTurn (or type s)       ||" << endl;
    cout << "||____________________________||" << endl;
    cout << "[______________________________]" << endl;
    while (decision != "Attack" || decision != "SkipTurn" || decision != "Abilities" || decision != "f" || decision != "d" || decision != "s")
    {
        cin >> decision;

        if (decision == "Attack" || decision == "f")
        {
            moveUsed = "Attack";
            if (atFinalStage == false)
            {
                while (enemyTarget != "1" || enemyTarget != "2" || enemyTarget != "3")
                {
                    if (enemyTarget == "1" || enemyTarget == "2" || enemyTarget == "3")
                        break;
                    cout << "Select an enemy (1, 2, or 3)" << endl;
                    cin >> enemyTarget;
                    if (enemyTarget == "1" || enemyTarget == "2" || enemyTarget == "3")
                    {
                        enemyAttackedTemp = stoi(enemyTarget);
                        enemyAttacked = enemyAttackedTemp;
                        usedPhysAtk = true;
                    }
                    else
                        cout << "Not a valid answer" << endl;
                }
                AtkDmg = baseAtkDmg;
            }
            if (atFinalStage == true)
            {
                cout << "Confirm attack on Bahamut (press any letter then Enter)" << endl;
                enemyAttacked = 1;
                cin >> enemyTarget;
                usedPhysAtk = true;
                AtkDmg = baseAtkDmg;
            }

        }

        else if (decision == "SkipTurn" || decision == "s")
        {
            enemyAttacked = -5;
            cout << endl;
        }

        else if (decision == "Abilities" || decision == "d")
        {
            cout << endl;
            callAbilities();
        }

        else
            cout << "Not a valid answer" << endl;

        if (decision == "Attack" || decision == "SkipTurn" || decision == "Abilities" || decision == "f" || decision == "d" || decision == "s")
            break;
    }
}

/** This method checks if Barrier is still activated
* If the number of turns passed since first activating barrier is
greater than zero, than the barrierBuffOn is true and the
number of turns left using Barrier is decreased by one
+ If the number of turns left on Barrier is zero, then
the barrierBuffOn bool variable is false
*/

void Archer::checkIfBarrierOn()
{
    if (barrierBuffTurns > 0 && barrierBuffOn == true)
    {
        barrierBuffTurns = barrierBuffTurns - 1;
    }
    else if (barrierBuffTurns == 0)
    {
        barrierBuffOn = false;
    }
}

void Archer::turnOffBarrier()
{
    if (barrierBuffTurns == 0)
        barrierBuffOn = false;
}

/** This is the callAbilities method where the hero can choose from various skills
*/

void Archer::callAbilities()
{
    string ability;
    bool validAbility = false;
    bool abilityExists = false;
    bool usingAnAttack = false;

    while (validAbility == false)
    {
        cout << "Type an ability or type Exit to exit Abilities screen" << endl;
        cout << " ______________________________________________________" << endl;
        cout << "|  Abilities:        Attributes/      Mana:     Power: |" << endl;
        cout << "|____________________Description:______________________|" << endl;
        cout << "||  FlameBurst        MAG/Fire         25        15   ||" << endl;
        cout << "||  WaterBomb         MAG/Water        25        15   ||" << endl;
        cout << "||  BoltBlast         MAG/Lightning    25        15   ||" << endl;
        cout << "||  StoneEdge         MAG/Earth        25        15   ||" << endl;
        cout << "||  Doubleshot        PHYS             25        35   ||" << endl;
        cout << "||  Powershot         PHYS             50        70   ||" << endl;
        cout << "||  Barrier           Gives All        40        75   ||" << endl;
        cout << "||                    Party Members                   ||" << endl;
        cout << "||                    a Temporary                     ||" << endl;
        cout << "||                    Increase in                     ||" << endl;
        cout << "||                    Armor and                       ||" << endl;
        cout << "||                    Mag Armor                       ||" << endl;
        cout << "||                    for Three                       ||" << endl;
        cout << "||                    Turns                           ||" << endl;
        cout << "||____________________________________________________||" << endl;
        cout << "[______________________________________________________]" << endl;

        if (currentLimit == 100)
        {
            cout << endl;
            cout << "*********************************************************" << endl;
            cout << "**  Limit Ability:   Description:    Mana:     Power:  **" << endl;
            cout << "*    Deadly Salvo     PHYS/Dmgs       60        200     *" << endl;
            cout << "*                     Single Foe                        *" << endl;
            cout << "*  (uses all of                                         *" << endl;
            cout << "**  your limit)                                        **" << endl;
            cout << "*********************************************************" << endl;
        }

        cin >> ability;

        if (ability == "FlameBurst" && currentMana >=25)
        {
            MagDmg = baseMagDmg + (baseMagDmg*0.15);
            currentMana = currentMana - 25;
            abilityType = "Fire";
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
            usedMagAtk = true;
        }
        else if (ability == "WaterBomb" && currentMana >= 25)
        {
            MagDmg = baseMagDmg + (baseMagDmg*0.15);
            currentMana = currentMana - 25;
            abilityType = "Water";
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
            usedMagAtk = true;
        }
        else if (ability == "BoltBlast" && currentMana >= 15)
        {
            MagDmg = baseMagDmg + (baseMagDmg*0.15);
            currentMana = currentMana - 15;
            abilityType = "Lightning";
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
            usedMagAtk = true;
        }
        else if (ability == "StoneEdge" && currentMana >= 25)
        {
            MagDmg = baseMagDmg + (baseMagDmg*0.15);
            currentMana = currentMana - 25;
            abilityType = "Earth";
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
            usedMagAtk = true;
        }
        else if (ability == "Doubleshot" && currentMana >= 25)
        {
            AtkDmg = baseAtkDmg + (baseAtkDmg*0.35);
            currentMana = currentMana - 25;
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
            usedPhysAtk = true;
        }
        else if (ability == "Powershot" && currentMana >= 50)
        {
            AtkDmg = baseAtkDmg + (baseAtkDmg*0.70);
            currentMana = currentMana - 50;
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
            usedPhysAtk = true;
        }
        else if (ability == "Barrier" && currentMana >= 40)
        {
            enemyAttacked = -1;
            currentMana = currentMana - 50;
            barrierBuffOn = true;
            barrierBuffTurns = 3;
            validAbility = true;
            moveUsed = ability;
        }
        else if (ability == "DeadlySalvo" && currentLimit == 100 && currentMana >= 60)
        {
            AtkDmg = baseAtkDmg + (baseAtkDmg*2);
            currentMana = currentMana - 60;
            currentLimit = 0;
            validAbility = true;
            moveUsed = "Deadly Salvo";
            usingAnAttack = true;
            usedPhysAtk = true;
        }
        else if (ability == "Exit")
        {
            cout << endl;
            callBattleMenu();
            validAbility = true;
        }
        else
        {
            for (int i = 0; i < 8; i++)
            {
                if (ability == listOfAbilites[i])
                {
                    abilityExists = true;
                    break;
                }
            }
            if (abilityExists == false)
                cout << "Sorry, but that ability doesn't exist" << endl;
            else if (abilityExists == true)
                cout << "Sorry, but not enough mana" << endl;
        }
    }

    enemyAttackedTemp = 0;
    string enemyTarget = "0";

    if (atFinalStage == false)
    {
        if (usingAnAttack == true)
        {
            while (enemyTarget != "1" || enemyTarget != "2" || enemyTarget != "3")
            {
                if (enemyTarget == "1" || enemyTarget == "2" || enemyTarget == "3")
                    break;

                cout << "Select an enemy (1, 2, or 3)" << endl;
                cin >> enemyTarget;
                if (enemyTarget == "1" || enemyTarget == "2" || enemyTarget == "3")
                    enemyAttacked = stoi(enemyTarget);
                else
                    cout << "Not a valid answer" << endl;
            }
        }
    }

    if (atFinalStage == true)
    {
        if (usingAnAttack == true)
        {
            cout << "Confirm attack on Bahamut (press any letter then Enter)" << endl;
            enemyAttacked = 1;
            cin >> enemyTarget;
        }
    }
}

/** After the hero chooses an ability, the type of the ability and the type of the
enemy is compared, and based off the types the hero's damage may or may not be altered
*/

void Archer::determineTypeEnemyAttacked(Skeleton Sk1, Skeleton Sk2, Skeleton Sk3)
{
    Skeleton skeletonTarget;

    if (enemyAttacked == 1)
    {
        skeletonTarget = Sk1;
    }
    else if (enemyAttacked == 2)
    {
        skeletonTarget = Sk2;
    }
    else if (enemyAttacked == 3)
    {
        skeletonTarget = Sk3;
    }

    if (abilityType == "Fire" && skeletonTarget.enemyType == "Wind")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Fire" && skeletonTarget.enemyType == "Water")
        MagDmg = MagDmg - (MagDmg * 0.20);
    else if (abilityType == "Lightning" && skeletonTarget.enemyType == "Earth")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Lightning" && skeletonTarget.enemyType == "Wind")
        MagDmg = MagDmg - (MagDmg * 0.20);
    else if (abilityType == "Earth" && skeletonTarget.enemyType == "Water")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Earth" && skeletonTarget.enemyType == "Lightning")
        MagDmg = MagDmg - (MagDmg * 0.20);
    else if (abilityType == "Water" && skeletonTarget.enemyType == "Fire")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Water" && skeletonTarget.enemyType == "Earth")
        MagDmg = MagDmg - (MagDmg * 0.20);
}

void Archer::determineTypeOfBahamut(Bahamut theBahamut)
{
    Bahamut bahamutTarget;

    if (enemyAttacked == 1)
    {
        bahamutTarget = theBahamut;
    }

    if (abilityType == "Fire" && bahamutTarget.enemyType == "Wind")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Fire" && bahamutTarget.enemyType == "Water")
        MagDmg = MagDmg - (MagDmg * 0.20);
    else if (abilityType == "Lightning" && bahamutTarget.enemyType == "Earth")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Lightning" && bahamutTarget.enemyType == "Wind")
        MagDmg = MagDmg - (MagDmg * 0.20);
    else if (abilityType == "Earth" && bahamutTarget.enemyType == "Water")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Earth" && bahamutTarget.enemyType == "Lightning")
        MagDmg = MagDmg - (MagDmg * 0.20);
    else if (abilityType == "Water" && bahamutTarget.enemyType == "Fire")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Water" && bahamutTarget.enemyType == "Earth")
        MagDmg = MagDmg - (MagDmg * 0.20);
}

/** This is the setter and getter for the hero's name
*/

void Archer::setArchName(string name)
{
    archName = name;
}

string Archer::getArchName()
{
    return archName;
}

/** These methods are used after a stage to level up the
archer
* The archer's new stats are increased by number of levels gained times
a certain amount
*/

void Archer::levelUpHero()
{
    newLevel = level + numLevelsGained;
    newMaxHealth = maxHealth + numLevelsGained*12;
    newMaxMana = maxMana + numLevelsGained*14;
    newBaseAtkDmg = baseAtkDmg + numLevelsGained*15;
    newBaseMagDmg = baseMagDmg + numLevelsGained*15;
    newArmor = armor + numLevelsGained*5;
    newMagArmor = mag_armor + numLevelsGained*3;
}

void Archer::finishLevelUp()
{
    level = newLevel;
    maxHealth = newMaxHealth;
    currentHealth = maxHealth;
    maxMana = newMaxMana;
    currentMana = maxMana;
    baseAtkDmg = newBaseAtkDmg;
    baseMagDmg = newBaseMagDmg;
    armor = newArmor;
    mag_armor = newMagArmor;
}
