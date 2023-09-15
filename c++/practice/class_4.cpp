#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Character 
{
    private:
        string name;
        int level, item_num, physical, power;
    public:
        Character(){}
        // Character(string n, int l, int i)
        // {
        //     this -> name = n;
        //     this -> level = l;
        //     this -> item_num = i;
        // }
        string getname()
        {
            return name;
        }
        int getlevel()
        {
            return level;
        }
        int getitem_num()
        {
            return item_num;
        }
        int getphysical()
        {
            return physical;
        }
        int getpower()
        {
            return power;
        }

        void setname(string name)
        {
            this -> name = name;
        }
        void setlevel(int level, int physical)
        {
            this -> level = level;
            this -> physical = physical;
        }
        void setitem_num(int item_num, int power)
        {
            this -> item_num = item_num;
            this -> power = power;
        }
};

int main()
{
    int num = -1, level1 = 1, level2 = 1, item1 = 0, item2 = 0, power1 = 1, power2 = 1, physical1 = 3, physical2 = 3, person = 0, p = 0;
    string name, str;
   
    cout << "첫 번째 챔피언 이름을 입력해 주세요 : ";
    cin >> name;
    Character c1;
    c1.setname(name);
    c1.setlevel(level1, physical1);
    c1.setitem_num(item1,power1);
    cout << "첫 번째 챔피언 " << c1.getname() << "가 생성되었습니다."<< endl;

    cout << "\n두 번째 챔피언 이름을 입력해 주세요 : ";
    cin >> name;
    Character c2;
    c2.setname(name);
    c2.setlevel(level2, physical2);
    c2.setitem_num(item2,power2);
    cout << "두 번째 챔피언 " << c2.getname() << "가 생성되었습니다."<< endl;

    while(num != 0)
    {
        cout << "\n현재 상태\n==========\n이름 : " << c1.getname() << "\n레벨 : " << c1.getlevel() << "\n남은 체력 : " << c1.getphysical() << "\n공격력 : " << c1.getpower() << "\n남은 아이템 개수 : " << c1.getitem_num() << "\n----------\n이름 : " << c2.getname() << "\n레벨 : " << c2.getlevel() << "\n남은 체력 : " << c2.getphysical() << "\n공격력 : " << c2.getpower() << "\n남은 아이템 개수 : " << c2.getitem_num() << endl << endl;
        p = 0;
        while(p == 0)
        {
            cout << "소환사님 플레이 할 챔피언을 픽하세요.\n1 = " <<  c1.getname() << ", 2 = " << c2.getname() << " : ";
            cin >> person;
            if(person == 1 || person == 2)
            {
                p = 1;
            }
            else
            {
                cout <<  "챔피언 번호를 잘못 입력하셨습니다." << endl;
            }
        }
        if(person == 1)
        {
            cout << "\n" << c1.getname();
        }
        else
        {
            cout << "\n" << c2.getname();
        }
        cout << "이(가) 수행할 스킬을 입력하세요.\n(0.종료, 1.이름 변경, 2.아이템 줍기, 3.아이템 사용(공격력+1), 4.레벨업(체력+1), 5.공격 : ";
        cin >> num;
        cout << "\n";
        switch (num)
        {
            case 0:
                num = 0;
                cout << "---종료---" << endl;
                break;
            case 1:
                cout << "새 이름을 입력해 주세요 : ";
                cin >> name;
                if (person == 1)
                {
                    cout << c1.getname() << " 챔피언의";
                    c1.setname(name);
                    cout << " 이름이 변경되었습니다.\n새로운 챔피언 이름 : " << c1.getname() << endl;
                }
                else
                {
                    cout << c2.getname() << " 챔피언의";
                    c2.setname(name);
                    cout << "이름이 변경되었습니다.\n새로운 챔피언 이름 : " << c2.getname() << endl;
                }
                break;
            case 2:
                if(person == 1)
                    {
                        item1 += 1;
                        c1.setitem_num(item1, power1);
                        cout << "아이템을 얻었습니다!\n" << c1.getname() << "의 남은 아이템 개수 : " << c1.getitem_num() << endl;
                    }
                else
                    {
                        item2 += 1;
                        c2.setitem_num(item2, power2);
                        cout << "아이템을 얻었습니다!\n" << c2.getname() << "의 남은 아이템 개수 : " << c2.getitem_num() << endl;
                    }
                break;
            case 3:
                if(person == 1)
                {
                    if(c1.getitem_num() <= 0)
                    {
                        cout << "사용할 아이템이 없습니다!\n" << c1.getname() << "의 현재 아이템 개수 : 0" << endl;
                        break;
                    }
                    item1 -= 1;
                    power1 += 1;
                    c1.setitem_num(item1, power1);
                    cout << "아이템을 사용했습니다!\n" << c1.getname() << "의 남은 아이템 개수 : " << c1.getitem_num() << ", 공격력 : " << c1.getpower() << endl;
                }
                else
                {
                    if(c2.getitem_num() <= 0)
                    {
                        cout << "사용할 아이템이 없습니다!\n" << c2.getname() << "의 현재 아이템 개수 : " << c2.getitem_num() << endl;
                        break;
                    }
                    item2 -= 1;
                    power2 += 1;
                    c2.setitem_num(item2, power2);
                    cout << "아이템을 사용했습니다!\n" << c2.getname() << "의 남은 아이템 개수 : " << c2.getitem_num() << ", 공격력 : " << c2.getpower() << endl;
                }
                break;
            case 4:
                if(person == 1)
                {
                    level1 += 1;
                    physical1 += 1;
                    c1.setlevel(level1, physical1);
                    cout << "level up!(레벨+1,체력+1)\n"<< c1.getname() << "의 현재 레벨 : " << c1.getlevel() << ", 남은 체력 : " <<  c1.getphysical() << endl;
                }
                else
                {
                    level2 += 1;
                    physical2 += 1;
                    c2.setlevel(level2, physical2);
                    cout << "level up!(레벨+1,체력+1)\n"<< c2.getname() << "의 현재 레벨 : " << c2.getlevel()<< ", 남은 체력 : " << c2.getphysical() << endl;
                }
                break;
            
            case 5:
                if(person == 1)
                {
                    cout << c1.getname() << "이(가) " <<  c2.getname() << "를 " << c1.getpower() << "의 힘으로 공격했습니다." << endl;
                    physical2 -= power1;
                    c2.setlevel(level2, physical2);
                    if(c2.getphysical() < 1)
                    {
                        cout << c2.getname() << "이 죽었습니다.\n게임 종료." << endl;
                        num = 0;
                        break;
                    }
                    else
                    {
                        cout << c2.getname() << "의 남은 체력 : " << c2.getphysical() << endl;
                    }
                }
                else
                {
                    cout << c2.getname() << "이(가) " <<  c1.getname() << "를 " << c2.getpower() << "의 힘으로 공격했습니다." << endl;
                    physical1 -= power2;
                    c1.setlevel(level1, physical1);
                    if(c1.getphysical() < 1)
                    {
                        cout << c1.getname() << "이 죽었습니다.\n게임 종료." << endl;
                        num = 0;
                        break;
                    }
                    else
                    {
                        cout << c1.getname() << "의 남은 체력 : " << c1.getphysical() << endl;
                    }
                }
                break;
        }
    }
    str = "\n현재 상태\n==========\n이름 : " + c1.getname() + "\n레벨 : " + to_string(c1.getlevel()) + "\n남은 체력 : " + to_string(c1.getphysical()) + "\n공격력 : " + to_string(c1.getpower()) + "\n남은 아이템 개수 : " + to_string(c1.getitem_num()) + "\n----------\n이름 : " + c2.getname() + "\n레벨 : " + to_string(c2.getlevel()) + "\n남은 체력 : " + to_string(c2.getphysical()) + "\n공격력 : " + to_string(c2.getpower()) + "\n남은 아이템 개수 : " + to_string(c2.getitem_num()) + "\n\n";
    ofstream f_w("game.txt");
    f_w << str;
    f_w.close();
}