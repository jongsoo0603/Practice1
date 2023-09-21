#include <iostream>
#include <iomanip> // setw() �� ����ϱ� ���� ���
#include <Windows.h> // system("cls")�� ����ϱ� ���� ���
#include <conio.h> // _getch()�� ����ϱ� ���� ��� 

#define SPACE 32 // �����̽��ٿ� ���͸� �Է¹ޱ� ���� ����
#define ENTER 13

const int num = 15; // ������ ����, ���� ����

using namespace std;

void CursorView(bool show) // Ŀ�� ������ ����
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
};

void print(string square[][num], string stone, int areaX, int areaY) // ��Ʈ���� 2�� ���� �迭�� ���� ũ�Ⱑ ����Ǿ�� �Ѵٰ� ��(��ĳ ������ �Ǽ�)
{
    system("cls"); // ��� ȭ���� Ŭ���� ����
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == areaX && j == areaY) { // areaX,Y = ���� ��ġ
                cout << setw(5) << "��"; // "��" ����Ͽ� ���� ��ġ. Ȯ��
            }
            else {
                cout << setw(5) << square[i][j];
            }
        }
        cout << endl;
    }
    cout << "*************************************************************" << endl;
    cout << "                             " << stone << " ����" << endl;
    cout << "*************************************************************" << endl;
    cout << "                           �̵����" << endl;
    cout << "           " << setw(5) << "Q��" << setw(6) << "��W" << setw(5) << "��E" << endl;
    cout << "           " << setw(5) << "A��" << setw(4) << "+" << setw(6) << "��D" << "     SPACE BAR : �ٵϵ� �α� " << endl;
    cout << "           " << setw(5) << "Z��" << setw(6) << "��S" << setw(5) << "��C" << endl;
    cout << "*************************************************************" << endl;
    cout << " ��ESC�� ������ ���� ���᡻";
};


int main()
{
    char moove; 
    string square[num][num], stone; 
    int player = 1, p = 0, areaX = 7, areaY = 7, end = 0, turn = 0; // areaX,Y = 7 : ���� ��ġ�� �ε���(������� ����)
    
    CursorView(false); // Ŀ�� ������ ����

    while (1) { // ���� ������
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "*************************************************************" << endl;
        cout << "                          ����" << endl;
        cout << "*************************************************************" << endl;
        cout << "               �� EnterŰ�� �Է��ؼ� ����" << endl;
        cout << "*************************************************************" << endl;
        moove = _getch(); // �Է°��� ���ۿ� ������� �ʰ� �Էµ� ���� �ٷιٷ� ��ȯ���ִ� �Լ�
        if (moove == ENTER) {
            break;
        }
    }


    ////////// ������ �̵�, �ٵϵ��� �δ� ��� //////////


    for (int i = 0; i < num; i++) // �ٵ���(2���� ���� �迭)�� ��� "��"�� �Է��Ͽ� �ʱ�ȭ
    {
        for (int j = 0; j < num; j++)
        {
            square[i][j] = "��";
        }
    }

    square[areaX][areaY] = "��"; // �浹�� ������� ����(7,7)
    
    while (end == 0) // ������ ������ ������ �ݺ��Ǵ� ū �ݺ���
    {
        // �Ͽ� ���� �÷��̾� ���� p�� �� ���� stone �Է�
        player++; //���� ���� �� ���� +1
        if (player % 2 == 0) // ������ = 0 -> �浹
        {
            p = 1;
            stone = "��";
        }
        else // ������ = 1 -> �鵹
        {
            p = 2;
            stone = "��";
        }

        print(square, stone, areaX, areaY);

        while (turn == 0) // �� ���� �������� �ݺ��ϴ� ���� �ݺ���
        {
            moove = _getch();
            if ((moove == 87) || (moove == 119)) // �� w
            {
                if (areaX - 1 < 0) // �̵� �� ��ġ�� �ٵ��� ������ �����ٸ�
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " �ذ�� : ������ ���� �� �����ϴ�!" << endl << endl;
                }
                else
                {
                    areaX--;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 65) || (moove == 97)) // �� a
            {
                if (areaY - 1 < 0)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " �ذ�� : ������ ���� �� �����ϴ�!" << endl << endl;
                }
                else
                {
                    areaY--;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 83) || (moove == 115)) // �� s
            {
                if (areaX + 1 > 14)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " �ذ�� : ������ ���� �� �����ϴ�!" << endl << endl;
                }
                else
                {
                    areaX++;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 68) || (moove == 100)) // �� d
            {
                if (areaY + 1 > 14)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " �ذ�� : ������ ���� �� �����ϴ�!" << endl << endl;
                }
                else
                {
                    areaY++;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 69) || (moove == 101)) // �ϵ� e
            {
                if (areaX - 1 < 0 || areaY + 1 > 14)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " �ذ�� : ������ ���� �� �����ϴ�!" << endl << endl;
                }
                else
                {
                    areaX--, areaY++;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 81) || (moove == 113)) // �ϼ� q
            {
                if (areaX - 1 < 0 || areaY - 1 < 0)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " �ذ�� : ������ ���� �� �����ϴ�!" << endl << endl;
                }
                else
                {
                    areaX--, areaY--;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 67) || (moove == 99)) // ���� c
            {
                if (areaX + 1 > 14 || areaY + 1 > 14)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " �ذ�� : ������ ���� �� �����ϴ�!" << endl << endl;
                }
                else
                {
                    areaX++, areaY++;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 90) || (moove == 122)) // ���� z
            {
                if (areaX + 1 > 14 || areaY - 1 < 0)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " �ذ�� : ������ ���� �� �����ϴ�!" << endl << endl;
                }
                else
                {
                    areaX++, areaY--;
                    print(square, stone, areaX, areaY);
                }
            }
            else if (moove == SPACE) // �ٵϵ� ����
            {
                if (square[areaX][areaY] == "��") // ���� ��ġ�� �ٵϵ��� ���ٸ�
                {
                    if (p == 1)
                    {
                        square[areaX][areaY] = "��"; // ���� ��ġ�� �ٵϵ��� ����
                        turn = 1; // ���� �ݺ��� Ż��� ���� �ѱ�
                        print(square, stone, areaX, areaY);
                    }
                    else
                    {
                        square[areaX][areaY] = "��";
                        turn = 1;
                        print(square, stone, areaX, areaY);
                    }
                }
                else
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " �ذ�� : �ٵϵ��� �ֽ��ϴ�!" << endl << endl;
                }
                }
            else if (moove == 27) // esc
            {
                cout << endl << endl << "�� ������ �����մϴ�... ��" << endl;
                turn = 1;
                end = 1;
                }
            else // ���ݱ��� �Է¹��� �Ͱ� �ٸ� �ƽ�Ű �ڵ带 �Է¹޾Ҵٸ�
            {
                print(square, stone, areaX, areaY);
                cout << setw(5) << " �ذ�� : �߸� �Է��ϼ̽��ϴ�." << endl << endl;
            }
        }


        ////////// 5�� �˻� ��� //////////


        int flagCase = 0; // ����ġ�� ���ڷ� ����ϱ� ���� ����
        int countWin = 0; // ���� ���� ���� ���ӵ� ���� �� ī��Ʈ
        while (flagCase < 4) // flagCase => 0:����, 1:����, 2:�ش밢��, 3:�ִ밢��, 4:�˻� ����
        {
            switch (flagCase)
            {

            case 0: // �� �˻�
                for (int k = 1; k < 5; k++)
                {
                    if (square[areaX + k][areaY] == stone) // x�� ++ => �� �˻� (�̵��� �ε����� ���� �������� ���� ���� ���� �־��ٸ�)
                    {
                        countWin++;
                    }
                    else if (square[areaX + k][areaY] != stone || (areaX + k) > num - 1) // ���� �ٸ��ų�, ���ų�, �ٵ����� ����ٸ�
                    {
                        break; // for�� Ż�� => ���� �ε����� �̵� ���ϰ� ����
                    }
                }
                for (int k = 1; k < 5; k++)
                {
                    if (square[areaX - k][areaY] == stone) // �� �˻�
                    {
                        countWin++;
                    }
                    else if (square[areaX - k][areaY] != stone || (areaX - k) < 0)
                    {
                        break;
                    }
                }
                if (countWin == 4) // 5���̶�� (6�� ����)
                {
                    flagCase = 4; // case 4 -> default -> ����ġ �� Ż��
                }
                flagCase++; // 0 -> 1 ���̽��� �Ѿ�� �˻�
                break;

            case 1: // �� �˻�
                for (int k = 1; k < 5; k++)
                {
                    if (square[areaX][areaY + k] == stone) // �� �˻�
                    {
                        countWin++;
                    }
                    else if (square[areaX][areaY + k] != stone || (areaY + k) >= num)
                    {
                        break;
                    }
                }
                for (int k = 1; k < 5; k++) // �� �˻�
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

            case 2: // �밢�� �˻�
                for (int k = 1; k < 5; k++)
                {
                    if (square[areaX - k][areaY - k] == stone) // �� �˻�
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
                    if (square[areaX + k][areaY + k] == stone) // �� �˻�
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

            case 3: // �ݴ� �밢�� �˻�
                for (int k = 1; k < 5; k++)
                {
                    if (square[areaX - k][areaY + k] == stone) // �� �˻�
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
                    if (square[areaX + k][areaY - k] == stone) // �� �˻�
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

        if (countWin == 4) // �¸� ���� ���� == ���� ����
        {
            if (stone == "��") { // �������� �� ���� �鵹�̶��
                cout << endl << "�� �� (��) �� �¸�! ��" << endl;
            }
            else {
                cout << endl << " �� �� (��) �� �¸�! �� " << endl;
            }
            cout << "�� ������ �����մϴ�... ��" << endl;
            end = 1; // ���� ���Ḧ �������� ū while���� false ����
        }

        turn = 0; // �� ���� �������� ���� while���� true ���� = �ʱ�ȭ
    }
}