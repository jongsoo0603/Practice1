#pragma once
#include "Gun.h"

Gun::Gun()
{
    this->power = 10;
}
int Gun::get_power()
{
    return power;
}
int Gun::get_NPA()
{
    return NPA;
}
void Gun::set_NPA(int NPA)
{
    this->NPA = NPA;
}
void Gun::increase_NPA()
{
    this->NPA = NPA + 1;
}
void Gun::print_attack()
{
    cout << "몬스터를 총으로 쐈습니다!" << endl;
}