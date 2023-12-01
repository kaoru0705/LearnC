//printf()함수가 arguments(인자)를 해석하는 과정
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// printf 인자(argument)가 스택이라는 다른 메모리공간으로 복사가 된다. float인자는 double 로 변환
// conversion specifier는 해석(interpret)하는 기능에 가까움. 출력을 어떻게 할지 해석하는 과정에서 8byte짜리를 4byte만큼 해석해서 망함
int main()
{
	float	n1 = 1.5f;	// 4 bytes
	double	n2 = 1.5;	// 8 bytes
	int		n3 = 1024;	// 4 bytes

	printf("%f %f %d\n\n", n1, n2, n3); //printf가 사용하기 위해서 인자들이 일렬로 나열되는 구조로 어딘가에 복사된다.

	//Note the warnings in output window	
	printf("%d %d %d\n\n", 1.5f, 1.5, n3);		// 4, 4, 4 (N, N, N) 스택에서 8바이트를 4바이트만 읽으니 씹창 난다.
	printf("%lld %lld %d\n\n", n1, n2, n3);	// 8, 8, 4 (N, N, Y)
	// 맞는데 부동소수점 방식으로 저장된 데이터를 강제로 integer로 변환해서 해석하려 하니 이상한 숫자가 나옴 type이 안 맞아서
	// 1.5 float -> double 0 011 1111 1111 1영51개 = 4609434218613702656 -> float이 float에다 4바이트 0이 붙은 거면? 1.5가 애초에 안나오겠죠?
	// float형으로 집어 넣어도 내부적으로는 double로 형변환
	printf("%f %d %d\n\n", n1, n2, n3);		// 8, 4, 4 (Y, N, N)
	printf("%f %lld %d\n\n", n1, n2, n3);	// 8, 8, 4 (Y, N, Y)  type이 안 맞아서

	return 0;
}