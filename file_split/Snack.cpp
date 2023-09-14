#pragma once
#include "Snack.h"

int Snack::count = 0;
string Snack::lastName = ""; 

Snack::Snack()
{
    count++;
}
int Snack::get_count() 
{
    return count;
}
string Snack::get_lastName()
{
    return lastName;
}
string Snack::get_name() 
{
    return name;
}
void Snack::set_lastName(string name)
{
    this -> lastName = name;
}
string Snack::show_info()
{
    return "과자입니다~\n";
}