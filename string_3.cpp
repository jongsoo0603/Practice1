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
	// string �ǽ�3

	int a = 1, b;
	string one, two;

	while (1)
	{
		cout << "���ڷ� �� ù ��° ���ڿ��� �Է�: ";
		getline(cin, one);

		stringstream ss1(one);

		for (int i = 0; i < one.size(); i++) // �ϳ� �� �̾Ƽ� �������� �Ǻ�
		{
			b = ss1.get();
			cout << b << endl;
			if (b < 48 || b > 57) // ���ڰ� �ƴ� �� for�� Ż��
			{
				a = 0;
			}
		}

		if (a == 0) // �ٽ� ������
		{
			cout << " -> NO" << endl;
			a = 1;
		}
		else if(a == 1)// ����������
		{
			cout << " -> OK" << endl;
			break;
		}
	}

	while (1)
	{
		cout << "���ڷ� �� �� ��° ���ڿ��� �Է�: ";
		getline(cin, two);

		stringstream ss2(two);

		for (int i = 0; i < one.size(); i++) // �ϳ� �� �̾Ƽ� �������� �Ǻ�
		{
			b = ss2.get();
			cout << b << endl;
			if (b < 48 || b > 57) // ���ڰ� �ƴ� �� for�� Ż��
			{
				a = 0;
			}
		}

		if (a == 0) // �ٽ� ������
		{
			cout << " -> NO" << endl;
			a = 1;
		}
		else if (a == 1)// ����������
		{
			cout << " -> OK" << endl;
			break;
		}
	}

	cout << "\"" << one << "\" + \"" << two << "\" -> \"" << one + two << "\"" << endl << endl;

	cout << one << " + " << two << " -> " << stoi(one) + stoi(two) << endl;



}