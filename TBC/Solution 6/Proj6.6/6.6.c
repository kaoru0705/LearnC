/* _Bool 자료형 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>

int main()
{
	int i;
	//i = 5;
	//i == 5;
	//5 = i;	// literal constant라 memory공간은 갖고 있지 못함
	//5 == i;	// 같냐고 비교하는 거기 때문에 문법오류가 안 나옴
	
	//while (i = 5) {/*do something*/ };		// 5를 대입하고 5니까 true로 간주
	//while (i == 5) {/* do something*/ };

	//_Bool boolean_true = (2 > 1); // 결국 정수형 처리 in c, c++에서도 물론 내부적으론 정수형 처리지만 bool이란 데이터타입이 따로 있음
	//_Bool boolean_false = (1 > 2); // 대부분의 사람들이 이미 bool type을 만들어서 사용하고 있기 때문에 _Bool라고 지어짐
	//
	//printf("True is %d\n", boolean_true); // boolean을 위한 format specifier가 없음
	//printf("False is %d\n", boolean_false);

	//printf(boolean_true ? "true" : "false"); // continual operator 우선순위가 낮다.
	//printf("\n");
	//printf(boolean_false ? "true" : "false");		//	bool자료형처럼 만들고 싶다. 안 써 stdbool.h 쓸 거임

	bool bt = true; //c++과 달리 keyword가 아니다 define임 keyword는 파란 색
	bool bf = false;
	
	printf("\n");
	printf("True is %d\n", bt);
	printf("False is %d\n", bf);

	return 0;
}