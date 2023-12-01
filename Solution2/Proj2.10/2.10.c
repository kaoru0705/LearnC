/* 디버거 사용법 */
#include <stdio.h>

void say_hello(void);// f12 go to definition

int main()
{
	int x, y, z; //쓰레기값 OS는 알 수 있지만 우리는 알 수 없는 값들 선언과 동시에 초기화 해주는 게 좋다.
	// step into(함수였다면 안으로 들어가고 아니면 한 줄 지나감)많이 씀 f11
	// step over(함수를 지나감) f10
	// step out shift f11
	x = 1; //f9 toggle
	y = 20;
	z = 3;

	z = x + y; // 현재 변수들이 어떤 값을 갖고 있나 state 내가 만든 프로그램의 상태
	// 디버거가 우리의 프로그램의 상태를 보여주고 있다.
	
	say_hello();//go to definition f12

	return 0;

}
void say_hello(void) 
{
	int x = 1;
	x = 10;

	printf("Hello World!\n");//f11을 해도 표준함수라 건너뜀 shift f5 stop debugging

	return;
}
