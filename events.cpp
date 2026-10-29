#include "events.h"
#include "battle.h"

#include <iostream>

using namespace std;

void dungeonEvent(Character &player)
{
    if (player.hasNextKey) eventNextLevelDoor(player); return; //если есть ключ, то дверь - единственное событие
    
    int roll = rnd(1, 100);
    if (roll <=50) eventBattle(player);
    else           eventChest(player);
}

void eventBattle(Character &player)
{
    Enemy e = randomEnemy(player.dungeonLevel);
    if (rnd(1, 100) <= 15)
    {
        e = makeGuardian(e);
        cout << "Вы чувствуете мощную ауру...\n"
                "Кажется это Хранитель Прохода!\n";
    }

    cout << "В темноте что-то есть...\n"
            "Вы пытаетесь опознать врага...\n";
    wait();
    cout << "Вам встретился - " << e.name << "!\n";
    cout << "❤️  Здоровье: " << e.hp << "/" << e.hpMax << "\n"
                                                         "⚔️  Атака: "
         << e.attack << "\n"
                        "🐾 Размер: "
         << e.dimensions << "\n";
    wait();
    battle(player, e);
}

void eventChest(Character &player)
{
}

void eventNextLevelDoor(Character &player)
{
    while (player.hasNextKey)
    {
        int choice;
        cout << "Перед Вами массивная дверь с замком\n"
                "Использовать ключ Хранителя?\n"
                "[1]Да [2]Нет\n";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
            {
                cout << "Вы использовали Ключ Хранителя!\n"
                        "Спуск на следующий уровень...\n";
                wait();
                player.hasNextKey = false;
                player.dungeonLevel += 1;
                return;
            }

            case 2:
            {
                cout << "Вы решили отложить Ключ Хранителя на потом!\n"
                        "Возвращение на уровень...\n";
                wait();
                return;
            }
            default:
                cout << "Введите 1 или 2!\n";
                break;   
        }
    }
}
