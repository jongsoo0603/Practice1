#include <string>
#include <vector>
#include<iostream>

using namespace std;
using ULL = unsigned long long;

int main()
{
	string t = "3141592", p = "271", tmp;

	ULL len = (t.length() - p.length()) + 1, answer = 0;

	for (int i = 0; i < len; i++)
	{
		tmp = t.substr(i, p.length());

		if (stoll(tmp) <= stoll(p))
		{
			answer += 1;
		}
	}

	cout << answer;

}