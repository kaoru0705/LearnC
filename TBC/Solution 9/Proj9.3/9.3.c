/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �Լ����� �ڷ����� ��ȯ�� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int int_min(int, int); // ��ȯ�ڷ����� �Լ��� �ڷ����̶�� �� �� �ִ�

int main()
{
	int i1, i2;

	while (1)
	{
		printf("Input two integers : ");

		if (scanf("%d %d", &i1, &i2) != 2) break;

		int lesser = int_min(i1, i2);
		// int lesser = min;
		printf("The lesser of %d and %d is %d\n", i1, i2, lesser);

		//printf("The lesser of %d and %d is %d\n", i1, i2, int_min(i1, i2));

	}

	printf("End.\n");

	

	return 0;
}

int int_min(int i, int j)
//int_min(int i, int j) ������ ��ȯ �ڷ����� ������ ���� ������ �����Ϸ��� �Լ��� ��ȯ �ڷ����� ���� ��� int�� ����
// �㳪 ���� �� ����
{
	//int min; // local variable ��������

	//if (i < j)
	//	min = i;
	//else
	//	min = j;

	//return min; // ���� ��ȯ

	return (i < j) ? i : j; // ����� �̷��� ���ٰ�

	// return (float)min; warning float to int? int�� ��ȯ�ϴ� ���������δ� int((float)min)�� �׷���.
	// ����ü ��ȯ���� ���� ���� ����
	//if (i < j) // if = control path, flow control��� �� ���⼭ ������ ��Ų�ٸ� ������Ű�� ���� ���� ������ �ؾߵȴ�.
	//	return i;
	///*else
	//	return j;*/ // ���� �̰� �ּ�ó���Ѵٸ� ���� 'int_min' : not all control paths return a value

	printf("who am I?"); // �̰� ��� ����� �� ����
}