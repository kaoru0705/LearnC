/* ���ڿ� �Է��ϱ� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char fruit_name[40]; //char fruit_name; stores only one character.
	printf("What is your favorate fruit?\n");

	scanf("%s", fruit_name); // scanf("%c", &fruit_name); // be careful with & �迭����
	//fruit_name�� 40���� �޸� ������ ��ǥ�ϴ� ù ��° �ּұ� ���� &�� ����.
	
	
	printf("You like %s!\n", fruit_name);// printf("You like % c!\n", fruit_name);
	//%s %c formatt specialfier=conversion specialfier in c c++������ conversion specifier�� �� ���� ��

	return 0;
}