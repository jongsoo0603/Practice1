#include <iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main()
{
	// ==========
	// string �ǽ�


	string s = "Police say two people are suspected of trying to create a shortcut for their construction work.The two have been detained and the case is under further investigation.The 38-year-old man and 55-year-old woman were working near the affected area, the 32nd Great Wall. two one two one two";

	cout << "2. ���ڿ��� ���� : " << s.size() << endl << endl;

	cout << "3. 100��° ���� : " << s[99] << endl << endl;

	string t;
	int i, num = 1;
	cout << "�˻��� �ܾ� �Է� : ";
	getline(cin, t);
	cout << endl;

	i = s.find(t);
	if (i == -1)
	{
		cout << "\n�ش� �ܾ string�� �����ϴ�." << endl;
	}
	else
	{
		while (1)
		{
			if (i == -1)
			{
				break;
			}
			cout << num << "��° \"" << t << "\" �ε��� : " << i << endl;
			i = s.find(t, (i + 1));
			num++;
			
		}
	}

	/*cout << "4. ù ��° \"tw0\" index : " << s.find(t) << endl << endl;

	cout << "5. �� ��° \"tw0\" index : " << s.find(t, (s.find(t) + 1)) << endl << endl;*/

}
