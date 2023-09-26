#include<iostream>
#include<list>

using std::cout;
using std::cin;
using std::endl;
using std::list;

int main()
{
	// ==========
	// list 실습

	int four = 0;
	
	list <int> myList = { 5,4, 3, 4, 2, 1, 1 };

	cout << "(1) myList :";
	for (int& l : myList)
	{
		cout << l << " ";
	}

	for (int& l : myList)
	{
		if (l == 4)
		{
			four++;
		}
	}
	cout << "\n\n(2) 4의 개수 : " << four;

	cout << "\n\n(3) 정렬(merge) : ";
	myList.sort();
	for (int& l : myList)
	{
		cout << l << " ";
	}

	cout << "\n\n(4) 중복제거(unique) : ";
	myList.unique();
	for (int& l : myList)
	{
		cout << l << " ";
	}

	cout << "\n\n(5) 6, 7 뒤에 추가(merge) : ";
	list <int> twoList = { 6, 7 };
	myList.merge(twoList);
	for (int& l : myList)
	{
		cout << l << " ";
	}

	cout << "\n\n(6) 0 앞에 추가(splice) : ";
	list <int> oneList = { 0 };
	oneList.splice(oneList.end(), myList);
	for (int& l : oneList)
	{
		cout << l << " ";
	}

	// =========
	// 정적 배열 복습
	int a[5] = { 1, 2, 3, 4, 5 };
	int insert;
	cout << "\n\n번외) 배열 앞에 0 삽입 \n\n기존 : ";
	for (int i : a)
	{
		cout << i << " ";
	}

	cout << "\n\n앞에 삽입할 숫자 입력 : ";
	cin >> insert;
	
	for (int i = 4; i > 0; i--) // 3->4, 2->3 ...
	{
		a[i] = a[i - 1];
	}
	a[0] = insert;

	cout << "\n삽입 후 : ";
	for (int arr : a)
	{
		cout << arr << " ";
	}

	cout << "\n\n뒤에 삽입할 숫자 입력 : ";
	cin >> insert;
	
	for (int i = 0; i < 4; i++)
	{
		a[i] = a[i + 1];
	}
	a[4] = insert;

	cout << "\n삽입 후 : ";
	for (int arr : a)
	{
		cout << arr << " ";
	}

}