#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    string wordIn, print = "airplane";
    time_t t1, t2;
    int count = 0;

    while ((t2 - t1) < 11)
    {
        cout << "\n"
             << print << endl;
        cout << "다음 단어를 입력하세요 : ";
        t1 = time(NULL);
        cin >> wordIn;

        if (print.back() != wordIn.front())
        {
            cout << "잘못된 입력" << endl;
        }
        else if (print.find(wordIn) != string::npos)
        {
            cout << "중복된 입력" << endl;
        }
        else
        {
            t2 = time(NULL);
            print += " -> " + wordIn;
            count += 1;
        }
    }
    cout << "타임오버!\n\n게임 종료!\n총 입력한 단어 개수 : " << count - 1 << endl;
}