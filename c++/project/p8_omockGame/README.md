# 오목 게임

---

# 👆🏻프로젝트 개요

C++의 콘솔 창에서 번갈아 가며 오목을 할 수 있는 간단한 게임입니다.

Windows.h 헤더 파일을 사용했기 때문에 window OS 에서 만 구현 가능합니다.

---

# 📺 시연 영상

[https://youtu.be/dKm1X0kbIGQ?si=1jyw5ljXaU6ZjsT2&t=453](https://youtu.be/dKm1X0kbIGQ?si=1jyw5ljXaU6ZjsT2&t=453)

---

# 📃 발표 PPT

[프로젝트8_최종.pdf](%E1%84%8B%E1%85%A9%E1%84%86%E1%85%A9%E1%86%A8%20%E1%84%80%E1%85%A6%E1%84%8B%E1%85%B5%E1%86%B7%20989246ad32cb44089dd08078abd473cd/%25E1%2584%2591%25E1%2585%25B3%25E1%2584%2585%25E1%2585%25A9%25E1%2584%258C%25E1%2585%25A6%25E1%2586%25A8%25E1%2584%2590%25E1%2585%25B38_%25E1%2584%258E%25E1%2585%25AC%25E1%2584%258C%25E1%2585%25A9%25E1%2586%25BC.pdf)

---

# 🌍 깃허브

[](https://github.com/jongsoo0603/codingOn/blob/fbebf499daeb640829ee204ec9cf37078b3101c3/c++/project/p8_omockGame.cpp)

---

# 📖 주요 코드

- 오목판 이동, 바둑돌을 두는 기능
    
    ```cpp
    ////////// 오목판 이동, 바둑돌을 두는 기능 //////////
    
        for (int i = 0; i < num; i++) // 바둑판(2차원 정적 배열)에 모두 "┼"를 입력하여 초기화
        {
            for (int j = 0; j < num; j++)
            {
                square[i][j] = "┼";
            }
        }
    
        square[areaX][areaY] = "○"; // 흑돌이 가운데에서 시작(7,7)
    
        while (end == 0) // 게임이 끝나기 전까지 반복되는 큰 반복문
        {
            // 턴에 따라 플레이어 변수 p와 돌 변수 stone 입력
            player++;            // 턴이 끝날 때 마다 +1
            if (player % 2 == 0) // 나머지 = 0 -> 흑돌
            {
                p = 1;
                stone = "●";
            }
            else // 나머지 = 1 -> 백돌
            {
                p = 2;
                stone = "○";
            }
    
            print(square, stone, areaX, areaY);
    
            while (turn == 0) // 한 턴을 기준으로 반복하는 작은 반복문
            {
                moove = _getch();
                if ((moove == 87) || (moove == 119)) // 북 w
                {
                    if (areaX - 1 < 0) // 이동 될 위치가 바둑판 밖으로 나간다면
                    {
                        print(square, stone, areaX, areaY);
                        cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl
                             << endl;
                    }
                    else
                    {
                        areaX--;
                        print(square, stone, areaX, areaY);
                    }
                }
                else if ((moove == 65) || (moove == 97)) // 서 a
                {
                    if (areaY - 1 < 0)
                    {
                        print(square, stone, areaX, areaY);
                        cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl
                             << endl;
                    }
                    else
                    {
                        areaY--;
                        print(square, stone, areaX, areaY);
                    }
                }
                else if ((moove == 83) || (moove == 115)) // 남 s
                {
                    if (areaX + 1 > 14)
                    {
                        print(square, stone, areaX, areaY);
                        cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl
                             << endl;
                    }
                    else
                    {
                        areaX++;
                        print(square, stone, areaX, areaY);
                    }
                }
                else if ((moove == 68) || (moove == 100)) // 동 d
                {
                    if (areaY + 1 > 14)
                    {
                        print(square, stone, areaX, areaY);
                        cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl
                             << endl;
                    }
                    else
                    {
                        areaY++;
                        print(square, stone, areaX, areaY);
                    }
                }
                else if ((moove == 69) || (moove == 101)) // 북동 e
                {
                    if (areaX - 1 < 0 || areaY + 1 > 14)
                    {
                        print(square, stone, areaX, areaY);
                        cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl
                             << endl;
                    }
                    else
                    {
                        areaX--, areaY++;
                        print(square, stone, areaX, areaY);
                    }
                }
                else if ((moove == 81) || (moove == 113)) // 북서 q
                {
                    if (areaX - 1 < 0 || areaY - 1 < 0)
                    {
                        print(square, stone, areaX, areaY);
                        cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl
                             << endl;
                    }
                    else
                    {
                        areaX--, areaY--;
                        print(square, stone, areaX, areaY);
                    }
                }
                else if ((moove == 67) || (moove == 99)) // 남동 c
                {
                    if (areaX + 1 > 14 || areaY + 1 > 14)
                    {
                        print(square, stone, areaX, areaY);
                        cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl
                             << endl;
                    }
                    else
                    {
                        areaX++, areaY++;
                        print(square, stone, areaX, areaY);
                    }
                }
                else if ((moove == 90) || (moove == 122)) // 남서 z
                {
                    if (areaX + 1 > 14 || areaY - 1 < 0)
                    {
                        print(square, stone, areaX, areaY);
                        cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl
                             << endl;
                    }
                    else
                    {
                        areaX++, areaY--;
                        print(square, stone, areaX, areaY);
                    }
                }
                else if (moove == 32) // 스페이스바로 바둑돌 놓기
                {
                    if (square[areaX][areaY] == "┼") // 현재 위치에 바둑돌이 없다면
                    {
                        if (p == 1)
                        {
                            square[areaX][areaY] = "●"; // 현재 위치에 바둑돌을 놓고
                            turn = 1;                   // 작은 반복문 탈출로 턴을 넘김
                            print(square, stone, areaX, areaY);
                        }
                        else
                        {
                            square[areaX][areaY] = "○";
                            turn = 1;
                            print(square, stone, areaX, areaY);
                        }
                    }
                    else
                    {
                        print(square, stone, areaX, areaY);
                        cout << setw(5) << " ※경고 : 바둑돌이 있습니다!" << endl
                             << endl;
                    }
                }
                else if (moove == 27) // esc
                {
                    cout << endl
                         << endl
                         << "《 게임을 종료합니다... 》" << endl;
                    turn = 1;
                    end = 1;
                }
                else // 지금까지 입력받은 것과 다른 아스키 코드를 입력받았다면
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " ※경고 : 잘못 입력하셨습니다." << endl
                         << endl;
                }
            }
    ```
    
- 5목 검사 기능
    
    ```cpp
    ////////// 5목 검사 기능 //////////
    
            int flagCase = 0;    // 스위치문 인자로 사용하기 위한 변수
            int countWin = 0;    // 현재 놓은 돌과 연속된 같은 돌 카운트
            while (flagCase < 4) // flagCase => 0:세로, 1:가로, 2:↖대각선, 3:↗대각선, 4:검사 종료
            {
                switch (flagCase)
                {
    
                case 0: // x축 검사
                    for (int k = 1; k < 5; k++)
                    {
                        if (square[areaX + k][areaY] == stone) // x축 ++ => ↓ 검사 (이동한 인덱스에 현재 놓은돌과 같은 돌이 놓여 있었다면)
                        {
                            countWin++;
                        }
                        else if (square[areaX + k][areaY] != stone || (areaX + k) > num - 1) // 돌이 다르거나, 없거나, 바둑판을 벗어난다면
                        {
                            break; // for문 탈출 => 다음 인덱스로 이동 안하고 종료
                        }
                    }
                    for (int k = 1; k < 5; k++)
                    {
                        if (square[areaX - k][areaY] == stone) // ↑ 검사
                        {
                            countWin++;
                        }
                        else if (square[areaX - k][areaY] != stone || (areaX - k) < 0)
                        {
                            break;
                        }
                    }
                    if (countWin == 4) // 5목이라면 (6목 제외)
                    {
                        flagCase = 4; // case 4 -> default -> 스위치 문 탈출
                    }
                    flagCase++; // 0 -> 1 케이스로 넘어가서 검사
                    break;
    
                case 1: // y축 검사
                    for (int k = 1; k < 5; k++)
                    {
                        if (square[areaX][areaY + k] == stone) // → 검사
                        {
                            countWin++;
                        }
                        else if (square[areaX][areaY + k] != stone || (areaY + k) >= num)
                        {
                            break;
                        }
                    }
                    for (int k = 1; k < 5; k++) // ← 검사
                    {
                        if (square[areaX][areaY - k] == stone)
                        {
                            countWin++;
                        }
                        else if (square[areaX][areaY - k] != stone || (areaY - k) < 0)
                        {
                            break;
                        }
                    }
    
                    if (countWin == 4)
                    {
                        flagCase = 4;
                        break;
                    }
                    flagCase++;
                    break;
    
                case 2: // ↖↘대각선 검사
                    for (int k = 1; k < 5; k++)
                    {
                        if (square[areaX - k][areaY - k] == stone) // ↖ 검사
                        {
                            countWin++;
                        }
                        else if (square[areaX - k][areaY - k] != stone || (areaX - k) < 0 || (areaY - k) < 0)
                        {
                            break;
                        }
                    }
                    for (int k = 1; k < 5; k++)
                    {
                        if (square[areaX + k][areaY + k] == stone) // ↘ 검사
                        {
                            countWin++;
                        }
                        else if (square[areaX + k][areaY + k] != stone || (areaX + k) >= num || (areaY + k) >= num)
                        {
                            break;
                        }
                    }
    
                    if (countWin == 4)
                    {
                        flagCase = 4;
                        break;
                    }
    
                    flagCase++;
                    break;
    
                case 3: // 반대 대각선 검사
                    for (int k = 1; k < 5; k++)
                    {
                        if (square[areaX - k][areaY + k] == stone) // ↗ 검사
                        {
                            countWin++;
                        }
                        else if (square[areaX - k][areaY + k] != stone || (areaX - k) < 0 || (areaY + k) >= num)
                        {
                            break;
                        }
                    }
                    for (int k = 1; k < 5; k++)
                    {
                        if (square[areaX + k][areaY - k] == stone) // ↙ 검사
                        {
                            countWin++;
                        }
                        else if (square[areaX + k][areaY - k] != stone || (areaX + k) >= num || (areaY - k) < 0)
                        {
                            break;
                        }
                    }
    
                    if (countWin == 4)
                    {
                        flagCase = 4;
                        break;
                    }
                    flagCase++;
                    break;
    
                default: // flagCase == 4
                    break;
                }
            }
    
            if (countWin == 4) // 승리 조건 만족 == 게임 종료
            {
                if (stone == "●")
                { // 마지막에 둔 돌이 백돌이라면
                    cout << endl
                         << "『 ● (백) 의 승리! 』" << endl;
                }
                else
                {
                    cout << endl
                         << " 『 ○ (흑) 의 승리! 』 " << endl;
                }
                cout << "《 게임을 종료합니다... 》" << endl;
                end = 1; // 게임 종료를 결정짓는 큰 while문의 false 조건
            }
    
            turn = 0; // 한 턴을 결정짓는 작은 while문의 true 조건 = 초기화
        }
    ```