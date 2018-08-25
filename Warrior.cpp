#include <iostream>
#include "Heroes.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "Skeleton.h"
#include "The_Bahamut.h"

using namespace std;

/** These are the constructors and the destructor
*/

Warrior::Warrior()
{

}

Warrior::Warrior(string newName)
{
    warName = newName;
}

Warrior::~Warrior()
{

}

Mage allyMage_W;
Archer allyArcher_W;

void Warrior::setAllies(Mage MageAlly, Archer ArcherAlly)
{
    allyMage_W = MageAlly;
    allyArcher_W = ArcherAlly;
}

/** This method just checks if the hero is alive
*/

void Warrior::check_set_HeroAlive()
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

void Warrior::checkIfHealed(Mage allyMage)
{
    if (allyMage.healedWarr == true)
    {
        currentHealth = currentHealth + allyMage.amtHealedWarr;
        if (currentHealth > maxHealth)
            currentHealth = maxHealth;
    }
}

/** This method checks if the mage used Revive on him
* The hero's current health is increased based off the
amount of magic damage of the mage, and the status
of the hero is now alive
*/

void Warrior::checkIfRevived(Mage allyMage)
{
    if (allyMage.revivedWarr == true)
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

void Warrior::stablizeStats()
{
    if (currentHealth > maxHealth)
        currentHealth = maxHealth;
    if (currentLimit > maxLimit)
        currentLimit = maxLimit;
}

/** This method check if the warrior is still enraged
*/

void Warrior::checkEnragedBeforeMenu()
{
    if (enrageBuffTurns == 0)
    {
        enrageBuffOn = false;
    }
}

/** This method is the battle menu for the warrior
* If the hero selects Attack, the the hero chooses who to attack
* If the hero selects Abilities, then the Abilities screen, or
the callAbilities method is called
*/

void Warrior::callBattleMenu()
{
    abilityType = "";
    moveUsed = "";
    string decision = "";
    enemyAttackedTemp = 0;
    string enemyTarget  = "0";

    if (enrageBuffOn == false)
    {
        cout << "(Warrior) " << warName << "'s Turn" << endl;
    }
    else if (enrageBuffOn == true)
    {
        cout << "(Enraged Warrior) " << warName << "'s Turn" << endl;
    }

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
                    }
                    else
                        cout << "Not a valid answer" << endl;
                }
                AtkDmg = baseAtkDmg;
            }
            if (atFinalStage == true)
            {
                cout << "Confirm attack on Bahamut (press any letter then Enter)" << endl;
                cin >> enemyTarget;
                enemyAttacked = 1;
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

/** If the warrior is enraged, then the warrior's attack damage is increased
*/

void Warrior::checkIfEnraged()
{
    if (enrageBuffTurns > 0 && enrageBuffOn == true)
    {
        AtkDmg = AtkDmg + (baseAtkDmg*0.50);
        enrageBuffTurns = enrageBuffTurns - 1;
    }
    else if (enrageBuffTurns == 0)
    {
        enrageBuffOn = false;
    }
}

/** This is the callAbilities method where the hero can choose from various skills
*/

void Warrior::callAbilities()
{
    string ability;
    bool validAbility = false;
    bool abilityExists = false;
    bool usingAnAttack = false;

    while (validAbility == false)
    {
        cout << "Type an ability or type Exit to exit Abilities screen" << endl;
        cout << " ____________________________________________________ " << endl;
        cout << "|  Abilities:     Attributes/      Mana:      Power: |" << endl;
        cout << "|_________________Description:_______________________|" << endl;
        cout << "||  Erupt          PHYS/Fire        25         15   ||" << endl;
        cout << "||  Geyser         PHYS/Water       25         15   ||" << endl;
        cout << "||  Tremor         PHYS/Earth       25         15   ||" << endl;
        cout << "||  VacuumCut      PHYS/Wind        25         15   ||" << endl;
        cout << "||  Enrage         Atk Buff         40         50   ||" << endl;
        cout << "||                 for Three                        ||" << endl;
        cout << "||                 Turns                            ||" << endl;
        cout << "||__________________________________________________||" << endl;
        cout << "[____________________________________________________]" << endl;
        if (currentLimit == 100)
        {
            cout << endl;
            cout << "*********************************************************" << endl;
            cout << "**  Limit Ability:   Description:    Mana:     Power:  **" << endl;
            cout << "*    Relentless       PHYS/Dmgs       50        250     *" << endl;
            cout << "*    Assault          Single Foe                        *" << endl;
            cout << "*  (uses all of                                         *" << endl;
            cout << "**  your limit)                                        **" << endl;
            cout << "*********************************************************" << endl;
        }

        cin >> ability;

        if (ability == "Erupt" && currentMana >= 25)
        {
            AtkDmg = baseAtkDmg + (baseAtkDmg*0.15);
            currentMana = currentMana - 25;
            abilityType = "Fire";
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
        }
        else if (ability == "Geyser" && currentMana >= 25)
        {
            AtkDmg = baseAtkDmg + (baseAtkDmg*0.15);
            currentMana = currentMana - 25;
            abilityType = "Water";
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
        }
        else if (ability == "Tremor" && currentMana >= 25)
        {
            AtkDmg = baseAtkDmg + (baseAtkDmg*0.15);
            currentMana = currentMana - 25;
            abilityType = "Earth";
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
        }
        else if (ability == "VacuumCut" && currentMana >= 25)
        {
            AtkDmg = baseAtkDmg + (baseAtkDmg*0.15);
            currentMana = currentMana - 25;
            abilityType = "Wind";
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
        }
        else if (ability == "Enrage" && currentMana >= 40)
        {
            enemyAttacked = 4;
            currentMana = currentMana - 40;
            enrageBuffOn = true;
            enrageBuffTurns = 4;
            validAbility = true;
            moveUsed = ability;
        }
        else if (ability == "RelentlessAssault" && currentLimit == 100 && currentMana >= 50)
        {
            AtkDmg = baseAtkDmg + (baseAtkDmg*2.5);
            currentMana = currentMana - 50;
            currentLimit = 0;
            validAbility = true;
            moveUsed = "Relentless Assault";
            usingAnAttack = true;
        }
        else if (ability == "Exit")
        {
            cout << endl;
            callBattleMenu();
            validAbility = true;
        }
        else
        {
            for (int i = 0; i < 5; i++)
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

void Warrior::determineTypeEnemyAttacked(Skeleton Sk1, Skeleton Sk2, Skeleton Sk3)
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
        AtkDmg = AtkDmg + (AtkDmg * 0.20);
    else if (abilityType == "Fire" && skeletonTarget.enemyType == "Water")
        AtkDmg = AtkDmg - (AtkDmg * 0.20);
    else if (abilityType == "Wind" && skeletonTarget.enemyType == "Lightning")
        AtkDmg = AtkDmg + (AtkDmg * 0.20);
    else if (abilityType == "Wind" && skeletonTarget.enemyType == "Fire")
        AtkDmg = AtkDmg - (AtkDmg * 0.20);
    else if (abilityType == "Earth" && skeletonTarget.enemyType == "Water")
        AtkDmg = AtkDmg + (AtkDmg * 0.20);
    else if (abilityType == "Earth" && skeletonTarget.enemyType == "Lightning")
        AtkDmg = AtkDmg - (AtkDmg * 0.20);
    else if (abilityType == "Water" && skeletonTarget.enemyType == "Fire")
        AtkDmg = AtkDmg + (AtkDmg * 0.20);
    else if (abilityType == "Water" && skeletonTarget.enemyType == "Earth")
        AtkDmg = AtkDmg - (AtkDmg * 0.20);
}

void Warrior::determineTypeOfBahamut(Bahamut theBahamut)
{
    Bahamut bahamutTarget;

    if (enemyAttacked == 1)
    {
        bahamutTarget = theBahamut;
    }

    if (abilityType == "Fire" && bahamutTarget.enemyType == "Wind")
        AtkDmg = AtkDmg + (AtkDmg * 0.20);
    else if (abilityType == "Fire" && bahamutTarget.enemyType == "Water")
        AtkDmg = AtkDmg - (AtkDmg * 0.20);
    else if (abilityType == "Wind" && bahamutTarget.enemyType == "Lightning")
        AtkDmg = AtkDmg + (AtkDmg * 0.20);
    else if (abilityType == "Wind" && bahamutTarget.enemyType == "Fire")
        AtkDmg = AtkDmg - (AtkDmg * 0.20);
    else if (abilityType == "Earth" && bahamutTarget.enemyType == "Water")
        AtkDmg = AtkDmg + (AtkDmg * 0.20);
    else if (abilityType == "Earth" && bahamutTarget.enemyType == "Lightning")
        AtkDmg = AtkDmg - (AtkDmg * 0.20);
    else if (abilityType == "Water" && bahamutTarget.enemyType == "Fire")
        AtkDmg = AtkDmg + (AtkDmg * 0.20);
    else if (abilityType == "Water" && bahamutTarget.enemyType == "Earth")
        AtkDmg = AtkDmg - (AtkDmg * 0.20);
}

/** This is the setter and getter for the hero's name
*/

void Warrior::setWarName(string name)
{
    warName = name;
}

string Warrior::getWarName()
{
    return warName;
}

/** These methods are used after a stage to level up the
warrior
* The warrior's new stats are increased by number of levels gained times
a certain amount
*/

void Warrior::levelUpHero()
{
    newLevel = level + numLevelsGained;
    newMaxHealth = maxHealth + numLevelsGained*15;
    newMaxMana = maxMana + numLevelsGained*12;
    newBaseAtkDmg = baseAtkDmg + numLevelsGained*15;
    newBaseMagDmg = baseMagDmg + numLevelsGained*2;
    newArmor = armor + numLevelsGained*5;
    newMagArmor = mag_armor + numLevelsGained*5;
}

void Warrior::finishLevelUp()
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

