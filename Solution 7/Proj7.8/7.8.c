/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �ܾ� ���� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define STOP '.'

int main()
{
	/* My answer ��¦ ������ */

	/*char input;
	unsigned word = 0;
	unsigned line = 0;
	unsigned chcount = 0;
	bool Ischar = false;


	printf("Enter text :\n");
	
	while ((input = getchar()) != STOP)
	{
		if (input != '\n' && input != ' ')
		{
			chcount++;
			Ischar = true;
		}
		else if (input == '\n')
		{
			line++;
			if (Ischar == true)
			{
				word++;
				Ischar = false;
			}
		}
		else if (input == ' ' && Ischar == true)
		{
			word++;
			Ischar = false;
		}
	}

	if (input == STOP)
		line++;

	printf("Characters = %u, Words = %u, Lines = %u", chcount, word, line);*/

	/* Professor answers */
	char c;
	int n_chars = 0;	// number of non-space characters
	int n_lines = 0;
	int n_words = 0;
	bool word_flag = false;
	bool line_flag = false;

	printf("Enter text :\n");

	while ((c = getchar()) != STOP)
	{
		if (!isspace(c))// isspace(c) == false �Ǽ����� �ʱ� ���� �̷��� ���⵵ �Ѵ�. ���� c��Ÿ���� !��ȣ ��� \n ������ �� ����
		{
			n_chars++;	// count non-space characters

			if (!line_flag)
			{
				n_lines++;
				line_flag = true;
			}

			if (!word_flag)
			{
				n_words++;
				word_flag = true;
			}
		}

		if (c == '\n')
			line_flag = false;

		if (isspace(c))
			word_flag = false;
	}

	printf("Characters = %d, Words = %d, Lines = %d", n_chars, n_words, n_lines);

	return 0;
}