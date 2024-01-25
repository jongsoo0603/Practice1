# [몬스터 공격 게임](https://www.notion.so/1324e0469f094661bbbf30d0e2f86959?pvs=4)

---

## 🎮 게임 규칙

❗ 아이템 줍기 or 공격 하기를 선택하여 몬스터의 체력을 0으로 만들면 게임 종료 ❗

- 아이템 줍기

  - 칼
    - 공격 가능 횟수 :3
    - 데미지 5
  - 총
    - 공격 가능 횟수 1
    - 데미지 10

- 공격 하기

  - 칼 or 총 선택하여 몬스터 공격

- 보완할 점
  - 몬스터 처치 후 경험치로 Level 및 HP 상향 기능
  - 회원 관리로 게임 저장 기능

---

# 📺 실행 결과

![1](https://github.com/jongsoo0603/codingOn/assets/98942866/27ab1c6a-b2df-4592-b27b-1a3f4722db7e)

. . .

![2](https://github.com/jongsoo0603/codingOn/assets/98942866/c840c536-27cc-4251-8758-6d93a17b3f88)

---

# 📖 주요 코드

<details>
<summary>Weapon.h - 캐릭터 속성 클래스화</summary>
<div markdown="1">

```cpp
#pragma once
#include "Weapon.h"

class Character
{
private:
    int level = 1, hp = 50, monsterHP = 50;

public:
    int get_level();
    int get_hp();
    int get_monsterHP();
    void set_monsterHP(int monsterHP);
    void pick_up_weapon(Weapon *pick); //
    void attack(Weapon *pick);
};
```

</div>
</details>

<details>
<summary>Game.cpp - 게임 플레이 코드</summary>
<div markdown="1">

```cpp
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
```

</div>
</details>

---
