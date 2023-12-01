/* 비트필드의 패딩 Padding */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <limits.h> // CHAR_BIT
#include <stdbool.h>
#include <string.h>	

void char_to_binary(unsigned char uc)
{
	const int bits = CHAR_BIT * sizeof(unsigned char);
	for (int i = bits - 1; i >= 0; i--)
		printf("%d", (uc >> i) & 1);
}

void print_binary(char* data, int bytes)//Note: extended for any sizes
{
	for (int i = 0; i < bytes; ++i)
		char_to_binary(data[bytes - 1 - i]); // char_to_binary(data[0]);  arguemnt 엔 1바이트의 값
	printf("\n");
}

int main(void)
{
	struct {
		bool option1 : 1;
		//bool : 0; // 강제로 메모리를 더 달라 패딩이 많이 들어가도 상관없으니까 메모리를 더 달라 
		bool option2 : 1;
		unsigned long long option3 : 1;
	} bbf;

	printf("%zu bytes\n", sizeof(bbf)); // 16 bytes 메모리 안에서 unsigned longlong이 강제로 짤리지 않게 하기 위해서 bool 2개를 8바이트로 패딩


	memset((char*)&bbf, 0xff, sizeof(bbf));		// 1로 초기화
	print_binary((char*)&bbf, sizeof(bbf));
	bbf.option1 = 0;	// padding 부분 빼고 0으로 바뀐다. 결국 1비트만 바꿈 padding 때문에 16 바이트인 거다.
	bbf.option2 = 0;
	bbf.option3 = 0;	// bbf.option3 = 2; ?? 결국 1비트라 2를 넣으면 넘어서 0이됨
	print_binary((char*)&bbf, sizeof(bbf));

	printf("%zu bytes\n", sizeof(bbf));

	struct {
		unsigned short option1 : 1;
		unsigned short option2 : 1;
		//unsigned short : 0;
		unsigned short option3 : 1;
	} usbf;

	printf("%zu bytes\n", sizeof(usbf)); // 2 bytes unsigned short의 최소 바이트는 맞춘다.

	struct {
		unsigned int option1 : 1; // unsigned int 는 1비트를 unsigned int는 해석하라는 뜻과 비트필드의 크기를 결정할 때 작용한다.
		//unsigned int : 0; // 이것을 추가하면 자료형 만큼 늘어난다.
		unsigned int option2 : 1;
		//bool option3 : 1;
	} uibf;

	printf("%zu bytes\n", sizeof(uibf)); // 4 bytes unsigned int unsigned int : 0; 추가시 8 bytes

	return 0;
}