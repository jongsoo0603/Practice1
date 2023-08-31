#include<iostream>

using namespace std;

string OddEven(int n1)
{
    if(n1 % 2 == 0)
    {
        return "짝수";
    }
    else
    {
        return "홀수";
    }
}

int biggest(int n1, int n2, int n3)
{
    if((n1 > n2) && (n1 > n3))
    {
        return n1;
    }
    else if((n2 > n1) && (n2 > n3))
    {
        return n2;
    }
    else
    {
        return n3;
    }
}

int smallest(int n1, int n2, int n3, int n4)
{
    if((n1 < n2) && (n1 < n3) && (n1 < n4))
    {
        return n1;
    }
    else if((n2 < n1) && (n2 < n3) && (n2 < n4))
    {
        return n2;
    }
    else if((n3 < n1) && (n3 < n2) && (n3 < n4))
    {
        return n3;
    }
    else
    {
        return n4;
    }
}

int main()
{
    int a, b, c, d;
    cout << "띄어쓰기로 구분하여 정수 네 개를 입력하시오: ";
    cin >> a >> b >> c >> d;

    cout << a << " 은(는) " << OddEven(a) << endl;
    cout << a << ", " << b << ", " << c << " 중 가장 큰 수는 " << biggest(a, b, c) << endl;
    cout << a << ", " << b << ", " << c << ", " << d << " 중 가장 작은 수는 " << smallest(a, b, c, d) << endl;
}