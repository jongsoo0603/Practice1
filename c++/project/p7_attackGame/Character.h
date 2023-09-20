#pragma once
#include "Weapon.h"

class Character
{
private:
    int level = 1, hp = 50, monsterHP = 50;

public:
    int get_level();
    int get_hp();
    int get_monsterHP();
    void set_monsterHP(int monsterHP);
    void pick_up_weapon(Weapon *pick); //
    void attack(Weapon *pick);
};