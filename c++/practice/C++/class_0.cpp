#include <iostream>

using namespace std;

class Rectangle
{
    private:
        float m_width, m_height;
    public:
        Rectangle(float width, float height) : m_width(width), m_height(height) {}
        float area()
        {
            return m_width * m_height;
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