// 클래스 상속, 정적 멤버, 업 캐스팅, 가상함수 사용

#include <iostream>
#include <cmath>

using namespace std;

class Calculation
{
protected:
    float x, y;
    static float result; // 정적멤버

public:
    float get_result()
    {
        return result;
    }
    virtual void print_result(float x, float y){}; // 가상함수
};

class Add : public Calculation // 상속
{
public:
    Add()
    {
        x = 0;
        y = 0;
        result;
    }

    void print_result(float x, float y)
    {
        result = x + y;
        cout << "------------------------------" << endl;
        cout << "결과 : " << result << endl;
        cout << "------------------------------" << endl;
    }
};
class Sub : public Calculation
{
public:
    Sub()
    {
        x;
        y;
        result;
    }

    void print_result(float x, float y)
    {
        result = x - y;
        cout << "------------------------------" << endl;
        cout << "결과 : " << result << endl;
        cout << "------------------------------" << endl;
    }
};
class Mul : public Calculation
{
public:
    Mul()
    {
        x;
        y;
        result;
    }

    void print_result(float x, float y)
    {
        result = x * y;
        cout << "------------------------------" << endl;
        cout << "결과 : " << result << endl;
        cout << "------------------------------" << endl;
    }
};
class Div : public Calculation
{
public:
    Div()
    {
        x;
        y;
        result;
    }

    void print_result(float x, float y)
    {
        result = x / y;
        cout << "------------------------------" << endl;
        cout << "결과 : " << result << endl;
        cout << "------------------------------" << endl;
    }
};

float Calculation::result = 0;

int main()
{
    float x, y;
    string continue_ = "a";
    char operator_;

    Add a;
    Sub s;
    Mul m;
    Div d;

    Calculation c;
    Calculation *add = &a; // 업캐스팅
    Calculation *sub = &s;
    Calculation *mul = &m;
    Calculation *div = &d;

    while (continue_ != "EXIT")
    {
        if (continue_ == "Y")
        {
            x = c.get_result();
        }
        else
        {
            while (true)
            {
                cout << "숫자를 입력해 주세요 : ";
                cin >> x;
                if (isnan(x) == 0)
                {
                    break;
                }
                cout << "숫자가 아닙니다. ";
            }
        }

        while (true)
        {
            cout << "연산자를 입력해 주세요 : ";
            cin >> operator_;
            if (operator_ == '+' || operator_ == '-' || operator_ == '*' || operator_ == '/')
            {
                break;
            }
            cout << "연산자가 아닙니다. ";
        }

        while (true)
        {
            cout << "숫자를 입력해 주세요 : ";
            cin >> y;
            if (isnan(y) == 0)
            {
                break;
            }
            cout << "숫자가 아닙니다. ";
        }

        if (operator_ == '+')
        {
            add->print_result(x, y);
        }
        else if (operator_ == '-')
        {
            sub->print_result(x, y);
        }
        else if (operator_ == '*')
        {
            mul->print_result(x, y);
        }
        else
        {
            div->print_result(x, y);
        }

        while (true)
        {
            cout << "연산을 계속 하시겠습니까?(Y: 계속, AC: 초기화, EXIT: 종료): ";
            cin >> continue_;
            if (continue_ == "Y" || continue_ == "AC" || continue_ == "EXIT")
            {
                break;
            }
            cout << "잘못 입력하셨습니다. ";
        }
    }
    cout << "------------------------------\n계산기 종료\n------------------------------" << endl;
}