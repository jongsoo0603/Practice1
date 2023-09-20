#pragma once;
#include "Character.h"

int Character::get_level()
{
    return level;
}
int Character::get_hp()
{
    return hp;
}
int Character::get_monsterHP()
{
    return monsterHP;
}
void Character::set_monsterHP(int monsterHP)
{
    this->monsterHP = monsterHP;
}
void Character::pick_up_weapon(Weapon *pick)
{
    pick->increase_NPA();
}
void Character::attack(Weapon *pick)
{
    monsterHP -= pick->get_power();
    pick->set_NPA(pick->get_NPA() - 1);
}