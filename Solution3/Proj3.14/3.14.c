/* Complex Types 복소수형 */
#include <stdio.h>
#include <complex.h>
int main() 
{
	_Dcomplex z; // double type fcomplex dcomplex lcomplex 세 개가 있음
	z._Val[0] = 1.0;
	z._Val[1] = 1.0;
	//수학자들은 복소수를 직접 만드는 경우가 많음 visual studio는 꼼꼼하지 않음
	// GCC는 조금 더 지원을 잘해줌 허나 imaginary number가 구현이 안되있음
	
	return 0;
}