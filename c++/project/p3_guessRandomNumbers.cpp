#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
    srand(time(NULL));
    int lottoCheck[26] = {0}, guessCheck[26] = {0}, guessIn, randomNumber, ranking = 7, i = 0;
    string lottoString;
    vector<int> lotto, guess;

    while (i < 6)
    {
        randomNumber = (rand() % 24) + 1;
        if (lottoCheck[randomNumber] == 0)
        {
            lotto.push_back(randomNumber);
            lottoCheck[randomNumber] = 1;
            i++;
        }
    }

    i = 0;
    cout << "숫자는 1 ~ 25까지의 숫자만 입력할 수 있습니다." << endl;

    while (i < 6)
    {
        cout << i + 1 << "번째 번호를 입력하세요 : ";
        cin >> guessIn;
        if ((guessIn > 0 && guessIn < 26) && guessCheck[guessIn] == 0)
        {
            guess.push_back(guessIn);
            guessCheck[guessIn] = 1;
            i++;
        }
        else if (guessCheck[guessIn] == 1)
        {
            cout << "이미 입력된 숫자입니다. 다시 입력해 주세요" << endl;
        }
        else
        {
            cout << "잘못된 숫자입니다. 1 ~ 25까지의 숫자를 입력하세요." << endl;
        }
    }

    for (int g : guess)
    {
        if (lottoCheck[g] == guessCheck[g])
        {
            ranking--;
        }
    }

    cout << "--------------------\n*당첨번호 공개*" << endl;
    for (int l : lotto)
    {
        cout << l << " ";
    }
    cout << "\n1 ~ 7등 까지 결과가 나올 수 있습니다.\n결과 : " << ranking << "등입니다!" << endl;
}