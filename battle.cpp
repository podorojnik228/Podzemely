#include "battle.h"
#include "ui.h"

#include <iostream>
#include <random>
#include <chrono>

using namespace std;

//рандом
static mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
static int rnd(int a, int b)
{
    uniform_int_distribution<int> d(a, b);
    return d(rng);
}


void battle(Character& player, Enemy& enemy)
{
    cout << "====БИТВА====\n";
    cout << "====" << enemy.name << "====\n";
    while (player.hp > 0 && enemy.hp > 0)
    {
        int choice;
        cout << "1. Атака\n"
                "2. Бежать\n";
        cin >> choice;

        //Атака//
        if (choice == 1) 
        {
            //расчет дамага игрока
            int minDmgPlayer = (int)(player.strength * 1.5);
            int maxDmgPlayer = player.strength * 2;
            int dmgPlayer = rnd(minDmgPlayer, maxDmgPlayer);
            
            //расчет шанса на хит игрока
            int sizeEnemy = 100 - enemy.dimensions / 2;
            int hitChance = 70 + sizeEnemy - player.defense;
            if (hitChance < 5) hitChance = 5;
            if (hitChance > 90) hitChance = 90;
            
            //
            if (rnd(1, 100) > hitChance)
            {
                cout << "Промах!\n";
            }
            else
            {
                cout << "Вы нанесли врагу: " << dmgPlayer << " урона\n";
                enemy.hp -= dmgPlayer;
            } 
            if (enemy.hp <= 0) break; //проверка на смерть enemy

            //расчет дамага enemy
            int minDmgEnemy = max(1, enemy.attack - 1);
            int maxDmgEnemy = max(enemy.attack, enemy.attack + 1);
            int dmgEnemy = rnd(minDmgEnemy, maxDmgEnemy);

            //расчет шанса на хит enemy
            int hitChanceEnemy = 100 - enemy.dimensions / 2;
            if (rnd(1, 100) > hitChanceEnemy)
            {
                cout << "Враг промахнулся!\n";
            }
            else
            {
                cout << "Враг нанес вам: " << dmgEnemy << " урона\n";
                player.hp -= dmgEnemy;
            }
            
        }
        
        //Побег//
        else if (choice == 2) 
        {
            double escape = 20 + player.agility * 0.1;
            if (rnd(1, 100) > escape)
            {
                cout << "Вы не смогли сбежать!\n";
            }
            else
            {
                cout << "Вы сумели сбежать!\n";
                return;
            }
        }
        else
        {
            cout << "Введите 1 или 2!\n";
        }
    }
    if (player.hp > 0)
    {
        cout << "Враг побежден!\n"
                "Вы получили: " << enemy.goldReward <<" золота!\n";
        player.gold += enemy.goldReward;
        if (enemy.isGuardian)
        {
            player.hasNextKey = true;
            cout << "Вы получили Ключ!\n";
        }
        
    }
    if (player.hp <= 0)
    {
        cout << "Вы не смогли пережить этот бой!\n"
                "Вы потеряли Золото!\n";
        player.gold -= player.gold / 5;

        int r = rnd(1, 3);
        if (r == 1 && player.strength > 1)
        {
            cout << "Сила снижена на единцу!\n";
            player.strength -= 1;
        }
        else if (r == 2 && player.agility > 1)
        {
            cout << "Ловкость снижена на единцу!\n";
            player.agility -= 1;
        }
        else if (r == 3 && player.endurance > 1)
        {
            cout << "Выносливость снижена на единцу!\n";
            player.endurance -= 1;
        }
    }
    wait();
}