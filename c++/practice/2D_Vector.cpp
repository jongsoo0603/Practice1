#include <iostream>
#include <vector>
#include<iomanip>

using namespace std;

int main()
{
	// ===========
	// ���� �ǽ�

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

	vector< vector <int> >arr; // x�� ����
	arr.assign(x, vector <int>(y)); // y�� ����


	for (int i = 0; i < x; i++) // �迭 �Է�
	{
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = z; // arr.at(i).at(j) = z
			z++;
		}
	}

	for (int i = 0; i < x; i++) // �迭 ���
	{
		for (int j = 0; j < y; j++)
		{
			cout << setw(3) << arr[i][j]; // setw(3) == 3ĭ Ȯ�� �� ���(iomanip �������)
		}
		cout << endl;
	}
}