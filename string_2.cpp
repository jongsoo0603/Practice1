#include <iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main()
{
	// ==========
	// string 실습2
	string one, two;
	int a = 0;

	while (1)
	{
		cout << "숫자로 된 첫 번째 문자열을 입력: ";
		getline(cin, one);

		for (int i = 0; i < one.size(); i++)
		{
			if (isdigit(one[i]) != 0)
			{
				a += 1;
			}
		}

		if (a == one.size())
		{
			cout << "-> OK" << endl << endl;
			a = 0;
			break;
		}
		else
		{
			cout << "-> NO" << endl;
		}
	}

	while (1)
	{
		cout << "숫자로 된 두 번째 문자열을 입력: ";
		getline(cin, two);

		for (int i = 0; i < two.size(); i++)
		{
			if (isdigit(two[i]) != 0)
			{
				a += 1;
			}
		}

		if (a == two.size())
		{
			cout << "-> OK" << endl << endl;
			a = 0;
			break;
		}
		else
		{
			cout << "-> NO" << endl;
		}
	}

	cout << "\"" << one << "\" + \"" << two << "\" -> \"" << one + two << "\"" << endl << endl;

	cout << one << " + " << two << " -> " << stoi(one) + stoi(two) << endl;


}