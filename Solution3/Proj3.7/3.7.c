/* �پ��� �������� */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() 
{
	//�ڷ����� �ּ� ũ���. �����Ϸ��� ���� �ٸ�
	//long�� ���� ������ ���� �� int �� 2byte �׶� long�� 4byte long long�� ���� ����
	char c = 65;
	short s = 200;
	unsigned int ui = 3000000000U;//3'000'000'000U c++������ �ڸ��� �ִ� �� ǥ��
	// literal U ǥ�� literal ���� ���� ���ڵڿ� literal�� ������ ���� �� �� ���. �Ǽ��� ���ɼ��� ���� ���� �����ϴ� ��찡 �ִ�.
	long l = 65537L;
	long long ll = 12345678908542LL; // 12'345'678'908'642ll

	printf("char = %hhd, %d, %c\n", c, c, c);//%c�� ���� ���
	printf("short = %hhd, %hd, %d\n", s, s, s);//%hhd overflow
	printf("unsigned int = %u, %d\n", ui, ui);//%d overflow
	printf("long = %ld, %hd\n", l, l);
	printf("long long = %lld, %ld\n", ll, ll); // warning %ld, ll

	return 0;
}