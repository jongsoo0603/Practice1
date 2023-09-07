#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> sides = { 3, 6, 2 };
    int answer = 0, maxInt = 0, max = 0, sum = 0;

    for (int i = 0; i < sides.size(); i++)
    {
        if (sides[i] > max)
        {
            maxInt = i;
            max = sides[i];
        }
    }

    max = sides[maxInt];
    sides[maxInt] = 0;

    for (int i = 0; i < sides.size(); i++)
    {
        sum += sides[i];
    }

    if (sum > max)
    {
        cout << 1;
    }
    else
    {
        cout << 2;
    }
}