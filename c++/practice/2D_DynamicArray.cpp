#include <iostream>

using namespace std;

int main()
{
	// ==============
	// 2���� �迭 �ǽ�
	int x, y, z = 1;

	while (1)
	{
		cout << "x�� �Է��ϼ���:";
		cin >> x; // ��
		cout << "y�� �Է��ϼ���:";
		cin >> y; // ��
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

	for (int i = 0; i < x; i++) // �迭 �Է�
	{
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = z;
			z++;
		}
	}

	for (int i = 0; i < x; i++) // �迭 ���
	{
		for (int j = 0; j < y; j++)
		{
			cout << arr[i][j] << "\t"; // cout << setw(3) << arr[i][j]
		}
		cout << endl;
	}

	for (int i = 0; i < x; i++) // �����迭 ����(�ݳ�)
	{
		delete[] arr[i];
	}
	delete[] arr;
}