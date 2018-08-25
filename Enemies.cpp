#include <iostream>
#include "Enemies.h"
#include "Skeleton.h"
#include "Slime.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

/** These are the constructors and the destructor
*/

Enemies::Enemies()
{

}

Enemies::Enemies(Slime S1, Slime S2, Slime S3)
{
    ESlime1 = S1;
    ESlime2 = S2;
    ESlime3 = S3;
}

Enemies::Enemies(Skeleton Sk1, Skeleton Sk2, Skeleton Sk3)
{
    ESkeleton1 = Sk1;
    ESkeleton2 = Sk2;
    ESkeleton3 = Sk3;
}

Enemies::Enemies(Bahamut TheBahamut)
{
    theBahamut = theBahamut;
}

Enemies::~Enemies()
{

}

/** These methods check if the enemies are still alive
*/

bool Enemies::areEnemiesAlive(Slime slime1, Slime slime2, Slime slime3)
{
    if (slime1.isEnemyAlive == false && slime2.isEnemyAlive == false && slime3.isEnemyAlive == false)
        isETeamAlive = false;
    return isETeamAlive;
}

bool Enemies::areEnemiesAlive(Skeleton skeleton1, Skeleton skeleton2, Skeleton skeleton3)
{
    if (skeleton1.isEnemyAlive == false && skeleton2.isEnemyAlive == false && skeleton3.isEnemyAlive == false)
        isETeamAlive = false;
    return isETeamAlive;
}

bool Enemies::isBahamutAlive(Bahamut theBahamut)
{
    if (theBahamut.isEnemyAlive == false)
        isETeamAlive = false;
    return isETeamAlive;
}
