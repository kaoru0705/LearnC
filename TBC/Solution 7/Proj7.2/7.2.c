/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ǥ�� ����� �Լ���  getchar(), putchar() */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// getchar(), putchar()

int main()
{
	/* 
		1. Intrduce getchar(), putchar()
		2. Use while loop to process character sequences
		3. Filter a specific character
		4. Convert numbers to asterisks
		5. Lower characters to Upper characters
	*/

	char ch; // int ch�� �������� ���� ���, int ch; scanf("%c", &ch); printf("%c", ch);�� ��������

	ch = getchar();		// �� ���ڸ� �����´�. abcdef\nġ�� ch = 'a'�� �ǰ� �������� buffer�� ����
	putchar(ch);		// �� ���ڸ� ����Ѵ�.

	while (ch != '\n') // Use '\n' to find the end of a sentence
	while ((ch = getchar()) != '\n') // =�� ������ �켱���� ���� ������ �Ұ�ȣ�� ħ
	{
		putchar(ch);	// �� ���ھ� �Է��� �� �޳�? buffer

	}


	while ((ch = getchar()) != '\n')
	{
		/* try 3 */
		if (ch >= '0' && ch <= '9')
			ch = '*';
		/* try 2 */
		//for (int i = '0'; i <= '9'; ++i) // ���������� ��� �ݺ��� �ϹǷ� ���� ���α׷��ӵ��� try 3�� ����.
		//	if (ch == i)
		//		ch = '*';

		/* try 1 */
		/*if (ch == '0')
			ch = '*';*/

		/*if (ch == 'f')
			ch = 'X';*/
		/*else if (ch == 'F') �������� �̷��� �� �Ѵ�. �������� ��
			ch = 'X';*/
		/*if (ch == 'f' || ch == 'F')
			ch = 'X';*/


		/* my poor answer */
		/*if (ch >= 'a' && ch <= 'z')
			ch -= 32;*/
		if (ch >= 'a' && ch <= 'z')
			ch -= 'a' - 'A';
		else if (ch >= 'A' && ch <= 'Z')
			ch += 'a' - 'A';
		putchar(ch);
	}

	putchar(ch); // ch = '\n'

	return 0;
}