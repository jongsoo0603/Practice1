
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> babbling = { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" };
    vector<string> pronunc = { "aya", "ye", "woo", "ma" };
    
    int answer = 0; 
    string star = "*", tmp;


    for (int i = 0; i < babbling.size(); i++) // babbling 속 pronunc를 *로 교체
    {
        tmp = "";
        for (int j = 0; j < pronunc.size(); j++)
        {
            int idx = babbling[i].find(pronunc[j]);
            if (idx != -1)
            {
                int len = pronunc[j].length();
                cout<< i << " = " << babbling[i] << " -> ";
                babbling[i].replace(idx, len, star);
                cout << babbling[i] << endl;
                if (babbling[i].substr(idx + 1, len) == pronunc[j])
                {
                    tmp += babbling[i].substr(idx + 1, len);
                }
                j = -1;
            }

        }
        babbling[i] += tmp;
    }

    for (int i = 0; i < babbling.size(); i++) // * 삭제, 비어있는 문자열 체크
    {
        int idx = babbling[i].find(star);
        while (idx != -1)
        {
            babbling[i].erase(babbling[i].begin() + idx);
            idx = babbling[i].find(star);
        }
        if (babbling[i].size() == 0)
        {
            answer += 1;
        }
    }

    for (int i = 0; i < babbling.size(); i++)
    {
        cout << i << ":" << babbling[i] << endl;
    }

    cout << answer;
}