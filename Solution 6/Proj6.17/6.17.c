/* for loop를 배열과 함께 사용하기 */
// 하드웨어 병렬처리를 언젠가 배우도록 하자.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 5

int main()
{
	/* Motivation */
	//int i1 = 0;
	//int i2 = 1;
	//int i3 = 2;
	//// ...

	//printf("%d\n", i1);
	//printf("%d\n", i2);
	//printf("%d\n", i3);
	//// ...


	/* prepare for array data */

	int my_arr[SIZE];
	for (int i = 0; i < SIZE; ++i)	//debug watch로 변수를 입력해서 값을 확인할 수도 있다.
									//배열이 너무 많을 때 전부 확인하기 힘드니 사용
	{
		my_arr[i] = i * i;
		// 1 + 2; // dummy debug할 때 이부분에 걸리게 해서 할당되는 걸 명확하게 확인하기 위해 쓴다.
		// 근데 이건 1 + 2; 는 R-value 연산이라 (즉 디버깅으로 볼 수 없는 임시메모리라) 안 걸리는 듯 합니다.
		// 참고로 말씀드리자면, 저는 개인적으로 디버깅시 더미로 넣을 때 이를테면 printf(""); 이런 출력함수를 대충 넣는 편입니다.
	}
	// printf array data
	for (int i = 0; i < SIZE; ++i)
		printf("%d ", my_arr[i]);	// 위 for문이랑 묶어서 한번에 하는 게 낫지 않나요? 그래도 된다.
	// 허나 size가 늘어나면 힘들 수도 있다. 비효율적으로 보일 수 있지만... c++ 하드웨어 가속 병렬처리 이런 걸 배우면 직관적인 상식과 다른 프로그래밍 기법들을 배우게 된다.

	//TODO: try debugger

	/* my answer */
	/*int your_number[SIZE];
	int sum = 0;

	printf("Enter 5 numbers : ");
	for (int i = 0; i < SIZE; ++i)
	{
		scanf("%d", &your_number[i]);
		sum += your_number[i];
	}

	printf("Sum = %d\n", sum);*/

	int number[SIZE];
	int sum = 0;
	int i;

	printf("Enter %d numbers : ", SIZE);

	for (i = 0; i < SIZE; ++i)		//for를 쪼개서 쓰는 게 낫다
		scanf("%d", &number[i]);

	for (i = 0; i < SIZE; ++i)
		sum += number[i];

	printf("Sum = %d\n", sum);
	printf("Average = %d\n", sum / SIZE);

	return 0;
}