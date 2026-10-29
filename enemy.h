#pragma once

#include <string>

struct EnemyTemplate
{
    std::string name;
    int baseHp;         // хп
    int baseAttack;     // атака
    int baseGold;       // золото 
    int baseDimensions; // размер

    int hpGrowth;       // рост хп за уровень
    int atkGrowth;      // рост атаки за уровень
    int goldGrowth;     // рост золота за уровень
};

struct Enemy
{
    std::string name;
    int hp;
    int hpMax;
    int attack;
    int goldReward;
    int dimensions;
    bool isGuardian = false;
};

Enemy makeEnemy(const EnemyTemplate& tmpl, int dungeonLevel);
Enemy makeGuardian(Enemy e);
Enemy randomEnemy(int dungeonLevel);




