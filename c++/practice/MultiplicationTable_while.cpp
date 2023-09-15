#include<iostream>

using namespace std;

int main()
{
    int i, j;

    cout << "5단 출력\n";

    i = 1;
    while (i < 6)
    {
        cout << "5 * " << i << " = " << (1 * i) << endl;
        i++;
    }
    
    cout << "\n1~9단 출력\n";

    i = 1;
    j = 1;
    while (i < 10)
    {
        cout << "----" << i << "단----\n";
        while(j < 10)
        {
            cout << i << " * " << j << " = " << (i * j) << endl;
            j++;
        }
        i++;
        j = 1;
    }
    
}