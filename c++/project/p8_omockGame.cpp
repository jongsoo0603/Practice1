// 특수문자 : ○ ● ☆ ┼
#include <iostream>
#include <iomanip>

const int num = 15;
using namespace std;

void print(string arr[num][num])
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cout << setw(5) << arr[i][j];
        }
        cout << endl;
    }
};
void printint(int arr[num][num])
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cout << setw(5) << arr[i][j];
        }
        cout << endl;
    }
};
int main()
{
    string square[num][num], moove, memory;
    int check[num][num], player = 0, p = 0, areaX = 7, areaY = 7, checkX = 7, checkY = 7, end = 0, turn = 0;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            square[i][j] = "┼";
            check[i][j] = 0;
        }
    }

    square[areaX][areaY] = "●";
    check[areaX][areaY] = 2;

    print(square);

    while (end == 0)
    {
        // printint(check);
        if (player % 2 == 0)
        {
            p = 1;
        }
        else
        {
            p = 2;
        }
        while (turn == 0)
        {
            cout << p << "차레 : w, a, s, d = 이동, o = 두기 : ";
            cin >> moove;
            if (moove == "w")
            {
                if (areaX - 1 < 0)
                {
                    cout << "밖으로 나갈 수 없습니다." << endl;
                }
                else
                {
                    areaX--;
                    memory = square[areaX][areaY];
                    square[areaX][areaY] = "☆";
                    print(square);
                    square[areaX][areaY] = memory;
                }
            }
            else if (moove == "a")
            {
                if (areaY - 1 < 0)
                {
                    cout << "밖으로 나갈 수 없습니다." << endl;
                }
                else
                {
                    areaY--;
                    memory = square[areaX][areaY];
                    square[areaX][areaY] = "☆";
                    print(square);
                    square[areaX][areaY] = memory;
                }
            }
            else if (moove == "s")
            {
                if (areaX + 1 > 14)
                {
                    cout << "밖으로 나갈 수 없습니다." << endl;
                }
                else
                {
                    areaX++;
                    memory = square[areaX][areaY];
                    square[areaX][areaY] = "☆";
                    print(square);
                    square[areaX][areaY] = memory;
                }
            }
            else if (moove == "d")
            {
                if (areaY + 1 > 14)
                {
                    cout << "밖으로 나갈 수 없습니다." << endl;
                }
                else
                {
                    areaY++;
                    memory = square[areaX][areaY];
                    square[areaX][areaY] = "☆";
                    print(square);
                    square[areaX][areaY] = memory;
                }
            }
            else if (moove == "o")
            {
                if (check[areaX][areaY] == 0)
                {
                    if (p == 1)
                    {
                        square[areaX][areaY] = "○";
                        check[areaX][areaY] = 1;
                        turn = 1;
                        print(square);
                    }
                    else
                    {
                        square[areaX][areaY] = "●";
                        check[areaX][areaY] = 2;
                        turn = 1;
                        print(square);
                    }
                }
                else
                {
                    cout << "바둑돌이 있습니다." << endl;
                }
            }
            else
            {
                cout << "잘못 입력하셨습니다" << endl;
            }
        }

        if (false) // 승리 조건
        {
            end = 1;
        }
        player++;
        turn = 0;
    }
}