#include <iostream>

using namespace std;

int main()
{
	// =========
	// �迭 �ǽ�2

	int student, score, sum = 0;


	cout << "�л��� ���� �Է��ϼ���: ";
	cin >> student;

	int* arr = new int[student];

	for (int i = 0; i < student; i++)
	{
		cout << i + 1 << " �� �л��� ������ �Է��ϼ���: ";
		cin >> score;
		arr[i] = score;
	}

	for (int i = 0; i < student; i++)
	{
		sum += arr[i];
	}

	cout << "�������: " << (sum * 1.0) / student;
}