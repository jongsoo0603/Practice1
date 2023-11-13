#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
    srand(time(NULL));
    int hitterIn, randomNumber, strike = 0, ball = 0, end = 0, gameCount = 0;
    vector<int> pitcher, hitter, pitcherCheck(10), hitterCheck(10);

    while (pitcher.size() < 3)
    {
        randomNumber = (rand() % 8) + 1;
        if (pitcherCheck[randomNumber] == 0)
        {
            pitcher.push_back(randomNumber);
            pitcherCheck[randomNumber] = 1;
        }
    }
    for (int p : pitcher) // pitcher 테스트용
    {
        cout << p << " ";
    }
    cout << endl;
    while (end == 0)
    {
        cout << "1 ~ 9 사이의 숫자 3개를 입력하시오.(이외의 숫자: 종료) : " << endl;
        while (hitter.size() < 3)
        {
            cin >> hitterIn;
            if ((hitterIn > 0 && hitterIn < 10) && hitterCheck[hitterIn] == 0)
            {
                hitter.push_back(hitterIn);
                hitterCheck[hitterIn] = 1;
            }
            else if ((hitterIn > 0 && hitterIn < 10) && hitterCheck[hitterIn] == 1)
            {
                cout << "이미 입력된 숫자입니다. 다시 입력해 주세요" << endl;
            }
            else
            {
                cout << "게임을 종료하였습니다." << endl;
                end = 1;
            }
        }

        for (int h : hitter)
        {
            if (pitcherCheck[h] == hitterCheck[h]) // 중복 개수 체크
            {
                ball++;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            if (pitcher[i] == hitter[i]) // 같은 인덱스에 같은 값인지 체크
            {
                strike++;
            }
        }

        if (strike != 3)
        {
            cout << "strike : " << strike << "   Ball : " << ball - strike << endl;
            hitter.clear(), hitterCheck.assign(10, 0);
            ball = 0, strike = 0;
            gameCount++;
        }
        else
        {
            cout << gameCount << "번 만에 맞췄습니다." << endl;
            end = 1;
        }
    }
}