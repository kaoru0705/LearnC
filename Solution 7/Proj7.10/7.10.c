/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Loop ����� continue & break */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/* continue */
	//for (int i = 0; i < 10; ++i)
	//{
	//	if (i == 5)
	//		continue;

	//	printf("%d ", i);

	//	/*if (i != 5)
	//		printf("%d ", i);*/	// continue�� ���ٰ� �ؼ� ������ �� �ϴ� ���� ���� �ʴ�.
	// // �������� �㳪 5�� �ѱ�ڴٿ� 5�� �ƴ� ���� ����ϰڴٴ� ���ӽ��� �ٸ���. continue�� �������� ���� �޾� ���� �� ����
	// // �˰����� �����ϰų� ����� �� �������� ����� ������Ģ ���а��� ���� �Ϲ����� ���¿� �����ϴ� �˰����� © ����
	// // �帧�� ���������� �������� �������� ����
	//}

	/* break */
	/*for (int i = 0; i < 10; ++i)
	{
		if (i == 5)
			break;

		printf("%d ", i);
	}*/

	/* while and continue */
	/*int count = 0;
	while (count < 5)
	{
		int c = getchar();
		if (c == 'a')
			continue;
		putchar(c);
		count++;
	}*/

	/* for and continue */
	/*for (int count = 0; count < 10; ++count)
	{
		int c = getchar();
		if (c == 'a')
			continue;
		putchar(c);
	}*/

	/* continue as a placeholder */
	//while (getchar() != '\n')
	//	continue;	// continue; = ;
	//// placeholder �ϴ� �� ���µ� �ڸ��� �����ϰ� ���⿡ ���� �� �� �ִٴ� �� ������
	//// ���� ������ ���� ����
	//// �޶� null statement ; �̰� ���� �ͺ��� ���Ƿ��� Ȯ�� ����

	/* Need to use continue ? */
	//char c;
	//while ((c = getchar()) != '\n')
	//{	// �� ���� ����
	//	//	//if (c != 'a')
	//	//	putchar(c);	// �̰� �����ϱ� ��
	//	if (c == 'a')	// �Ϲ������δ� ����� �ϴµ� �������� ���� ������ �ɷ����� ���ؼ� continue�� �� �Ŵ�
	//		// c == a�� ��쿡�� �ڿ� �κ��� �������� �ʴ´ٶ�� �ڵ�μ� ǥ���ϱ� ���� �� �Ŷ��
	//		// �����ϰų� ����� �߰��� �� �ִ� ��� a�� �ƴ϶� �ٸ� ���ڿ��� �Ÿ����� ���׷��̵尡 �� ���
	//		// continue�� ����ϴ� �� �� ���� ����.
	//		// �ǹ����� �� ������� ����� �ȴ�.
	//		continue;
	//	putchar(c);
	//}

	/* break */

	/*char c;
	while ((c = getchar()) != '.')
	{
		putchar(c);
	}*/

	//while (1) // ������ �� ������ �̷��� �����ϴ� ��찡 �� ����. ���ǿ� ���� ���� ����� �Բ� �����ؼ� �򰥸� ���ɼ��� �ִ�.
	//		// �� ������ �� ���� ��ɸ� �ϴ� ���� ���� �߼� while���� �� �̷� ������ �� ���� ��
	//		// ���� ���� ������ �׸��� �̰� ���������� �����ϱ� �� ����.
	//{
	//	char c = getchar();

	//	if (c == '.')
	//		break;
	//	putchar(c);
	//}
	//// main loop game server while(1) break

	for (int i = 0; i < 10; i++) // one loop break;
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 5)
				break;

			printf("(%d %d)", i, j);
		}

		printf("\n");
	}
	return 0;
}