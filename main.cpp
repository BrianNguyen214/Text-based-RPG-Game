// Author: Brian Nguyen
// Recitation: 201 Arcadia Zhang
//
// Assignment 8

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Heroes.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "Enemies.h"
#include "Slime.h"
#include "Skeleton.h"
#include "The_Bahamut.h"

using namespace std;

/**
* This the main file for my project
* To start off, I included several functions to that perform various functions, such as a function that
calculates the amount of damage the hero does to an enemy and some that create the Battle Stats screen
* The function that determines the net battle of the hero damage simply takes two parameters, the hero's damage
and the enemy's armor, and the net battle damage is the difference between the two
* The display functions were perhaps the most challenging aspect of my project
* I created unique displays for each of the three stages of my game, and the main essence of
how I created them is that I compared the number characters of the current line of a certain stat/name to
the number of characters of another "basis" line of the same stat/name
* For instances, if the current health stat line had more characters than the basis health stat line,
then I would remove spaces equal to the difference of the number of characters in the current stat line with the
number of characters in the basis stat line from the current stat line so that the box shape of
the screen is kept the same
* I used this logic to create the other displays and other stats
* Moreover, I incorporated these displays to give the user a representation of how
the game is progressing, making the game more understandable as it is a text
based RPG
*/

int heroNetBattleDamage(int HeroDmg, int EnemyArmor)
{
    int netDmg = HeroDmg - EnemyArmor;
    return netDmg;
}

int enemyNetBattleDamage(int EnemyDmg, int HeroArmor, Archer HeroArch)
{
    if (HeroArch.barrierBuffOn == false)
    {
        int netDmg = EnemyDmg - HeroArmor;
        return netDmg;
    }
    if (HeroArch.barrierBuffOn == true)
    {
        int netDmg = EnemyDmg - (HeroArmor+(HeroArmor*0.75));
        return netDmg;
    }
}

void displayBattleStatsStage1(Warrior Warr, Mage Mag, Archer Arch, Slime slime1, Slime slime2, Slime slime3)
{
    if (Warr.currentHealth <= 0)
        Warr.currentHealth = 0;
    if (Mag.currentHealth <= 0)
        Mag.currentHealth = 0;
    if (Arch.currentHealth <= 0)
        Arch.currentHealth = 0;

    if (Warr.currentHealth > Warr.maxHealth)
        Warr.currentHealth = Warr.maxHealth;
    if (Mag.currentHealth > Mag.maxHealth)
        Mag.currentHealth = Mag.maxHealth;
    if (Arch.currentHealth > Arch.maxHealth)
        Arch.currentHealth = Arch.maxHealth;

    if (Warr.currentLimit > Warr.maxLimit)
        Warr.currentLimit = Warr.maxLimit;
    if (Mag.currentLimit > Mag.maxLimit)
        Mag.currentLimit = Mag.maxLimit;
    if (Arch.currentLimit > Arch.maxLimit)
        Arch.currentLimit = Arch.maxLimit;

    std::stringstream wmh, wch, mmh, mch, amh, ach;

    int missingChar;

    /** Hero Health Lines */

    int WMH = Warr.maxHealth;
    int WCH = Warr.currentHealth;
    int MMH = Mag.maxHealth;
    int MCH = Mag.currentHealth;
    int AMH = Arch.maxHealth;
    int ACH = Arch.currentHealth;

    wmh << WMH;
    wch << WCH;
    mmh << MMH;
    mch << MCH;
    amh << AMH;
    ach << ACH;

    string spacesWHL = "     ";
    string maxWarrHealthLine = wmh.str() + "/" + wmh.str() + spacesWHL;
    string currWarrHealthLine = wch.str() + "/" + wmh.str() + spacesWHL;
    int maxWHL_length = (int)maxWarrHealthLine.length();
    int currWHL_length = (int)currWarrHealthLine.length();
    if (currWHL_length < maxWHL_length)
    {
        missingChar = maxWHL_length - currWHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrHealthLine = currWarrHealthLine + " ";
        }
    }
    string spacesMHL = "     ";
    string maxMageHealthLine = mmh.str() + "/" + mmh.str() + spacesMHL;
    string currMageHealthLine = mch.str() + "/" + mmh.str() + spacesMHL;
    int maxMHL_length = (int)maxMageHealthLine.length();
    int currMHL_length = (int)currMageHealthLine.length();
    if (currMHL_length < maxMHL_length)
    {
        missingChar = maxMHL_length - currMHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageHealthLine = currMageHealthLine + " ";
        }
    }
    string spacesAHL = "   ";
    string maxArchHealthLine = amh.str() + "/" + amh.str() + spacesAHL;
    string currArchHealthLine = ach.str() + "/" + amh.str() + spacesAHL;
    int maxAHL_length = (int)maxArchHealthLine.length();
    int currAHL_length = (int)currArchHealthLine.length();
    if (currAHL_length < maxAHL_length)
    {
        missingChar = maxAHL_length - currAHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchHealthLine = currArchHealthLine + " ";
        }
    }

    std::stringstream wmm, wcm, mmm, mcm, amm, acm;

    /** Hero Mana Lines */

    int WMM = Warr.maxMana;
    int WCM = Warr.currentMana;
    int MMM = Mag.maxMana;
    int MCM = Mag.currentMana;
    int AMM = Arch.maxMana;
    int ACM = Arch.currentMana;

    wmm << WMM;
    wcm << WCM;
    mmm << MMM;
    mcm << MCM;
    amm << AMM;
    acm << ACM;

    string spacesWML = "       ";
    string maxWarrManaLine = wmm.str() + "/" + wmm.str() + spacesWML;
    string currWarrManaLine = wcm.str() + "/" + wmm.str() + spacesWML;
    int maxWML_length = (int)maxWarrManaLine.length();
    int currWML_length = (int)currWarrManaLine.length();
    if (currWML_length < maxWML_length)
    {
        missingChar = maxWML_length - currWML_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrManaLine = currWarrManaLine + " ";
        }
    }
    string spacesMML = "       ";
    string maxMageManaLine = mmm.str() + "/" + mmm.str() + spacesMML;
    string currMageManaLine = mcm.str() + "/" + mmm.str() + spacesMML;
    int maxMML_length = (int)maxMageManaLine.length();
    int currMML_length = (int)currMageManaLine.length();
    if (currMML_length < maxMML_length)
    {
        missingChar = maxMML_length - currMML_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageManaLine = currMageManaLine + " ";
        }
    }
    string spacesAML = "     ";
    string maxArchManaLine = amm.str() + "/" + amm.str() + spacesAML;
    string currArchManaLine = acm.str() + "/" + amm.str() + spacesAML;
    int maxAML_length = (int)maxArchManaLine.length();
    int currAML_length = (int)currArchManaLine.length();
    if (currAML_length < maxAML_length)
    {
        missingChar = maxAML_length - currAML_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchManaLine = currArchManaLine + " ";
        }
    }

    std::stringstream wmil, wmal, wcl, mmil, mmal, mcl, amil, amal, acl;
    int extraChar;

    /** Hero Limit Lines */

    int WMiL = Warr.minLimit;
    int WMaL = Warr.maxLimit;
    int WCL = Warr.currentLimit;
    int MMiL = Mag.minLimit;
    int MMaL = Mag.maxLimit;
    int MCL = Mag.currentLimit;
    int AMiL = Arch.minLimit;
    int AMaL = Arch.maxLimit;
    int ACL = Arch.currentLimit;

    wmil << WMiL;
    wmal << WMaL;
    wcl << WCL;
    mmil << MMiL;
    mmal << MMaL;
    mcl << MCL;
    amil << AMiL;
    amal << AMaL;
    acl << ACL;

    string spacesWLL = "        ";
    string minWarrLimitLine = wmil.str() + "/" + wmal.str() + spacesWLL;
    string currWarrLimitLine = wcl.str() + "/" + wmal.str() + spacesWLL;
    int minWLL_length = (int)minWarrLimitLine.length();
    int currWLL_length = (int)currWarrLimitLine.length();
    if (currWLL_length > minWLL_length)
    {
        extraChar = currWLL_length - minWLL_length;
        for (int i = 0; i < extraChar; i++)
        {
            currWarrLimitLine = currWarrLimitLine.replace(currWarrLimitLine.length()-1,1,"");
        }
    }

    string spacesMLL = "        ";
    string minMageLimitLine = mmil.str() + "/" + mmal.str() + spacesMLL;
    string currMageLimitLine = mcl.str() + "/" + mmal.str() + spacesMLL;
    int minMLL_length = (int)minMageLimitLine.length();
    int currMLL_length = (int)currMageLimitLine.length();
    if (currMLL_length > minMLL_length)
    {
        extraChar = currMLL_length - minMLL_length;
        for (int i = 0; i < extraChar; i++)
        {
            currMageLimitLine = currMageLimitLine.replace(currMageLimitLine.length()-1,1,"");
        }
    }

    string spacesALL = "      ";
    string minArchLimitLine = amil.str() + "/" + amal.str() + spacesALL;
    string currArchLimitLine = acl.str() + "/" + amal.str() + spacesALL;
    int minALL_length = (int)minArchLimitLine.length();
    int currALL_length = (int)currArchLimitLine.length();
    if (currALL_length > minALL_length)
    {
        extraChar = currALL_length - minALL_length;
        for (int i = 0; i < extraChar; i++)
        {
            currArchLimitLine = currArchLimitLine.replace(currArchLimitLine.length()-1,1,"");
        }
    }

    std::stringstream s1mh, s1ch, s2mh, s2ch, s3mh, s3ch;

    /** Enemy Health */

    int S1MH = slime1.maxHealth;
    int S1CH = slime1.currentHealth;
    int S2MH = slime2.maxHealth;
    int S2CH = slime2.currentHealth;
    int S3MH = slime3.maxHealth;
    int S3CH = slime3.currentHealth;

    s1mh << S1MH;
    s1ch << S1CH;
    s2mh << S2MH;
    s2ch << S2CH;
    s3mh << S3MH;
    s3ch << S3CH;

    string S1HL = "     ";
    string maxS1HealthLine = s1mh.str() + "/" + s1mh.str() + S1HL;
    string currS1HealthLine = s1ch.str() + "/" + s1mh.str() + S1HL;
    int maxS1HL_length = (int)maxS1HealthLine.length();
    int currS1HL_length = (int)currS1HealthLine.length();
    if (currS1HL_length < maxS1HL_length)
    {
        missingChar = maxS1HL_length - currS1HL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currS1HealthLine = currS1HealthLine + " ";
        }
    }
    string S2HL = "     ";
    string maxS2HealthLine = s2mh.str() + "/" + s2mh.str() + S2HL;
    string currS2HealthLine = s2ch.str() + "/" + s2mh.str() + S2HL;
    int maxS2HL_length = (int)maxS2HealthLine.length();
    int currS2HL_length = (int)currS2HealthLine.length();
    if (currS2HL_length < maxS2HL_length)
    {
        missingChar = maxS2HL_length - currS2HL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currS2HealthLine = currS2HealthLine + " ";
        }
    }
    string S3HL = "   ";
    string maxS3HealthLine = s3mh.str() + "/" + s3mh.str() + S3HL;
    string currS3HealthLine = s3ch.str() + "/" + s3mh.str() + S3HL;
    int maxS3HL_length = (int)maxS3HealthLine.length();
    int currS3HL_length = (int)currS3HealthLine.length();
    if (currS3HL_length < maxS3HL_length)
    {
        missingChar = maxS3HL_length - currS3HL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currS3HealthLine = currS3HealthLine + " ";
        }
    }

    std::stringstream bt;

    /** Barrier */
    int BT = Arch.barrierBuffTurns;

    bt << BT;

    string barrierLine;
    if (Arch.barrierBuffOn == false)
        barrierLine = "||                                                           ||";
    if (Arch.barrierBuffOn == true)
        barrierLine = "|| **Barrier Activated** (Turns Left: " + bt.str() + ")                     ||";

    /** Warrior Name */

    string WarNameLine;
    if (Warr.enrageBuffOn == false)
    {
        WarNameLine = Warr.defaultWarName + "             ";
    }
    if (Warr.enrageBuffOn == true)
    {
        WarNameLine = Warr.tempWarName + "     ";
    }

    cout << " _____________________________________________________________" << endl;
    cout << "[________________________Battle Stats:________________________]" << endl;
    cout <<  barrierLine << endl;
    cout << "|| " << WarNameLine << "Mage                Archer            ||" << endl;
    cout << "|| Health: " << currWarrHealthLine
         << "Health: " << currMageHealthLine
         << "Health: " << currArchHealthLine << "||" << endl;
    cout << "|| Mana: " << currWarrManaLine
         << "Mana: " << currMageManaLine
         << "Mana: " << currArchManaLine << "||" << endl;
    cout << "|| Limit: " << currWarrLimitLine
         << "Limit: " << currMageLimitLine
         << "Limit: " << currArchLimitLine << "||" << endl;
    cout << "||                                                           ||" << endl;
    cout << "|| Slime               Slime               Slime             ||" << endl;
    cout << "|| Health: " << currS1HealthLine
         << "Health: " << currS2HealthLine
         << "Health: " << currS3HealthLine << "||" << endl;
    cout << "||___________________________________________________________||" << endl;
    cout << "[_____________________________________________________________]" << endl;
    cout << endl;
}

void displayBattleStatsStage2(Warrior Warr, Mage Mag, Archer Arch, Skeleton skeleton1, Skeleton skeleton2, Skeleton skeleton3)
{
    if (Warr.currentHealth <= 0)
        Warr.currentHealth = 0;
    if (Mag.currentHealth <= 0)
        Mag.currentHealth = 0;
    if (Arch.currentHealth <= 0)
        Arch.currentHealth = 0;

    if (Warr.currentHealth > Warr.maxHealth)
        Warr.currentHealth = Warr.maxHealth;
    if (Mag.currentHealth > Mag.maxHealth)
        Mag.currentHealth = Mag.maxHealth;
    if (Arch.currentHealth > Arch.maxHealth)
        Arch.currentHealth = Arch.maxHealth;

    if (Warr.currentLimit > Warr.maxLimit)
        Warr.currentLimit = Warr.maxLimit;
    if (Mag.currentLimit > Mag.maxLimit)
        Mag.currentLimit = Mag.maxLimit;
    if (Arch.currentLimit > Arch.maxLimit)
        Arch.currentLimit = Arch.maxLimit;

    std::stringstream wmh, wch, mmh, mch, amh, ach;

    int missingChar;

    /** Hero Health Lines */

    int WMH = Warr.maxHealth;
    int WCH = Warr.currentHealth;
    int MMH = Mag.maxHealth;
    int MCH = Mag.currentHealth;
    int AMH = Arch.maxHealth;
    int ACH = Arch.currentHealth;

    wmh << WMH;
    wch << WCH;
    mmh << MMH;
    mch << MCH;
    amh << AMH;
    ach << ACH;

    string spacesWHL = "     ";
    string maxWarrHealthLine = wmh.str() + "/" + wmh.str() + spacesWHL;
    string currWarrHealthLine = wch.str() + "/" + wmh.str() + spacesWHL;
    int maxWHL_length = (int)maxWarrHealthLine.length();
    int currWHL_length = (int)currWarrHealthLine.length();
    if (currWHL_length < maxWHL_length)
    {
        missingChar = maxWHL_length - currWHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrHealthLine = currWarrHealthLine + " ";
        }
    }
    string spacesMHL = "     ";
    string maxMageHealthLine = mmh.str() + "/" + mmh.str() + spacesMHL;
    string currMageHealthLine = mch.str() + "/" + mmh.str() + spacesMHL;
    int maxMHL_length = (int)maxMageHealthLine.length();
    int currMHL_length = (int)currMageHealthLine.length();
    if (currMHL_length < maxMHL_length)
    {
        missingChar = maxMHL_length - currMHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageHealthLine = currMageHealthLine + " ";
        }
    }
    string spacesAHL = "      ";
    string maxArchHealthLine = amh.str() + "/" + amh.str() + spacesAHL;
    string currArchHealthLine = ach.str() + "/" + amh.str() + spacesAHL;
    int maxAHL_length = (int)maxArchHealthLine.length();
    int currAHL_length = (int)currArchHealthLine.length();
    if (currAHL_length < maxAHL_length)
    {
        missingChar = maxAHL_length - currAHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchHealthLine = currArchHealthLine + " ";
        }
    }

    std::stringstream wmm, wcm, mmm, mcm, amm, acm;

    /** Hero Mana Lines */

    int WMM = Warr.maxMana;
    int WCM = Warr.currentMana;
    int MMM = Mag.maxMana;
    int MCM = Mag.currentMana;
    int AMM = Arch.maxMana;
    int ACM = Arch.currentMana;

    wmm << WMM;
    wcm << WCM;
    mmm << MMM;
    mcm << MCM;
    amm << AMM;
    acm << ACM;

    string spacesWML = "       ";
    string maxWarrManaLine = wmm.str() + "/" + wmm.str() + spacesWML;
    string currWarrManaLine = wcm.str() + "/" + wmm.str() + spacesWML;
    int maxWML_length = (int)maxWarrManaLine.length();
    int currWML_length = (int)currWarrManaLine.length();
    if (currWML_length < maxWML_length)
    {
        missingChar = maxWML_length - currWML_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrManaLine = currWarrManaLine + " ";
        }
    }
    string spacesMML = "       ";
    string maxMageManaLine = mmm.str() + "/" + mmm.str() + spacesMML;
    string currMageManaLine = mcm.str() + "/" + mmm.str() + spacesMML;
    int maxMML_length = (int)maxMageManaLine.length();
    int currMML_length = (int)currMageManaLine.length();
    if (currMML_length < maxMML_length)
    {
        missingChar = maxMML_length - currMML_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageManaLine = currMageManaLine + " ";
        }
    }
    string spacesAML = "        ";
    string maxArchManaLine = amm.str() + "/" + amm.str() + spacesAML;
    string currArchManaLine = acm.str() + "/" + amm.str() + spacesAML;
    int maxAML_length = (int)maxArchManaLine.length();
    int currAML_length = (int)currArchManaLine.length();
    if (currAML_length < maxAML_length)
    {
        missingChar = maxAML_length - currAML_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchManaLine = currArchManaLine + " ";
        }
    }

    std::stringstream wmil, wmal, wcl, mmil, mmal, mcl, amil, amal, acl;
    int extraChar;

    /** Hero Limit Lines */

    int WMiL = Warr.minLimit;
    int WMaL = Warr.maxLimit;
    int WCL = Warr.currentLimit;
    int MMiL = Mag.minLimit;
    int MMaL = Mag.maxLimit;
    int MCL = Mag.currentLimit;
    int AMiL = Arch.minLimit;
    int AMaL = Arch.maxLimit;
    int ACL = Arch.currentLimit;

    wmil << WMiL;
    wmal << WMaL;
    wcl << WCL;
    mmil << MMiL;
    mmal << MMaL;
    mcl << MCL;
    amil << AMiL;
    amal << AMaL;
    acl << ACL;

    string spacesWLL = "        ";
    string minWarrLimitLine = wmil.str() + "/" + wmal.str() + spacesWLL;
    string currWarrLimitLine = wcl.str() + "/" + wmal.str() + spacesWLL;
    int minWLL_length = (int)minWarrLimitLine.length();
    int currWLL_length = (int)currWarrLimitLine.length();
    if (currWLL_length > minWLL_length)
    {
        extraChar = currWLL_length - minWLL_length;
        for (int i = 0; i < extraChar; i++)
        {
            currWarrLimitLine = currWarrLimitLine.replace(currWarrLimitLine.length()-1,1,"");
        }
    }

    string spacesMLL = "        ";
    string minMageLimitLine = mmil.str() + "/" + mmal.str() + spacesMLL;
    string currMageLimitLine = mcl.str() + "/" + mmal.str() + spacesMLL;
    int minMLL_length = (int)minMageLimitLine.length();
    int currMLL_length = (int)currMageLimitLine.length();
    if (currMLL_length > minMLL_length)
    {
        extraChar = currMLL_length - minMLL_length;
        for (int i = 0; i < extraChar; i++)
        {
            currMageLimitLine = currMageLimitLine.replace(currMageLimitLine.length()-1,1,"");
        }
    }

    string spacesALL = "         ";
    string minArchLimitLine = amil.str() + "/" + amal.str() + spacesALL;
    string currArchLimitLine = acl.str() + "/" + amal.str() + spacesALL;
    int minALL_length = (int)minArchLimitLine.length();
    int currALL_length = (int)currArchLimitLine.length();
    if (currALL_length > minALL_length)
    {
        extraChar = currALL_length - minALL_length;
        for (int i = 0; i < extraChar; i++)
        {
            currArchLimitLine = currArchLimitLine.replace(currArchLimitLine.length()-1,1,"");
        }
    }

    /** Warrior Name */

    string WarNameLine;
    if (Warr.enrageBuffOn == false)
    {
        WarNameLine = Warr.defaultWarName + "             ";
    }
    if (Warr.enrageBuffOn == true)
    {
        WarNameLine = Warr.tempWarName + "     ";
    }

    /** Enemy Names */

    string spacesSk1 = "  ";
    string maxSk1NameLine = "Lightning " + skeleton1.skeletonDefaultName + spacesSk1;
    string currSk1NameLine = skeleton1.skeletonName + spacesSk1;
    int maxSk1NL_length = (int)maxSk1NameLine.length();
    int currSk1NL_length = (int)currSk1NameLine.length();
    if (currSk1NL_length < maxSk1NL_length)
    {
        missingChar = maxSk1NL_length - currSk1NL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currSk1NameLine = currSk1NameLine + " ";
        }
    }

    string spacesSk2 = "  ";
    string maxSk2NameLine = "Lightning " + skeleton2.skeletonDefaultName + spacesSk2;
    string currSk2NameLine = skeleton2.skeletonName + spacesSk2;
    int maxSk2NL_length = (int)maxSk2NameLine.length();
    int currSk2NL_length = (int)currSk2NameLine.length();
    if (currSk2NL_length < maxSk2NL_length)
    {
        missingChar = maxSk2NL_length - currSk2NL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currSk2NameLine = currSk2NameLine + " ";
        }
    }

    string spacesSk3 = "   ";
    string maxSk3NameLine = "Lightning " + skeleton3.skeletonDefaultName + spacesSk3;
    string currSk3NameLine = skeleton3.skeletonName + spacesSk3;
    int maxSk3NL_length = (int)maxSk3NameLine.length();
    int currSk3NL_length = (int)currSk3NameLine.length();
    if (currSk3NL_length < maxSk3NL_length)
    {
        missingChar = maxSk3NL_length - currSk3NL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currSk3NameLine = currSk3NameLine + " ";
        }
    }

    std::stringstream s1mh, s1ch, s2mh, s2ch, s3mh, s3ch;

    /** Enemy Health */

    int S1MH = skeleton1.maxHealth;
    int S1CH = skeleton1.currentHealth;
    int S2MH = skeleton2.maxHealth;
    int S2CH = skeleton2.currentHealth;
    int S3MH = skeleton3.maxHealth;
    int S3CH = skeleton3.currentHealth;

    s1mh << S1MH;
    s1ch << S1CH;
    s2mh << S2MH;
    s2ch << S2CH;
    s3mh << S3MH;
    s3ch << S3CH;

    string S1HL = "     ";
    string maxS1HealthLine = s1mh.str() + "/" + s1mh.str() + S1HL;
    string currS1HealthLine = s1ch.str() + "/" + s1mh.str() + S1HL;
    int maxS1HL_length = (int)maxS1HealthLine.length();
    int currS1HL_length = (int)currS1HealthLine.length();
    if (currS1HL_length < maxS1HL_length)
    {
        missingChar = maxS1HL_length - currS1HL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currS1HealthLine = currS1HealthLine + " ";
        }
    }
    string S2HL = "     ";
    string maxS2HealthLine = s2mh.str() + "/" + s2mh.str() + S2HL;
    string currS2HealthLine = s2ch.str() + "/" + s2mh.str() + S2HL;
    int maxS2HL_length = (int)maxS2HealthLine.length();
    int currS2HL_length = (int)currS2HealthLine.length();
    if (currS2HL_length < maxS2HL_length)
    {
        missingChar = maxS2HL_length - currS2HL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currS2HealthLine = currS2HealthLine + " ";
        }
    }
    string S3HL = "      ";
    string maxS3HealthLine = s3mh.str() + "/" + s3mh.str() + S3HL;
    string currS3HealthLine = s3ch.str() + "/" + s3mh.str() + S3HL;
    int maxS3HL_length = (int)maxS3HealthLine.length();
    int currS3HL_length = (int)currS3HealthLine.length();
    if (currS3HL_length < maxS3HL_length)
    {
        missingChar = maxS3HL_length - currS3HL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currS3HealthLine = currS3HealthLine + " ";
        }
    }

    std::stringstream bt;

    /** Barrier */
    int BT = Arch.barrierBuffTurns;

    bt << BT;

    string barrierLine;
    if (Arch.barrierBuffOn == false)
        barrierLine = "||                                                           ||";
    if (Arch.barrierBuffOn == true)
        barrierLine = "|| **Barrier Activated** (Turns Left: " + bt.str() + ")                     ||";

    cout << " ________________________________________________________________" << endl;
    cout << "[_________________________Battle Stats:__________________________]" << endl;
    cout << barrierLine << endl;
    cout << "|| " << WarNameLine << "Mage                Archer               ||" << endl;
    cout << "|| Health: " << currWarrHealthLine
         << "Health: " << currMageHealthLine
         << "Health: " << currArchHealthLine << "||" << endl;
    cout << "|| Mana: " << currWarrManaLine
         << "Mana: " << currMageManaLine
         << "Mana: " << currArchManaLine << "||" << endl;
    cout << "|| Limit: " << currWarrLimitLine
         << "Limit: " << currMageLimitLine
         << "Limit: " << currArchLimitLine << "||" << endl;
    cout << "||                                                              ||" << endl;
    cout << "|| " << currSk1NameLine
         << currSk2NameLine
         << currSk3NameLine << "||" << endl;
    cout << "|| Health: " << currS1HealthLine
         << "Health: " << currS2HealthLine
         << "Health: " << currS3HealthLine << "||" << endl;
    cout << "||______________________________________________________________||" << endl;
    cout << "[________________________________________________________________]" << endl;
    cout << endl;
}

void displayBattleStatsStage3(Warrior Warr, Mage Mag, Archer Arch, Bahamut theBahamut)
{
    if (Warr.currentHealth <= 0)
        Warr.currentHealth = 0;
    if (Mag.currentHealth <= 0)
        Mag.currentHealth = 0;
    if (Arch.currentHealth <= 0)
        Arch.currentHealth = 0;

    if (Warr.currentHealth > Warr.maxHealth)
        Warr.currentHealth = Warr.maxHealth;
    if (Mag.currentHealth > Mag.maxHealth)
        Mag.currentHealth = Mag.maxHealth;
    if (Arch.currentHealth > Arch.maxHealth)
        Arch.currentHealth = Arch.maxHealth;

    if (Warr.currentLimit > Warr.maxLimit)
        Warr.currentLimit = Warr.maxLimit;
    if (Mag.currentLimit > Mag.maxLimit)
        Mag.currentLimit = Mag.maxLimit;
    if (Arch.currentLimit > Arch.maxLimit)
        Arch.currentLimit = Arch.maxLimit;

    std::stringstream wmh, wch, mmh, mch, amh, ach;

    int missingChar;

    /** Hero Health Lines */

    int WMH = Warr.maxHealth;
    int WCH = Warr.currentHealth;
    int MMH = Mag.maxHealth;
    int MCH = Mag.currentHealth;
    int AMH = Arch.maxHealth;
    int ACH = Arch.currentHealth;

    wmh << WMH;
    wch << WCH;
    mmh << MMH;
    mch << MCH;
    amh << AMH;
    ach << ACH;

    string spacesWHL = "     ";
    string maxWarrHealthLine = wmh.str() + "/" + wmh.str() + spacesWHL;
    string currWarrHealthLine = wch.str() + "/" + wmh.str() + spacesWHL;
    int maxWHL_length = (int)maxWarrHealthLine.length();
    int currWHL_length = (int)currWarrHealthLine.length();
    if (currWHL_length < maxWHL_length)
    {
        missingChar = maxWHL_length - currWHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrHealthLine = currWarrHealthLine + " ";
        }
    }
    string spacesMHL = "     ";
    string maxMageHealthLine = mmh.str() + "/" + mmh.str() + spacesMHL;
    string currMageHealthLine = mch.str() + "/" + mmh.str() + spacesMHL;
    int maxMHL_length = (int)maxMageHealthLine.length();
    int currMHL_length = (int)currMageHealthLine.length();
    if (currMHL_length < maxMHL_length)
    {
        missingChar = maxMHL_length - currMHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageHealthLine = currMageHealthLine + " ";
        }
    }
    string spacesAHL = "   ";
    string maxArchHealthLine = amh.str() + "/" + amh.str() + spacesAHL;
    string currArchHealthLine = ach.str() + "/" + amh.str() + spacesAHL;
    int maxAHL_length = (int)maxArchHealthLine.length();
    int currAHL_length = (int)currArchHealthLine.length();
    if (currAHL_length < maxAHL_length)
    {
        missingChar = maxAHL_length - currAHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchHealthLine = currArchHealthLine + " ";
        }
    }

    std::stringstream wmm, wcm, mmm, mcm, amm, acm;

    /** Hero Mana Lines */

    int WMM = Warr.maxMana;
    int WCM = Warr.currentMana;
    int MMM = Mag.maxMana;
    int MCM = Mag.currentMana;
    int AMM = Arch.maxMana;
    int ACM = Arch.currentMana;

    wmm << WMM;
    wcm << WCM;
    mmm << MMM;
    mcm << MCM;
    amm << AMM;
    acm << ACM;

    string spacesWML = "       ";
    string maxWarrManaLine = wmm.str() + "/" + wmm.str() + spacesWML;
    string currWarrManaLine = wcm.str() + "/" + wmm.str() + spacesWML;
    int maxWML_length = (int)maxWarrManaLine.length();
    int currWML_length = (int)currWarrManaLine.length();
    if (currWML_length < maxWML_length)
    {
        missingChar = maxWML_length - currWML_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrManaLine = currWarrManaLine + " ";
        }
    }
    string spacesMML = "       ";
    string maxMageManaLine = mmm.str() + "/" + mmm.str() + spacesMML;
    string currMageManaLine = mcm.str() + "/" + mmm.str() + spacesMML;
    int maxMML_length = (int)maxMageManaLine.length();
    int currMML_length = (int)currMageManaLine.length();
    if (currMML_length < maxMML_length)
    {
        missingChar = maxMML_length - currMML_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageManaLine = currMageManaLine + " ";
        }
    }
    string spacesAML = "     ";
    string maxArchManaLine = amm.str() + "/" + amm.str() + spacesAML;
    string currArchManaLine = acm.str() + "/" + amm.str() + spacesAML;
    int maxAML_length = (int)maxArchManaLine.length();
    int currAML_length = (int)currArchManaLine.length();
    if (currAML_length < maxAML_length)
    {
        missingChar = maxAML_length - currAML_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchManaLine = currArchManaLine + " ";
        }
    }

    std::stringstream wmil, wmal, wcl, mmil, mmal, mcl, amil, amal, acl;
    int extraChar;

    /** Hero Limit Lines */

    int WMiL = Warr.minLimit;
    int WMaL = Warr.maxLimit;
    int WCL = Warr.currentLimit;
    int MMiL = Mag.minLimit;
    int MMaL = Mag.maxLimit;
    int MCL = Mag.currentLimit;
    int AMiL = Arch.minLimit;
    int AMaL = Arch.maxLimit;
    int ACL = Arch.currentLimit;

    wmil << WMiL;
    wmal << WMaL;
    wcl << WCL;
    mmil << MMiL;
    mmal << MMaL;
    mcl << MCL;
    amil << AMiL;
    amal << AMaL;
    acl << ACL;

    string spacesWLL = "        ";
    string minWarrLimitLine = wmil.str() + "/" + wmal.str() + spacesWLL;
    string currWarrLimitLine = wcl.str() + "/" + wmal.str() + spacesWLL;
    int minWLL_length = (int)minWarrLimitLine.length();
    int currWLL_length = (int)currWarrLimitLine.length();
    if (currWLL_length > minWLL_length)
    {
        extraChar = currWLL_length - minWLL_length;
        for (int i = 0; i < extraChar; i++)
        {
            currWarrLimitLine = currWarrLimitLine.replace(currWarrLimitLine.length()-1,1,"");
        }
    }

    string spacesMLL = "        ";
    string minMageLimitLine = mmil.str() + "/" + mmal.str() + spacesMLL;
    string currMageLimitLine = mcl.str() + "/" + mmal.str() + spacesMLL;
    int minMLL_length = (int)minMageLimitLine.length();
    int currMLL_length = (int)currMageLimitLine.length();
    if (currMLL_length > minMLL_length)
    {
        extraChar = currMLL_length - minMLL_length;
        for (int i = 0; i < extraChar; i++)
        {
            currMageLimitLine = currMageLimitLine.replace(currMageLimitLine.length()-1,1,"");
        }
    }

    string spacesALL = "      ";
    string minArchLimitLine = amil.str() + "/" + amal.str() + spacesALL;
    string currArchLimitLine = acl.str() + "/" + amal.str() + spacesALL;
    int minALL_length = (int)minArchLimitLine.length();
    int currALL_length = (int)currArchLimitLine.length();
    if (currALL_length > minALL_length)
    {
        extraChar = currALL_length - minALL_length;
        for (int i = 0; i < extraChar; i++)
        {
            currArchLimitLine = currArchLimitLine.replace(currArchLimitLine.length()-1,1,"");
        }
    }

    /**Bahamut Type */

    string spacesBTL = "                                                    ";
    string noTypeBTypeLine = spacesBTL;
    string withTypeBTypeLine = theBahamut.enemyType + spacesBTL;
    int noTypeBTL_length = (int)noTypeBTypeLine.length();
    int withTypeBTL_length = (int)withTypeBTypeLine.length();
    if (withTypeBTL_length > noTypeBTL_length)
    {
        missingChar = withTypeBTL_length - noTypeBTL_length;
        for (int i = 0; i < missingChar; i++)
        {
             withTypeBTypeLine = withTypeBTypeLine.replace(withTypeBTypeLine.length()-1,1,"");
        }
    }

    std::stringstream bmh, bch;

    /**Bahamut Health */

    int BMH = theBahamut.maxHealth;
    int BCH = theBahamut.currentHealth;

    bmh << BMH;
    bch << BCH;

    string spacesBHL = "                                         ";
    string maxBHealthLine = bmh.str() + "/" + bmh.str() + spacesBHL;
    string currBHealthLine = bch.str() + "/" + bmh.str() + spacesBHL;
    int maxBHL_length = (int)maxBHealthLine.length();
    int currBHL_length = (int)currBHealthLine.length();
    if (currBHL_length < maxBHL_length)
    {
        missingChar = maxBHL_length - currBHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currBHealthLine = currBHealthLine + " ";
        }
    }

    std::stringstream bt;

    /** Barrier */
    int BT = Arch.barrierBuffTurns;

    bt << BT;

    string barrierLine;
    if (Arch.barrierBuffOn == false)
        barrierLine = "||                                                           ||";
    if (Arch.barrierBuffOn == true)
        barrierLine = "|| **Barrier Activated** (Turns Left: " + bt.str() + ")                     ||";

    /** Warrior Name */

    string WarNameLine;
    if (Warr.enrageBuffOn == false)
    {
        WarNameLine = Warr.defaultWarName + "             ";
    }
    if (Warr.enrageBuffOn == true)
    {
        WarNameLine = Warr.tempWarName + "     ";
    }

    cout << " _____________________________________________________________" << endl;
    cout << "[________________________Battle Stats:________________________]" << endl;
    cout <<  barrierLine << endl;
    cout << "|| " << WarNameLine << "Mage                Archer            ||" << endl;
    cout << "|| Health: " << currWarrHealthLine
         << "Health: " << currMageHealthLine
         << "Health: " << currArchHealthLine << "||" << endl;
    cout << "|| Mana: " << currWarrManaLine
         << "Mana: " << currMageManaLine
         << "Mana: " << currArchManaLine << "||" << endl;
    cout << "|| Limit: " << currWarrLimitLine
         << "Limit: " << currMageLimitLine
         << "Limit: " << currArchLimitLine << "||" << endl;
    cout << "||                                                           ||" << endl;
    cout << "|| The Bahamut                                               ||" << endl;
    cout << "|| Type: " << withTypeBTypeLine << "||" << endl;
    cout << "|| Health: " << currBHealthLine << "||" << endl;
    cout << "||___________________________________________________________||" << endl;
    cout << "[_____________________________________________________________]" << endl;
    cout << endl;
}

void displayLevelUpScreen(Warrior Warr, Mage Mag, Archer Arch)
{
    int missingChar;

    std::stringstream wl, wnl, ml, mnl, al, anl;

    /** Hero Level Lines */

    int WL = Warr.level;
    int WNL = Warr.newLevel;
    int ML = Mag.level;
    int MNL = Mag.newLevel;
    int AL = Arch.level;
    int ANL = Arch.newLevel;

    wl << WL;
    wnl << WNL;
    ml << ML;
    mnl << MNL;
    al << AL;
    anl << ANL;

    string spacesWLvlL = "         ";
    string minWarrLevelLine = std::string("1") + " -> " + "0" + spacesWLvlL;
    string currWarrLevelLine = wl.str() + " -> " + wnl.str() + spacesWLvlL;
    int minWLvlL_length = (int)minWarrLevelLine.length();
    int currWLvlL_length = (int)currWarrLevelLine.length();
    if (currWLvlL_length > minWLvlL_length)
    {
        missingChar = currWLvlL_length - minWLvlL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrLevelLine = currWarrLevelLine.replace(currWarrLevelLine.length()-1,1,"");
        }
    }
    string spacesMLvlL = "         ";
    string minMageLevelLine = std::string("1") + " -> " + "0" + spacesMLvlL;
    string currMageLevelLine = ml.str() + " -> " + mnl.str() + spacesMLvlL;
    int minMLvlL_length = (int)minMageLevelLine.length();
    int currMLvlL_length = (int)currMageLevelLine.length();
    if (currMLvlL_length > minMLvlL_length)
    {
        missingChar = currMLvlL_length - minMLvlL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageLevelLine = currMageLevelLine.replace(currMageLevelLine.length()-1,1,"");
        }
    }
    string spacesALvlL = "            ";
    string minArchLevelLine = std::string("1") + " -> " + "0" + spacesALvlL;
    string currArchLevelLine = al.str() + " -> " + anl.str() + spacesALvlL;
    int minALvlL_length = (int)minArchLevelLine.length();
    int currALvlL_length = (int)currArchLevelLine.length();
    if (currALvlL_length > minALvlL_length)
    {
        missingChar = currALvlL_length - minALvlL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchLevelLine = currArchLevelLine.replace(currArchLevelLine.length()-1,1,"");
        }
    }

    std::stringstream wmh, wnmh, mmh, mnmh, amh, anmh;

    /** Hero Leveled Health Lines */

    int WMH = Warr.maxHealth;
    int WNMH = Warr.newMaxHealth;
    int MMH = Mag.maxHealth;
    int MNMH = Mag.newMaxHealth;
    int AMH = Arch.maxHealth;
    int ANMH = Arch.newMaxHealth;

    wmh << WMH;
    wnmh << WNMH;
    mmh << MMH;
    mnmh << MNMH;
    amh << AMH;
    anmh << ANMH;

    string spacesWMHL = "       ";
    string minWarrMHLine = std::string("350") + " -> " + "0" + spacesWMHL;
    string currWarrMHLine = wmh.str() + " -> " + wnmh.str() + spacesWMHL;
    int minWMHL_length = (int)minWarrMHLine.length();
    int currWMHL_length = (int)currWarrMHLine.length();
    if (currWMHL_length > minWMHL_length)
    {
        missingChar = currWMHL_length - minWMHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrMHLine = currWarrMHLine.replace(currWarrMHLine.length()-1,1,"");
        }
    }
    string spacesMMHL = "       ";
    string minMageMHLine = std::string("250") + " -> " + "0" + spacesMMHL;
    string currMageMHLine = mmh.str() + " -> " + mnmh.str() + spacesMMHL;
    int minMMHL_length = (int)minMageMHLine.length();
    int currMMHL_length = (int)currMageMHLine.length();
    if (currMMHL_length > minMMHL_length)
    {
        missingChar = currMMHL_length - minMMHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageMHLine = currMageMHLine.replace(currMageMHLine.length()-1,1,"");
        }
    }
    string spacesAMHL = "          ";
    string minArchMHLine = std::string("250") + " -> " + "0" + spacesAMHL;
    string currArchMHLine = amh.str() + " -> " + anmh.str() + spacesAMHL;
    int minAMHL_length = (int)minArchMHLine.length();
    int currAMHL_length = (int)currArchMHLine.length();
    if (currAMHL_length > minAMHL_length)
    {
        missingChar = currAMHL_length - minAMHL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchMHLine = currArchMHLine.replace(currArchMHLine.length()-1,1,"");
        }
    }

    std::stringstream wmm, wnmm, mmm, mnmm, amm, anmm;

    /** Hero Leveled Mana Lines */

    int WMM = Warr.maxMana;
    int WNMM = Warr.newMaxMana;
    int MMM = Mag.maxMana;
    int MNMM = Mag.newMaxMana;
    int AMM = Arch.maxMana;
    int ANMM = Arch.newMaxMana;

    wmm << WMM;
    wnmm << WNMM;
    mmm << MMM;
    mnmm << MNMM;
    amm << AMM;
    anmm << ANMM;

    string spacesWMML = "       ";
    string minWarrMMLine = std::string("100") + " -> " + "0" + spacesWMML;
    string currWarrMMLine = wmm.str() + " -> " + wnmm.str() + spacesWMML;
    int minWMML_length = (int)minWarrMMLine.length();
    int currWMML_length = (int)currWarrMMLine.length();
    if (currWMML_length > minWMML_length)
    {
        missingChar = currWMML_length - minWMML_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrMMLine = currWarrMMLine.replace(currWarrMMLine.length()-1,1,"");
        }
    }
    string spacesMMML = "       ";
    string minMageMMLine = std::string("150") + " -> " + "0" + spacesMMML;
    string currMageMMLine = mmm.str() + " -> " + mnmm.str() + spacesMMML;
    int minMMML_length = (int)minMageMMLine.length();
    int currMMML_length = (int)currMageMMLine.length();
    if (currMMML_length > minMMML_length)
    {
        missingChar = currMMML_length - minMMML_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageMMLine = currMageMMLine.replace(currMageMMLine.length()-1,1,"");
        }
    }
    string spacesAMML = "          ";
    string minArchMMLine = std::string("125") + " -> " + "0" + spacesAMML;
    string currArchMMLine = amm.str() + " -> " + anmm.str() + spacesAMML;
    int minAMML_length = (int)minArchMMLine.length();
    int currAMML_length = (int)currArchMMLine.length();
    if (currAMML_length > minAMML_length)
    {
        missingChar = currAMML_length - minAMML_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchMMLine = currArchMMLine.replace(currArchMMLine.length()-1,1,"");
        }
    }

    std::stringstream wbad, wnbad, mbad, mnbad, abad, anbad;

    /** Hero Leveled Base AD Lines */

    int WBAD = Warr.baseAtkDmg;
    int WNBAD = Warr.newBaseAtkDmg;
    int MBAD = Mag.baseAtkDmg;
    int MNBAD = Mag.newBaseAtkDmg;
    int ABAD = Arch.baseAtkDmg;
    int ANBAD = Arch.newBaseAtkDmg;

    wbad << WBAD;
    wnbad << WNBAD;
    mbad << MBAD;
    mnbad << MNBAD;
    abad << ABAD;
    anbad << ANBAD;

    string spacesWBADL = "        ";
    string minWarrBADLine = std::string("95") + " -> " + "0" + spacesWBADL;
    string currWarrBADLine = wbad.str() + " -> " + wnbad.str() + spacesWBADL;
    int minWBADL_length = (int)minWarrBADLine.length();
    int currWBADL_length = (int)currWarrBADLine.length();
    if (currWBADL_length > minWBADL_length)
    {
        missingChar = currWBADL_length - minWBADL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrBADLine = currWarrBADLine.replace(currWarrBADLine.length()-1,1,"");
        }
    }
    string spacesMBADL = "        ";
    string minMageBADLine = std::string("15") + " -> " + "0" + spacesMBADL;
    string currMageBADLine = mbad.str() + " -> " + mnbad.str() + spacesMBADL;
    int minMBADL_length = (int)minMageBADLine.length();
    int currMBADL_length = (int)currMageBADLine.length();
    if (currMBADL_length > minMBADL_length)
    {
        missingChar = currMBADL_length - minMBADL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageBADLine = currMageBADLine.replace(currMageBADLine.length()-1,1,"");
        }
    }
    string spacesABADL = "           ";
    string minArchBADLine = std::string("15") + " -> " + "0" + spacesABADL;
    string currArchBADLine = abad.str() + " -> " + anbad.str() + spacesABADL;
    int minABADL_length = (int)minArchBADLine.length();
    int currABADL_length = (int)currArchBADLine.length();
    if (currABADL_length > minABADL_length)
    {
        missingChar = currABADL_length - minABADL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchBADLine = currArchBADLine.replace(currArchBADLine.length()-1,1,"");
        }
    }

    std::stringstream wbmd, wnbmd, mbmd, mnbmd, abmd, anbmd;

    /** Hero Leveled Base MD Lines */

    int WBMD = Warr.baseMagDmg;
    int WNBMD = Warr.newBaseMagDmg;
    int MBMD = Mag.baseMagDmg;
    int MNBMD = Mag.newBaseMagDmg;
    int ABMD = Arch.baseMagDmg;
    int ANBMD = Arch.newBaseMagDmg;

    wbmd << WBMD;
    wnbmd << WNBMD;
    mbmd << MBMD;
    mnbmd << MNBMD;
    abmd << ABMD;
    anbmd << ANBMD;

    string spacesWBMDL = "        ";
    string minWarrBMDLine = std::string("15") + " -> " + "0" + spacesWBMDL;
    string currWarrBMDLine = wbmd.str() + " -> " + wnbmd.str() + spacesWBMDL;
    int minWBMDL_length = (int)minWarrBMDLine.length();
    int currWBMDL_length = (int)currWarrBMDLine.length();
    if (currWBMDL_length > minWBMDL_length)
    {
        missingChar = currWBMDL_length - minWBMDL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrBMDLine = currWarrBMDLine.replace(currWarrBMDLine.length()-1,1,"");
        }
    }
    string spacesMBMDL = "        ";
    string minMageBMDLine = std::string("95") + " -> " + "0" + spacesMBMDL;
    string currMageBMDLine = mbmd.str() + " -> " + mnbmd.str() + spacesMBMDL;
    int minMBMDL_length = (int)minMageBMDLine.length();
    int currMBMDL_length = (int)currMageBMDLine.length();
    if (currMBMDL_length > minMBMDL_length)
    {
        missingChar = currMBMDL_length - minMBMDL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageBMDLine = currMageBMDLine.replace(currMageBMDLine.length()-1,1,"");
        }
    }
    string spacesABMDL = "           ";
    string minArchBMDLine = std::string("75") + " -> " + "0" + spacesABMDL;
    string currArchBMDLine = abmd.str() + " -> " + anbmd.str() + spacesABMDL;
    int minABMDL_length = (int)minArchBMDLine.length();
    int currABMDL_length = (int)currArchBMDLine.length();
    if (currABMDL_length > minABMDL_length)
    {
        missingChar = currABMDL_length - minABMDL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchBMDLine = currArchBMDLine.replace(currArchBMDLine.length()-1,1,"");
        }
    }

    std::stringstream wa, wna, ma, mna, aa, ana;

    /** Hero Leveled Armor Lines */

    int WA = Warr.armor;
    int WNA = Warr.newArmor;
    int MA = Mag.armor;
    int MNA = Mag.newArmor;
    int AA = Arch.armor;
    int ANA = Arch.armor;

    wa << WA;
    wna << WNA;
    ma << MA;
    mna << MNA;
    aa << AA;
    ana << ANA;

    string spacesWAL = "        ";
    string minWarrALine = std::string("60") + " -> " + "0" + spacesWAL;
    string currWarrALine = wa.str() + " -> " + wna.str() + spacesWAL;
    int minWAL_length = (int)minWarrALine.length();
    int currWAL_length = (int)currWarrALine.length();
    if (currWAL_length > minWAL_length)
    {
        missingChar = currWAL_length - minWAL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrALine = currWarrALine.replace(currWarrALine.length()-1,1,"");
        }
    }
    string spacesMAL = "        ";
    string minMageALine = std::string("40") + " -> " + "0" + spacesMAL;
    string currMageALine = ma.str() + " -> " + mna.str() + spacesMAL;
    int minMAL_length = (int)minMageALine.length();
    int currMAL_length = (int)currMageALine.length();
    if (currMAL_length > minMAL_length)
    {
        missingChar = currMAL_length - minMAL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageALine = currMageALine.replace(currMageALine.length()-1,1,"");
        }
    }
    string spacesAAL = "           ";
    string minArchALine = std::string("45") + " -> " + "0" + spacesAAL;
    string currArchALine = aa.str() + " -> " + ana.str() + spacesAAL;
    int minAAL_length = (int)minArchALine.length();
    int currAAL_length = (int)currArchALine.length();
    if (currAAL_length > minAAL_length)
    {
        missingChar = currAAL_length - minAAL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchALine = currArchALine.replace(currArchALine.length()-1,1,"");
        }
    }

    std::stringstream wma, wnma, mma, mnma, ama, anma;

    /** Hero Leveled Magic Armor Lines */

    int WMA = Warr.mag_armor;
    int WNMA = Warr.newMagArmor;
    int MMA = Mag.mag_armor;
    int MNMA = Mag.newMagArmor;
    int AMA = Arch.mag_armor;
    int ANMA = Arch.newMagArmor;

    wma << WMA;
    wnma << WNMA;
    mma << MMA;
    mnma << MNMA;
    ama << AMA;
    anma << ANMA;

    string spacesWMAL = "        ";
    string minWarrMALine = std::string("55") + " -> " + "0" + spacesWMAL;
    string currWarrMALine = wma.str() + " -> " + wnma.str() + spacesWMAL;
    int minWMAL_length = (int)minWarrMALine.length();
    int currWMAL_length = (int)currWarrMALine.length();
    if (currWMAL_length > minWMAL_length)
    {
        missingChar = currWMAL_length - minWMAL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currWarrMALine = currWarrMALine.replace(currWarrMALine.length()-1,1,"");
        }
    }
    string spacesMMAL = "        ";
    string minMageMALine = std::string("35") + " -> " + "0" + spacesMMAL;
    string currMageMALine = mma.str() + " -> " + mnma.str() + spacesMMAL;
    int minMMAL_length = (int)minMageMALine.length();
    int currMMAL_length = (int)currMageMALine.length();
    if (currMMAL_length > minMMAL_length)
    {
        missingChar = currMMAL_length - minMMAL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currMageMALine = currMageMALine.replace(currMageMALine.length()-1,1,"");
        }
    }
    string spacesAMAL = "           ";
    string minArchMALine = std::string("55") + " -> " + "0" + spacesAMAL;
    string currArchMALine = ama.str() + " -> " + anma.str() + spacesAMAL;
    int minAMAL_length = (int)minArchMALine.length();
    int currAMAL_length = (int)currArchMALine.length();
    if (currAMAL_length > minAMAL_length)
    {
        missingChar = currAMAL_length - minAMAL_length;
        for (int i = 0; i < missingChar; i++)
        {
            currArchMALine = currArchMALine.replace(currArchMALine.length()-1,1,"");
        }
    }

    cout << " _______________________________________________________________" << endl;
    cout << "[__________________________Level_Up:____________________________]" << endl;
    cout << "||             Warrior        Mage           Archer            ||" << endl;
    cout << "|| Level:      " << currWarrLevelLine
         << currMageLevelLine
         << currArchLevelLine << "||" << endl;
    cout << "|| MaxHealth:  " << currWarrMHLine
         << currMageMHLine
         << currArchMHLine << "||" << endl;
    cout << "|| MaxMana:    " << currWarrMMLine
         << currMageMMLine
         << currArchMMLine << "||" << endl;
    cout << "|| BaseAtkDmg: " << currWarrBADLine
         << currMageBADLine
         << currArchBADLine << "||" << endl;
    cout << "|| BaseMagDmg: " << currWarrBMDLine
         << currMageBMDLine
         << currArchBMDLine << "||" << endl;
    cout << "|| Armor:      " << currWarrALine
         << currMageALine
         << currArchALine << "||" << endl;
    cout << "|| MagArmor:   " << currWarrMALine
         << currMageMALine
         << currArchMALine << "||" << endl;
    cout << "||_____________________________________________________________||" << endl;
    cout << "[_______________________________________________________________]" << endl;
    cout << endl;
}

/**
* These are other functions I used in my project as well
* I used the split function to split the data from the Save Progress
file that I outputted key data to, such as the username, number of stages
the user completed, and the number of lines of dialogue the user read through
already
* I created a function just for saving because I thought that it would help
keep the program more organized and I also reuse the function at
a few places in the game
*/

void split(string sent, string words[], string data[], char sep, int index)
{
    int i = 0;
    int begin = 0;
    int end = 0;
    while (i < (int)sent.length())
    {
        if (sent[i] == sep)
        {
            begin = end;
            words[index] = sent.substr(begin, i - begin);
            end = i + 1;
        }
        i++;
    }

    begin = end;
    data[index] = sent.substr(begin, i - begin);
}

void askUserToSave(string userName, Heroes userHeroes, Warrior userWarrior, Mage userMage, Archer userArcher)
{
    ofstream SaveProgress;
    string save;
    bool confirmSave = false;

    while (confirmSave == false)
    {
        cout << "Do you wish to save your progress? (yes or no)" << endl;
        cin >> save;

        if (save == "yes")
        {
            SaveProgress.open("A8 Save Progress");
            SaveProgress << "UserName: " << userName << endl;
            SaveProgress << "WarrName: " << userWarrior.warName << endl;
            SaveProgress << "MageName: " << userMage.mageName << endl;
            SaveProgress << "ArchName: " << userArcher.archName << endl;
            SaveProgress << "NumberOfStageCompleted: " << userHeroes.numStagesCompleted << endl;
            SaveProgress << "LevelOfHeroes: " << userWarrior.level << endl;
            SaveProgress << "TotalNumberOfLevelsGained: " << userWarrior.totalNumLevelsGained << endl;
            SaveProgress << "NumberOfLinesDialogue: " << userHeroes.numLinesDialogue << endl;
            confirmSave = true;
            cout << "Progress has been saved and you may exit the game" << endl;
            break;
        }
        else if (save == "no")
        {
            cout << "Are you sure you do not want to save? (yes or no)" << endl;
            cin >> save;
            if (save == "yes")
            {
                confirmSave = true;
                break;
            }
        }
        else
        {
            cout << "Not a valid answer" << endl;
        }
    }
}

/**
* The beginning of the main function lays the ground work
for the game
* Besides declaring key variables and opening files; it also checks
if there is a saved file
* If there is a saved file, the data from the A8 Save Progress file is
read and parsed, and that data is used to restore current stats of the heroes and
progression of the user
* Based on how many stages the user completed, the user resume the game
at a certain location (either starting from the beginning of the game or
after a save location)
*/

int main()
{
    ifstream Dialogue;
    ifstream SavedProgress;

    string continueDialogue;
    int numLinesOfDialogueCompleted = 0;

    Dialogue.open("A8 Dialogue");
    SavedProgress.open("A8 Save Progress");

    string line;
    string words[8];
    string data[8];
    string listen;
    string userName;
    string WarrName;
    string MageName;
    string ArchName;

    Warrior userWarrior;
    Mage userMage;
    Archer userArcher;

    Heroes userHeroes(userWarrior, userMage, userArcher);

    userHeroes.setWarrior(userWarrior);
    userHeroes.setMage(userMage);
    userHeroes.setArcher(userArcher);

    userWarrior.setAllies(userMage, userArcher);
    userMage.setAllies(userWarrior, userArcher);
    userArcher.setAllies(userWarrior, userMage);

    for (int i = 0; i < 8; i++)
    {
        words[i];
        data[i];
        getline(SavedProgress, line);
        split(line, words, data, ' ', i);
    }

    if (words[0] == "UserName:")
    {
        userName = data[0];
        WarrName = data[1];
        MageName = data[2];
        ArchName = data[3];
        userWarrior.setWarName(WarrName);
        userMage.setMageName(MageName);
        userArcher.setArchName(ArchName);

        userHeroes.numStagesCompleted = stoi(data[4]);
        userHeroes.numLinesDialogue = stoi(data[7]);
        /*
        userWarrior.level = stoi(data[5]);
        userMage.level = stoi(data[5]);
        userArcher.level = stoi(data[5]);
        */
        userWarrior.totalNumLevelsGained = stoi(data[6]);
        userMage.totalNumLevelsGained = stoi(data[6]);
        userArcher.totalNumLevelsGained = stoi(data[6]);

        userWarrior.numLevelsGained = userWarrior.totalNumLevelsGained;
        userMage.numLevelsGained = userMage.totalNumLevelsGained;
        userArcher.numLevelsGained = userArcher.totalNumLevelsGained;

        userWarrior.levelUpHero();
        userMage.levelUpHero();
        userArcher.levelUpHero();

        userWarrior.finishLevelUp();
        userMage.finishLevelUp();
        userArcher.finishLevelUp();

        //cout << "Warrior level " << userWarrior.level << endl;

        for (int i = 0; i < userHeroes.numLinesDialogue; i++)
        {
            getline(Dialogue, line);
            numLinesOfDialogueCompleted++;
        }
    }

    Enemies userEnemies;
    /*
    for (int i = 0; i < 7; i++)
    {
        cout << words[i] << endl;
    }

    for (int i = 0; i < 7; i++)
    {
        cout << data[i] << endl;
    }
    */

    int questionTimes = 0;
    bool stageCompleted = true;

    /*
            userHeroes.numStagesCompleted = 1;
            userWarrior.numLevelsGained = 3;
            userMage.numLevelsGained = 3;
            userArcher.numLevelsGained = 3;
            userWarrior.levelUpHero();
            userMage.levelUpHero();
            userArcher.levelUpHero();

    displayLevelUpScreen(userWarrior, userMage, userArcher);
    */

/**
* If this is the first time the user opens the game (or the user forgot to save
their game at a save location), the user is asked for their username
and the names of the heroes
* Besides this, there is an optional background story that the user
may read to know more about the (made-up) "lore" of game
*/

    if (userHeroes.numStagesCompleted == 0)
    {
        cout << "What is your name? (no spaces)" << endl;
        cin >> userName;

        while (listen != "yes" || listen != "no")
        {
            if (listen == "yes" || listen == "no")
            {
                break;
            }
            else if (questionTimes > 0)
            {
                cout << "Sorry, not a valid answer" << endl;
            }
            cout << userName << ", do you wish to listen the calamity of Puritania and the Bahamut?" << endl;
            cout << "(yes, or no)" << endl;
            cin >> listen;
            questionTimes++;
        }

        string continueStory = "f";
        if (listen == "yes")
        {
            cout << "Thank you. Here's the story" << endl;
            cout << "**                                                                          **" << endl;
            cout << "(Press the f letter then Enter to continue or the d letter then Enter to exit)" << endl;
            cout << "**                                                                          **" << endl;
            cout << endl;
            int x = 0;
            while (x < 14)
            {
                if (continueStory == "f")
                {
                    getline(Dialogue, line);

                    cout << line;
                    cin >> continueStory;
                    cout << endl;
                    x++;
                }
                else if (continueStory == "d")
                {
                    break;
                }
                else
                {
                    while (continueStory != "f" || continueStory != "d")
                    {
                        if (continueStory == "f" || continueStory == "d")
                            break;
                        if (continueStory != "f" || continueStory != "d")
                        {
                            cout << "Sorry, not a valid answer" << endl;
                            cin >> continueStory;
                        }
                    }
                }
            }
            for (int j = 0; j < 20; j++)
            {
                cout << endl;
            }

        }
        else if (listen == "no")
        {
            for (int i = 0; i < 14; i++)
            {
                getline(Dialogue, line);
            }
            cout << "Alright. Let's dive into the game." << endl;
        }

        numLinesOfDialogueCompleted = 14;

        cout << "Guide your heroes, defeat the Bahamut, and bring peace to Puritania once again." << endl;
        cout << "However, first you must name your heroes." << endl << endl;

        cout << "Name your warrior" << endl;
        cin >> WarrName;

        userWarrior.setWarName(WarrName);

        cout << "Name your mage" << endl;
        cin >> MageName;

        userMage.setMageName(MageName);

        cout << "Name your archer" << endl;
        cin >> ArchName;

        userArcher.setArchName(ArchName);

        userHeroes.setWarrior(userWarrior);
        userHeroes.setMage(userMage);
        userHeroes.setArcher(userArcher);

        userWarrior.setAllies(userMage, userArcher);
        userMage.setAllies(userWarrior, userArcher);
        userArcher.setAllies(userWarrior, userMage);

/** The game is designed to help the user figure out the mechanics
and tips of the game
* These tips come from a file called A8 Dialogue, which is dedicated
store most of the dialogue, and those lines are read at specific times
throughout the game
*/

        cout << endl;
        getline(Dialogue, line);
        getline(Dialogue, line);
        numLinesOfDialogueCompleted = numLinesOfDialogueCompleted + 2;
        cout << line << endl;
        cout << endl;
        cout << "**                        Attention                         **" << endl;
        cout << "**                 for the rest of the game                 **" << endl;
        cout << "** Press any letter then Enter to continue through dialogue **" << endl;
        cout << "**                                                          **" << endl << endl;

        for (int i = 0; i < 4; i++)
        {
            getline(Dialogue, line);
            cout << line;
            cin >> continueDialogue;
            numLinesOfDialogueCompleted++;
            cout << endl;
        }

        Slime slimeOne;
        Slime slimeTwo;
        Slime slimeThree;
        Enemies userEnemiesS1(slimeOne, slimeTwo, slimeThree);

        displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);

        for (int i = 0; i < 6; i++)
        {
            getline(Dialogue, line);
            cout << line;
            cin >> continueDialogue;
            numLinesOfDialogueCompleted++;
            cout << endl;
        }

        int dmgEnemyTakes = 0;
        int dmgHeroTakes = 0;
        int roundNum = 1;

/** This is the first stage of the game
* Basically, for every stage the heroes get their turn to make a decision, such as use a
regular attack or ability, to defeat the enemies
* Then the enemies likewise get their turn to try and defeat the heroes
* This process repeats until either the heroes successfully defeat all of the enemies or the
enemies defeat all of the heroes
*/

        /** Stage 1 */
        while (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) != false || userEnemiesS1.areEnemiesAlive(slimeOne, slimeTwo, slimeThree) != false)
        {
            if (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) == false || userEnemiesS1.areEnemiesAlive(slimeOne, slimeTwo, slimeThree) == false)
            {
                break;
            }

/** For the most part, every heroes' turn are very similar to each other
* The hero's battle menu is called where they may select to attack, use an
ability, or skip their turn
* Based on the ability they choose and the target of the hero,
the net battle damage is calculated
* Otherwise, if the ability doesn't inflict damage to an enemy, then the ability
will do as is stated based off of its description
* Then a brief description of the hero's action is stated and the
display of the stage is shown
*/
        userArcher.checkIfBarrierOn();

        // Warrior's Turn /
        if (userWarrior.isHeroAlive == true)
        {
            userWarrior.callBattleMenu();
            userWarrior.checkIfEnraged();
            if (userWarrior.enemyAttacked == 1)
            {
                dmgEnemyTakes = heroNetBattleDamage(userWarrior.baseAtkDmg, slimeOne.armor);
                slimeOne.currentHealth = slimeOne.currentHealth - dmgEnemyTakes;
                if (slimeOne.currentHealth <= 0)
                    slimeOne.currentHealth = 0;
                slimeOne.check_set_EnemyAlive();
                cout << userWarrior.warName << " used " << userWarrior.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if (userWarrior.enemyAttacked == 2)
            {
                dmgEnemyTakes = heroNetBattleDamage(userWarrior.baseAtkDmg, slimeTwo.armor);
                slimeTwo.currentHealth = slimeTwo.currentHealth - dmgEnemyTakes;
                if (slimeTwo.currentHealth <= 0)
                    slimeTwo.currentHealth = 0;
                slimeTwo.check_set_EnemyAlive();
                cout << userWarrior.warName << " used " << userWarrior.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if (userWarrior.enemyAttacked == 3)
            {
                dmgEnemyTakes = heroNetBattleDamage(userWarrior.baseAtkDmg, slimeThree.armor);
                slimeThree.currentHealth = slimeThree.currentHealth - dmgEnemyTakes;
                if (slimeThree.currentHealth <= 0)
                    slimeThree.currentHealth = 0;
                slimeThree.check_set_EnemyAlive();
                cout << userWarrior.warName << " used " << userWarrior.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if (userWarrior.enemyAttacked == 4)
            {
                cout << userWarrior.warName << " used " << userWarrior.moveUsed << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if(userWarrior.enemyAttacked == -5)
            {
                cout << userWarrior.warName << " used Skip Turn " << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }

            userWarrior.stablizeStats();
            if (userEnemiesS1.areEnemiesAlive(slimeOne, slimeTwo, slimeThree) == false)
            {
                cout << "The enemies have been vanquished" << endl;
                stageCompleted = true;
                break;
            }
        }

/** The stage will be immediately finished if during that hero's turn they finish off the
last enemy
*/

        // Mage's Turn /
        if (userMage.isHeroAlive == true)
        {
            userMage.callBattleMenu();
            if (userMage.enemyAttacked == 1)
            {
                dmgEnemyTakes = heroNetBattleDamage(userMage.baseMagDmg, slimeOne.mag_armor);
                slimeOne.currentHealth = slimeOne.currentHealth - dmgEnemyTakes;
                if (slimeOne.currentHealth <= 0)
                    slimeOne.currentHealth = 0;
                slimeOne.check_set_EnemyAlive();
                cout << userMage.mageName << " used " << userMage.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if (userMage.enemyAttacked == 2)
            {
                dmgEnemyTakes = heroNetBattleDamage(userMage.baseMagDmg, slimeTwo.mag_armor);
                slimeTwo.currentHealth = slimeTwo.currentHealth - dmgEnemyTakes;
                if (slimeTwo.currentHealth <= 0)
                    slimeTwo.currentHealth = 0;
                slimeTwo.check_set_EnemyAlive();
                cout << userMage.mageName << " used " << userMage.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if (userMage.enemyAttacked == 3)
            {
                dmgEnemyTakes = heroNetBattleDamage(userMage.baseMagDmg, slimeThree.mag_armor);
                slimeThree.currentHealth = slimeThree.currentHealth - dmgEnemyTakes;
                if (slimeThree.currentHealth <= 0)
                    slimeThree.currentHealth = 0;
                slimeThree.check_set_EnemyAlive();
                cout << userMage.mageName << " used " << userMage.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if (userMage.enemyAttacked == 0)
            {
                userWarrior.checkIfHealed(userMage);
                userArcher.checkIfHealed(userMage);

                if (userMage.healedWarr == true)
                {
                    cout << userMage.mageName << " used " << userMage.moveUsed << " on (Warrior) " << userWarrior.warName << " (+"
                         << userMage.amtHealedWarr << " hp)" << endl;
                }
                if (userMage.healedArch == true)
                {
                    cout << userMage.mageName << " used " << userMage.moveUsed << " on (Archer) " << userArcher.archName << " (+"
                         << userMage.amtHealedArch << " hp)" << endl;
                }
                if (userMage.healedMage == true)
                {
                    cout << userMage.mageName << " used " << userMage.moveUsed << " on herself (+"
                         << userMage.amtHealedMage << " hp)" << endl;
                }
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if (userMage.enemyAttacked == -1)
            {
                userWarrior.checkIfHealed(userMage);
                userArcher.checkIfHealed(userMage);

                cout << userMage.mageName << " used " << userMage.moveUsed << " (+"
                        << userMage.MagDmg << " hp to all)" << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if (userMage.enemyAttacked == -2)
            {
                userWarrior.checkIfRevived(userMage);
                userArcher.checkIfRevived(userMage);

                if (userMage.revivedWarr == true)
                {
                    cout << userMage.mageName << " used " << userMage.moveUsed << " on (Warrior) " << userWarrior.warName << " (+"
                         << userMage.MagDmg << " hp)" << endl;
                }
                if (userMage.revivedArch == true)
                {
                    cout << userMage.mageName << " used " << userMage.moveUsed << " on (Archer) " << userArcher.archName << " (+"
                         << userMage.MagDmg << " hp)" << endl;
                }
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if(userMage.enemyAttacked == -5)
            {
                cout << userMage.mageName << " used Skip Turn " << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }

            userMage.stablizeStats();
            if (userEnemiesS1.areEnemiesAlive(slimeOne, slimeTwo, slimeThree) == false)
            {
                cout << "The enemies have been vanquished" << endl;
                stageCompleted = true;
                break;
            }
        }

        // Archer's Turn /
        if (userArcher.isHeroAlive == true)
        {
            userArcher.callBattleMenu();
            if (userArcher.enemyAttacked == 1)
            {
                dmgEnemyTakes = heroNetBattleDamage(userArcher.baseAtkDmg, slimeOne.armor);
                slimeOne.currentHealth = slimeOne.currentHealth - dmgEnemyTakes;
                if (slimeOne.currentHealth <= 0)
                    slimeOne.currentHealth = 0;
                slimeOne.check_set_EnemyAlive();
                cout << userArcher.archName << " used " << userArcher.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if (userArcher.enemyAttacked == 2)
            {
                dmgEnemyTakes = heroNetBattleDamage(userArcher.baseAtkDmg, slimeTwo.armor);
                slimeTwo.currentHealth = slimeTwo.currentHealth - dmgEnemyTakes;
                if (slimeTwo.currentHealth <= 0)
                    slimeTwo.currentHealth = 0;
                slimeTwo.check_set_EnemyAlive();
                cout << userArcher.archName << " used " << userArcher.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if (userArcher.enemyAttacked == 3)
            {
                dmgEnemyTakes = heroNetBattleDamage(userArcher.baseAtkDmg, slimeThree.armor);
                slimeThree.currentHealth = slimeThree.currentHealth - dmgEnemyTakes;
                if (slimeThree.currentHealth <= 0)
                slimeThree.currentHealth = 0;
                slimeThree.check_set_EnemyAlive();
                cout << userArcher.archName << " used " << userArcher.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if (userArcher.enemyAttacked == -1)
            {
                cout << userArcher.archName << " used " << userArcher.moveUsed << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }
            else if(userArcher.enemyAttacked == -5)
            {
                cout << userArcher.archName << " used Skip Turn " << endl;
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
            }

            userArcher.stablizeStats();
            if (userEnemiesS1.areEnemiesAlive(slimeOne, slimeTwo, slimeThree) == false)
            {
                cout << "The enemies have been vanquished" << endl;
                stageCompleted = true;
                break;
            }

            if (roundNum == 1)
            {
                getline(Dialogue, line);
                cout << line;
                numLinesOfDialogueCompleted++;
                cin >> continueDialogue;
                cout << endl;
            }
        }

        userArcher.turnOffBarrier();
        cout << "Press any letter to end heroes' turn ";
        cin >> continueDialogue;
        cout << endl;

            slimeOne.turnsUsed = slimeTwo.turnsUsed = slimeThree.turnsUsed = 0;

/** The enemies' turns are very similar except that they will select a
random ability and a random target
* Of course, the enemy will always choose a target that is still currently
alive
*/
        // SlimeOne's Turn /
        if (slimeOne.isEnemyAlive == true)
        {
            cout << "Slime(1)'s Turn" << endl;
            slimeOne.callRandomAbility();
            slimeOne.selectRandomTarget(userWarrior, userMage, userArcher);
            if (slimeOne.targettedHero == 1)
            {
                dmgHeroTakes = enemyNetBattleDamage(slimeOne.AtkDmg, userWarrior.armor, userArcher);
                userWarrior.currentHealth = userWarrior.currentHealth - dmgHeroTakes;
                cout << slimeOne.slimeName << " used " << slimeOne.abilityUsed << " on (Warrior) " << userWarrior.warName
                     << " (" << dmgHeroTakes << " dmg)" << endl;
                userWarrior.currentLimit = userWarrior.currentLimit + (dmgHeroTakes * 0.5);
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
                slimeOne.turnsUsed = slimeTwo.turnsUsed = slimeThree.turnsUsed = 1;
            }
            else if (slimeOne.targettedHero == 2)
            {
                dmgHeroTakes = enemyNetBattleDamage(slimeOne.AtkDmg, userMage.armor, userArcher);
                userMage.currentHealth = userMage.currentHealth - dmgHeroTakes;
                cout << slimeOne.slimeName << " used " << slimeOne.abilityUsed << " on (Mage) " << userMage.mageName
                     << " (" << dmgHeroTakes << " dmg)" << endl;
                userMage.currentLimit = userMage.currentLimit + (dmgHeroTakes * 0.5);
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
                slimeOne.turnsUsed = slimeTwo.turnsUsed = slimeThree.turnsUsed = 1;
            }
            else if (slimeOne.targettedHero == 3)
            {
                dmgHeroTakes = enemyNetBattleDamage(slimeOne.AtkDmg, userArcher.armor, userArcher);
                userArcher.currentHealth = userArcher.currentHealth - dmgHeroTakes;
                cout << slimeOne.slimeName << " used " << slimeOne.abilityUsed << " on (Archer) " << userArcher.archName
                     << " (" << dmgHeroTakes << " dmg)" << endl;
                userArcher.currentLimit = userArcher.currentLimit + (dmgHeroTakes * 0.5);
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
                slimeOne.turnsUsed = slimeTwo.turnsUsed = slimeThree.turnsUsed = 1;
            }
        }

            if (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) == false)
            {
                cout << "Your heroes have been defeated" << endl;
                break;
            }

        // SlimeTwo's Turn /
        if (slimeTwo.isEnemyAlive == true)
        {
            cout << "Slime(2)'s Turn" << endl;
            slimeTwo.callRandomAbility();
            slimeTwo.selectRandomTarget(userWarrior, userMage, userArcher);
            if (slimeTwo.targettedHero == 1)
            {
                dmgHeroTakes = enemyNetBattleDamage(slimeTwo.AtkDmg, userWarrior.armor, userArcher);
                userWarrior.currentHealth = userWarrior.currentHealth - dmgHeroTakes;
                cout << slimeTwo.slimeName << " used " << slimeTwo.abilityUsed << " on (Warrior) " << userWarrior.warName
                     << " (" << dmgHeroTakes << " dmg)" << endl;
                userWarrior.currentLimit = userWarrior.currentLimit + (dmgHeroTakes * 0.5);
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
                slimeOne.turnsUsed = slimeTwo.turnsUsed = slimeThree.turnsUsed = 2;
            }
            else if (slimeTwo.targettedHero == 2)
            {
                dmgHeroTakes = enemyNetBattleDamage(slimeTwo.AtkDmg, userMage.armor, userArcher);
                userMage.currentHealth = userMage.currentHealth - dmgHeroTakes;
                cout << slimeTwo.slimeName << " used " << slimeTwo.abilityUsed << " on (Mage) " << userMage.mageName
                     << " (" << dmgHeroTakes << " dmg)" << endl;
                userMage.currentLimit = userMage.currentLimit + (dmgHeroTakes * 0.5);
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
                slimeOne.turnsUsed = slimeTwo.turnsUsed = slimeThree.turnsUsed = 2;
            }
            else if (slimeTwo.targettedHero == 3)
            {
                dmgHeroTakes = enemyNetBattleDamage(slimeTwo.AtkDmg, userArcher.armor, userArcher);
                userArcher.currentHealth = userArcher.currentHealth - dmgHeroTakes;
                cout << slimeTwo.slimeName << " used " << slimeTwo.abilityUsed << " on (Archer) " << userArcher.archName
                     << " (" << dmgHeroTakes << " dmg)" << endl;
                userArcher.currentLimit = userArcher.currentLimit + (dmgHeroTakes * 0.5);
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
                slimeOne.turnsUsed = slimeTwo.turnsUsed = slimeThree.turnsUsed = 2;
            }
        }

            if (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) == false)
            {
                cout << "Your heroes have been defeated" << endl;
                break;
            }

        // SlimeThree's Turn /
        if (slimeThree.isEnemyAlive == true)
        {
            cout << "Slime(3)'s Turn" << endl;
            slimeThree.callRandomAbility();
            slimeThree.selectRandomTarget(userWarrior, userMage, userArcher);
            if (slimeThree.targettedHero == 1)
            {
                dmgHeroTakes = enemyNetBattleDamage(slimeThree.AtkDmg, userWarrior.armor, userArcher);
                userWarrior.currentHealth = userWarrior.currentHealth - dmgHeroTakes;
                cout << slimeThree.slimeName << " used " << slimeThree.abilityUsed << " on (Warrior) " << userWarrior.warName
                     << " (" << dmgHeroTakes << " dmg)" << endl;
                userWarrior.currentLimit = userWarrior.currentLimit + (dmgHeroTakes * 0.5);
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
                slimeOne.turnsUsed = slimeTwo.turnsUsed = slimeThree.turnsUsed = 3;
            }
            else if (slimeThree.targettedHero == 2)
            {
                dmgHeroTakes = enemyNetBattleDamage(slimeThree.AtkDmg, userMage.armor, userArcher);
                userMage.currentHealth = userMage.currentHealth - dmgHeroTakes;
                cout << slimeThree.slimeName << " used " << slimeThree.abilityUsed << " on (Mage) " << userMage.mageName
                     << " (" << dmgHeroTakes << " dmg)" << endl;
                userMage.currentLimit = userMage.currentLimit + (dmgHeroTakes * 0.5);
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
                slimeOne.turnsUsed = slimeTwo.turnsUsed = slimeThree.turnsUsed = 3;
            }
            else if (slimeThree.targettedHero == 3)
            {
                dmgHeroTakes = enemyNetBattleDamage(slimeThree.AtkDmg, userArcher.armor, userArcher);
                userArcher.currentHealth = userArcher.currentHealth - dmgHeroTakes;
                cout << slimeThree.slimeName << " used " << slimeThree.abilityUsed << " on (Archer) " << userArcher.archName
                     << " (" << dmgHeroTakes << " dmg)" << endl;
                userArcher.currentLimit = userArcher.currentLimit + (dmgHeroTakes * 0.5);
                displayBattleStatsStage1(userWarrior, userMage, userArcher, slimeOne, slimeTwo, slimeThree);
                slimeOne.turnsUsed = slimeTwo.turnsUsed = slimeThree.turnsUsed = 3;
            }
        }

            if (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) == false)
            {
                cout << "Your heroes have been defeated" << endl;
                break;
            }

            if (roundNum == 1)
            {
                for (int i = 0; i < 2; i++)
                {
                    getline(Dialogue, line);
                    cout << line;
                    numLinesOfDialogueCompleted++;
                    cin >> continueDialogue;
                    cout << endl;
                }
            }

            cout << "Press any letter to end enemies' turn ";
            cin >> continueDialogue;
            cout << endl;

            roundNum++;
        }

/** After every stage completed successfully, the user's heroes are leveled up
* I set arbitrarily amounts of how much the heroes leveled up since I didn't
incorporate an experience, or EXP gaining system simply just a leveling up
system
* Leveling up a hero increases their stats, such as max health, attack damage, and armor, which in
turn makes them stronger
* I created a display to show by what amount each of the heroes' stats
increased
*/
        if (stageCompleted = true)
        {
            cout << "Great job, " << userName << " ";
            cin >> continueDialogue;

            userHeroes.numStagesCompleted = 1;
            userWarrior.numLevelsGained = 3;
            userMage.numLevelsGained = 3;
            userArcher.numLevelsGained = 3;

            userWarrior.totalNumLevelsGained = 3;
            userMage.totalNumLevelsGained = 3;
            userArcher.totalNumLevelsGained = 3;

            userWarrior.levelUpHero();
            userMage.levelUpHero();
            userArcher.levelUpHero();

            displayLevelUpScreen(userWarrior, userMage, userArcher);

            userWarrior.finishLevelUp();
            userMage.finishLevelUp();
            userArcher.finishLevelUp();

            for (int i = 0; i < 5; i++)
            {
                getline(Dialogue, line);
                cout << line;
                numLinesOfDialogueCompleted++;
                cin >> continueDialogue;
                cout << endl;
            }

            userHeroes.numLinesDialogue = numLinesOfDialogueCompleted;
            askUserToSave(userName, userHeroes, userWarrior, userMage, userArcher);
        }
    }

/** If there is a saved file, a message welcomes the
player back
*/

    else if (userHeroes.numStagesCompleted >= 1)
    {
        cout << "Welcome back, " << userName << endl;
        cout << "Let's continue this adventure" << endl;
        cout << "(Reminder: press any letter then Enter to continue)" << endl;
        cin >> continueDialogue;
    }

/** This is the beginning of stage 2, and it works very similarly to stage 1
* The real only main differences are that there are different enemies and I introduce the
user to the heroes' abilities and the type advantage/disadvantage system
* (Play the game to learn more about the type system)
*/
    if (userHeroes.numStagesCompleted == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            getline(Dialogue, line);
            cout << line;
            cin >> continueDialogue;
            numLinesOfDialogueCompleted++;
            cout << endl;
        }

        Skeleton skeletonOne;
        Skeleton skeletonTwo;
        Skeleton skeletonThree;

        skeletonOne.typesSet = 0;
        skeletonOne.setRandomType();
        skeletonTwo.typesSet = 1;
        skeletonTwo.setRandomType();
        skeletonThree.typesSet = 2;
        skeletonThree.setRandomType();
        Enemies userEnemiesS2(skeletonOne, skeletonTwo, skeletonThree);

        skeletonOne.setNameWithType();
        skeletonTwo.setNameWithType();
        skeletonThree.setNameWithType();

        displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);

        for (int i = 0; i < 10; i++)
        {
            getline(Dialogue, line);
            cout << line;
            cin >> continueDialogue;
            numLinesOfDialogueCompleted++;
            cout << endl;
        }

        userWarrior.currentLimit = 0;
        userMage.currentLimit = 0;
        userArcher.currentLimit = 0;
        int dmgEnemyTakes = 0;
        int dmgHeroTakes = 0;
        int roundNum = 1;
        stageCompleted = false;

        /** Stage 2 */
        while (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) != false || userEnemiesS2.areEnemiesAlive(skeletonOne, skeletonTwo, skeletonThree) != false)
        {
            if (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) == false || userEnemiesS2.areEnemiesAlive(skeletonOne, skeletonTwo, skeletonThree) == false)
            {
                break;
            }

            if (roundNum == 2)
            {
                for (int i = 0; i < 6; i++)
                {
                    getline(Dialogue, line);
                    cout << line;
                    numLinesOfDialogueCompleted++;
                    cin >> continueDialogue;
                    cout << endl;
                }
            }

            userArcher.checkIfBarrierOn();

            // Warrior's Turn /
            userWarrior.stablizeStats();
            userWarrior.checkIfRevived(userMage);
            if (userWarrior.isHeroAlive == true)
            {
                userWarrior.checkEnragedBeforeMenu();
                userWarrior.callBattleMenu();
                userWarrior.checkIfEnraged();

                userWarrior.determineTypeEnemyAttacked(skeletonOne, skeletonTwo, skeletonThree);

                if (userWarrior.enemyAttacked == 1)
                {
                    dmgEnemyTakes = heroNetBattleDamage(userWarrior.AtkDmg, skeletonOne.armor);
                    skeletonOne.currentHealth = skeletonOne.currentHealth - dmgEnemyTakes;
                    if (skeletonOne.currentHealth <= 0)
                        skeletonOne.currentHealth = 0;
                    skeletonOne.check_set_EnemyAlive();
                    cout << userWarrior.warName << " used " << userWarrior.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if (userWarrior.enemyAttacked == 2)
                {
                    dmgEnemyTakes = heroNetBattleDamage(userWarrior.AtkDmg, skeletonTwo.armor);
                    skeletonTwo.currentHealth = skeletonTwo.currentHealth - dmgEnemyTakes;
                    if (skeletonTwo.currentHealth <= 0)
                        skeletonTwo.currentHealth = 0;
                    skeletonTwo.check_set_EnemyAlive();
                    cout << userWarrior.warName << " used " << userWarrior.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if (userWarrior.enemyAttacked == 3)
                {
                    dmgEnemyTakes = heroNetBattleDamage(userWarrior.AtkDmg, skeletonThree.armor);
                    skeletonThree.currentHealth = skeletonThree.currentHealth - dmgEnemyTakes;
                    if (skeletonThree.currentHealth <= 0)
                        skeletonThree.currentHealth = 0;
                    skeletonThree.check_set_EnemyAlive();
                    cout << userWarrior.warName << " used " << userWarrior.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }

                else if (userWarrior.enemyAttacked == 4)
                {
                    cout << userWarrior.warName << " used " << userWarrior.moveUsed << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if(userWarrior.enemyAttacked == -5)
                {
                    cout << userWarrior.warName << " used Skip Turn " << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }

                userWarrior.stablizeStats();
                if (userEnemiesS2.areEnemiesAlive(skeletonOne, skeletonTwo, skeletonThree) == false)
                {
                    cout << "The enemies have been vanquished" << endl;
                    stageCompleted = true;
                    break;
                }
            }

            // Mage's Turn /
            userMage.stablizeStats();
            if (userMage.isHeroAlive == true)
            {
                userMage.checkIfAlliesAlive(userWarrior, userArcher);
                userMage.callBattleMenu();

                userMage.determineTypeEnemyAttacked(skeletonOne, skeletonTwo, skeletonThree);

                if (userMage.enemyAttacked == 1)
                {
                    dmgEnemyTakes = heroNetBattleDamage(userMage.MagDmg, skeletonOne.mag_armor);
                    skeletonOne.currentHealth = skeletonOne.currentHealth - dmgEnemyTakes;
                    if (skeletonOne.currentHealth <= 0)
                        skeletonOne.currentHealth = 0;
                    skeletonOne.check_set_EnemyAlive();
                    cout << userMage.mageName << " used " << userMage.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if (userMage.enemyAttacked == 2)
                {
                    dmgEnemyTakes = heroNetBattleDamage(userMage.MagDmg, skeletonTwo.mag_armor);
                    skeletonTwo.currentHealth = skeletonTwo.currentHealth - dmgEnemyTakes;
                    if (skeletonTwo.currentHealth <= 0)
                        skeletonTwo.currentHealth = 0;
                    skeletonTwo.check_set_EnemyAlive();
                    cout << userMage.mageName << " used " << userMage.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if (userMage.enemyAttacked == 3)
                {
                    dmgEnemyTakes = heroNetBattleDamage(userMage.MagDmg, skeletonThree.mag_armor);
                    skeletonThree.currentHealth = skeletonThree.currentHealth - dmgEnemyTakes;
                    if (skeletonThree.currentHealth <= 0)
                        skeletonThree.currentHealth = 0;
                    skeletonThree.check_set_EnemyAlive();
                    cout << userMage.mageName << " used " << userMage.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if (userMage.enemyAttacked == 0)
                {
                    userWarrior.checkIfHealed(userMage);
                    userArcher.checkIfHealed(userMage);

                    if (userMage.healedWarr == true)
                    {
                        cout << userMage.mageName << " used " << userMage.moveUsed << " on (Warrior) " << userWarrior.warName << " (+"
                             << userMage.amtHealedWarr << " hp)" << endl;
                    }
                    if (userMage.healedArch == true)
                    {
                        cout << userMage.mageName << " used " << userMage.moveUsed << " on (Archer) " << userArcher.archName << " (+"
                             << userMage.amtHealedArch << " hp)" << endl;
                    }
                    if (userMage.healedMage == true)
                    {
                        cout << userMage.mageName << " used " << userMage.moveUsed << " on herself (+"
                             << userMage.amtHealedMage << " hp)" << endl;
                    }
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if (userMage.enemyAttacked == -1)
                {
                    userWarrior.checkIfHealed(userMage);
                    userArcher.checkIfHealed(userMage);

                    cout << userMage.mageName << " used " << userMage.moveUsed << " (+"
                            << userMage.MagDmg << " hp to all)" << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if (userMage.enemyAttacked == -2)
                {
                    userWarrior.checkIfRevived(userMage);
                    userArcher.checkIfRevived(userMage);

                    if (userMage.revivedWarr == true)
                    {
                        cout << userMage.mageName << " used " << userMage.moveUsed << " on (Warrior) " << userWarrior.warName << " (+"
                             << userMage.MagDmg << " hp)" << endl;
                    }
                    if (userMage.revivedArch == true)
                    {
                        cout << userMage.mageName << " used " << userMage.moveUsed << " on (Archer) " << userArcher.archName << " (+"
                             << userMage.MagDmg << " hp)" << endl;
                    }
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if(userMage.enemyAttacked == -5)
                {
                    cout << userMage.mageName << " used Skip Turn " << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }

                userMage.stablizeStats();
                if (userEnemiesS2.areEnemiesAlive(skeletonOne, skeletonTwo, skeletonThree) == false)
                {
                    cout << "The enemies have been vanquished" << endl;
                    stageCompleted = true;
                    break;
                }
            }

            // Archer's Turn /
            userArcher.stablizeStats();
            userArcher.checkIfRevived(userMage);
            if (userArcher.isHeroAlive == true)
            {
                userArcher.callBattleMenu();
                userArcher.determineTypeEnemyAttacked(skeletonOne, skeletonTwo, skeletonThree);

                if (userArcher.enemyAttacked == 1)
                {
                    if (userArcher.usedPhysAtk == true)
                        dmgEnemyTakes = heroNetBattleDamage(userArcher.AtkDmg, skeletonOne.armor);
                    else if (userArcher.usedMagAtk == true)
                        dmgEnemyTakes = heroNetBattleDamage(userArcher.MagDmg, skeletonOne.mag_armor);
                    skeletonOne.currentHealth = skeletonOne.currentHealth - dmgEnemyTakes;
                    if (skeletonOne.currentHealth <= 0)
                        skeletonOne.currentHealth = 0;
                    skeletonOne.check_set_EnemyAlive();
                    cout << userArcher.archName << " used " << userArcher.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if (userArcher.enemyAttacked == 2)
                {
                    if (userArcher.usedPhysAtk == true)
                        dmgEnemyTakes = heroNetBattleDamage(userArcher.AtkDmg, skeletonTwo.armor);
                    else if (userArcher.usedMagAtk == true)
                        dmgEnemyTakes = heroNetBattleDamage(userArcher.MagDmg, skeletonTwo.mag_armor);
                    skeletonTwo.currentHealth = skeletonTwo.currentHealth - dmgEnemyTakes;
                    if (skeletonTwo.currentHealth <= 0)
                        skeletonTwo.currentHealth = 0;
                    skeletonTwo.check_set_EnemyAlive();
                    cout << userArcher.archName << " used " << userArcher.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if (userArcher.enemyAttacked == 3)
                {
                    if (userArcher.usedPhysAtk == true)
                        dmgEnemyTakes = heroNetBattleDamage(userArcher.AtkDmg, skeletonOne.armor);
                    else if (userArcher.usedMagAtk == true)
                        dmgEnemyTakes = heroNetBattleDamage(userArcher.MagDmg, skeletonOne.mag_armor);
                    skeletonThree.currentHealth = skeletonThree.currentHealth - dmgEnemyTakes;
                    if (skeletonThree.currentHealth <= 0)
                    skeletonThree.currentHealth = 0;
                    skeletonThree.check_set_EnemyAlive();
                    cout << userArcher.archName << " used " << userArcher.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if (userArcher.enemyAttacked == -1)
                {
                    cout << userArcher.archName << " used " << userArcher.moveUsed << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }
                else if(userArcher.enemyAttacked == -5)
                {
                    cout << userArcher.archName << " used Skip Turn " << endl;
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                }

                userArcher.stablizeStats();
                if (userEnemiesS2.areEnemiesAlive(skeletonOne, skeletonTwo, skeletonThree) == false)
                {
                    cout << "The enemies have been vanquished" << endl;
                    stageCompleted = true;
                    break;
                }
            }

            userArcher.turnOffBarrier();
            cout << "Press any letter to end heroes' turn ";
            cin >> continueDialogue;
            cout << endl;

            skeletonOne.turnsUsed = skeletonTwo.turnsUsed = skeletonThree.turnsUsed = 0;

        // SKeletonOne's Turn /
            if (skeletonOne.isEnemyAlive == true)
            {
                cout << "Skeleton(1)'s Turn" << endl;
                skeletonOne.callRandomAbility();
                skeletonOne.selectRandomTarget(userWarrior, userMage, userArcher);
                if (skeletonOne.targettedHero == 1)
                {
                    dmgHeroTakes = enemyNetBattleDamage(skeletonOne.AtkDmg, userWarrior.armor, userArcher);
                    userWarrior.currentHealth = userWarrior.currentHealth - dmgHeroTakes;
                    cout << skeletonOne.skeletonName << " used " << skeletonOne.abilityUsed << " on (Warrior) " << userWarrior.warName
                         << " (" << dmgHeroTakes << " dmg)" << endl;
                    userWarrior.currentLimit = userWarrior.currentLimit + (dmgHeroTakes * 0.5);
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                    skeletonOne.turnsUsed = skeletonTwo.turnsUsed = skeletonThree.turnsUsed = 1;
                }
                else if (skeletonOne.targettedHero == 2)
                {
                    dmgHeroTakes = enemyNetBattleDamage(skeletonOne.AtkDmg, userMage.armor, userArcher);
                    userMage.currentHealth = userMage.currentHealth - dmgHeroTakes;
                    cout << skeletonOne.skeletonName << " used " << skeletonOne.abilityUsed << " on (Mage) " << userMage.mageName
                         << " (" << dmgHeroTakes << " dmg)" << endl;
                    userMage.currentLimit = userMage.currentLimit + (dmgHeroTakes * 0.5);
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                    skeletonOne.turnsUsed = skeletonTwo.turnsUsed = skeletonThree.turnsUsed = 1;
                }
                else if (skeletonOne.targettedHero == 3)
                {
                    dmgHeroTakes = enemyNetBattleDamage(skeletonOne.AtkDmg, userArcher.armor, userArcher);
                    userArcher.currentHealth = userArcher.currentHealth - dmgHeroTakes;
                    cout << skeletonOne.skeletonName << " used " << skeletonOne.abilityUsed << " on (Archer) " << userArcher.archName
                         << " (" << dmgHeroTakes << " dmg)" << endl;
                    userArcher.currentLimit = userArcher.currentLimit + (dmgHeroTakes * 0.5);
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                    skeletonOne.turnsUsed = skeletonTwo.turnsUsed = skeletonThree.turnsUsed = 1;
                }
            }

            userWarrior.check_set_HeroAlive();
            userMage.check_set_HeroAlive();
            userArcher.check_set_HeroAlive();

            if (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) == false)
            {
                cout << "Your heroes have been defeated" << endl;
                break;
            }

        // SkeletonTwo's Turn /
            if (skeletonTwo.isEnemyAlive == true)
            {
                cout << "Skeleton(2)'s Turn" << endl;
                skeletonTwo.callRandomAbility();
                skeletonTwo.selectRandomTarget(userWarrior, userMage, userArcher);
                if (skeletonTwo.targettedHero == 1)
                {
                    dmgHeroTakes = enemyNetBattleDamage(skeletonTwo.AtkDmg, userWarrior.armor, userArcher);
                    userWarrior.currentHealth = userWarrior.currentHealth - dmgHeroTakes;
                    cout << skeletonTwo.skeletonName << " used " << skeletonTwo.abilityUsed << " on (Warrior) " << userWarrior.warName
                         << " (" << dmgHeroTakes << " dmg)" << endl;
                    userWarrior.currentLimit = userWarrior.currentLimit + (dmgHeroTakes * 0.5);
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                    skeletonOne.turnsUsed = skeletonTwo.turnsUsed = skeletonThree.turnsUsed = 2;
                }
                else if (skeletonTwo.targettedHero == 2)
                {
                    dmgHeroTakes = enemyNetBattleDamage(skeletonTwo.AtkDmg, userMage.armor, userArcher);
                    userMage.currentHealth = userMage.currentHealth - dmgHeroTakes;
                    cout << skeletonTwo.skeletonName << " used " << skeletonTwo.abilityUsed << " on (Mage) " << userMage.mageName
                         << " (" << dmgHeroTakes << " dmg)" << endl;
                    userMage.currentLimit = userMage.currentLimit + (dmgHeroTakes * 0.5);
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                    skeletonOne.turnsUsed = skeletonTwo.turnsUsed = skeletonThree.turnsUsed = 2;
                }
                else if (skeletonTwo.targettedHero == 3)
                {
                    dmgHeroTakes = enemyNetBattleDamage(skeletonTwo.AtkDmg, userArcher.armor, userArcher);
                    userArcher.currentHealth = userArcher.currentHealth - dmgHeroTakes;
                    cout << skeletonTwo.skeletonName << " used " << skeletonTwo.abilityUsed << " on (Archer) " << userArcher.archName
                         << " (" << dmgHeroTakes << " dmg)" << endl;
                    userArcher.currentLimit = userArcher.currentLimit + (dmgHeroTakes * 0.5);
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                    skeletonOne.turnsUsed = skeletonTwo.turnsUsed = skeletonThree.turnsUsed = 2;
                }
            }

            userWarrior.check_set_HeroAlive();
            userMage.check_set_HeroAlive();
            userArcher.check_set_HeroAlive();

            if (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) == false)
            {
                cout << "Your heroes have been defeated" << endl;
                break;
            }

        // SkeletonThree's Turn /
            if (skeletonThree.isEnemyAlive == true)
            {
                cout << "Skeleton(3)'s Turn" << endl;
                skeletonThree.callRandomAbility();
                skeletonThree.selectRandomTarget(userWarrior, userMage, userArcher);
                if (skeletonThree.targettedHero == 1)
                {
                    dmgHeroTakes = enemyNetBattleDamage(skeletonThree.AtkDmg, userWarrior.armor, userArcher);
                    userWarrior.currentHealth = userWarrior.currentHealth - dmgHeroTakes;
                    cout << skeletonThree.skeletonName << " used " << skeletonThree.abilityUsed << " on (Warrior) " << userWarrior.warName
                         << " (" << dmgHeroTakes << " dmg)" << endl;
                    userWarrior.currentLimit = userWarrior.currentLimit + (dmgHeroTakes * 0.5);
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                    skeletonOne.turnsUsed = skeletonTwo.turnsUsed = skeletonThree.turnsUsed = 3;
                }
                else if (skeletonThree.targettedHero == 2)
                {
                    dmgHeroTakes = enemyNetBattleDamage(skeletonThree.AtkDmg, userMage.armor, userArcher);
                    userMage.currentHealth = userMage.currentHealth - dmgHeroTakes;
                    cout << skeletonThree.skeletonName << " used " << skeletonThree.abilityUsed << " on (Mage) " << userMage.mageName
                         << " (" << dmgHeroTakes << " dmg)" << endl;
                    userMage.currentLimit = userMage.currentLimit + (dmgHeroTakes * 0.5);
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                    skeletonOne.turnsUsed = skeletonTwo.turnsUsed = skeletonThree.turnsUsed = 3;
                }
                else if (skeletonThree.targettedHero == 3)
                {
                    dmgHeroTakes = enemyNetBattleDamage(skeletonThree.AtkDmg, userArcher.armor, userArcher);
                    userArcher.currentHealth = userArcher.currentHealth - dmgHeroTakes;
                    cout << skeletonThree.skeletonName << " used " << skeletonThree.abilityUsed << " on (Archer) " << userArcher.archName
                         << " (" << dmgHeroTakes << " dmg)" << endl;
                    userArcher.currentLimit = userArcher.currentLimit + (dmgHeroTakes * 0.5);
                    displayBattleStatsStage2(userWarrior, userMage, userArcher, skeletonOne, skeletonTwo, skeletonThree);
                    skeletonOne.turnsUsed = skeletonTwo.turnsUsed = skeletonThree.turnsUsed = 3;
                }
            }

            userWarrior.check_set_HeroAlive();
            userMage.check_set_HeroAlive();
            userArcher.check_set_HeroAlive();

            if (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) == false)
            {
                cout << "Your heroes have been defeated" << endl;
                break;
            }

            cout << "Press any letter to end enemies' turn ";
            cin >> continueDialogue;
            cout << endl;

            roundNum++;
        }

/** As I did before, the user's heroes get their second level up of the game here
after they successfully defeat the Skeletons
*/

        if (stageCompleted == true)
        {
            cout << "Great job, " << userName << " ";
            cin >> continueDialogue;

            userHeroes.numStagesCompleted = 2;
            userWarrior.numLevelsGained = 6;
            userMage.numLevelsGained = 6;
            userArcher.numLevelsGained = 6;

            userWarrior.totalNumLevelsGained = 9;
            userMage.totalNumLevelsGained = 9;
            userArcher.totalNumLevelsGained = 9;

            userWarrior.levelUpHero();
            userMage.levelUpHero();
            userArcher.levelUpHero();

            displayLevelUpScreen(userWarrior, userMage, userArcher);

            userWarrior.finishLevelUp();
            userMage.finishLevelUp();
            userArcher.finishLevelUp();

            for (int i = 0; i < 6; i++)
            {
                getline(Dialogue, line);
                cout << line;
                numLinesOfDialogueCompleted++;
                cin >> continueDialogue;
                cout << endl;
            }

            userHeroes.numLinesDialogue = numLinesOfDialogueCompleted;
            askUserToSave(userName, userHeroes, userWarrior, userMage, userArcher);
        }
    }

/** Here is the final stage of the game where the user and their heroes face off against the
Bahamut
* Again, the mechanics of the fight are pretty similar to the previous fights
* The only main concern of the user is that they must be careful about
how they utilize their abilities otherwise it can easily turn into a defeat
*/

    if (userHeroes.numStagesCompleted == 2)
    {
        for (int i = 0; i < 5; i++)
        {
            getline(Dialogue, line);
            cout << line;
            cin >> continueDialogue;
            numLinesOfDialogueCompleted++;
            cout << endl;
        }

        Bahamut theBahamut;
        Enemies userEnemiesS3(theBahamut);
        theBahamut.setRandomType();

        displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);

        for (int i = 0; i < 1; i++)
        {
            getline(Dialogue, line);
            cout << line;
            cin >> continueDialogue;
            numLinesOfDialogueCompleted++;
            cout << endl;
        }

        userWarrior.currentLimit = 0;
        userMage.currentLimit = 0;
        userArcher.currentLimit = 0;
        int dmgEnemyTakes = 0;
        int dmgHeroTakes = 0;
        int roundNum = 1;
        userWarrior.atFinalStage = true;
        userMage.atFinalStage = true;
        userArcher.atFinalStage = true;

        stageCompleted = false;

        /** Final Stage */

        while (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) != false || userEnemiesS3.isBahamutAlive(theBahamut) != false)
        {
            if (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) == false || userEnemiesS3.isBahamutAlive(theBahamut) == false)
            {
                break;
            }


            if (roundNum == 2)
            {
                for (int i = 0; i < 1; i++)
                {
                    getline(Dialogue, line);
                    cout << line;
                    numLinesOfDialogueCompleted++;
                    cin >> continueDialogue;
                    cout << endl;
                }
            }

            userArcher.checkIfBarrierOn();

            // Warrior's Turn /
            userWarrior.stablizeStats();
            userWarrior.checkIfRevived(userMage);
            if (userWarrior.isHeroAlive == true)
            {
                userWarrior.checkEnragedBeforeMenu();
                userWarrior.callBattleMenu();
                userWarrior.checkIfEnraged();

                userWarrior.determineTypeOfBahamut(theBahamut);

                if (userWarrior.enemyAttacked == 1)
                {
                    dmgEnemyTakes = heroNetBattleDamage(userWarrior.AtkDmg, theBahamut.armor);
                    theBahamut.currentHealth = theBahamut.currentHealth - dmgEnemyTakes;
                    if (theBahamut.currentHealth <= 0)
                        theBahamut.currentHealth = 0;
                    theBahamut.check_set_EnemyAlive();
                    cout << userWarrior.warName << " used " << userWarrior.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                    displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                }

                else if (userWarrior.enemyAttacked == 4)
                {
                    cout << userWarrior.warName << " used " << userWarrior.moveUsed << endl;
                    displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                }
                else if(userWarrior.enemyAttacked == -5)
                {
                    cout << userWarrior.warName << " used Skip Turn " << endl;
                    displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                }

                userWarrior.stablizeStats();
                if (userEnemiesS3.isBahamutAlive(theBahamut) == false)
                {
                    cout << "The Bahamut has been vanquished" << endl;
                    stageCompleted = true;
                    break;
                }
            }

            // Mage's Turn /
            userMage.stablizeStats();
            if (userMage.isHeroAlive == true)
            {
                userMage.checkIfAlliesAlive(userWarrior, userArcher);
                userMage.callBattleMenu();

                userMage.determineTypeOfBahamut(theBahamut);

                if (userMage.enemyAttacked == 1)
                {
                    dmgEnemyTakes = heroNetBattleDamage(userMage.MagDmg, theBahamut.mag_armor);
                    theBahamut.currentHealth = theBahamut.currentHealth - dmgEnemyTakes;
                    if (theBahamut.currentHealth <= 0)
                        theBahamut.currentHealth = 0;
                    theBahamut.check_set_EnemyAlive();
                    cout << userMage.mageName << " used " << userMage.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                    displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                }

                if (userMage.enemyAttacked == 0)
                {
                    userWarrior.checkIfHealed(userMage);
                    userArcher.checkIfHealed(userMage);

                    if (userMage.healedWarr == true)
                    {
                        cout << userMage.mageName << " used " << userMage.moveUsed << " on (Warrior) " << userWarrior.warName << " (+"
                             << userMage.amtHealedWarr << " hp)" << endl;
                    }
                    if (userMage.healedArch == true)
                    {
                        cout << userMage.mageName << " used " << userMage.moveUsed << " on (Archer) " << userArcher.archName << " (+"
                             << userMage.amtHealedArch << " hp)" << endl;
                    }
                    if (userMage.healedMage == true)
                    {
                        cout << userMage.mageName << " used " << userMage.moveUsed << " on herself (+"
                             << userMage.amtHealedMage << " hp)" << endl;
                    }
                    displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                }

                if (userMage.enemyAttacked == -1)
                {
                    userWarrior.checkIfHealed(userMage);
                    userArcher.checkIfHealed(userMage);

                    cout << userMage.mageName << " used " << userMage.moveUsed << " (+"
                            << userMage.MagDmg << " hp to all)" << endl;
                    displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                }

                if (userMage.enemyAttacked == -2)
                {
                    userWarrior.checkIfRevived(userMage);
                    userArcher.checkIfRevived(userMage);

                    if (userMage.revivedWarr == true)
                    {
                        cout << userMage.mageName << " used " << userMage.moveUsed << " on (Warrior) " << userWarrior.warName << " (+"
                             << userMage.MagDmg << " hp)" << endl;
                    }
                    if (userMage.revivedArch == true)
                    {
                        cout << userMage.mageName << " used " << userMage.moveUsed << " on (Archer) " << userArcher.archName << " (+"
                             << userMage.MagDmg << " hp)" << endl;
                    }
                    displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                }
                else if(userMage.enemyAttacked == -5)
                {
                    cout << userMage.mageName << " used Skip Turn " << endl;
                    displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                }

                userMage.stablizeStats();
                if (userEnemiesS3.isBahamutAlive(theBahamut) == false)
                {
                    cout << "The Bahamut has been vanquished" << endl;
                    stageCompleted = true;
                    break;
                }
            }

            // Archer's Turn /
            userArcher.stablizeStats();
            userArcher.checkIfRevived(userMage);
            if (userArcher.isHeroAlive == true)
            {
                userArcher.callBattleMenu();
                userArcher.determineTypeOfBahamut(theBahamut);

                if (userArcher.enemyAttacked == 1)
                {
                    if (userArcher.usedPhysAtk == true)
                        dmgEnemyTakes = heroNetBattleDamage(userArcher.AtkDmg, theBahamut.armor);
                    else if (userArcher.usedMagAtk == true)
                        dmgEnemyTakes = heroNetBattleDamage(userArcher.MagDmg, theBahamut.mag_armor);
                    theBahamut.currentHealth = theBahamut.currentHealth - dmgEnemyTakes;
                    if (theBahamut.currentHealth <= 0)
                        theBahamut.currentHealth = 0;
                    theBahamut.check_set_EnemyAlive();
                    cout << userArcher.archName << " used " << userArcher.moveUsed << " (" << dmgEnemyTakes << " dmg)" << endl;
                    displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                }
                else if (userArcher.enemyAttacked == -1)
                {
                    cout << userArcher.archName << " used " << userArcher.moveUsed << endl;
                    displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                }
                else if(userArcher.enemyAttacked == -5)
                {
                    cout << userArcher.archName << " used Skip Turn " << endl;
                    displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                }

                userArcher.stablizeStats();
                if (userEnemiesS3.isBahamutAlive(theBahamut) == false)
                {
                    cout << "The Bahamut has been vanquished" << endl;
                    stageCompleted = true;
                    break;
                }
            }

            userArcher.turnOffBarrier();
            cout << "Press any letter to end heroes' turn ";
            cin >> continueDialogue;
            cout << endl;

            // Bahamut's Turn /
                if (theBahamut.isEnemyAlive == true)
                {
                    cout << "The Bahamut's Turn" << endl;
                    theBahamut.callRandomAbility();
                    theBahamut.selectRandomTarget(userWarrior, userMage, userArcher);
                    if (theBahamut.targettedHero == 1)
                    {
                        dmgHeroTakes = enemyNetBattleDamage(theBahamut.AtkDmg, userWarrior.armor, userArcher);
                        userWarrior.currentHealth = userWarrior.currentHealth - dmgHeroTakes;
                        cout << theBahamut.bahamutName << " used " << theBahamut.abilityUsed << " on (Warrior) " << userWarrior.warName
                             << " (" << dmgHeroTakes << " dmg)" << endl;
                        userWarrior.currentLimit = userWarrior.currentLimit + (dmgHeroTakes * 0.30);
                        theBahamut.setRandomType();
                        displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                    }
                    else if (theBahamut.targettedHero == 2)
                    {
                        dmgHeroTakes = enemyNetBattleDamage(theBahamut.AtkDmg, userMage.armor, userArcher);
                        userMage.currentHealth = userMage.currentHealth - dmgHeroTakes;
                        cout << theBahamut.bahamutName << " used " << theBahamut.abilityUsed << " on (Mage) " << userMage.mageName
                             << " (" << dmgHeroTakes << " dmg)" << endl;
                        userMage.currentLimit = userMage.currentLimit + (dmgHeroTakes * 0.30);
                        theBahamut.setRandomType();
                        displayBattleStatsStage3(userWarrior, userMage, userArcher, theBahamut);
                    }
                    else if (theBahamut.targettedHero == 3)
                    {
                        dmgHeroTakes = enemyNetBattleDamage(theBahamut.AtkDmg, userArcher.armor, userArcher);
                        userArcher.currentHealth = userArcher.currentHealth - dmgHeroTakes;
                        cout << theBahamut.bahamutName << " used " << theBahamut.abilityUsed << " on (Archer) " << userArcher.archName
                             << " (" << dmgHeroTakes << " dmg)" << endl;
                        userArcher.currentLimit = userArcher.currentLimit + (dmgHeroTakes * 0.30);
                        theBahamut.setRandomType();
                        displayBattleStatsStage3(userWarrior, userMage, userArcher,theBahamut);
                    }
                }

                userWarrior.check_set_HeroAlive();
                userMage.check_set_HeroAlive();
                userArcher.check_set_HeroAlive();

                if (userHeroes.areHeroesAlive(userWarrior, userMage, userArcher) == false)
                {
                    cout << "Your heroes have been defeated" << endl;
                    break;
                }

                cout << "Press any letter to end the Bahamut's turn ";
                cin >> continueDialogue;
                cout << endl;

                roundNum++;
        }

        if (stageCompleted == true)
        {
            cout << "Great job, " << userName << " ";
            cin >> continueDialogue;
            cout << endl;

            for (int i = 0; i < 4; i++)
            {
                getline(Dialogue, line);
                cout << line;
                numLinesOfDialogueCompleted++;
                cin >> continueDialogue;
                cout << endl;
            }

            cout << endl;
            cout << "Thanks for playing" << endl;
        }
    }

/** At last, I thank the user for playing the game and close the files used
during the game
*/

    Dialogue.close();
    SavedProgress.close();

    return 0;
}
