#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int line = 0, i, j, number = 1;

    while (true)
    {
        cout << "마방진 행열의 3 이상 '홀수'를 입력하세요 : ";
        cin >> line;
        if (line % 2 == 1 && line > 1)
        {
            break;
        }
    }

    int square[line][line];        // 2차원 배열 선언
    for (int i = 0; i < line; i++) // 2차원 배열 모두 0으로 초기화
    {
        for (int j = 0; j < line; j++)
        {
            square[i][j] = 0;
        }
    }

    // 1은 미리 (0,line/2)로 설정
    i = 0, j = (line / 2);
    square[i][j] = number;
    number++;

    while (number < (line * line) + 1)
    {

        if (i == 0 && j != line - 1) // 빨간색 표시
        {
            if (square[line - 1][j + 1] == 0) // 대각선 위가 비어있다면
            {
                i = line - 1, j++;
            }
            else
            {
                i++;
            }
        }
        else if (i != 0 && j == line - 1) // 파란색 표시
        {
            if (square[i - 1][0] == 0)
            {
                i--, j = 0;
            }
            else
            {
                i++;
            }
        }
        else if (i == 0 && j == line - 1) // (0,끝)
        {
            i++;
        }
        else // 일반적인 상황
        {
            if (square[i - 1][j + 1] == 0)
            {
                i--, j++;
            }
            else
            {
                i++;
            }
        }

        square[i][j] = number;
        number++;
    }

    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < line; j++)
        {
            cout << setw(5) << square[i][j];
        }
        cout << endl
             << endl;
    }
}