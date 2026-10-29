#include "dungeon.h"
#include "enemy.h"
#include "battle.h"
#include "ui.h"

#include <iostream>

using namespace std;

void dungeon(Character& player) 
{
    bool inTheDungeon = true;
    cout << "\nВы спускаетесь в подземелье...\n";
    wait();

    while (inTheDungeon)
    {
        cout << "====|Вы находитесь в подземельях|====\n"
                "=======|Уровень подземелий: " << player.dungeonLevel << "|=======\n"
                "[1]Исследовать уровень\n"
                "[2]Персонаж\n"
                "[3]Отдых\n"
                "[4]Вернуться в город\n";
        int cmd;
        cin >> cmd;
        cin.ignore();

        switch (cmd)
        {
            case 1:
            {
                Enemy e = randomEnemy(player.dungeonLevel);
                cout << "В темноте что-то есть...\n"
                        "Вы пытаетесь опознать врага...\n"
                        "Вам встретился - " << e.name << "!\n";

                cout << "❤️  Здоровье: " << e.hp << "/" << e.hpMax << "\n"
                        "⚔️  Атака: " << e.attack << "\n"
                        "🐾 Размер: " << e.dimensions << "\n"; 
                wait();

                battle(player, e);
                break;
            }

            case 2:
                cout << "\n"; 
                break;

            case 3:
                cout << "\n"; 
                break;

            case 4:
            {
                char answer;
                cout << "Вы уверенны, что хотите вернуться в город?  y/n\n";
                cin >> answer;
                cin.ignore();
                if (answer == 'y' || answer == 'Y')
                {
                    cout << "Портал открывается...\n";
                    inTheDungeon = false;

                }
                else if (answer == 'n' || answer == 'N')
                {
                    cout << "Отлично, исследуем дальше!\n";
                }
                else 
                {
                    cout << "Непонятный ответ. Возвращаемся в меню.\n";
                }
                break;
            }
                
            default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            wait();
            break;
        }
    }
}