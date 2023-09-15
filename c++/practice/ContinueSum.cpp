#include<iostream>

using namespace std;

int main()
{
    int n, sum;

    cout << "사용자가 입력한 숫자 더하기\n" << endl;

    sum = 0;
    n = 0;

    while (1)
    {
        cout << "숫자를 입력하세요 (0: exit) :";
        cin >> n;
        if(n == 0)
        {
            break;
        }
        sum += n;
    }

    cout << "사용자가 입력한 수의 합은 : " << sum ;
    
}