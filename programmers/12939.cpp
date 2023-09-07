#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	string s = "1 2 3 4", answer = "", m, n;
	int max = -2147483648, min = 2147483647, num;

	stringstream stream;
	stream.str(s);

	while (stream >> num)
	{
		if(num >= max)
		{
			max = num;
		}
		if (num <= min)
		{
			min = num;
		}
	}

	answer = to_string(min) + " " + to_string(max);

	cout << answer;
}