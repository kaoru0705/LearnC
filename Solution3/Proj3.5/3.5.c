/* 정수와 실수 */
#include <stdio.h>

int main() 
{
	//2와 2.0이 메모리에 저장될 때 구분하게 되어있음
	//부동소수점 floating point, point가 왔다갔다 하기 때문
	//3.14 = 3.14E0 = 3.14e0 = 0.314E1 = 31.4E-1 Exponent
	//32bit Single Precision 아니 왜 float이 아니고 single임? 왜?그냥 64bit Double(float의 두 배) Precision
	// float double 은 당연히 floating point연산 때문에 더 느리다. float보다 double이 더 느릴 거고
	//나중에 복잡한 프로그램을 만들 때 double 남용은 위험할지도 모른다.
	float i = 0.1234567f;
	printf("%f", i);

	return 0;
}