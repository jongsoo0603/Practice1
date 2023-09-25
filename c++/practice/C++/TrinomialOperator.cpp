#include<iostream>

int main()
{
    int num;
    
    std::cout << "숫자을 입력하세요\n";    
    std::cin >> num;

    num % 5 == 0 ? std::cout << "입력한 숫자는 5의 배수입니다." : std::cout << "입력한 숫자는 5의 배수가 아니네요ㅠㅠ";

}