#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream f_w("member.txt");

	string name, pw, mem;

	cout << "3명의 회원에 대한 이름 비밀번호를 순차적으로 입력하세요." << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << "번째 회원 : ";
		cin >> name >> pw;
		f_w << name + " " + pw + "\n";
	}

	f_w.close();

	ifstream f_r("member.txt");

	cout << "\n----------회원 명부 파일 읽기----------" << endl;
	while (getline(f_r, mem))
	{
		cout << mem << endl;
	}

	f_r.close();

}