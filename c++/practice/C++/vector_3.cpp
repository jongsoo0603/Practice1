#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
	// ===========
	// ���� ����2

	vector <int> v;

	int x;
	
	cout << "���� 5�� �Է� : ";
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	cout <<  "�Էµ� �迭: ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) % 2 != 0)
		{
			cout << v.at(i) << " ����" << endl;
			v.erase(v.begin() + i);
			i--;
		}
	}

	cout << "\n���� ��� : ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	
}