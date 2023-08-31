#include<iostream>

using namespace std;

int main()
{
    //실습 1//
    string city[] = {"Korea", "Japan", "China", "USA", "UK"};
    
    /*
    // for-each문
    // for ( 자료형 변수이름 : 배열 ) { }
    for(string ci : city)
    {
        cout << ci << endl;
    }
    */

    // 일반 for문
    // (배열의 총 바이트) / (첫 번째 인덱스 바이트) = 배열의 갯수
    for(int i = 0; i < sizeof(city) / sizeof(city[0]); i++)
    {
        cout << city[i] << endl;
    }



    // 실습2 //
    string city2[5];

    cout << "나라 이름을 띄어쓰기로 5개 입력하세요: ";

    for(int i = 0; i < 5; i++)
    {
        cin >> city2[i];
    }

    for(string ci2 : city2)
    {
        cout << ci2 << endl;
    }



    // 실습 3 //
    int grade[5];
    double sum;
    
    for(int i = 0; i < 5; i++)
    {
        cout << i + 1 << "번 학생의 성적을 입력하세요 : ";
        cin >> grade[i];
        sum += grade[i];
    }
    
    cout << "성적 평균 : " << sum / 5;
    // 원소 개수 모를 때
    // cout << "성적 평균 : " << (double(sum) / double(sizeof(grade) / sizeof(grade[0])));
}
