// 가상함수
#include<iostream>

using namespace std;

class Person 
{
    public:
        virtual void intro() 
        {
            cout << "사람입니다~" << endl;
        }
};

class Student : public Person 
{
    private :
	    string name;

    public:
        Student(string name) 
        {
            this->name = name;
        }
        void intro() 
        {
            cout << name << "은(는) 학생입니다." << endl;
        }

        void learn() 
        {
            cout << name << "은(는) 배웁니다." << endl;
        }
};

class Teacher : public Person 
{
    private:
    	string name;

    public:
        Teacher(string name) 
        {
            this->name = name;
        }
        void intro() 
        {
            cout << name << "은(는) 선생입니다." << endl;
        }

        void teach() 
        {
            cout << name << "은(는) 가르칩니다." << endl;
        }
};

int main()
{
    string names[3];
    
    cout << "세 명의 이름을 입력해주세요.(선생님, 학생, 학생) : " << endl;
    for(int i = 0; i < 3; i++)
    {
        cin >> names[i];
    }

    Teacher t(names[0]);
    Student s1(names[1]);
    Student s2(names[2]);

    Person *pList[3];

    pList[0] = &t;
    pList[1] = &s1;
    pList[2] = &s2;

    for(auto p : pList)
    {
        p -> intro();
    }

    ((Teacher*)pList[0]) -> teach();
    ((Student*)pList[1]) -> learn();
    ((Student*)pList[2]) -> learn();

}