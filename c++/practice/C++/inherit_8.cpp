// static 멤버
// 모든 클래스에서 접근할 수 있는 변수(공유 저장소 느낌)

#include <iostream>
#include <vector>

using namespace std;

class Snack 
{
    protected:
        int price;
        string name;
        string maker;
        static int count;
    public:
        Snack(){ count++;}
        virtual ~Snack() { count--;}
        static int get_count() 
        {
            return count;
        }
        string get_name() 
        {
            return name;
        }
        virtual string show_info()
        {
            return "과자입니다~\n";
        }
};

class Candy : public Snack 
{
	string flavor;
    public:
        Candy(string flavor) 
        {
            this->price = 200;
            this->name = "사탕";
            this->maker = "농심";
            this->flavor = flavor;
        }
        string show_info() 
        {
            return  flavor + "맛 사탕\n";
        }
};

class Chocolate : public Snack 
{
	string shape;
    public:
        Chocolate(string shape) 
        {
            this->price = 1000;
            this->name = "초콜릿";
            this->maker = "롯데";
            this->shape = shape;
        }

        string show_info() 
        {
            return shape + "모양 초콜릿\n";
        }
};

int Snack::count = 0;

int main()
{
    int choice = 1, sum = 0;
    string flavor, shape;
    vector <string> snackBasket;

    while (1)
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
            snackBasket.push_back(c.show_info());
            sum += Snack::get_count();
        }
        else if(choice == 2)
        {
            cout << "모양 입력하세요 : ";
            cin >> shape;
            Chocolate ch(shape);
            snackBasket.push_back(ch.show_info());
            sum += Snack::get_count();
        }
        else
        {
            cout << "0~2 사이의 숫자를 입력하세요." << endl;
        }
    }

    cout << "\n과자 바구니에 담긴 간식의 개수는 " << sum << "개 입니다.\n과자 바구니에 담긴 간식 확인하기!" << endl;
    for(string s : snackBasket)
    {
        cout << s;
    }
}