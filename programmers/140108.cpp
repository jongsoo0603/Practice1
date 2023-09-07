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

	string s = "aaabbaccccabba", xs;
	char x, dif;
	int xCnt = 0, dCnt = 0;

	x = s[0];
	for (int i = 0; i < s.size(); i++)
	{
		xs += s[i];
		if (s[i] == x)
		{
			xCnt += 1;
		}
		else
		{
			dCnt += 1;
		}


	}
	cout << xs;
}