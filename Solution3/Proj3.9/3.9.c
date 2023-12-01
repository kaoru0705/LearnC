/* Fixed-width Intengers */
#include <stdio.h>
//#include <stdint.h> // also included in inttypes.h 이미 있는 자료형들의 이름만 바꿔서 사용할 수 있게 해준다.
#include <inttypes.h> //고정너비정수형의 형식지정자를 모르니 사용하는 헤더파일 PRId32
// c언어에서는 자료형의 최소 메모리 크기만 규정한다. 한시스템에서 만든 코드가 다른 시스템에서는 잘 작동하지 않을 수 있으므로 이식성이 높은 변수가 필요하다.
//multiplatform을 할 때는 신경을 쓰자
int main() 
{
	int i;
	//
	int32_t i32;		//32 bit integer로 명확한 정수형 int32 int8 int64 너비를 고정시키는 것처럼 특성과 크기에 따라 명확히 표현한다. 
	int_least8_t i8;	// smallest 8 bit 적어도 8비트를 갖고 있는 type으로 i8선언
	int_fast8_t f8;		// fastest minimum 8bit 중에서 가장 빠른 거
	intmax_t imax;		// biggest signed integers signed integers중에서 메모리를 가장 많이 사용하는 거
	uintmax_t uimax;	// biggest unsigned integers

	i32 = 1004;

	printf("me32 = %d\n", i32);
	printf("me32 = %" "d" "\n", i32);//printf 문자열을 쪼개는 것이 가능함
	printf("me32 = %" PRId32 "\n", i32);// PRI는 print "d" = macro PRId32 scanf도 있음
										//Fixed-width Integers를 출력할 때 형식지정자 format specifier를 모르니 만든 define
	printf("wow" "haha");


	return 0;
}