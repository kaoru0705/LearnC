/* Array & Runtime error */
// 반복문은 배열과 많이 사용되는 경우가 많다.
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

	my_numbers[0] = 1;		// []안 표현 subscripts, indices=(index)의 복수형, offsets(첫 메모리 주소로부터 얼마나 떨어져 있나)
	my_numbers[1] = 3;		// my_numbers 연속되는 메모리공간의 첫 번째 주소를 의미
	my_numbers[2] = 4;
	my_numbers[3] = 2;
	my_numbers[4] = 1024;

	//// = scanf("%d", my_numbers); 배열일 경우 자체가 주소
	//scanf("%d", &my_numbers[0]);	// [] > &
	printf("%d\n", my_numbers[0]);
	printf("%d\n", my_numbers[1]);
	printf("%d\n", my_numbers[2]);
	printf("%d\n", my_numbers[3]);
	printf("%d\n", my_numbers[4]);

	/* Runtime Error */ // 실행될 때 오류 물결표시는 MSVC에서 잡아주는 거임
	//my_numbers[5] = 123;	// out of bound compile에서 안 잡아준다. OS로부터 쓰겠다고 할당받아 가져온 게 5칸인데
	//// debugger가 찾아주기도 한다.
	////compile time, runtime 둘 다 체크하면서 만들어야 한다.

	//my_numbers = 7;	// compile error

	//printf("%d\n", my_numbers[5]);	// out of bound

	return 0;
}