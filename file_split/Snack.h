#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Snack 
{
    protected:
        int price;
        string name;
        string maker;
        static int count;
        static string lastName;
    public:
        Snack();
        static int get_count();
        static string get_lastName();
        string get_name();
        void set_lastName(string name);
        virtual string show_info();
};
