#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> babbling = { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" };
    
    int answer = 0;

    string pronunc[4] = { "aya", "ye", "woo", "ma" };

    string star = "*";

    for (int i = 0; i < babbling.size(); i++) // babbling 속 pronunc를 *로 교체
    {
        for (int j = 0; j < 4; j++)
        {
            int idx = babbling[i].find(pronunc[j]);
            if (idx != -1)
            {
                int len = pronunc[j].length();
                babbling[i].replace(idx, len, star);
            }
        }
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

    /*for (int i = 0; i < babbling.size(); i++)
    {
        cout << i << ":" << babbling[i] << endl;
    }*/

    cout << answer << endl;
}