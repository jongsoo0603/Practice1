#pragma once
#include "Game.h"

int Game()
{
    int end = 1, select, weaponPick, NPA; // end:게임종료, selcet:기능선택, weaponPick:무기선택, NPA:공격가능횟수

    Character c;
    Gun g;
    Sword s;

    Weapon *sword = &s;
    Weapon *gun = &g;

    while (end != 0)
    {
        while (true)
        {
            cout << "수행할 스킬을 입력하세요.(0.종료, 1.아이템 줍기, 2.공격, 3.나의 정보 보기) : ";
            cin >> select;
            if (select < 0 || select > 3)
            {
                cout << "잘못 입력하셨습니다." << endl;
            }
            else
            {
                break;
            }
        }
        switch (select)
        {
        case 0:
            end = 0;
            cout << "---종료---" << endl;
            break;

        case 1:
            while (true)
            {
                cout << "주을 무기를 선택하세요(칼 : 0, 총 : 1) : ";
                cin >> weaponPick;
                if (weaponPick < 0 || weaponPick > 1)
                {
                    cout << "잘못 입력하셨습니다." << endl;
                }
                else
                {
                    break;
                }
            }
            if (weaponPick == 0)
            {
                c.pick_up_weapon(sword);
            }
            else
            {
                c.pick_up_weapon(gun);
            }
            cout << "남은 공격 가능 횟수(칼 : " << s.get_NPA() << ", 총 : " << g.get_NPA() << ")\n\n";
            break;

        case 2:

            if (s.get_NPA() == 0 && g.get_NPA() == 0)
            {
                cout << "사용 가능한 무기가 없습니다.\n"
                     << endl;
            }
            else
            {
                cout << "공격 가능 횟수(칼 : " << s.get_NPA() << ", 총 : " << g.get_NPA() << ")\n";
                while (true)
                {
                    cout << "사용할 무기를 선택하세요(칼 : 0, 총 : 1) : ";
                    cin >> weaponPick;
                    if (weaponPick < 0 || weaponPick > 1)
                    {
                        cout << "잘못 입력하셨습니다." << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                if (weaponPick == 0 && s.get_NPA() > 0)
                {
                    c.attack(sword);
                    sword->print_attack();
                }
                else if (weaponPick == 1 && g.get_NPA() > 0)
                {
                    c.attack(gun);
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
                 << "\n레벨 : " << c.get_level() << "\nHP : " << c.get_hp() << "\n공격 가능 횟수(칼 : " << s.get_NPA() << ", 총 : " << g.get_NPA() << ")\n몬스터 HP : " << c.get_monsterHP() << "\n==============================\n"
                 << endl;
            break;
        }
    }
}