// 업캐스팅, 다운캐스팅
#include <iostream>

using namespace std;

class Snack {
protected:
	int price;
	string name;
	string maker;
public:
	Snack() { }
	string getName() {
		return name;
	}
	virtual void showInfo() {
		cout << name << " 과자입니다~" << endl;
	}
};

class Candy : public Snack
{
	private:
        string taste;
	public:
		Candy(string taste, int price, string name, string maker)
		{
			this -> taste = taste;
			this -> price = price;
			this -> name = name;
			this -> maker = maker;
		}
        virtual void showInfo()
        {
		    cout << name << " 사탕입니다~" << endl;
	    }
        string getTaste()
        {
            return taste;
        }
};

class Chocolate : public Snack
{
	private:
        string shape;
	public:
		Chocolate(string shape, int price, string name, string maker)
		{
			this -> shape = shape;
			this -> price = price;
			this -> name = name;
			this -> maker = maker;
		}
        virtual void showInfo() 
        {
		    cout << name << " 초콜렛입니다~" << endl;
        }
        string getShape()
        {
            return shape;
        }
};

int main()
{
	Candy c1("자두", 500, "신호등", "롯데");
	Candy c2("사과", 600, "츄파", "삼성");

	Chocolate ch1("사각", 700, "가나", "농심");
	Chocolate ch2("삼각", 800, "킷캣", "오리온");

	Snack *snackBasket[] = {&c1, &c2, &ch1, &ch2}; // Snack * = Candy *, Snack * = Chocolate * => 업캐스팅(부모 변수 접근)
    

	// for (Snack *s : snackBasket) 
    // {
	// 	// cout << s -> getName() << endl;
    //     s -> showInfo();
	// }

    // for(int i  = 0; i < 4; i++)
    // {
    //    snackBasket[i] -> showInfo();
    // }
    
    for(int i = 0; i < 2; i++)
    {
        snackBasket[i] -> showInfo();
        cout << ((Candy*)snackBasket[i])->getTaste() << " 맛\n" << endl;// Candy * = Snack* => 다운캐스팅
    }
    for(int i = 2; i < 4; i++)
    {
        snackBasket[i] -> showInfo();
        cout << ((Chocolate*)snackBasket[i])->getShape() << " 모양\n" << endl; // Candy * = Snack* => 다운캐스팅
    }

}