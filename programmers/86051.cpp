#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() 
{
	vector<int> numbers = { 1,2,3,4,6,7,8,0 };

    int sum = 0, answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
    }

    cout << sum << endl;

    cout << 45 - sum;

}