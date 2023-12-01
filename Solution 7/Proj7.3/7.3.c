/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ctype.h ���� �Լ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> // �����Լ� isalpha() and more
// 7.2���� �ߴ� ������ �̹� ���̺귯���� �ִ�?
/*
	Reference link
	https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
*/
// ���α׷��ӵ��� �� �ܿ��� ���� �� �ƴϴ�. ���۸��� �ؼ� ���� ���
int main()
{
	char ch;

	while ((ch = getchar()) != '\n')
	{
		//if (ch >= '0' && ch <= '9') // try 3
		//	ch = '*';
		if (isdigit(ch) != 0)	//  c++ ������ �˰��� ���� �е��� �̰� != 0�� ���ڲ��� �� c���� ���� ���� ��
			ch = '*';

		/*if (ch >= 'a' && ch <= 'z')
			ch -= 'a' - 'A';
		else if (ch >= 'A' && ch <= 'Z')
			ch += 'a' - 'A';*/

		if (islower(ch))	// ���
			ch = toupper(ch);
		else if (isupper(ch))
			ch = tolower(ch);

		putchar(ch);
	}

	putchar(ch);

	return 0;
}