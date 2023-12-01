//scanf() �Լ��� ����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <inttypes.h> // intmax_t

int main()
{
	/* multiple inputs with blank separators*/
	//int i;
	//float f;
	//char str[30];
	//scanf("%d %f %s", &i, &f, str); //Note % is absent in front of str
	////scanf�� �Է� �� ��ĭ�� ������ ������� 123 4567 hello hi �Է��ϸ� " hi" �� buffer�� ���� �ִ� ä�� ���� �� �Ҹ�
	//printf("%d %f %s\n", i, f, str);

	/* character */
	//char c;
	//scanf("%c", &c);	// try blank ���ڸ� �Է� ���� ���� ��ĭ�� �Է��� ����
	//printf("%i\n", c);// blank is 32

	/* Unsigned as signed */
	//unsigned i;
	//scanf("%i", &i);	// try negative number ���� �� signed�� �ް� unsigned i �޸𸮿� ������ �״ٰ� �ٽ� signed�� ���� �̷� �� ���� ����.
	//printf("%i\n", i);

	/* Unsigned as unsigned */
	//unsigned i2;
	//scanf("%u", &i2);	// try negative number
	//printf("%u\n", i2);

	/* floating point numbers */
	// l for double for %f, %e, %E, %g
	//double d = 0.0;
	//scanf("%f", &d);	// lf, try E notation 3.14e4 d = 0.0
	//printf("%f\n", d);	// f

	/* Width */
	//char str[30];
	//scanf("%5s", str);	// width 5�ڸ������� �Է¹���
	//printf("%s\n", str);

	/* h modifier */
	//char i;
	//scanf("%hhd", &i);	// try large numbers 8��Ʈ�� �Է¹ް� ������ ©��
	//printf("%i\n", i);

	/* integer with characters */
	//int i;
	//scanf("%i", &i);	// try '123ab', '123a456' ���ڸ� ������ ���̻� ���ڸ� �Է��� �� ���������� ����
	//printf("%i\n", i);

	/* j modifier */
	//intmax_t i;	// portable type
	//scanf("%ji", &i); // j when intmax or unintmax �ڷ��� ���ľ�
	//printf("%ji", i); // proj 3.9

	/* Regular characters */ //���Խ�, ���ڿ��� �Է¹��� �� ��Ģ�� �°� �Է� �̷� �� �ִ�.
	/*int a, b;*/
	//scanf("%d%d", &a, &b); //�̰� ��ĭ �� ����
	//scanf("%d,%d", &a, &b);	// try blank separator only, comma�� ��� �� ��° �����Ⱚ�� ���� 123 enter�� 
	//scanf("%d ,%d", &a, &b);	//��ĭ�� �����ϰ� �Է� ������� �� �̰� �̻��ϰ� comma �յ� �� ������
	//scanf("%d, %d", &a, &b); // comma �ڿ� ��ĭ�� ���� ����
	//scanf("%d , %d", &a, &b);
	//scanf("%d-%d", &a, &b);	//-�� ����
	//scanf("%dA%d", &a, &b); //A�� ����
	/*printf("%d %d\n", a, b);*/

	/* char receives blank */
	//int a, b;
	//char c;
	//scanf("%d%c%d", &a, &c, &b);	// try 123 456 (blank)
	//printf("%d|%c|%d", a, c, b);	// | is separator

	// sentences?, getchar(), fgets(), etc.

	/* return value of scanf() */
	//int a, b;
	//int i = scanf("%d%d", &a, &b);	// �� ���� �Է� �޾Ҵ°�? �����ڿ� �°� �Է��ؾ� �ȴ�.
	//printf("%d", i);
	//printf("\n%d %d", a, b);
	//int ������ �ʰ��ϴ� ���ڵ� �����ڿ� ���� ©�� �� count�ȴ�. 111111111111111111111111111111 3 -> i = 2
	///*ex) a 2312
	//		0
	//	- 858993460 - 858993460*/

	/* modifier for printf() */
	//int i = 123;
	//int width = 5;	// from script file, scanf, etc. �����ϰ� width �ٲٱ�
	//printf("Input width : ");
	//scanf("%d", &width);
	//printf("%.*d\n", width, i);

	/* *modifier for scanf() */
	//int i;
	//scanf("%*d%*d%d", &i);	// �Է��� �ޱ� �޴µ� �����ϰ� ������ ������ �� �� suppress 
	//printf("Your third input = %d", i);

	//char a, b, c;

	//scanf("%c %c %c", &a, &b, &c);
	//// 123 4567 hello hi �̷��� �Է��� �ϸ� a = ' ' b = 'h' c = 'i' buffer�� �ִ� �� �̷��� ����
	//// 123 4567 hello enter a b c enter�ϸ� a = '\n' b = 'a' c = 'b' �Էµ� buffer �����ض�
	//// enter 3�� ġ�µ� �� �� %c�� '\n'�� �Է¹���? �߹߳�� �� �� ��°�� ������ whitespace�� ���Ƶ����ݾ�.

	///* https://en.cppreference.com/w/c/io/fscanf */
	///*Because most conversion specifiers first consume all consecutive whitespace, code such as

	//scanf("%d", &a); // ���ϱ� %d�� buffer�� �ִ� whitespace�� �þ���� �ٵ� ���ۿ� ���� ���ڴ� ����� �� ����
	//scanf("%d", &b);
	//will read two integers that are entered on different lines
	//(second %d will consume the newline left over by the first)
	//or on the same line, separated by spaces or tabs (second %d will consume the spaces or tabs).

	//The conversion specifiers that do not consume leading whitespace, such as %c,
	//can be made to do so by using a whitespace character in the format string:

	//scanf("%d", &a);
	//scanf(" %c", &c); // consume all consecutive whitespace after %d, then read a char
	//
	//scanf("%d %d", &a, &b); // ���⼭ �ù� ���� "a 3" �̷��� �Է��ص� �� �� ������ �� ��
	////���� ����� �Է¹��� �ʾҴٸ� ������� �Է��� ���ۿ� ��� �����ִ�. �׷��� �� �� ����ȵǰ� �˰��� �� ����
	//*/

	//printf("%c %c %c", a, b, c);
	//printf("yo");

	return 0;
}