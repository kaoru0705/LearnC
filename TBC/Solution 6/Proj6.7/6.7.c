/* 관계 연산자의 우선순위 */
/* https://www.tutorialspoint.com/cprogramming/c_operators.htm */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// relational > equality
// conditional ?: 우선순위가 낮다.
//Priority가 애매하다 싶으면 찾아 봐라 아니면 괄호를 쳐라
int main()
{
	//int x = 1, y = 2, z;

	//x > y + 2;
	//x > (y + 2);	// 사실상 이렇게 됨

	//x = y > 2;
	//x = (y > 2);

	//z = x > y;
	//z = (x > y);

	//x != y == z;
	//(x != y) == z;

	int i = 5;
	printf("%d\n", 0 ? 6 : i ? i : 7);	// associativity(결합 법칙) right to left 오른쪽 것부터 결합법칙 한다는 뜻
	// practically 0 ? 6 : (i ? i : 7)
	// x = y = z = 6; Associativity right to left

	return 0;
}