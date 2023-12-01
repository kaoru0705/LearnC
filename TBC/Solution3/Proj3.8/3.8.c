/* 8진수와 16진수 */
#include <stdio.h>

int main() 
{
	unsigned int decimal = 4294967295;
	unsigned int binary = 0b11111111111111111111111111111111;
	unsigned int oct = 037777777777;//0 8진수
	unsigned int hex = 0xffffffff;//0x 16진수 16진수로 적으면 꽤 많이 줄어든다. .google에 숫자 to hex라 입력하면 알아서 바꿔준다.

	printf("%u\n", decimal);
	printf("%u\n", binary);
	printf("%u\n", oct);
	printf("%u\n", hex);

	printf("%o %x %#o %#x %#X", decimal, decimal, decimal, decimal, decimal);//#기호를 붙이면 진수표현이 됨 x를 대문자로 하면 대문자로 출력됨

	return 0;
}