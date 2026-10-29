#pragma once
#include <iostream>
#include <string>

struct Character
{
    std::string name;

    /// /cтаты
    int hp = 20;
    int hpMAX = 20;
    int satiety = 30;
    int satietyMAX = 100;

    // хар-ки
    int strength = 1;
    int agility = 1;
    int endurance = 1;

    /// оружие/броня
    int weapon = 1;
    int armor = 1;

    /// защита/атака
    int defense = (endurance * 1.5) * armor;
    int attack = (strength * 1.5) * weapon;

    /// золото
    int gold = 0;

    /// подземелье
    int dungeonLevel = 1;
    bool hasNextKey = false;
};

void printCharacter(const Character& player);

//void createCharacter(Character& c);
//void checkLevelUp(Character& c);