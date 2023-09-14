#pragma once
#include"snackMain.h"

int snackMain()
{
    int choice = 1;
    string flavor, shape;
    vector <string> snackBasket;
    while(1)
    {
        cout << "\n과자 바구니에 추가할 간식을 고르시오.(1.: 사탕, 2: 초콜릿, 0: 종료) : ";
        cin >> choice;
        if(choice == 0)
        {
            break;
        }
        else if(choice == 1)
        {
            cout << "맛을 입력하세요 : ";
            cin >> flavor;
            Candy c(flavor);
            c.set_lastName(c.get_name());
            snackBasket.push_back(c.show_info());
        }
        else if(choice == 2)
        {
            cout << "모양 입력하세요 : ";
            cin >> shape;
            Chocolate ch(shape);
            ch.set_lastName(ch.get_name());
            snackBasket.push_back(ch.show_info());
        }
        else
        {
            cout << "0~2 사이의 숫자를 입력하세요." << endl;
        }
    }

    cout << "\n과자 바구니에 담긴 간식의 개수는 " << Snack::get_count() << "개 입니다.\n\n과자 바구니에 담긴 간식 확인하기!" << endl;
    for(string s : snackBasket)
    {
        cout << s;
    }
    cout << "\n마지막으로 추가한 간식의 종류 : " << Snack::get_lastName() << endl;
}