/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ���ڿ� ���ڸ� ��� �Է� �ޱ� */ /* 4.10 ���� �ض� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(char cr, int lines, int width);

int main()
{
	char c;
	int rows, cols;
	// char yo;
	/* try 1 */
	//while (1)	// program�� ������ �� �ٹٲ����� �޼��ϱ� ���� " %d %d"���� �Է��ϰ� display�� ����ϰ� �����ϱ� ����
	//{
	//	scanf("%c %d %d", &c, &rows, &cols);	// scanf�� ���� ���� ����'\n'�� buffer�� ���ܵ�
	//	//while (getchar() != '\n')		//  a 3 3 '\n' b 1 2 �Է½� �̰� ���� �ʴ´ٸ� c = '\n'�� ���� �״��� b�� rows�� cols�� �޾Ƶ����� �� �� �� �� ���� 3 �״�ΰ� �ȴ�.
	//	//	continue;
	//	display(c, rows, cols);
	//	if (c == '\n')
	//		break;		//doesn't work well
	//}

	/* try 2 */

	printf("Input one character and two integers:\n");
	while ((c = getchar()) != '\n')
	{
		scanf("%d %d", &rows, &cols);
		while (getchar() != '\n') continue;

		display(c, rows, cols);
		printf("Input another character and two integers:\n");
		printf("Press Enter to quit.\n");
	}

	return 0;
}
/* my answer */
//void display(char cr, int lines, int width)
//{
//	for (int i = 0; i < lines; i++)
//	{
//		for (int j = 0; j < width; j++)
//			printf("%c", cr);
//
//		printf("\n");
//	}
//}
void display(char cr, int lines, int width)
{
	int row, col;
	for (row = 1; row <= lines; row++)
	{
		for (col = 1; col <= width; col++)
			putchar(cr);

		putchar('\n');
	}
}
