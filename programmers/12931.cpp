#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n = 123, answer = 0;
    string a = to_string(n), b;
    for (int i = 0; i < a.size(); i++)
    {
        b = a[i];
        answer += stoi(b);
    }
    cout << answer;
}