#include <iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string s = "Codingon";
	
	cout << "1. string s : " << s << endl;

	s[0] = tolower(s[0]);
	cout << "2. ù ��° ���� �ҹ��ڷ� ���� : " << s << endl;

	cout << "3. \"ding\" �κй��ڿ� ��ȯ : " << s.substr(2,4) << endl;

	string o = "oooo";
	s.replace(2, 4, o);
	cout << "4. \"coooooon\"���� ���� : " << s << endl;

	s.erase(2, 5);
	cout << "5. \"con\"���� ���� : " << s << endl;
	
	
}
