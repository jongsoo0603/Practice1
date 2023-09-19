

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Weapon
{
public:
    static int gNPA, sNPA; // Number of possible attacks
    int swordPower = 5, gunPower = 10;

    virtual void print_attack() {}

    void set_NPA(int NPA, int weaponPick) //
    {
        if (weaponPick == 0) // sword
        {
            this->sNPA = NPA;
            cout << "남은 공격 가능 횟수(칼 : " << sNPA << ", 총 : " << gNPA << ")\n\n";
        }
        else // gun
        {
            this->gNPA = NPA;
            cout << "남은 공격 가능 횟수(칼 : " << sNPA << ", 총 : " << gNPA << ")\n\n";
        }
    }

    int get_gNPA()
    {
        return gNPA;
    }
    int get_sNPA()
    {
        return sNPA;
    }
    int get_swordPower()
    {
        return swordPower;
    }
    int get_gunPower()
    {
        return gunPower;
    }
};

class Sword : public Weapon
{
public:
    void print_attack()
    {
        cout << "몬스터를 칼로 찔렀습니다!" << endl;
    }
};

class Gun : public Weapon
{
public:
    void print_attack()
    {
        cout << "몬스터를 총으로 쐈습니다!" << endl;
    }
};

class Character // 무기 줍기, 공격하기
{
private:
    int weaponPick;

public:
    int level = 1, hp = 50, monsterHP = 50;

    Weapon wp;

    int get_level()
    {
        return level;
    }
    int get_hp()
    {
        return hp;
    }
    int get_monsterHP()
    {
        return monsterHP;
    }

    void set_monsterHP(int monsterHP)
    {
        this->monsterHP = monsterHP;
    }

    int pick_up_weapon(int weaponPick)
    {
        if (weaponPick == 0) // sword
        {
            Weapon::sNPA += 3;
            return Weapon::sNPA;
        }
        else // gun
        {
            Weapon::gNPA += 1;
            return Weapon::gNPA;
        }
    }

    void attack(int weaponPick)
    {
        if (weaponPick == 0)
        {
            monsterHP -= wp.get_swordPower();
            wp.set_NPA(wp.get_sNPA() - 1, weaponPick);
        }
        else
        {
            monsterHP -= wp.get_gunPower();
            wp.set_NPA(wp.get_gNPA() - 1, weaponPick);
        }
    }
};

int Weapon::gNPA = 0;
int Weapon::sNPA = 0;

int main()
{
    int end = 1, select, weaponPick, NPA; // end:게임종료, selcet:기능선택, weaponPick:무기선택, NPA:공격가능횟수

    Character c;
    Gun g;
    Sword s;

    Weapon w;
    Weapon *sword = &s;
    Weapon *gun = &g;

    while (end != 0)
    {
        cout << "수행할 스킬을 입력하세요.\n(0.종료, 1.아이템 줍기, 2.공격, 3.나의 정보 보기) : ";
        cin >> select;

        switch (select)
        {
        case 0:
            end = 0;
            cout << "---종료---" << endl;
            break;

        case 1:

            cout << "주을 무기를 선택하세요(칼 : 0, 총 : 1) : ";
            cin >> weaponPick;
            NPA = c.pick_up_weapon(weaponPick);
            w.set_NPA(NPA, weaponPick);
            break;

        case 2:

            if (w.get_gNPA() == 0 && w.get_sNPA() == 0)
            {
                cout << "사용 가능한 무기가 없습니다.\n"
                     << endl;
            }
            else
            {
                cout << "공격 가능 횟수(칼 : " << w.get_sNPA() << ", 총 : " << w.get_gNPA() << ")\n";
                cout << "사용할 무기를 선택하세요(칼 : 0, 총 : 1) : ";
                cin >> weaponPick;
                if (weaponPick == 0 && w.get_sNPA() > 0)
                {
                    c.attack(weaponPick);
                    sword->print_attack();
                }
                else if (weaponPick == 1 && w.get_gNPA() > 0)
                {
                    c.attack(weaponPick);
                    gun->print_attack();
                }
                else
                {
                    cout << "선택한 무기의 공격 가능 횟수가 0입니다.\n"
                         << endl;
                    break;
                }
                cout << "몬스터의 남은 피 : " << c.get_monsterHP() << endl
                     << endl;
            }

            if (c.get_monsterHP() < 1)
            {
                cout << "몬스터가 죽었습니다. 게임 종료." << endl;
                end = 0;
            }
            break;

        case 3:
            cout << "\n=============================="
                 << "\n레벨 : " << c.get_level() << "\nHP : " << c.get_hp() << "\n공격 가능 횟수(칼 : " << w.get_sNPA() << ", 총 : " << w.get_gNPA() << ")\n몬스터 HP : " << c.get_monsterHP() << "\n==============================\n"
                 << endl;
            break;
        }
    }
}