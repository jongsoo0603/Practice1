#include <iostream>

using namespace std;

struct Rectangle
{
    float width = 0;
    float height = 0;
};

struct Position
{
    int x, y, z;
};


int main()
{
    Rectangle r;

    // 포인터 사용
    // Rectangle *rr = &r;
    // rr -> width;
    // rr -> height;

    // 구조체 활용
    // Position p[100];
    // for(int i = 0; i < 100; i++)
    // {
    //     p[i].x;
    //     p[i].y;
    //     p[i].z;
    // }
    
    cout << "가로, 세로 길이를 입력하세요. : ";
    cin >> r.width >> r.height;
    
    cout << "넓이는 : " << r.width * r.height << endl;
}