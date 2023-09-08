#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

using namespace std;

int main() 
{
	//ifstream file_r;
	//file_r.open("test_file.txt");
	ifstream file_r("hello.txt"); //���� 2���� �� ����

	if (file_r.fail()) {
		cout << "���� ����" << endl;
	}

	vector <string> v = {};
	string file_str = "", line;
	while (getline(file_r, line))
	{
		file_str = line + "\n";
		v.insert(v.begin(), file_str);
	}

	file_r.close();

	// ofstream file_w;
	// file_write.open("output.txt");
	ofstream file_w("output.txt");

	if (file_w.fail()) {
		cout << "���� ����" << endl;
	}

	for (int i = 0; i < v.size(); i++)
	{
		file_w << v[i];
	}

	file_w.close();
}