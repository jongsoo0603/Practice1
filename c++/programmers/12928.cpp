#include<iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n = 12, answer = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (n % i == 0)
        {
            answer += i;
        }
    }
    cout << answer;
}