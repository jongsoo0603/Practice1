#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// aaabbacc - ccab - ba
	// a -> xcnt 1 dcnt 0
	// aa -> xcnt 2 dcnt 0
	// aaa -> xcnt 3 dcnt 0
	// aaab -> xcnt 3 dcnt 1
	// aaabb -> xcnt 3 dcnt 2
	// aaabba -> xcnt 4 dcnt 2
	// aaabbac -> xcnt 4 dcnt 3
	// aaabbac -> xcnt 4 dcnt 4

	string s = "abracadabra";
	string xs;
	char x;
	int xCnt = 0, dCnt = 0, answer = 0, len = 0;

	x = s[0];
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == x)
		{
			xCnt += 1;
		}
		else
		{
			dCnt += 1;
		}

		xs += s[i];
		
		if (xCnt == dCnt)
		{
			answer += 1;
			xCnt = 0;
			dCnt = 0;
			x = s[i+1];
			cout << xs << endl;
			xs = {};
		}
		else if (i == s.size() - 1)
		{
			answer += 1;
			cout << xs << endl;
		}


	}
	cout << answer;
}