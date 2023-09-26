#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s = "1HELLO 1WORLD", answer;

	if (s[0] > 96 || s[0] < 123)
	{
		s[0] = toupper(s[0]);
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 32)
		{
			s[i+1] = toupper(s[i + 1]);
		}
		else
		{
			s[i + 1] = tolower(s[i + 1]);
		}
	}

	cout << s;
}