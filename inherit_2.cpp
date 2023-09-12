// 오버라이딩

#include<iostream>

using namespace std;

class Shape
{
    protected:
        int side_num;
        double side_len;
    public:
        void printinfo()
        {
            cout << "변의 개수 : " << side_num << ", 변의 길이 : " << side_len << endl;
        }
};

class Recrangle : public Shape
{
    private:
        double height;
    public:
        Recrangle(int side_num, double side_len, double height)
        {
            this -> side_num = side_num;
            this -> side_len = side_len;
            this -> height = height;
        }
        void printinfo()
        {
            cout << "사각형의 넓이는 " << side_len * height << endl;
        }

};

class Triangle : public Shape
{
    private:
        double height;
    public:
        Triangle(int side_num, double side_len, double height)
        {
            this -> side_num = side_num;
            this -> side_len = side_len;
            this -> height = height;
        }
        void printinfo()
        {
            cout << "삼각형의 넓이는 " << (side_len * height) / 2 << endl;
        }
};

int main()
{
    int side_num;
    double side_len, height;

    cout << "사각형의 변의 개수, 밑변의 길이, 높이 입력 : ";
    cin >> side_num >> side_len >> height;
    Recrangle r(side_num, side_len, height);
    r.printinfo();

    cout << "사각형의 변의 개수, 밑변의 길이, 높이 입력 : ";
    cin >> side_num >> side_len >> height;
    Triangle t(side_num, side_len, height);
    t.printinfo();
}