#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> arr = { "a", "b", "c" };
    string answer = "";
    for (int i = 0; i < arr.size(); i++)
    {
        answer += arr[i];
    }
    cout << answer;
}