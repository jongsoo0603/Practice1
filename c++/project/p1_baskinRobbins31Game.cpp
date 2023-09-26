#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int computerCount, myCount, gameNumber = 0, gameSequence = 0, remember = 0;

    srand(time(NULL));

    cout << "컴퓨터 : 종!수가~ 좋!아하는~ 랜!덤~ 게!임! 무슨~ 게임! 게임스타트! 게임스타트!\n나 : 베스킨~ 라빈스~ 써리~ 원!";

    while (gameNumber < 31)
    {
        if (gameSequence % 2 == 0)
        {
            while (true)
            {
                cout << "\n\n나 : ";
                cin >> myCount;
                if (myCount > 0 && myCount < 4)
                {
                    break;
                }
                cout << "컴퓨터 : 마시면서 배우는! 술!게!임!\n1에서 3까지잖아~~ 다시 불러!";
            }
            gameNumber += myCount;
        }
        else
        {
            computerCount = (rand() % 3) + 1;
            cout << "\n\n컴퓨터 : " << computerCount << endl;

            gameNumber += computerCount;
        }

        for (; remember < gameNumber + 1; remember++)
        {
            if (remember == 32)
            {
                break;
            }
            else if (remember != 0)
            {
                cout << remember << " ";
            }
        }

        gameSequence += 1;
    }

    if (gameSequence % 2 == 0)
    {
        cout << "\n\n나 : ";
    }
    else
    {
        cout << "\n\n컴퓨터 : ";
    }
    cout << "이겼다!! 마~셔 마~셔! 먹~고 디~져!" << endl;
}