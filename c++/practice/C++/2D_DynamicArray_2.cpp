#include <iostream>

using namespace std;

int main()
{
	// =========
	// 배열 복습
	int x, y, a, sum = 0;

	while (1)
	{
		cout << "행과 열의 수를 입력하세요:";
		cin >> x >> y;
		if (x > 0 && y > 0)
		{
			break;
		}
		cout << "x와 y모두 양수를 입력하세요.\n";
	}

	int** arr = new int* [x]; // 행 동적배열 선언, 할당

	for (int i = 0; i < x; i++) // 열 동적배열 선언, 할당
	{
		arr[i] = new int[y];
	}

	cout << "행렬 원소를 입력하세요: \n";

	for (int i = 0; i < x; i++) // 배열 입력
	{
		for (int j = 0; j < y; j++)
		{
			cin >> a;
			arr[i][j] = a;
		}
	}

	cout << "\n각 행의 합:\n";
	for (int i = 0; i < x; i++) 
	{
		for (int j = 0; j < y; j++)
		{
			sum += arr[i][j];
		}
		cout << "행 " << i + 1 << " : " << sum << endl;
		sum = 0;
	}

	cout << "\n\n각 열의 합:\n";
	for (int i = 0; i <y; i++) 
	{
		for (int j = 0; j < x; j++)
		{
			sum += arr[j][i];
		}
		cout << "열 " << i + 1 << " : " << sum << endl;
		sum = 0;
	}



	for (int i = 0; i < x; i++) // 동적배열 해제(반납)
	{
		delete[] arr[i];
	}
	delete[] arr;
}