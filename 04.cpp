// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include<iomanip>

using namespace std;

int main()
{
	/*
	cout << "Hello World!\n";

	// ==========
	// 동적배열
	int n2;
	cout << "숫자를 입력하세요: ";
	cin >> n2;

	int* arr = new int[n2];

	for (int i = 0; i < n2; i++)
	{
		arr[i] = i + 1;
	}

	// 반납은 delete
	delete[] arr;



	// ==========
	// 2차원 동적배열
	int n3;
	cout << "숫자를 입력하세요: ";
	cin >> n3;



	// 동적 배열 선언 & 할당
	int **arr2 = new int *[n3]; // 2차원

	for (int i = 0; i < n3; i++)
	{
		arr2[i] = new int [n3]; // 1차원
	}

	for (int i = 0; i < n3; i++)
	{
		for (int j = 0; j < n3; j++)
		{
			arr2[i][j] = 0; // 동적 배열 사용
		}
	}

	for (int i = 0; i < n3; i++)
	{
		for (int j = 0; j < n3; j++)
		{
			cout << arr2[i][j]; // 동적 배열 사용
		}
		cout << endl;
	}

	

	// 동적 배열 해제(반납)
	for (int i = 0; i < n3; i++)
	{
		delete[] arr2[i];
	}
	delete[] arr2;
	


	// =========
	// 배열 실습
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

	int **arr = new int *[x]; // 동적배열 선언

	for (int i = 0; i < x; i++) // 동적배열 할당
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

	

	// =========
	// 배열 실습2

	int student, score, sum = 0;

	
	cout << "학생의 수를 입력하세요: ";
	cin >> student;

	int *arr = new int[student];

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
	arr.assign(x, vector <int> (y)); // y열 생성


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
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
	
	

	// ===========
	// 벡터 실습2

	vector <int> myVector = {1,1,1,1,2,3,4};
	vector <int> v;

	for (int i = 0; i < (myVector.size() - 1); i++)
	{
		for (int j = (i + 1); j < myVector.size(); j++)
		{
			if (myVector.at(i) == myVector.at(j))
			{
				myVector.erase(myVector.begin() + j);
				j--;
			}
		}
	}
	
	cout << "결과: { ";
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << " ,";
	}
	cout << "};";
	*/





}




















// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
