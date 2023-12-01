//scanf() 함수의 사용법
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
	////scanf로 입력 시 빈칸이 있으면 끊어버림 123 4567 hello hi 입력하면 " hi" 는 buffer에 남아 있는 채로 종료 시 소멸
	//printf("%d %f %s\n", i, f, str);

	/* character */
	//char c;
	//scanf("%c", &c);	// try blank 문자를 입력 받을 때는 빈칸도 입력을 받음
	//printf("%i\n", c);// blank is 32

	/* Unsigned as signed */
	//unsigned i;
	//scanf("%i", &i);	// try negative number 받을 때 signed로 받고 unsigned i 메모리에 저장해 뒀다가 다시 signed로 꺼냄 이런 짓 하지 마라.
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
	//scanf("%5s", str);	// width 5자리까지만 입력받음
	//printf("%s\n", str);

	/* h modifier */
	//char i;
	//scanf("%hhd", &i);	// try large numbers 8비트만 입력받고 나머진 짤림
	//printf("%i\n", i);

	/* integer with characters */
	//int i;
	//scanf("%i", &i);	// try '123ab', '123a456' 문자를 만나면 더이상 숫자를 입력할 건 끝났나보다 생각
	//printf("%i\n", i);

	/* j modifier */
	//intmax_t i;	// portable type
	//scanf("%ji", &i); // j when intmax or unintmax 자료형 수식어
	//printf("%ji", i); // proj 3.9

	/* Regular characters */ //정규식, 문자열을 입력받을 때 규칙에 맞게 입력 이런 용어가 있다.
	/*int a, b;*/
	//scanf("%d%d", &a, &b); //이건 빈칸 다 씹음
	//scanf("%d,%d", &a, &b);	// try blank separator only, comma가 없어서 두 번째 쓰레기값이 나옴 123 enter도 
	//scanf("%d ,%d", &a, &b);	//빈칸을 무시하고 입력 받으라는 뜻 이건 이상하게 comma 앞뒤 다 무시함
	//scanf("%d, %d", &a, &b); // comma 뒤에 빈칸만 무시 ㅋㅋ
	//scanf("%d , %d", &a, &b);
	//scanf("%d-%d", &a, &b);	//-로 구분
	//scanf("%dA%d", &a, &b); //A로 구분
	/*printf("%d %d\n", a, b);*/

	/* char receives blank */
	//int a, b;
	//char c;
	//scanf("%d%c%d", &a, &c, &b);	// try 123 456 (blank)
	//printf("%d|%c|%d", a, c, b);	// | is separator

	// sentences?, getchar(), fgets(), etc.

	/* return value of scanf() */
	//int a, b;
	//int i = scanf("%d%d", &a, &b);	// 몇 개를 입력 받았는가? 형식자에 맞게 입력해야 된다.
	//printf("%d", i);
	//printf("\n%d %d", a, b);
	//int 범위를 초과하는 숫자도 형식자에 맞춰 짤릴 뿐 count된다. 111111111111111111111111111111 3 -> i = 2
	///*ex) a 2312
	//		0
	//	- 858993460 - 858993460*/

	/* modifier for printf() */
	//int i = 123;
	//int width = 5;	// from script file, scanf, etc. 유연하게 width 바꾸기
	//printf("Input width : ");
	//scanf("%d", &width);
	//printf("%.*d\n", width, i);

	/* *modifier for scanf() */
	//int i;
	//scanf("%*d%*d%d", &i);	// 입력을 받긴 받는데 무시하고 변수에 대입을 안 함 suppress 
	//printf("Your third input = %d", i);

	//char a, b, c;

	//scanf("%c %c %c", &a, &b, &c);
	//// 123 4567 hello hi 이렇게 입력을 하면 a = ' ' b = 'h' c = 'i' buffer에 있던 게 이렇게 적용
	//// 123 4567 hello enter a b c enter하면 a = '\n' b = 'a' c = 'b' 입력됨 buffer 조심해라
	//// enter 3번 치는데 맨 앞 %c만 '\n'를 입력받음? 야발년아 두 세 번째는 공백이 whitespace를 빨아들이잖아.

	///* https://en.cppreference.com/w/c/io/fscanf */
	///*Because most conversion specifiers first consume all consecutive whitespace, code such as

	//scanf("%d", &a); // 보니까 %d는 buffer에 있는 whitespace를 씹어먹음 근데 버퍼에 남은 문자는 적용될 수 있음
	//scanf("%d", &b);
	//will read two integers that are entered on different lines
	//(second %d will consume the newline left over by the first)
	//or on the same line, separated by spaces or tabs (second %d will consume the spaces or tabs).

	//The conversion specifiers that do not consume leading whitespace, such as %c,
	//can be made to do so by using a whitespace character in the format string:

	//scanf("%d", &a);
	//scanf(" %c", &c); // consume all consecutive whitespace after %d, then read a char
	//
	//scanf("%d %d", &a, &b); // 여기서 시발 문자 "a 3" 이렇게 입력해도 둘 다 대입이 안 됨
	////이유 제대로 입력받지 않았다면 사용자의 입력이 버퍼에 계속 남아있다. 그래서 둘 다 적용안되고 똥값이 된 거임
	//*/

	//printf("%c %c %c", a, b, c);
	//printf("yo");

	return 0;
}