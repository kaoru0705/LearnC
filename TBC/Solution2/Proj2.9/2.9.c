/* �Լ� ����� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void say_hello(void); // prototyping, function declaration
//���� �ص� �˾Ƽ� ȣ���� �� �������� �Ѿ�ٰ� ��ŷ�� �� ��ħ

int main() // os�� ���α׷��� �����ų �� ������ main���� ����
{
	say_hello();	// main�Լ������� ���� �Ǿ��־ ȣ���� �� �ִ�.
	// �������� ���� �Ŀ� ��ŷ�ϴ� �������� ��ü�� ã�ƴٰ� ���⼭ �� �� �ְ� �������ش�.
	say_hello();


	return 0;
}

void say_hello(void)	// function definition ��ü
{
	printf("Hellow Wolrd!\n");

	//return; // output void �� ��� return ���� ����
}