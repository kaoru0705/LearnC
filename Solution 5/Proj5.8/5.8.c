/* 증가/감소 연산자 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/* https://en.cppreference.com/w/c/language/operator_precedence */
int main()
{
	int a = 0;
	a++; // a = a + 1 or a += 1(shorthand assignment operator); ++가 존재하는 이유 어셈블러 관점에서 a++ 자연스러움
	 // programming에서 +1은 자주 사용된다. 파이썬에선 없다.
	printf("%d\n", a);

	++a; // a = a + 1 or a += 1;
	printf("%d\n", a);

	/*double b = 0;
	b++; 
	printf("%f\n", b);

	++b;
	printf("%f\n", b);*/

	//int count = 0;
	//while (count < 10) // ++count(전위 연산자) or count++(후위 연산자) while (count++ < 10) toggle f9
	//{
	//	printf("%d ", count++); // ++count or count ++ // 출력하고 나중에 증가하네? 헷갈리지 않나? 이런 용법 기억해라.
	//	// 의외로 자주 씀 헷갈릴 수 있지만 효율성 때문에 사용한다.
	//	// 애초에 c언어는 효율성을 높일려고 사용하기 때문
	//
	//	//count++;
	//}
	//printf("\n");

	/*int i = 1, j = 1;
	int i_post, pre_j;

	i_post = i++;
	pre_j = ++j;

	printf("%d %d\n", i, j);
	printf("%d %d\n", i_post, pre_j);*/

	/*int i = 3;
	int l = 2 * --i; //증감 연산자는 연산자의 우선순위가 매우 높다. 괄호 제외하고 제일 먼저
	printf("%d %d\n", i, l);

	i = 1;
	l = 2 * i--;
	printf("%d %d\n", i, l);*/

	/* very high precedence */
	//int x, y, z;
	//x = 3, y = 4;
	//z = (x + y++) * 5; // (x+y)++ or x+(y++) ?
	//printf("%d %d %d", x, y, z);

	/* ++ and -- affect modifiable L-values 수정가능한 lvalue에만 사용 가능 */ 
	//int x = 1, y = 1, z;
	//z = x * y++; // (x) * (y++), not (x*y)++      (x*y)는 메모리 공간을 갖고 있지 못하고 임시로 값을 가지고 있을 뿐
	//printf("%d %d %d", x, y, z);
	////z = (x * y)++; // error
	////z = 3++; // error

	/* Bad practices */// 프로그래밍 실력이 좋아지면 이런 걸 의외로 많이 쓸 수 있다.
	// 허나 남발하지 마라. 너무 복잡하게 쓰면 좋지 않다. 이럴 수도 있고 저럴 수도 있는 경우엔 절대 쓰면 안 됨
	int n = 1;
	printf("%d %d\n", n, n * n++); // 예로 들어 함수 호출할 때 인자로서 들어갈 때 n이 여러 번 사용할 때 system마다 결과가 다르게 나올 수 있다.
	int x = n / 3 + 5 * (1 + n++); //system상 다른 값이 나올 수 있다. 이런 경우엔 쪼개서 써라. 의도를 명확히 해라.
	int y = n++ + n++; // 헷갈리고 의도가 뭔지 모르겠다.
	printf("%d %d", x, y);

	return 0;
}