/* 중요한 프로젝트는 책꽂이를 해라*/
/* How to avoid goto statements */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// cpu가 일을 할 때는 goto문처럼 한다. 근데 사람이 프로그래밍할 때는 꼭 cpu가 일을 하는 데 맞춰서 할 필요는 없다.
int main()
{
	/* if else */
	int size = 15, cost;
//
//	if (size < 10)
//		goto a;
//	goto b;
//
//a: cost = 50 * size; // 이거 a로 가도 다시 b로 덮여 씌워짐
//b: cost = 100 * size;

	/*if (size < 10)
		cost = 50 * size;
	else
		cost = 100 * size;*/

	/* loop */
	char c;

//read: c = getchar();
//	putchar(c);
//	if (c == '.') goto quit;
//	goto read;
//quit:
	
while (1)
{
	c = getchar();
	putchar(c);
	if (c == '.') break;
}

	return 0;
}