#pragma once
#include "Sword.h"

Sword::Sword()
{
    this->power = 5;
}
int Sword::get_power()
{
    return power;
}
int Sword::get_NPA()
{
    return NPA;
}
void Sword::set_NPA(int NPA)
{
    this->NPA = NPA;
}
void Sword::increase_NPA()
{
    this->NPA = NPA + 3;
}
void Sword::print_attack()
{
    cout << "몬스터를 칼로 찔렀습니다!" << endl;
}