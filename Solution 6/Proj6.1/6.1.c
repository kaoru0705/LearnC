// while 반복 루프에서 scanf() 반환값 사용하기
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num, sum = 0;
	char ch;

	// nothing instead of int status;
	/* My poor answer */
	//// 반복이 멈추질 않아! conversion specifier를 data type과 맞춰야 한다.
	// printf("%d", 'A');는 되지만 scanf("%d", &num); num에 문자 입력은 안된다.
	//printf("Enter an integer (q to quit) : ");
	//scanf("%d", &i);
	//while (i != (int)'q')
	//{
	//	printf("Enter next integer (q to quit) : ");
	//	scanf("%d", &i);
	//	sum += i;
	//}
	//sum -= (int)'q';
	//printf("Sum = %d", sum);
	printf("Enter an integer (q to quit) : ");
	// nothing instead of status = scanf("%d", &num);
	while(scanf("%d", &num) == 1) // instead of while (status == 1) // '==' equality operator 관계 연산자
	{
		sum += num;
		printf("Enter next integer (q to quit) : ");
		// nothing instead of status = scanf("%d", &num);
	}
	// scanf를 두 번 입력해야 되다니, 입력받을 변수를 늘리면 두 부분 다 고쳐야 되잖아. 실수할 확률이 늘어남
	// 가급적 간결하고 반복되는 부분이 두 군데 이상 있으면 안된다.
	// while(scanf("%d", &num) == 1) 고치니까 편안하지만 while 조건문에서 비교만이 아니라 함수호출까지 하고 있다.이러면 복잡하게 보일 수 있다.
	// 다른 반복문을 쓰는 게 낫지 않을까?
	printf("Sum : %d\n", sum);

	//q가 버퍼에 남은 상태
	scanf("%c", &ch);
	printf("%c", ch);

	return 0;
}