#pragma once
#include <iostream>

using namespace std;

class Weapon
{
protected:
    int power, NPA = 0; // Number of possible attacks

public:
    virtual int get_power();
    virtual int get_NPA();
    virtual void set_NPA(int NPA) {}
    virtual void increase_NPA() {} // 칼은 3, 총은 1 만큼 NPA 증가
    virtual void print_attack() {} // "~로 괴물을 ~했습니다."
};