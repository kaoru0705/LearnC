/* 변수를 선언하는 방법 */
#include <stdio.h>
int main() 
{
	int x = 1, y = 2; //y = 2, z = x + y; 연산하는 내용이 있으므로 분리하는 게 좋다.
	//declaration 메모리 공간을 확보했고 x라는 변수를 통해서 접근할 수 있다.
	// 빈칸 대신 underscore int tax_rate;
	//초보때는 맨앞에 underscore를 안 쓰는 게 좋다. 표준 라이브러리에서 앞에 underscore를 사용하는 변수가 미리 선언되는 경우가 있다.
	int z = x + y; //z is seperate cuz it has operator

	return 0;
}