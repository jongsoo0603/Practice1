#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string name, pw, line, m_name, m_pw;
	int cnt = 0;

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;
	cout << "����� �Է��ϼ��� : ";
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
		cout << "�α��� ����";
	}
	else
	{
		cout << "�α��� ����";
	}

	f_r.close();

}