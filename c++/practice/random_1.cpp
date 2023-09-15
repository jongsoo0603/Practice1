#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
    vector<int> lotto;
    srand(time(NULL));

    while (true)
    {
        // 난수 % 44 = 난수의 범위 0~44까지 한정 -> +1 -> 1 ~ 45
        int randN = (rand() % 44) + 1;
        int check[46] = {0};
        // int check = 0;
        // for(int i = 0; i < lotto.size(); i++)
        // {
        //     if(lotto.at(i) == randN)
        //     {
        //         check += 1;
        //     }
        // }
        // if(check == 0)
        // {
        //     lotto.push_back(randN);
        // }
        if (check[randN] == 0)
        {
            lotto.push_back(randN);
            check[randN] = 1;
        }
        if (lotto.size() == 6)
        {
            break;
        }
    }

    cout << "당첨번호 : ";
    for (int l : lotto)
    {
        cout << l << " ";
    }
}