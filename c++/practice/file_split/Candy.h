#pragma once
#include"Snack.h"

class Candy : public Snack 
{
    string flavor;
    public:
        Candy(string flavor);
        string show_info();
};