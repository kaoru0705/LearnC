/* �Լ� �������� �迭 �������� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> //islower tolower ����ض� ��
#include <stdbool.h> //bool
//#include <string.h> // professor�� ���� string.h�� �� �� �� �ƴϴ�. strcmp�� ���ڿ��� �񱳰��� char ch; strcmp(&options[0], &ch); �� �� �� �Ұ����ϴ�.

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);//TODO: add a new menu

int main(void)
{
	char options[] = { 'u', 'l', 't'};//TODO: add a new menu
	int n = sizeof(options) / sizeof(char);

	typedef void (*FUNC_TYPE)(char*);
	FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose };//TODO: add a new menu

	printf("Enter a string\n>> ");

	char input[100];

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again.\n>> ");

	

	/* My Answers */
	/*printf("Choose an option:\nu) to upper\nl) to lower\n");
	char ch; // ���� while �ȿ� �� ���� �ھƼ� �������� ��츦 ����Ϸ��� ���� ch�� while�ȿ� �־ ���� ���� �ӽú����� ���� �� ���� �Ŷ�� ����������... flag ���� �� �����Ƽ� �̷��� �ٲ�µ� flag�� stdbool.h�� ���� �� �¾Ҵ�.
	scanf("%c", &ch); 

	while (getchar() != '\n');

	for (int i = 0; i < n; i++)
		if (options[i] == ch)
		{
			operations[i](input);
			printf("%s\n", input);
			break;
		}*/
	while (true)
	{
		printf("Choose an option:\n");
		printf("u) to upper\n");
		printf("l) to lower\n");
		printf("t) to transpose\n");

		char c;
		while (scanf("%c%*[^\n]%*c", &c) != 1) // �ϳ� �Է� �ް� \n������ �����ְ� \n�� ����� ������.
			printf("Please try again.\n");

		bool found = false; // �̰� ������ �� ���������� stdbool.h�� include ������ ���� ��� �ߴ�.

		/*switch (c)
		{
		case 'u':
			ToUpper(input);
			found = true;
			break;
		case 'l':
			ToLower(input);
			found = true;
			break;
		}*/

		for (int i = 0; i < n; ++i) // case���� �̰� �� �� ���� �ڵ�� ���� �� case���� ���������� ���� �� �ִ�. �㳪 options[] operations[]�� ������ �˰� �ִ� ���¶�� �������� �׷��� �������� �ʰ� ����� �߰��ϱ� �� ����. ex> 't' ����� �����ϴ� ���� �߿��� �� �κ��� ��ĥ �� ����
			if (options[i] == c)
			{
				(*(operations[i]))(input);
				found = true;
				break;
			}
		if (found)
			break;
		else
			printf("Wrong input try again\n");
	}

	printf("%s\n", input);

	return 0;
}

void update_string(char* str, int(*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}
void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}
void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}
void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}