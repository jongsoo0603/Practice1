#include<iostream>

using namespace std;

class Character 
{
    private:
        string name;
        int level, item_num;
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
        void setname(string name)
        {
            this->name = name;
        }
        void setlevel(int level)
        {
            this->level = level;
        }
        void setitem_num(int item_num)
        {
            this->item_num = item_num;
        }
};

int main()
{
    int num = -1, l = 0, i = 0;
    string n;
    
    Character c;
   
    cout << "이름을 입력해 주세요 : ";
    cin >> n;
    c.setname(n);
    cout << c.getname() << " 캐릭터가 생성되었습니다."<< endl;

    while(num != 0)
    {
        cout << "\n어떤 동작을 실행하기겠습니까?(0: 종료) : ";
        cin >> num;
        switch (num)
        {
            case 0:
                num = 0;
                cout << "---종료---" << endl;
                break;
            case 1:
                cout << "새 이름을 입력해 주세요 : ";
                cin >> n;
                c.setname(n);
                cout << "이름이 변경되었습니다.\nnew name : " << c.getname() << endl;
                break;
            case 2:
                l += 1;
                c.setlevel(l);
                cout << "level up!\n현재 레벨 : " << c.getlevel() << endl;
                break;
            case 3:
                i += 1;
                c.setitem_num(i);
                cout << "아이템을 얻었습니다!\n현재 아이템 개수 : " << c.getitem_num() << endl;
                break;
            case 4:
                i -= 1;
                c.setitem_num(i);
                cout << "아이템을 사용했습니다!\n현재 아이템 개수 : " << c.getitem_num() << endl;
                break;
            case 5:
                cout << "이름 : " << c.getname() << "\n레벨 : " << c.getlevel() << "\n현재 아이템 개수 : " << c.getitem_num() << endl;
                break;
        }
    }
}