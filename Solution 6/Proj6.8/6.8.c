/* for loop introduction mainly uses in loop */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/* Indefinite loop vs.Counting loop */
	//while (1)	// ���� ������ �˻������� �״������ʹ� �Ű� �� ����. indefinite
	//{
	//	// do something
	//}

	/*
		Counting Loop
		1. Counter intialization
		2. Counter check
		3. Counter change
	*/

	// while�� Ʋ���� ���� ������ indefinite�̱� ���� 
	//int i;

	//i = 1;

	//while (i <= 10)		//Note: <=
	//{
	//	printf("%d ", i);
	//	i++;
	//}

	// int i; for loop �ȿ��� ���� ����

	for (int i = 1; i <= 10; i++)	// ���� �� ������ �� ���� ���´�. �Ǽ��� ���� ���ϰ� ��Ȯ�ϰ� �����ϰ� ����� �� �ִ�.
		printf("%d ", i);

	// printf("%d\n", i); //error

	return 0;
}