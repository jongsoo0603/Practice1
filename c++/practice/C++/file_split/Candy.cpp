#pragma once
#include "Candy.h"

using std::string;

Candy::Candy(string flavor) 
{
    this->price = 200;
    this->name = "사탕";
    this->maker = "농심";
    this->flavor = flavor;
}
string Candy::show_info() 
{
    return  flavor + "맛 사탕\n";
}