/* ������ */
#include <stdio.h>
//ASCII CHART
//https://en.cppreference.com/w/c/language/ascii
//https://en.cppreference.com/w/c/language/escape
int main() 
{
	char c = 'A';
	char d = '*'; // d = 'A'

	printf("%c %hhd\n", c, c);
	printf("%c %hhd\n", d, d);
	
	printf("%c \n", c + 1); //B�� ����

	char a = '\a';// escape sequence ���� ��ü���ٴ� ������ ǥ�� bell \a = byte 0x07 in ASCII encoding
	char b = 0x07;
	printf("%c\n", b);
	printf("%c\n", a);
	printf("%hhd\n", a);
	printf("\7\n");//�̰͵� 8���� ���� ������ ���� \���� = 8����
	printf("\07\n");//\07 = \7 (0���� ����)= bell = 8���� 7�� �ǹ���
	printf("\x7\n");
	printf("\x23\n"); //#
	printf("%c\n", 65); //A ���
	printf("\101 \n"); //A ���
	printf("\65\n"); // \65 = 5
	printf("\12");// \12 = \012 = \n

	float salary;
	printf("$______\n");
	printf("$______\b\b\b\b\b\b");// \b backsapce
	scanf("%f", &salary);

	printf("AB\tCDEF\n"); // \t horizontal tab ���� �����ִ� tab
	printf("ABCD\tEF\n");
	printf("\\ \'HA+\' \"HELLO\" \?\n" "fuck");

	return 0;
}