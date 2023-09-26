#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
	// ===========
	// 벡터 복습2

	vector <int> v;

	int x;
	
	cout << "정수 5개 입력 : ";
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	cout <<  "입력된 배열: ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) % 2 != 0)
		{
			cout << v.at(i) << " 삭제" << endl;
			v.erase(v.begin() + i);
			i--;
		}
	}

	cout << "\n삭제 결과 : ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	
}