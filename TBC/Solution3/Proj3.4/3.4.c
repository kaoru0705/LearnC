/* ������ ����� ���α׷� ����� */
#include <stdio.h>

int main()
{
	//breakpoint�� ����� f10���� debug ���� �㳪 ���� toggle
	//int i = 0, j = 0;

	//printf("Input two intergers\n");

	//scanf("%d%d", &i, &j);//%d%d %d %d ������ ���� ���� �㳪 �ٸ� ��쵵 �ִ�. ������������ ������ ���ƾ� �Ѵ�.

	//printf("Your numbers are %d and %d\n", i, j); //%f float�� ����
	float won = 0.0f;
	float dollar = 0.0f;

	printf("Input Won\n");
	scanf("%f", &won);

	dollar = won * 0.00089f; //warning C4244: '=': conversion from 'double' to 'float', possible loss of data
	//warning�� ����� �� ����. 0.00089�� float�� literal�� �ٲ�
	// won & 0.00089�� type�� �ٸ�
	printf("Dollar = %f\n", dollar);

	return 0;
}