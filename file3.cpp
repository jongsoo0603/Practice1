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
			in = 1;
		}
	}

	f_r.close();

	string str;

	if (in == 1)
	{
		cout << "�α��� ����\n��ȭ��ȣ�� �Է��ϼ��� : ";
		cin >> pn;
		tmp = name + " " + pn + "\n";
		if (str.empty()) // ������ ���ٸ�
		{
			str += tmp;
			ofstream f_w("member_tel.txt");
			f_w << str;
			f_w.close();
		}
		else // ������ ����� ���ٸ�
		{
			str = {};
			ifstream t_r("member_tel.txt");
			while (getline(t_r, line, ' '))
			{
				str += line + " ";
			}
			str.erase(str.size() - 1);
			t_r.close();

			idx = str.find(name);  // �̸��� �ε���

			cout << "str " << str << " idx " << idx;

			if (idx != -1) //�̸��� ������ replace
			{
				str.replace(idx, tmp.size(), tmp);
				ofstream f_w("member_tel.txt");
				idx = 0;
				for (int i = 0; i < (str.size() / tmp.size()); i++) //�̸�+��ȣ ũ��� �߶� 
				{
					f_w << str.substr(idx, tmp.size());
					idx += tmp.size();
				}
				f_w.close();
			}
			else// ������ �߰�
			{
				str += tmp;
				ofstream f_w("member_tel.txt");
				idx = 0;
				for (int i = 0; i < (str.size() / tmp.size()); i++) //�̸�+��ȣ ũ��� �߶� 
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
		cout << "�α��� ����";
	}

	

}