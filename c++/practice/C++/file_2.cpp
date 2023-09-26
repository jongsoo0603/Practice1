#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string name, pw, line, m_name, m_pw;
	int cnt = 0;

	cout << "이름을 입력하세요 : ";
	cin >> name;
	cout << "비번을 입력하세요 : ";
	cin >> pw;

	ifstream f_r("member.txt");

	while (getline(f_r, line))
	{
		stringstream stream(line);
		stream >> m_name >> m_pw;
		if (name == m_name && pw == m_pw)
		{
			cnt = 1;
		}
	}
	if (cnt == 1)
	{
		cout << "로그인 성공";
	}
	else
	{
		cout << "로그인 실패";
	}

	f_r.close();

}