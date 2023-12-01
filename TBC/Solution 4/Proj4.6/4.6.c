//Manifest Constants 명백한 상수들 define으로 선언된 기호적 상수를 Manifest Constants라고도 부름 요즘에 많이 쓰이진 않음
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h> // INT_MAX, ... , etc. // 대표적인 manifest 상수들
#include <float.h> // FLT_MAX, ... , etc.

#define PI 3.141592 // manifest constants, symbolic constants
// macro는 상수를 선언하기보다는 여러 번 사용하는 기능을 함수로 반복사용도 가능 후에 나옴

int main()
{
	printf("PI is %f\n", PI);
	printf("Biggest int: %d\n", INT_MAX);
	printf("One byte in this system is %d bits\n", CHAR_BIT);
	printf("Smallest normal float %e\n", FLT_MIN);


	return 0;
}