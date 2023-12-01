/* 중요한 프로젝트는 책꽂이를 해라*/
/* Recursion 재귀호출 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 무한루프를 사용할 때 재귀호출을 사용하면 안 된다.
void my_func(int);
// stack overflow 무한한 메모리가 아니라 출력하다가 비정상적으로 종료된다. 주소는 다 다르다. 변수이름이 아니라 주소가 중요함
//Level 1, address of variable n = 00EFF948 32bit 이상 차이남 스택에 쌓이는 건 프로그램도 같이 쌓인다. my_func자체도
//Level 2, address of variable n = 00EFF870 그림으로 표현할려고 변수만 쌓이는 것처럼 표현한 것 뿐
// stack에 쌓이는 건 생각보다 많다.

int main()
{
	my_func(1);

	return 0;
}

void my_func(int n)
{
	printf("Level %d, address of variable n = %p\n", n, &n);
	
	if (n < 4) //TODO: stop condition // if (n < 4) runtime stack overflow
		my_func(n + 1); // 더해진 상태로 호출하고 다시 돌아옴
	// 재귀호출이 어렵게 느껴지겠지만 수학 알고리즘에서는 편한 경우가 있다.
	// 아주 반복되는 양이 많거나 컴퓨터가 작동되는 효율을 높이고 싶은 경우에는 일반적인 for문으로 바꿀 수 있다.
	// 종단점은 무조건 그 위치에 멈춘다. step out을 한다한들  f5만 종단점에서부터 시작
	// 종단점이 line21에 있으면 거기에 멈춤 이럴 땐 종단점을 지우고 step out을 한다.
	// f5는 debug를 끝내고 결과만 보여주는 게 아니다. 말그대로 continue임ㅋㅋ
	printf("Level %d, address of variable n = %p\n", n, &n);

}