/* �߿��� ������Ʈ�� å���̸� �ض� */
/* �Է� Ȯ���ϱ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long get_long(void);

int main()
{
	long number;
	while (1)
	{
		printf("Please input a integer between 1 and 100.\n"); // between�� 1 100 ���� �� ��

		number = get_long();

		if (number > 1 && number < 100)
		{
			printf("Ok, Thank you.\n");
			break;
		}
		else
			printf("Wrong input. Please try again.\n");
	}

	printf("Your input %d is between 1 and 100. Thank you.\n", number);

	return 0;
}

long get_long(void)		// ��� �̰͵� ������ file�� ������ ����ϰ� ���� �� �ִ�.
{
	printf("Please input an integer and press enter.\n");

	long input;
	char c;

	while (scanf("%ld", &input) != 1)
	{
		printf("Your input - ");

		while ((c = getchar()) != '\n') // ����� �Է¹��� �ʾҴٸ� ������� �Է��� ���ۿ� ��� �����ִ�.
			putchar(c); // input left in buffer
		// ���α׷��Ӵ� ���ߺ��� ���־� �ȴ�. �Լ��� ��� long type�� �Ź� �̷��� copy and paste�� �Է¹����� ���ȴ�
		// �Լ��� ����
		printf(" - is not an integer. Please try again.\n");
	}

	printf("Your input %ld is an integer. Thank you.\n", input);

	return input;
}