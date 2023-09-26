#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
public:
    Sword();
    int get_power();
    int get_NPA();
    void set_NPA(int NPA);
    void increase_NPA();
    void print_attack();
};