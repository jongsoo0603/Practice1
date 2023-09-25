#include<iostream>
#include<list>

using std::cout;
using std::cin;
using std::endl;
using std::list;

int main()
{
	// ==========
	// list �ǽ�

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
	cout << "\n\n(2) 4�� ���� : " << four;

	cout << "\n\n(3) ����(merge) : ";
	myList.sort();
	for (int& l : myList)
	{
		cout << l << " ";
	}

	cout << "\n\n(4) �ߺ�����(unique) : ";
	myList.unique();
	for (int& l : myList)
	{
		cout << l << " ";
	}

	cout << "\n\n(5) 6, 7 �ڿ� �߰�(merge) : ";
	list <int> twoList = { 6, 7 };
	myList.merge(twoList);
	for (int& l : myList)
	{
		cout << l << " ";
	}

	cout << "\n\n(6) 0 �տ� �߰�(splice) : ";
	list <int> oneList = { 0 };
	oneList.splice(oneList.end(), myList);
	for (int& l : oneList)
	{
		cout << l << " ";
	}

	// =========
	// ���� �迭 ����
	int a[5] = { 1, 2, 3, 4, 5 };
	int insert;
	cout << "\n\n����) �迭 �տ� 0 ���� \n\n���� : ";
	for (int i : a)
	{
		cout << i << " ";
	}

	cout << "\n\n�տ� ������ ���� �Է� : ";
	cin >> insert;
	
	for (int i = 4; i > 0; i--) // 3->4, 2->3 ...
	{
		a[i] = a[i - 1];
	}
	a[0] = insert;

	cout << "\n���� �� : ";
	for (int arr : a)
	{
		cout << arr << " ";
	}

	cout << "\n\n�ڿ� ������ ���� �Է� : ";
	cin >> insert;
	
	for (int i = 0; i < 4; i++)
	{
		a[i] = a[i + 1];
	}
	a[4] = insert;

	cout << "\n���� �� : ";
	for (int arr : a)
	{
		cout << arr << " ";
	}

}