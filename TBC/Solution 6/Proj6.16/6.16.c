/* Array & Runtime error */
// �ݺ����� �迭�� ���� ���Ǵ� ��찡 ����.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define NUM_DAYS 365

int main()
{
	/*char my_chars[] = "Hello, world!"; // 14bytes

	int daily_temperature[NUM_DAYS];
	double stock_prices_history[NUM_DAYS];

	printf("%zd\n", sizeof(stock_prices_history));
	printf("%zd\n", sizeof(double) * NUM_DAYS);
	printf("%zd\n", sizeof(stock_prices_history[0]));*/

	int my_numbers[5];

	my_numbers[0] = 1;		// []�� ǥ�� subscripts, indices=(index)�� ������, offsets(ù �޸� �ּҷκ��� �󸶳� ������ �ֳ�)
	my_numbers[1] = 3;		// my_numbers ���ӵǴ� �޸𸮰����� ù ��° �ּҸ� �ǹ�
	my_numbers[2] = 4;
	my_numbers[3] = 2;
	my_numbers[4] = 1024;

	//// = scanf("%d", my_numbers); �迭�� ��� ��ü�� �ּ�
	//scanf("%d", &my_numbers[0]);	// [] > &
	printf("%d\n", my_numbers[0]);
	printf("%d\n", my_numbers[1]);
	printf("%d\n", my_numbers[2]);
	printf("%d\n", my_numbers[3]);
	printf("%d\n", my_numbers[4]);

	/* Runtime Error */ // ����� �� ���� ����ǥ�ô� MSVC���� ����ִ� ����
	//my_numbers[5] = 123;	// out of bound compile���� �� ����ش�. OS�κ��� ���ڴٰ� �Ҵ�޾� ������ �� 5ĭ�ε�
	//// debugger�� ã���ֱ⵵ �Ѵ�.
	////compile time, runtime �� �� üũ�ϸ鼭 ������ �Ѵ�.

	//my_numbers = 7;	// compile error

	//printf("%d\n", my_numbers[5]);	// out of bound

	return 0;
}