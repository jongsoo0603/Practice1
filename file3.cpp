#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	string name, pw, line, m_name, m_pw, pn, tmp;
	int in = 0, idx;
	vector<string> v;

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
			in = 1;
		}
	}

	f_r.close();

	string str;

	if (in == 1)
	{
		cout << "로그인 성공\n전화번호를 입력하세요 : ";
		cin >> pn;
		tmp = name + " " + pn + "\n";
		if (str.empty()) // 파일이 없다면
		{
			str += tmp;
			ofstream f_w("member_tel.txt");
			f_w << str;
			f_w.close();
		}
		else // 파일이 만들어 졌다면
		{
			str = {};
			ifstream t_r("member_tel.txt");
			while (getline(t_r, line, ' '))
			{
				str += line + " ";
			}
			str.erase(str.size() - 1);
			t_r.close();

			idx = str.find(name);  // 이름의 인덱스

			cout << "str " << str << " idx " << idx;

			if (idx != -1) //이름이 있으면 replace
			{
				str.replace(idx, tmp.size(), tmp);
				ofstream f_w("member_tel.txt");
				idx = 0;
				for (int i = 0; i < (str.size() / tmp.size()); i++) //이름+번호 크기로 잘라서 
				{
					f_w << str.substr(idx, tmp.size());
					idx += tmp.size();
				}
				f_w.close();
			}
			else// 없으면 추가
			{
				str += tmp;
				ofstream f_w("member_tel.txt");
				idx = 0;
				for (int i = 0; i < (str.size() / tmp.size()); i++) //이름+번호 크기로 잘라서 
				{
					f_w << str.substr(idx, tmp.size());
					idx += tmp.size();
				}
				f_w.close();
			}
		}
		
		
	}
	else
	{
		cout << "로그인 실패";
	}

	

}