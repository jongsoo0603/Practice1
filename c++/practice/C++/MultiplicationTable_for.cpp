#include<iostream>

using namespace std;

int main()
{
    int i, j;

    cout << "5단 출력\n";

    for(i = 1; i <= 5; i++)
    {
        cout << "5 * " << i << " = " << (1 * i) << endl;
    }
    
    cout << "\n1~9단 출력\n";

    for(i = 1; i <= 9; i++)
    {
        cout << "----" << i << "단----\n";
        for(j = 1; j <= 9; j++)
        {
            cout << i << " * " << j << " = " << (i * j) << endl;
        }
    }
    
}