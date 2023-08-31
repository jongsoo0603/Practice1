#include<iostream>

using namespace std;

int add(int n1, int n2)
{
    return n1 + n2;
}

int sub(int n1, int n2)
{
    if(n1 < n2)
    {
        return n2 - n1;
    }
    else
    {
        return n1 - n2;
    }
}

int mul(int n1, int n2)
{
    return n1 * n2;
}

double divide(int n1, int n2)
{
    return double(n1) / double(n2);
}

int main()
{
    int a, b;
    cout << "띄어쓰기로 구분하여 사칙연산 할 정수 두 개를 입력하시오: ";
    cin >> a >> b;

    cout << "add = " << add(a,b) << endl;
    cout << "sub = " << sub(a,b) << endl;
    cout << "mul = " << mul(a,b) << endl;
    cout << "devide = " << divide(a,b) << endl;
}