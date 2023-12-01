/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ���� ���� switch & case */
// ������ ������ � ���� �����Ŀ� ���� �޶����� switch case
// switch �� if�� ������ �� �ִ�.
// �㳪 �ڵ尡 �� ������ �������� ����� �ϳ��ϳ� �ڵ��� �� �ִ� ������ �� ���� switch case�� ���� ���
// switch case�� �����ϸ� if ������ ���� ������ �˰����� ��쿡�� ���� ����� �� �ִ�.
// ������ ��쿡�� �ƹ����� if
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char c;

	while ((c = getchar()) != '.') // apple�Է� �� c = 'a'
	{
		printf("You love ");

		switch (c) //Note: integer types only
		{
		case 'a':	// ���ڵ� int��
		case 'A':		// case 'a': case 'A': �̷��Ե� ����
			printf("apple");	// break; �� ������ ���� ��µȴ�. �� ������ case���� �� �̾�� �׷�����
			break;
		case 'b':
		case 'B':
			printf("baseball");
			break;
		case 'c':
		case 'C':
			printf("cake");
			break;
		default:
			printf("nothing");
		}


		printf(".\n");

		while (getchar() != '\n')
			continue;	// ù���� ���� ���� ����, ������ buffer�� �ִ� �͵�pple '\n'�� �Ҹ�
	}
	// buffer�� . ���� '\n'�� ���� �ִ�.
	//TODO: upper letters ? (use tolower()?)

	return 0;
}