#include <iostream>
#include <vector>
#include<iomanip>

using namespace std;

int main()
{
	// =========
	// 벡터 실습2

	vector <int> myVector = { 1,1,1,1,2,3,4 };
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
}