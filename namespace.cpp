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

using namespace busan; // busan�̶�� ���ӽ����̽��� ������������ ���������� ��ü ��ȯ
// �Ʒ� ó�� �ϳ� �� ��ȯ �ϴ°� �� ���� ����
// using busan::num;
// using busan::land;


int main()
{
	seoul::num = 1; // seoul�̶�� ���ӽ����̽��� ��������
	num = 2; // ���������� ��ȯ�� busan�� ��������

	seoul::land = "lotte";
	land = "beach";

	cout << "���� ������ȣ: " << seoul::num << endl;
	cout << "���� ���帶ũ: " << seoul::land << endl;
	cout << "�λ� ������ȣ: " << num << endl;
	cout << "�λ� ���帶ũ: " << land << endl;

}