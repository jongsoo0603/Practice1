#include<iostream>

using namespace std;

class Rectangle {
private:
	double width{ 0 };
	double height{ 0 };

public:

	Rectangle(double w, double h) : width(w), height(h)
    {
		// this->width = w;
		// this->height = h;
	}
    
    double getwidth()
    {
        return width;
    }
    double getheight()
    {
        return height;
    }

    void setwidth(double width)
    {
        this->width = width;
    }
    void setheight(double height)
    {
        this->height = height;
    }

    double area()
    {
        return width * height;
    }
};


int main()
{
    Rectangle rect(1, 2);
    cout << "\nrect(1, 2) 넓이는 : " << rect.area() << endl;

    float w, h;
    cout << "\n사각형의 가로와 세로 길이를 입력해주세요. (띄어쓰기로 구분) : ";
    cin >> w >> h;

    rect.setwidth(w);
    rect.setheight(h);

    cout << "넓이는 : " << rect.area() << endl;
    cout << "가로와 세로 길이는 : " << rect.getwidth() << " " << rect.getheight() << endl;
}