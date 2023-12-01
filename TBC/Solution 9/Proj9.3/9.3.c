/* 중요한 프로젝트는 책꽂이를 해라*/
/* 함수형의 자료형과 반환값 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int int_min(int, int); // 반환자료형을 함수의 자료형이라고 할 수 있다

int main()
{
	int i1, i2;

	while (1)
	{
		printf("Input two integers : ");

		if (scanf("%d %d", &i1, &i2) != 2) break;

		int lesser = int_min(i1, i2);
		// int lesser = min;
		printf("The lesser of %d and %d is %d\n", i1, i2, lesser);

		//printf("The lesser of %d and %d is %d\n", i1, i2, int_min(i1, i2));

	}

	printf("End.\n");

	

	return 0;
}

int int_min(int i, int j)
//int_min(int i, int j) 정수형 반환 자료형은 생략이 가능 역으로 컴파일러가 함수의 반환 자료형이 없을 경우 int로 간주
// 허나 쓰는 걸 권장
{
	//int min; // local variable 지역변수

	//if (i < j)
	//	min = i;
	//else
	//	min = j;

	//return min; // 값을 반환

	return (i < j) ? i : j; // 고수는 이렇게 쓴다고

	// return (float)min; warning float to int? int를 반환하니 내부적으로는 int((float)min)라 그렇다.
	// 구조체 반환값이 여러 개가 가능
	//if (i < j) // if = control path, flow control라고 함 여기서 리턴을 시킨다면 만족시키지 않을 때도 리턴을 해야된다.
	//	return i;
	///*else
	//	return j;*/ // 만약 이걸 주석처리한다면 오류 'int_min' : not all control paths return a value

	printf("who am I?"); // 이건 평생 실행될 일 없음
}