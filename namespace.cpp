#include<iostream>

using namespace std;

namespace seoul
{
	int num;
	string land;
}

namespace busan
{
	int num;
	string land;
}

using namespace busan; // busan이라는 네임스페이스의 지역변수들을 전역변수로 전체 변환
// 아래 처럼 하나 씩 변환 하는게 더 좋은 습관
// using busan::num;
// using busan::land;


int main()
{
	seoul::num = 1; // seoul이라는 네임스페이스의 지역변수
	num = 2; // 전역변수로 변환된 busan의 지역변수

	seoul::land = "lotte";
	land = "beach";

	cout << "서울 지역번호: " << seoul::num << endl;
	cout << "서울 랜드마크: " << seoul::land << endl;
	cout << "부산 지역번호: " << num << endl;
	cout << "부산 랜드마크: " << land << endl;

}