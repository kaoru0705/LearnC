/* �ݺ� �������� ù���� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n = 1;
/* ���� ���� ���������� goto��ó�� ���ư���? */
//label:
//	printf("%d\n", n);
//	n = n + 1;
//
//	if (n == 10) goto out; // ��� �� �� goto  ������ ���̰� �б� ���� ������ �߻��ϱ� ����.
//
//	goto label;
//
//out:
	while (n < 11)
	{
		printf("%d\n", n);
		n = n + 1; //���ϴ� ������ �ݵ�� ���� //n = n + 1 infinite loop
	}




	return 0;
}