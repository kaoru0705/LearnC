/* Boolean Types */
#include <stdio.h>
#include <stdbool.h>

int main() 
{
	printf("%u\n", sizeof(_Bool)); // 1 byte 자료형이 가질 수 있는 가장 작은 사이즈가 바이트라 1 byte
	// 왜냐하면 바이트가 주소를 배정받을 수 있는 최소단위
	// 그럼, 나머지 7bit는 낭비 아니냐? 비트연산자에서 나옴 나머지 7비트
	
	_Bool b1;
	b1 = 0; //false
	b1 = 1; //true;

	printf("%d\n", b1); // 별다른 format specifier가 없음 %d쓴다.

	bool b2, b3;//stdbool.h 추가 시 선언 가능
	b2 = true;
	b3 = false; //예약어 문자처럼 쓸 수 있다.
	//엄밀히 따지면 컴퓨터는 true냐 false냐가 아니라 false가 아니면 true다. 이런식으로 판단함
	printf("%d %d\n", b2, b3);


	return 0;
}