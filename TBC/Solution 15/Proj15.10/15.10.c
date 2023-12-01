/* 비트필드의 사용방법 */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <limits.h> // CHAR_BIT
#include <stdbool.h>

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
	struct items {
		bool has_sword : 1;		// : number means bits to use!
		bool has_shield : 1;
		bool has_potion : 1;
		bool has_guntlet : 1;
		bool has_hammer : 1;
		bool has_key : 1;
		bool has_ring : 1;
		bool has_amulet : 1; // bool말고도 정수형도 가능 실수형은 안 된다. bool은 1byte지만 1비트짜리 has_amulet을 bool처럼 해석해라
	} items_flag;

	items_flag.has_sword = true;	// flags = flags | MASK_SWORD; true도 가능 11010000인지 00001011인지는 컴파일러에 따라 다르다.
	items_flag.has_shield = 1;
	items_flag.has_potion = 0;
	items_flag.has_guntlet = 1;
	items_flag.has_hammer = 0;
	items_flag.has_key = 0;
	items_flag.has_ring = 0;
	items_flag.has_amulet = 0;

	printf("Size = %zd\n", sizeof(items_flag));

	print_binary((char*)&items_flag, sizeof(items_flag));

	if (items_flag.has_key == 1)	// if ((flags & MASK_KEY) == MASK_KEY)
		printf(">> You can enter.\n");

	union {
		struct items bf;
		unsigned char uc;
	} uni_flag;

	uni_flag.uc = 0;
	uni_flag.bf.has_amulet = true;
	uni_flag.uc |= (1 << 5);

	print_binary((char*)& uni_flag, sizeof(uni_flag));
	uni_flag.bf.has_key = false;
	print_binary((char*)&uni_flag, sizeof(uni_flag));

	/*
		KNK DOS example
	*/

	struct file_time {
		unsigned int seconds : 5;	// 2^5 = 32, (0 ~ 29) 30*2 seconds
		unsigned int minutes : 6;	// 2^6 = 64, (0 ~ 59) 60 minutes
		unsigned int hours	 : 5;	// 2^5 = 32, (0 ~ 23) 24 hours
	};

	struct file_date {
		unsigned int day	: 5;	// 2^5 = 32, 1 ~ 31 // day를 컴파일러한테 unsigned int인 것처럼 해석해달라 그런데 실제로 사용하는 메모리는 5비트다.
		unsigned int month	: 4;	// 2^4 = 16, 1 ~ 12
		unsigned int year	: 7;	// 2^7 = 128, 1980 ~ 1980년 마이크로소프트의 중요한 해
	} fd;

	/* 1988 12 28*/
	fd.day = 32;			// try overflow. ex)32 try 'signed int'
	fd.month = 18;
	fd.year = 8;

	printf("Day %u, Month %u, Year %u\n", fd.day, fd.month, fd.year);
	//scanf("%d", &fd.day); /* WRONG */ // error C2104: '&' on bit field ignored 비트필드는 비트 단위로 메모리를 사용하기 때문에 scanf처럼 주소의 최소단위인 1바이트로 넘겨주기가 곤란하다. 컴파일 할 수 없게 막아놨군

	return 0;
}