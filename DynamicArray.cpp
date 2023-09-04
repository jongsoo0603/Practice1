#include <iostream>

using namespace std;

int main()
{
	// =========
	// 배열 실습2

	int student, score, sum = 0;


	cout << "학생의 수를 입력하세요: ";
	cin >> student;

	int* arr = new int[student];

	for (int i = 0; i < student; i++)
	{
		cout << i + 1 << " 번 학생의 성적을 입력하세요: ";
		cin >> score;
		arr[i] = score;
	}

	for (int i = 0; i < student; i++)
	{
		sum += arr[i];
	}

	cout << "성정평균: " << (sum * 1.0) / student;
}