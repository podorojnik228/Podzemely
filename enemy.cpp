#include "enemy.h"
#include "character.h"

#include <random>
#include <chrono>
#include <vector>

using namespace std;

static mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
static int rnd(int a, int b)
{
    uniform_int_distribution<int> d(a, b);
    return d(rng);
}

static vector<EnemyTemplate> templates = 
{
    //имя, baseHp, baseAtk, gold, dimensions, hpGrowth, atkGrowth, goldGrowth
    {"Гоблин",   10, 2, 5, 60, 5, 1, 2},
    {"Мертвец",  15, 3, 8, 80, 7, 2, 2},
    {"Великан",  40, 7, 20, 110, 15, 3, 2},
    {"Призрак",  12, 4, 15, 80, 6, 2, 2},
    {"Крыса",     6, 1, 2, 15, 3, 1, 2},
    {"Скелет",   18, 3, 10, 70, 7, 2, 2},
    {"Тролль",   50, 8, 25, 120, 18, 4, 2},
    {"Человек",  20, 5, 13, 90, 8, 2, 2}
};

Enemy makeEnemy(const EnemyTemplate& tmpl, int dungeonLevel)
{
    Enemy e;
    e.name = tmpl.name;

    int scale = dungeonLevel - 1;

    e.hpMax = tmpl.baseHp + scale * tmpl.hpGrowth;
    e.hp = e.hpMax;

    e.attack = tmpl.baseAttack + scale * tmpl.atkGrowth;
     
    e.goldReward = tmpl.baseGold + scale * tmpl.goldGrowth;

    e.dimensions = tmpl.baseDimensions;

    return e;
}

Enemy makeGuardian(Enemy e)
{       
    Enemy g;
    g.name = "Хранитель Прохода";
    
    g.hpMax = e.hpMax * 1.5;
    g.hp = g.hpMax;

    g.attack = e.attack * 1.5;

    g.goldReward = e.goldReward * 1.5;

    g.dimensions = e.dimensions;

    g.isGuardian = true;

    return g;
}

Enemy randomEnemy(int dungeonLevel)
{
    int index = rnd(0, (int)templates.size() - 1);
    return makeEnemy(templates[index], dungeonLevel);
}
