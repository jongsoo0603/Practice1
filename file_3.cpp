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


	if (in == 1)
	{
		cout << "\n�α��� ����\n��ȭ��ȣ�� �Է��ϼ��� : ";
		cin >> pn;
		tmp = name + " " + pn + "\n";

		string str = {};
		ifstream t_r("member_tel.txt");
		if (t_r.fail()) // ������ ���ٸ�
		{
			ofstream t_w("member_tel.txt"); // tmp�� ���� ����
			t_w << tmp;
			t_w.close();
			cout << "\n������ �����߽��ϴ�." << endl;
		}

		else // ������ ������� �ִٸ�
		{
			while (getline(t_r, line, ' ')) // str ���ڿ��� ���� ��ü ���� �������� ����
			{
				str += line + " ";
			}
			str.erase(str.size() - 1);
			t_r.close();

			idx = str.find(name);  // �̸��� �ε���

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
				cout << "\n��ȣ�� �����߽��ϴ�." << endl;
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
				cout << "\n��ȣ�� �߰��߽��ϴ�." << endl;
			}
		}
	}
	else
	{
		cout << "�α��� ����";
	}

	

}