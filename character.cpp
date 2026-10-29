#include "character.h"

#include <iostream>

using namespace std;

void printCharacter(const Character& player)
{
    cout << "\n===" << player.name << "===\n"
    "❤️  HP: " << player.hp << "/" << player.hpMAX << "\n"
    "💪 Сила: " << player.strength << "\n"
    "✋ Ловкость: " << player.agility << "\n"
    "⚡ Выносливость: " << player.endurance << "\n"
    "🌕 Золото: " << player.gold << "\n"
    "🍗 Сытость: " << player.satiety << "/" << player.satietyMAX << "\n"
    " 🕯︎ Уровень подземелья: " << player.dungeonLevel << "\n";
}
