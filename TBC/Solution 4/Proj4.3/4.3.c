/* 문자열이 메모리에 저장되는 구조 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//문자열의 끝이 어딘지 표현하기 위해서 메모리 공간을 하나 더 쓴다.
int main()
{
	int a = 1;
	int int_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	printf("%i %i %i\n", int_arr[0], int_arr[1], int_arr[9]);

	//printf("%i\n", int_arr[10000]);// exited with code -1073741819. 0이 아니니 문제가 있다는 뜻

	char c = 'a'; // 실제로 문자는 정수로 저장됨 예전에도 나옴
	char str1[10] = "Hello";// null character 6글자다. 컴파일러가 알아서 추가함
	char str2[10] = { 'H', 'i' };
	//\0 is the most commonly used octal escape sequence
	printf("%c\n", c);
	printf("%s", str1);
	printf("%s\n", str2);

	printf("%hhi %hhi %hhi %hhi %hhi\n", str2[0], str2[1], str2[2], str2[3], str2[4]); //str2[3] str2[4]는 쓰레기 값일 수도 있다.

	//char str3[10] = "Hello, World"; //array size is not enough
	char str3[20] = "Hello, \0World";
	printf("%s\n", str3);
	printf("%c\n", str3[10]);//출력할 땐 널에서 짤리지만 분명히 저장되어 있다.

	return 0;
}