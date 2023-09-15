#include<iostream>

int main()
{
    int a, b;
    std::string c;
    
    std::cout << "연산할 정수 두 개를 입력해 주세요\n";    
    std::cin >> a >> b;
    std::cout << "연산자를 입력해 주세요(+ - * /)\n";
    std::cin >> c;

    if (c == "+")
    {
        std::cout << "**** 연산결과 --->값:" << (a+b);
    }
    else if(c == "-")
    {
        std::cout << "**** 연산결과 --->값:" << (a-b);
    }
    else if(c == "*")
    {
        std::cout << "**** 연산결과 --->값:" << (a*b);
    }
    else if(c == "/")
    {
        std::cout << "**** 연산결과 --->목:" << (a/b) << ", 나머지:" << (a%b) << "입니다.";
    }
    
}