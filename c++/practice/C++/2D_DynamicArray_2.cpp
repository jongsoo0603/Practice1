#include <iostream>

using namespace std;

int main()
{
	// =========
	// �迭 ����
	int x, y, a, sum = 0;

	while (1)
	{
		cout << "��� ���� ���� �Է��ϼ���:";
		cin >> x >> y;
		if (x > 0 && y > 0)
		{
			break;
		}
		cout << "x�� y��� ����� �Է��ϼ���.\n";
	}

	int** arr = new int* [x]; // �� �����迭 ����, �Ҵ�

	for (int i = 0; i < x; i++) // �� �����迭 ����, �Ҵ�
	{
		arr[i] = new int[y];
	}

	cout << "��� ���Ҹ� �Է��ϼ���: \n";

	for (int i = 0; i < x; i++) // �迭 �Է�
	{
		for (int j = 0; j < y; j++)
		{
			cin >> a;
			arr[i][j] = a;
		}
	}

	cout << "\n�� ���� ��:\n";
	for (int i = 0; i < x; i++) 
	{
		for (int j = 0; j < y; j++)
		{
			sum += arr[i][j];
		}
		cout << "�� " << i + 1 << " : " << sum << endl;
		sum = 0;
	}

	cout << "\n\n�� ���� ��:\n";
	for (int i = 0; i <y; i++) 
	{
		for (int j = 0; j < x; j++)
		{
			sum += arr[j][i];
		}
		cout << "�� " << i + 1 << " : " << sum << endl;
		sum = 0;
	}



	for (int i = 0; i < x; i++) // �����迭 ����(�ݳ�)
	{
		delete[] arr[i];
	}
	delete[] arr;
}