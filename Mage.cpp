#include <iostream>
#include "Heroes.h"
#include "Mage.h"
#include "Warrior.h"
#include "Archer.h"

using namespace std;

/** These are the constructors and the destructor
*/

Mage::Mage()
{

}

Mage::Mage(string newName)
{
    mageName = newName;
}

Mage::~Mage()
{

}

Warrior allyWarrior_M;
Archer allyArcher_M;

void Mage::setAllies(Warrior WarriorAlly, Archer ArcherAlly)
{
    allyWarrior_M = WarriorAlly;
    allyArcher_M = ArcherAlly;
}

/** This method just checks if the hero is alive
*/

void Mage::check_set_HeroAlive()
{
    if (currentHealth <= 0)
    {
        isHeroAlive = false;
    }
}

/** This method checks if the mage's allies are still alive
* Based on the results from this, the mage may or may not be able to
use a certain skill on a hero, such as Heal or Revive
*/

void Mage::checkIfAlliesAlive(Warrior allyWarr, Archer allyArch)
{
    if (allyWarr.isHeroAlive == false)
    {
        isWarrAlive = false;
        //cout << "Warr is dead" << endl;
    }
    if (allyWarr.isHeroAlive == true)
    {
        isWarrAlive = true;
        //cout << "Warr is alive" << endl;
    }

    if (allyArch.isHeroAlive == false)
    {
        isArchAlive = false;
        //cout << "Arch is dead" << endl;
    }
    if (allyArch.isHeroAlive == true)
    {
        isArchAlive = true;
        //cout << "Arch is alive" << endl;
    }
}

/** This method just ensures that the current health/limit
doesn't exceed the max health/limit
*/

void Mage::stablizeStats()
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

void Mage::callBattleMenu()
{
    healedWarr = false;
    amtHealedWarr = 0;
    healedArch = false;
    amtHealedArch = 0;
    healedMage =false;
    amtHealedMage = 0;

    revivedWarr = false;
    revivedArch = false;

    abilityType = "";
    moveUsed = "";
    string decision = "";
    enemyAttackedTemp = 0;
    string enemyTarget = "0";

    cout << "(Mage) " << mageName << "'s Turn" << endl;
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
                    MagDmg = baseMagDmg;
                }
            }
            if (atFinalStage == true)
            {
                cout << "Confirm attack on Bahamut (press any letter then Enter)" << endl;
                enemyAttacked = 1;
                cin >> enemyTarget;
                MagDmg = baseMagDmg;
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

/** This is the callAbilities method where the hero can choose from various skills
*/

void Mage::callAbilities()
{
    string ability;
    bool validAbility = false;
    bool abilityExists = false;
    string healHero;
    bool healedHero = false;
    string reviveHero;
    bool revivedHero = false;

    bool usingAnAttack = false;

    while (validAbility == false)
    {
        cout << "Type an ability or type Exit to exit Abilities screen" << endl;
        cout << " _______________________________________________________" << endl;
        cout << "|  Abilities:        Attributes/      Mana:     Power:  |" << endl;
        cout << "|____________________Description:_______________________|" << endl;
        cout << "||  Fireball          MAG/Fire         20        15    ||" << endl;
        cout << "||  Splash            MAG/Water        20        15    ||" << endl;
        cout << "||  Spark             MAG/Lightning    20        15    ||" << endl;
        cout << "||  Gust              MAG/Wind         20        15    ||" << endl;
        cout << "||  Heal              Heals a Party    25        10    ||" << endl;
        cout << "||                    Member                           ||" << endl;
        cout << "||  Healmore          Heals Every      40        10    ||" << endl;
        cout << "||                    Party Member                     ||" << endl;
        cout << "||  Revive            Revives a        40        15    ||" << endl;
        cout << "||                    Party Member                     ||" << endl;
        cout << "||_____________________________________________________||" << endl;
        cout << "[_______________________________________________________]" << endl;

        if (currentLimit == 100)
        {
            cout << endl;
            cout << "**********************************************************" << endl;
            cout << "**  Limit Ability:   Attributes/      Mana:     Power:  **" << endl;
            cout << "*    Arcane           MAG/Dmgs         50        200     *" << endl;
            cout << "*    Devastation      Single Foe                         *" << endl;
            cout << "*  (uses all of                                          *" << endl;
            cout << "**  your limit)                                         **" << endl;
            cout << "**********************************************************" << endl;
        }

        cin >> ability;

        if (ability == "Fireball" && currentMana >= 20)
        {
            MagDmg = baseMagDmg + (baseMagDmg*0.15);
            currentMana = currentMana - 20;
            abilityType = "Fire";
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
        }
        else if (ability == "Splash" && currentMana >= 20)
        {
            MagDmg = baseMagDmg + (baseMagDmg*0.15);
            currentMana = currentMana - 20;
            abilityType = "Water";
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
        }
        else if (ability == "Spark" && currentMana >= 20)
        {
            MagDmg = baseMagDmg + (baseMagDmg*0.15);
            currentMana = currentMana - 20;
            abilityType = "Lightning";
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
        }
        else if (ability == "Gust" && currentMana >= 20)
        {
            MagDmg = baseMagDmg + (baseMagDmg*0.15);
            currentMana = currentMana - 20;
            abilityType = "Wind";
            validAbility = true;
            moveUsed = ability;
            usingAnAttack = true;
        }
        else if (ability == "Heal" && currentMana >= 25)
        {
            enemyAttacked = 0;
            MagDmg = baseMagDmg + (baseMagDmg*0.10);

            while (healedHero == false)
            {
                if (isWarrAlive == true && isArchAlive == true)
                {
                    cout << "Who do you wish to heal? (warrior, archer, or mage)" << endl;
                    cin >> healHero;

                    if (healHero == "warrior")
                    {
                        amtHealedWarr = MagDmg;
                        healedWarr = true;
                        healedHero = true;
                        moveUsed = ability + " on (Warrior)" + allyWarrior_M.warName;
                        break;
                    }
                    else if (healHero == "archer")
                    {
                        amtHealedArch = MagDmg;
                        healedArch = true;
                        healedHero = true;
                        moveUsed = ability + " on (Archer)" + allyArcher_M.archName;
                        break;
                    }
                    else if (healHero == "mage")
                    {
                        currentHealth = currentHealth + MagDmg;
                        if (currentHealth > maxHealth)
                            currentHealth = maxHealth;
                        amtHealedMage = MagDmg;
                        healedMage = true;
                        healedHero = true;
                        moveUsed = ability;
                        break;
                    }
                    else
                        cout << "Sorry, but that hero doesn't exist" << endl;
                }

                if (isWarrAlive == true && isArchAlive == false)
                {
                    cout << "Who do you wish to heal? (warrior or mage)" << endl;
                    cin >> healHero;

                    if (healHero == "warrior")
                    {
                        amtHealedWarr = MagDmg;
                        healedWarr = true;
                        healedHero = true;
                        moveUsed = ability + " on (Warrior)" + allyWarrior_M.warName;
                        break;
                    }
                    else if (healHero == "mage")
                    {
                        currentHealth = currentHealth + MagDmg;
                        if (currentHealth > maxHealth)
                            currentHealth = maxHealth;
                        amtHealedMage = MagDmg;
                        healedMage = true;
                        healedHero = true;
                        moveUsed = ability;
                        break;
                    }
                    else
                        cout << "Sorry, but that hero doesn't exist" << endl;
                }

                if (isArchAlive == true && isWarrAlive == false)
                {
                    cout << "Who do you wish to heal? (archer or mage)" << endl;
                    cin >> healHero;

                    if (healHero == "archer")
                    {
                        amtHealedArch = MagDmg;
                        healedArch = true;
                        healedHero = true;
                        moveUsed = ability + " on (Archer)" + allyArcher_M.archName;
                        break;
                    }
                    else if (healHero == "mage")
                    {
                        currentHealth = currentHealth + MagDmg;
                        if (currentHealth > maxHealth)
                            currentHealth = maxHealth;
                        amtHealedMage = MagDmg;
                        healedMage = true;
                        healedHero = true;
                        moveUsed = ability;
                        break;
                    }
                    else
                        cout << "Sorry, but that hero doesn't exist" << endl;
                }

                if (isArchAlive == false && isWarrAlive == false)
                {
                    cout << "Who do you wish to heal? (mage)" << endl;
                    cin >> healHero;

                    if (healHero == "mage")
                    {
                        currentHealth = currentHealth + MagDmg;
                        if (currentHealth > maxHealth)
                            currentHealth = maxHealth;
                        amtHealedMage = MagDmg;
                        healedMage = true;
                        healedHero = true;
                        moveUsed = ability;
                        break;
                    }
                    else
                        cout << "Sorry, but that hero doesn't exist" << endl;
                }
            }
            currentMana = currentMana - 25;
            validAbility = true;
            moveUsed = ability;
        }
        else if (ability == "Healmore" && currentMana >= 40)
        {
            enemyAttacked = -1;
            MagDmg = baseMagDmg + (baseMagDmg * 0.10);
            amtHealedWarr = MagDmg;
            healedWarr = true;
            amtHealedArch = MagDmg;
            healedArch = true;

            currentHealth = currentHealth + MagDmg;
            currentMana = currentMana - 40;
            validAbility = true;
            moveUsed = ability;
        }
        else if (ability == "Revive" && currentMana >= 40)
        {
            enemyAttacked = -2;
            MagDmg = baseMagDmg + (baseMagDmg*0.15);

            while (revivedHero == false)
            {
                if (isWarrAlive == false && isArchAlive == false)
                {
                    cout << "Who do you wish to revive? (warrior or archer)" << endl;
                    cin >> reviveHero;

                    if (reviveHero == "warrior")
                    {
                        revivedWarr = true;
                        revivedHero = true;
                        moveUsed = ability;
                    }
                    else if (reviveHero == "archer")
                    {
                        revivedArch = true;
                        revivedHero = true;
                        moveUsed = ability;
                    }
                    else
                        cout << "Sorry, but that hero doesn't exist" << endl;
                }
                else if (isWarrAlive == true && isArchAlive == false)
                {
                    cout << "Who do you wish to revive? (archer)" << endl;
                    cin >> reviveHero;

                    if (reviveHero == "archer")
                    {
                        revivedArch = true;
                        revivedHero = true;
                        moveUsed = ability;
                    }
                    else
                        cout << "Sorry, but that hero doesn't exist" << endl;
                }
                else if (isWarrAlive == false && isArchAlive == true)
                {
                    cout << "Who do you wish to revive? (warrior)" << endl;
                    cin >> reviveHero;

                    if (reviveHero == "warrior")
                    {
                        revivedWarr = true;
                        revivedHero = true;
                        moveUsed = ability;
                    }
                    else
                        cout << "Sorry, but that hero doesn't exist" << endl;
                }
                else if (isWarrAlive == true && isArchAlive == true)
                {
                    cout << "All heroes are alive (type any letter then Enter to go back to Abilities screen)" << endl;
                    cin >> reviveHero;
                    revivedHero = true;
                    callAbilities();
                }
            }
            currentMana = currentMana - 40;
            validAbility = true;
        }
        else if (ability == "ArcaneDevastation" && currentLimit == 100 && currentMana >= 50)
        {
            MagDmg = baseMagDmg + (baseMagDmg*2);
            currentMana = currentMana - 50;
            currentLimit = 0;
            validAbility = true;
            moveUsed = "Arcane Devastation";
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

void Mage::determineTypeEnemyAttacked(Skeleton Sk1, Skeleton Sk2, Skeleton Sk3)
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
    else if (abilityType == "Wind" && skeletonTarget.enemyType == "Lightning")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Wind" && skeletonTarget.enemyType == "Fire")
        MagDmg = MagDmg - (MagDmg * 0.20);
    else if (abilityType == "Lightning" && skeletonTarget.enemyType == "Earth")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Lightning" && skeletonTarget.enemyType == "Wind")
        MagDmg = MagDmg - (MagDmg * 0.20);
    else if (abilityType == "Water" && skeletonTarget.enemyType == "Fire")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Water" && skeletonTarget.enemyType == "Earth")
        MagDmg = MagDmg - (MagDmg * 0.20);
}

void Mage::determineTypeOfBahamut(Bahamut theBahamut)
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
    else if (abilityType == "Wind" && bahamutTarget.enemyType == "Lightning")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Wind" && bahamutTarget.enemyType == "Fire")
        MagDmg = MagDmg - (MagDmg * 0.20);
    else if (abilityType == "Lightning" && bahamutTarget.enemyType == "Earth")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Lightning" && bahamutTarget.enemyType == "Wind")
        MagDmg = MagDmg - (MagDmg * 0.20);
    else if (abilityType == "Water" && bahamutTarget.enemyType == "Fire")
        MagDmg = MagDmg + (MagDmg * 0.20);
    else if (abilityType == "Water" && bahamutTarget.enemyType == "Earth")
        MagDmg = MagDmg - (MagDmg * 0.20);
}

/** This is the setter and getter for the hero's name
*/

void Mage::setMageName(string name)
{
    mageName = name;
}

string Mage::getMageName()
{
    return mageName;
}

/** These methods are used after a stage to level up the
mage
* The mage's new stats are increased by number of levels gained times
a certain amount
*/

void Mage::levelUpHero()
{
    newLevel = level + numLevelsGained;
    newMaxHealth = maxHealth + numLevelsGained*12;
    newMaxMana = maxMana + numLevelsGained*14;
    newBaseAtkDmg = baseAtkDmg + numLevelsGained*2;
    newBaseMagDmg = baseMagDmg + numLevelsGained*15;
    newArmor = armor + numLevelsGained*4.8;
    newMagArmor = mag_armor + numLevelsGained*5;
}

void Mage::finishLevelUp()
{
    level = newLevel;
    maxHealth = newMaxHealth;
    currentHealth = maxHealth;
    maxMana = newMaxMana;
    currentMana = newMaxMana;
    baseAtkDmg = newBaseAtkDmg;
    baseMagDmg = newBaseMagDmg;
    armor = newArmor;
    mag_armor = newMagArmor;
}
