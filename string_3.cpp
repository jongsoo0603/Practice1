#include <iostream>
#include<string>
#include <sstream> 

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

int main()
{
	// ==========
	// string 실습3

	int a = 1, b;
	string one, two;

	while (1)
	{
		cout << "숫자로 된 첫 번째 문자열을 입력: ";
		getline(cin, one);

		stringstream ss1(one);

		for (int i = 0; i < one.size(); i++) // 하나 씩 뽑아서 숫자인지 판별
		{
			b = ss1.get();
			cout << b << endl;
			if (b < 48 || b > 57) // 숫자가 아닐 때 for문 탈출
			{
				a = 0;
			}
		}

		if (a == 0) // 다시 돌리고
		{
			cout << " -> NO" << endl;
			a = 1;
		}
		else if(a == 1)// 빠져나오고
		{
			cout << " -> OK" << endl;
			break;
		}
	}

	while (1)
	{
		cout << "숫자로 된 두 번째 문자열을 입력: ";
		getline(cin, two);

		stringstream ss2(two);

		for (int i = 0; i < one.size(); i++) // 하나 씩 뽑아서 숫자인지 판별
		{
			b = ss2.get();
			cout << b << endl;
			if (b < 48 || b > 57) // 숫자가 아닐 때 for문 탈출
			{
				a = 0;
			}
		}

		if (a == 0) // 다시 돌리고
		{
			cout << " -> NO" << endl;
			a = 1;
		}
		else if (a == 1)// 빠져나오고
		{
			cout << " -> OK" << endl;
			break;
		}
	}

	cout << "\"" << one << "\" + \"" << two << "\" -> \"" << one + two << "\"" << endl << endl;

	cout << one << " + " << two << " -> " << stoi(one) + stoi(two) << endl;



}