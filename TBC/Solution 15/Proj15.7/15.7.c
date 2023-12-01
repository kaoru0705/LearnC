/* ��Ʈ���� �������� �پ��� ���� */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <math.h>

// MASK �츮�� ����ũ�� ���� ������ �ո� ������ �κи� ����
// c������ binary number�� ���� �ڵ� �� �� c++�� ����
// c���� ^ ������ ����. �׷��� Decimal�� MASK�� �����ϴ� ��ĵ� �� ��
// ��������� c���� MASK�� ������ �� shift�� 16������ ���� ���� �ȴ�. 8������ ���� �� ��
//					 Shift		 Decimal	Binary	  Hex	Octet
#define MASK_SWORD	 (1 << 0) // 2^0		00000001  0x01  01
#define MASK_SHIELD  (1 << 1) // 2^1		00000010  0x02  02
#define MASK_POTION	 (1 << 2) // 2^2		00000100  0x04  04
#define MASK_GUNTLET (1 << 3) // 2^3		00001000  0x08  010
#define MASK_HAMMER  (1 << 4) // 2^4		00010000  0x10  020
#define MASK_KEY	 (1 << 5) // 2^5		00100000  0x20  040
#define MASK_RING	 (1 << 6) // 2^6		01000000  0x40  0100
#define MASK_AMULET	 (1 << 7) // 2^7		10000000  0x80  0200

void char_binary(const char num);
void int_binary(const int num);

/*
	flag			01011010 mask �� ����ϰڴٴ� ���� ���� ���� �͸� ���ڴ�.
	mask			00000011 ����ŷ�� �Ǿ��ִ� �κи� ���ڴ�.
	mask & flag ==	00000010
*/

int main(void)
{
	/*
	bool has_sword = false;		1bit�� ǥ���� ������ �ϳ��ϳ� 1����Ʈ�� ���� ���� �Ʊ���.
	bool has_shield = false;
	bool has_potion = false;
	bool has_guntlet = false;
	bool has_hammer = false;
	bool has_key = false;
	bool has_ring = false;
	bool has_amulet = false;
	*/

	char flags = 0;		// MASK flags �������� ����
	char_binary(flags);

	printf("\nTurning Bits On (Setting Bits)\n");

	flags = flags | MASK_SWORD;//flag |= MASK_SWORD; ���� �����!
	char_binary(flags);
	flags |= MASK_AMULET; // ����̸� �����!
	char_binary(flags);

	printf("\nTurning Bits On (Clearning Bits)\n");

	flags = flags | MASK_POTION;
	char_binary(flags);		// ���� ����ְ�
	flags = flags & ~MASK_POTION;// flags &= ~MASK_POTION; ������ �Ծ���
	char_binary(flags);

	printf("\nToggling Bits\n"); // �����ߴ� ����

	flags = flags ^ MASK_HAMMER;
	char_binary(flags);

	flags = flags ^ MASK_HAMMER;
	char_binary(flags);

	flags = flags ^ MASK_HAMMER;
	char_binary(flags);

	printf("\nChecking the Value of a Bit\n");

	if ((flags & MASK_KEY) == MASK_KEY)	// key�ִ��� Ȯ���� �� ��
		printf(">> You can enter.\n");
	else
		printf(">> You can not enter.\n");

	flags |= MASK_KEY;// Obtained a key!

	if ((flags & MASK_KEY) == MASK_KEY)
		printf(">> You can enter.\n");
	else
		printf(">> You can not enter.\n");

	printf("\nTrimming\n");

	int int_flag = 0xffffffff;
	// 11111111 11111111 11111111 11111111
	int_binary(int_flag);
	int_flag &= 0xff;	// �̺κи� ���� �ʹ�.
	// Trim by 11111111
	int_binary(int_flag);

	return 0;
}

void char_binary(const char num)
{
	printf("Decimal %3d \t== Binary ", num);

	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; ++i)
	{
		const char mask = 1 << (bits - 1 - i);

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}

	printf("\n");
}

void int_binary(const int num)
{
	printf("Decimal %12d \t== Binary ", num);

	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; ++i)
	{
		const int mask = 1 << (bits - 1 - i);

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}

	printf("\n");
}