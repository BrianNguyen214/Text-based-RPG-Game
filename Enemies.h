#ifndef Enemies_H
#define Enemies_H
#include "Slime.h"
#include "Skeleton.h"
#include "The_Bahamut.h"

#include <iostream>

using namespace std;

/**
* This is the Enemies h file, and its purpose conceptually is to set the enemies as a team, battling
the heroes
* This file contains four methods:
    -the first is to set the type (i.e. fire, ice, earth, holy) of the enemies;
    -the second is to randomly generate the kinds of enemies/classes (Slime, Skeleton, Golem, Demon) of
    the enemy team;
    -the next is to check if any of the enemies are alive in order to determine if the
    battle sequence should end
    -finally one is to level, or increase the stats of the enemies every stage; besides this,
    the level of the enemies of the stages is kept track;
* The battle sequence is a battle between heroes and enemies, and the
battle sequence will end if either the heroes defeat all the enemies or all of the
heroes are defeated
*/

class Enemies
{
	public:
		Enemies();
		Enemies(Slime, Slime, Slime);
		Enemies(Skeleton, Skeleton, Skeleton);
		Enemies(Bahamut);

		~Enemies();

		void setEnemyRandomType(Skeleton, Skeleton, Skeleton);
		void generateStageEnemies();
        bool areEnemiesAlive(Slime, Slime, Slime);
        bool areEnemiesAlive(Skeleton, Skeleton, Skeleton);
        bool isBahamutAlive(Bahamut);
        void levelUpEnemies();

        int enemiesLevel = 1;
        int turnsUsed = 0;

        bool isETeamAlive = true;

        Slime ESlime1;
        Slime ESlime2;
        Slime ESlime3;

        Skeleton ESkeleton1;
        Skeleton ESkeleton2;
        Skeleton ESkeleton3;

        Bahamut theBahamut;

        string enemyType;
        string enemiesTypes[5]= {"Fire", "Ice", "Earth", "Lightning", "Wind"};

	private:

};
#endif // Enemies_H

