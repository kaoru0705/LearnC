/* 부동소수점의 한계 */
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include<float.h> //FLT_MAX DBL_MAX double
#include<math.h> // asinf
// 이러한 위험성이 존재한다.

int main()
{
	//round-off errors (ex1) 범위가 너무 다른 숫자끼리 연산하면 이렇다. round-off error를 반올림오류라고 번역하는 건 좀 그렇다.
	
	//float a, b;
	//a = 1.0E20f + 1.0f;
	//b = a - 1.0E20f;
	//printf("%f\n", a);
	//printf("%f\n", b);

	
	////round-off errors (ex2)
	
	//float a = 0.0f;
	//for (int i = 0; i < 100; i++)
	//	a += 0.01f;//0.01을 완벽하게 만들 수 없기 때문
	//
	//printf("%f\n", a);

	// overflow
	
	//float max = 3.402823466e+38F;// FLT_MAX go to definition 최대수 찾아서 복사함 double이면 해결되겠지
	//printf("%f\n", max);
	//max = max * 100.0f;
	//printf("%f\n", max);//infinite exponent 128이 쓰인 듯

	//underflow

	//float f = 1.401298464e-45F;//FLT_TRUE_MIN 2^(-126)*2^(-23) subnormal number중에서도 가장 작은 양수 min positive
	//printf("%e\n", f);
	//f = f / 2.0f; // subnormal 숫자가 사라져버리는 걸 이렇게 부름 부동소수점 정밀도로 표현할 수 없는 작은 숫자
	//// 심지어 subnormal로도 표현이 안되는 숫자다. float형으로 표현 불가한 숫자다.
	////f = 1.501298464e-45f; 비정규값이 있으니 그나마 오차를 줄일 수 있었다. 
	//printf("%e\n", f);

	//float f = 104.0f;
	//printf("%f\n", f);
	//f = f / 0.0f;//potential divide by 0 이런 일이 없도록 주의
	//printf("%f\n", f);

	float f = asinf(1.0f); // pi/2
	printf("%f\n", f);

	f = asinf(2.0f);// arcsin 은 -1<=x<=1
	printf("%f\n", f);//-nan(ind) not a number 수학적으로 존재하지 않는 답

	return 0;
}