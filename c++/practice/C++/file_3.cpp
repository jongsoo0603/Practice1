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


	if (in == 1)
	{
		cout << "\n로그인 성공\n전화번호를 입력하세요 : ";
		cin >> pn;
		tmp = name + " " + pn + "\n";

		string str = {};
		ifstream t_r("member_tel.txt");
		if (t_r.fail()) // 파일이 없다면
		{
			ofstream t_w("member_tel.txt"); // tmp로 파일 생성
			t_w << tmp;
			t_w.close();
			cout << "\n파일을 생성했습니다." << endl;
		}

		else // 파일이 만들어져 있다면
		{
			while (getline(t_r, line, ' ')) // str 문자열에 파일 전체 공백 기준으로 붙임
			{
				str += line + " ";
			}
			str.erase(str.size() - 1);
			t_r.close();

			idx = str.find(name);  // 이름의 인덱스

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
				cout << "\n번호를 수정했습니다." << endl;
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
				cout << "\n번호를 추가했습니다." << endl;
			}
		}
	}
	else
	{
		cout << "로그인 실패";
	}

	

}