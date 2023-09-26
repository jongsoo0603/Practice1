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
	cout << "2. 첫 번째 문자 소문자로 변경 : " << s << endl;

	cout << "3. \"ding\" 부분문자열 반환 : " << s.substr(2,4) << endl;

	string o = "oooo";
	s.replace(2, 4, o);
	cout << "4. \"coooooon\"으로 변경 : " << s << endl;

	s.erase(2, 5);
	cout << "5. \"con\"으로 변경 : " << s << endl;
	
	
}
