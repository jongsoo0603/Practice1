#include<iostream>

using namespace std;

int main()
{
    int n, i, sum;

    cout << "1부터 n까지의 합 구하기\n\n숫자(양의 정수)를 입력하세요 : ";
    cin >> n;

    sum = 0;
    i = 1;

    while (i <= n)
    {
        sum += i;
        i++;
    }

    cout << "1부터 " << n << "까지의 합은 : " << sum;
    
}