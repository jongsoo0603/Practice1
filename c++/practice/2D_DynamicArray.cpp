#include <iostream>

using namespace std;

int main()
{
	// ==============
	// 2차원 배열 실습
	int x, y, z = 1;

	while (1)
	{
		cout << "x를 입력하세요:";
		cin >> x; // 행
		cout << "y를 입력하세요:";
		cin >> y; // 열
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

	for (int i = 0; i < x; i++) // 배열 입력
	{
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = z;
			z++;
		}
	}

	for (int i = 0; i < x; i++) // 배열 출력
	{
		for (int j = 0; j < y; j++)
		{
			cout << arr[i][j] << "\t"; // cout << setw(3) << arr[i][j]
		}
		cout << endl;
	}

	for (int i = 0; i < x; i++) // 동적배열 해제(반납)
	{
		delete[] arr[i];
	}
	delete[] arr;
}