#include <iostream>

using namespace std;


class Rectangle {
private:
	double width{ 0 };
	double height{ 0 };
public:

	Rectangle() {};

	Rectangle(double width, double height) {
		this->width = width;
		this->height = height;
	}

	Rectangle(Rectangle& other) {
		cout << "copy" << endl;
		width = other.width*2;
		height = other.height*2;
	}

	double area() {
		return width * height;
	}

	// Rectangle& operator=(const Rectangle& other) {
	// 	cout << "operator = " << endl;
	// 	if (this == &other) {
	// 		return *this;
	// 	}

	// 	width = 1;
	// 	height = 1;
	// 	return *this;
	// }
};

int main() {
	double width, height;
	cout << "가로, 세로 길이를 입력하세요 : ";
	cin >> width >> height;

	Rectangle r(width, height);

	cout << "1. 넓이는 : " << r.area() << endl;

	//Rectangle r2(r);
	Rectangle r2 = r;
	cout << "2. 넓이는 : " << r2.area() << endl;

	Rectangle r3;
	r3 = r;
	cout << "3. 넓이는 : " << r3.area() << endl;;

}






