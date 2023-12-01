/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �޴� ����� ���� */
// ��ü ������ ���� ���� �з����� ������� �޶�����.
/* https://en.cppreference.com/w/c/program/exit */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit()


char get_choice(void);
char get_first_char(void);
int get_integer(void);
void count(void);

int main()
{
	int user_choice;

	while ((user_choice = get_choice()) != 'q')
	{
		switch (user_choice)
		{
		case 'a':
			printf("Avengers assemble!\n");
			break;
		case 'b':
			putchar('\a'); //Beep
			break;
		case 'c':
			count();
			break;
		default:		// ���߰������� ����� ���� ����Ǹ� �ȵǴ� �ڵ�ٽ��� ���� �̷��� ǥ�⸦ �ϸ� debugging�� �ð��� �Ƴ� �� �ִ�.
			printf("Error with %d \n", user_choice); // �����ڰ� ���� �߻��ϸ� �ȵǴ� ������ �߰��ϱ� ����
			exit(1);	// #define EXIT_SUCCESS 0 #define EXIT_FAILURE 1
			break;
		}

	}
	/* My Answer */
	/*char ch;
	int count;
	int i;

	while (1)
	{
		printf("Enter the letter of your choice:\n");
		printf("a. avengers		b. beep\n");
		printf("c. count		q. quit\n");

		ch = getchar();

		if (ch == 'a')
			printf("Avengers assemble!\n");
		else if (ch == 'b')
			printf("\a");
		else if (ch == 'c')
		{
			printf("Enter an integer:\n");
			scanf("%d", &count);
			for (i = 1; i <= count; ++i)
				printf("%d\n", i);
		}
		else if (ch == 'q')
			break;

		while ((getchar()) != '\n')
			continue;
	}*/
	return 0;
}

void count(void)
{
	int n, i;

	printf("Enter an integer:\n");
	n = get_integer();
	for (i = 1; i <= n; ++i)
		printf("%d\n", i);
	while (getchar() != '\n')
		continue;
}

char get_choice(void)
{
	int user_input;

	printf("Enter letter of your choice:\n");
	printf("a. avengers\tb. beep\n");		// \t �̰͵� �������.
	printf("c. count\tq. quit\n");

	user_input = get_first_char();

	while ((user_input < 'a' || user_input > 'c') && user_input != 'q')
	{
		printf("Please try again.\n");
		user_input = get_first_char();
	}

	return user_input;
}

char get_first_char(void)
{
	int ch;

	ch = getchar();
	while (getchar() != '\n')
		continue;

	return ch;
}

int get_integer(void)
{
	int input;
	char c;

	while (scanf("%d", &input) != 1)
	{
		while ((c = getchar()) != '\n')
			putchar(c);
		printf(" is not an integer.\nPlease try again.");
	}

	return input;
}