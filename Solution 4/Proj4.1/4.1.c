/* 문자열 입력하기 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char fruit_name[40]; //char fruit_name; stores only one character.
	printf("What is your favorate fruit?\n");

	scanf("%s", fruit_name); // scanf("%c", &fruit_name); // be careful with & 배열에서
	//fruit_name은 40개의 메모리 공간을 대표하는 첫 번째 주소기 때문 &는 없다.
	
	
	printf("You like %s!\n", fruit_name);// printf("You like % c!\n", fruit_name);
	//%s %c formatt specialfier=conversion specialfier in c c++에서는 conversion specifier를 더 많이 씀

	return 0;
}