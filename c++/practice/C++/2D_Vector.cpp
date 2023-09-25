#include <iostream>
#include <vector>
#include<iomanip>

using namespace std;

int main()
{
	// ===========
	// 벡터 실습

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

	vector< vector <int> >arr; // x행 생성
	arr.assign(x, vector <int>(y)); // y열 생성


	for (int i = 0; i < x; i++) // 배열 입력
	{
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = z; // arr.at(i).at(j) = z
			z++;
		}
	}

	for (int i = 0; i < x; i++) // 배열 출력
	{
		for (int j = 0; j < y; j++)
		{
			cout << setw(3) << arr[i][j]; // setw(3) == 3칸 확보 후 출력(iomanip 헤더파일)
		}
		cout << endl;
	}
}