#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream f_w("member.txt");

	string name, pw, mem;

	cout << "3���� ȸ���� ���� �̸� ��й�ȣ�� ���������� �Է��ϼ���." << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << "��° ȸ�� : ";
		cin >> name >> pw;
		f_w << name + " " + pw + "\n";
	}

	f_w.close();

	ifstream f_r("member.txt");

	cout << "\n----------ȸ�� ��� ���� �б�----------" << endl;
	while (getline(f_r, mem))
	{
		cout << mem << endl;
	}

	f_r.close();

}