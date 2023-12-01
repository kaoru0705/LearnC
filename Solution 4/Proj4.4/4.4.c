/* strlen() 함수 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h> // strlen and more

//strlen()
int main()
{
	char str1[100] = "Hello";
	char str2[] = "Hello";// 6 글자 넣어줌 딱 맞게
	char str3[100] = " \0"; // blank != NULL
	char str4[100] = "\n";

	printf("%zu %zu\n", sizeof(str1), strlen(str1)); // strlen return size_t = zu, null character는 세지 않음 %zu가 안되는 컴파일러도 있다.
	printf("%zu %zu\n", sizeof(str2), strlen(str2));
	printf("%zu %zu\n", sizeof(str3), strlen(str3));
	printf("%zu %zu\n", sizeof(str4), strlen(str4));

	/* Extra */
	char *str5 = (char*)malloc(sizeof(char) * 100);// OS에게 얼마나 많은 메모리를 받아오고 쓸지 알 수 없기 때문(반복) 주소를 적는 메모지만큼의 사이즈만 알 수 있다.
	str5[0] = 'H'; str5[1] = 'e'; str5[2] = 'l'; str5[3] = 'l'; str5[4] = 'o';
	str5[5] = '\0';// 동적할당을 할 땐 편리하게 "HELLO"이렇게 저장 못 함
	printf("%zu %zu\n", sizeof(str5), strlen(str5)); // str5 포인터 변수 자체의 사이즈 4byte 1byte가 아니네? ㅋㅋ


	return 0;
}