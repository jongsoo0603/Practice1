#pragma once
#include"Chocolate.h"

Chocolate::Chocolate(string shape) 
{
    this->price = 1000;
    this->name = "초콜릿";
    this->maker = "롯데";
    this->shape = shape;
}

string Chocolate::show_info() 
{
    return shape + "모양 초콜릿\n";
}