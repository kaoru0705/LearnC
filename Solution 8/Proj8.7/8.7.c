/* 중요한 프로젝트는 책꽂이를 해라*/
/* 입력 스트림과 숫자 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
		Assume that your input is :
		Hello 123 3.14
	*/

	// console에서 왜 엔터로 입력되게 한 거냐 딱 잘라 말하긴 힘들지만 대신 buffer에 담기기만 하고 프로그램으로 넘어가지 않았기 때문에 
	// 삭제하고 다시적을 수 있는 거다. abc > abf

	char str[255];
	int i, i2;
	double d;

	scanf("%s %d %lf", str, &i, &d);
	printf("%s %d %f\n", str, i, d);

	//// or (see the difference)

	scanf("%s %d %d", str, &i, &i2);
	printf("%s %d %d\n", str, i, i2);	// str[0] != '\n' char ch; %c였으면 ch == '\n' 
	//									// %s는 whitespace를 씹어먹는다? %d마냥?
	//									// 예아 그리고 whitespace로 구분 %c 빼고는 대부분은  whitespace를 무시한다

	// 기본적으로 프로그램은 콘솔창에 입력한 것을 한 글자 한 글자 문자로 받아들인다.
	// getchar()같은 경우는 빈칸까지 하나하나 받아들이고 scanf같은 경우는 빈칸이 있으면 한가지 항목을 입력했나보다 하고 끊어줌
	/*
	* hello 123 3.14
	* hello 123 3.140000 프로그램이 받아들일 때는 문자로 받아들이는데 scanf 내부에서 숫자로 변환될 수 있는 문자구나하고
	* abcd 456 1.234567 456다음 빈칸이 있어서 아 두번째 입력은 끝났구나
	scanf에 명령을 할 때는 정수로 받아라하고 명령했고 실제로 프로그램은 1이라는 숫자를 문자형태로 받아서 아 숫자가 될 수 있구나 여기까진 괜찮아 근데 .은 scanf가 정수니까 숫자가 아니구나 하고
	받아들이지 않고 넘김
	어떤 자료형이냐에 따라서 똑같은 입력도 다르게 받아들인다.
	getchar putchar는 문자로 받아들여서 곧이곧대로 출력
	scanf printf 내부적으로 문자형태로 들어온 문자열, 문자들의 stream을 우리가 원하는 형태로 받아들이고 출력한다.
	정수로 변환할 수 없는 문자가 들어온다면 입력을 중단하고 나머지는 buffer에 남겨둔다.
	*/


	// or (see the difference)

	char c;
	while ((c = getchar()) != '\n')
		putchar(c);
	printf("\n");

	// 콘솔입출력에서는 문자형태로 data가 스트림을 통해 왔다갔다한다고 생각하지만
	// 결국 내부적으로는 2진수로 변환된 data의 stream으로 왔다갔다 한다.

	return 0;
}