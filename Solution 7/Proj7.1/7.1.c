/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Branching Statement �б⹮ if */ // branch �������� ��������
/* https://docs.microsoft.com/en-us/cpp/c-language/c-sequence-points?view=msvc-170 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int number;
	printf("Input a positive integer : ");
	scanf("%d", &number);

	if (number % 2 == 0)	// 0�� �ƴ� ���� �� true, Sequence Points
		printf("Even\n");
	else
		printf("Odd\n");

	return 0;
}