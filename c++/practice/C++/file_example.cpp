#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool checkFileOpen(ifstream& file) {
	if (file.fail()) return false;
	else return true;
}

bool checkFileOpen(ofstream& file) {
	if (file.fail()) {
		cout << "파일 없음" << endl;
		return false;
	}
	else return true;
}

int main() {
	ifstream member_file;
	string name, pw, name_in, pw_in;

	member_file.open("member.txt");
	if (!checkFileOpen(member_file)) return -1;


	cout << "이름을 입력하세요. ";
	cin >> name_in;

	cout << "비번을 입력하세요. ";
	cin >> pw_in;

	bool flag = false; // 로그인 성공 여부를 담는 변수
	while (member_file >> name >> pw) {
		if (name == name_in && pw == pw_in) {
			flag = true;
			break;
		}
	}
	member_file.close();

	if (flag) {
		string tel_in, tel;
		cout << "로그인 성공" << endl;
		cout << "전화번호를 입력하세요. ";
		cin >> tel_in;

		ifstream member_tel_file_r("member_tel.txt");
		string member_tel_temp = "";

		bool is_modify = false; // 기존 정보 수정 or 추가를 판단하는 변수
		if (!member_tel_file_r.fail()) {
			while (member_tel_file_r >> name >> tel) {
				string line = name + " ";
				if (name == name_in) {
					line += tel_in;
					is_modify = true;
				}
				else line += tel;
				member_tel_temp += line + "\n";
			}
			member_tel_file_r.close();
		}

		ofstream member_tel_file_w;
		
		if (is_modify) {
			member_tel_file_w.open("member_tel.txt");
			member_tel_file_w << member_tel_temp;
		}
		else {
			member_tel_file_w.open("member_tel.txt", ios::app);
			member_tel_file_w << name_in + " " + tel_in + "\n";
		}
		
		member_tel_file_w.close();
	}
	else cout << "로그인 실패";

	return 0;
}