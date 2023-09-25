#pragma once
#include"Snack.h"

class Chocolate : public Snack 
{
	string shape;
    public:
        Chocolate(string shape);
        string show_info();
};