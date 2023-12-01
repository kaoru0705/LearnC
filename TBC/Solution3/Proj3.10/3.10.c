/* 문자형 */
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
	
	printf("%c \n", c + 1); //B가 나옴

	char a = '\a';// escape sequence 문자 자체보다는 행위를 표현 bell \a = byte 0x07 in ASCII encoding
	char b = 0x07;
	printf("%c\n", b);
	printf("%c\n", a);
	printf("%hhd\n", a);
	printf("\7\n");//이것도 8진수 ㅋㅋ 낚이지 마라 \숫자 = 8진수
	printf("\07\n");//\07 = \7 (0생략 가능)= bell = 8진수 7을 의미함
	printf("\x7\n");
	printf("\x23\n"); //#
	printf("%c\n", 65); //A 출력
	printf("\101 \n"); //A 출력
	printf("\65\n"); // \65 = 5
	printf("\12");// \12 = \012 = \n

	float salary;
	printf("$______\n");
	printf("$______\b\b\b\b\b\b");// \b backsapce
	scanf("%f", &salary);

	printf("AB\tCDEF\n"); // \t horizontal tab 줄을 맞춰주는 tab
	printf("ABCD\tEF\n");
	printf("\\ \'HA+\' \"HELLO\" \?\n" "fuck");

	return 0;
}