/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* else�� if�� ¦���� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int number;
	scanf("%d", &number);

	/*if (number == 1)
		printf("One");
	else if (number == 2)
		printf("Two");
	else if (number == 3)
		printf("Three");*/

	//if (number == 1)
	//	printf("One");
	//else
	//	if (number == 2)
	//		printf("Two");
	//	else
	//		if (number == 3)
	//			printf("Three"); // Indenting ���� �̷��Դ� �� ����. 
	
	// minimum 127 levels of nestings else if�� �ּ� 127���� �������ش�. �ٵ� �������� 10�� �̻� �� �� ���ٰ� ��

	/*if (number > 5)
	{
		if (number < 10)
			printf("Larger than 5 smaller than 10\n");
		else
			printf("Larger than or equal to 10\n");
	}
	else
		printf("Less than or equal to 5");*/

	// Compilers ignore indenting
	// else�� indenting�� ������� �����̿� �ִ� if�� �ٴ´�. �򰥸� ������ �ִ� ���� �߰�ȣ�� �Ķ�
	
	
	//if (number > 5)
	//	if (number < 10)
	//		printf("Larger than 5 smaller than 10\n");
	//else
	//	printf("Less than or equal to 5"); // �̰� ���ô�. compiler�� �˾Ƽ� indenting�ؼ� �� ��° if�� �����.

	

	return 0;
}