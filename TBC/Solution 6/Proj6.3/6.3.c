/* Entry-Condition Loop �������� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/*
	while (expression)	��ǻ�� ���������δ� ������ 0�̸� false �ƴϸ� true  
		statement
	*/

	int i;

	//i = 1;
	//while (i < 5)		// infinite loop
	//	printf("Hi!\n");// ���� i�� ���� interation �ݺ��ϴ� �� ����
	
	//i = 1;
	//while (--i < 5)		// wrong direction
	//	printf("Hi!\n");

	/*i = 1;
	while (i < 5)
	{
		printf("i before = %d\n", i);
		i++;
		printf("i after = %d\n", i);
	}*/

	//i = 10;
	//while (i++ < 5)		// cannot enter while(i++) �̷� �� �ǿܷ� ���� ��
	//{
	//	printf("Hi\n");
	//}

	/* Common mistakes */
	
	//i = 0;
	//while (i < 3)
	//	printf("%i\n", i);
	//	i++;// indenting = tab�ϴ� �� �̷��� �θ�

	//i = 0;
	//while (i++ < 3);	// null statement
	// printf("%i\n", i);

	while (scanf("%d", &i) == 1)
		;// null statement 
	// do something (?) ���� �̷��� ��ȣ��ó�� �� �ʿ䰡 ����. ��ǻ�Ͱ� ���� ���� ���� �� ���� �ٸ��� ��
	// ������ �б� ���ϰ� �ǻ簡 ��Ȯ�� �ڵ带 �߿� �� ��
	printf("%d", i); // ���� ���� ��� ���� �Է��� �� �þ����

	return 0;
}