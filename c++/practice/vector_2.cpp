#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// =========
	// ���� ����

	int x, max = 0, idx, del, y;

	vector <int> myVector;

	cout << "���� 5�� �Է�: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		myVector.push_back(x);
	}

	cout << "\n(3)������ ũ��: " << myVector.size() << endl;

	cout << "\n(4)��� ���� : ";
	for (int i = 0; i < 5; i++)
	{
		cout << myVector.at(i) << " ";
	}


	for (int i = 0; i < 5; i++)
	{
		if (max < myVector.at(i))
		{
			max = myVector.at(i);
		}
	}
	cout << "\n\n(5)���� ū �� : " << max << endl;

	cout << "\n(6)��� ���� X 2 : ";
	for (int i = 0; i < 5; i++)
	{
		myVector.at(i) *= 2;
		cout << myVector.at(i) << " ";
	}

	cout << "\n\n������ �ε��� �Է� : ";
	cin >> idx;
	myVector.erase(myVector.begin() + idx);
	cout << "(7)��� ���� : ";
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector.at(i) << " ";
	}

	cout << "\n\n������ �ε��� �Է� : ";
	cin >> idx;
	cout << "������ ���� �Է� : ";
	cin >> x;
	myVector.insert(myVector.begin() + idx, x);
	cout << "(8)��� ���� : ";
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector.at(i) << " ";
	}

}