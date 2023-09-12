#include <iostream>

using namespace std;

class Rectangle
{
    private: // 접근제어자
        float width, height;
    public: // 접근제어자
        Rectangle(float _width, float _height) : width(_width), height(_height){} // 생성자

        float area() // 클래스 안에서 메소드 선언
        {
            return width * height;
        }
};

int main()
{
    float w, h;

    cout << "사각형의 가로와 세로 길이를 입력해주세요. (띄어쓰기로 구분) : ";
    cin >> w >> h;

    Rectangle r(w, h);
    
    cout << "넓이는 : " << r.area();
}