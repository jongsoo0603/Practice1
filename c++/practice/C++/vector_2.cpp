#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// =========
	// 벡터 복습

	int x, max = 0, idx, del, y;

	vector <int> myVector;

	cout << "정수 5개 입력: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		myVector.push_back(x);
	}

	cout << "\n(3)벡터의 크기: " << myVector.size() << endl;

	cout << "\n(4)모든 원소 : ";
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
	cout << "\n\n(5)가장 큰 값 : " << max << endl;

	cout << "\n(6)모든 원소 X 2 : ";
	for (int i = 0; i < 5; i++)
	{
		myVector.at(i) *= 2;
		cout << myVector.at(i) << " ";
	}

	cout << "\n\n삭제할 인덱스 입력 : ";
	cin >> idx;
	myVector.erase(myVector.begin() + idx);
	cout << "(7)모든 원소 : ";
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector.at(i) << " ";
	}

	cout << "\n\n삽입할 인덱스 입력 : ";
	cin >> idx;
	cout << "삽입할 원소 입력 : ";
	cin >> x;
	myVector.insert(myVector.begin() + idx, x);
	cout << "(8)모든 원소 : ";
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector.at(i) << " ";
	}

}