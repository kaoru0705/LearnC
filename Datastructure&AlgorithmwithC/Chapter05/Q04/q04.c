#include <stdio.h>
/* top-down analysis vs bottom-up analysis*/
void recur2(int n)
{
	if (n > 0)
	{
		recur2(n - 2);
		printf("%d\n", n);
		recur2(n - 1);
	}
}
int main()
{
	recur2(5);
	return 0;
}
/*
하향식분석은
recur2(n)를 호출할 때 n-2를 호출한다. n-2가 n>0이라면 계속 n-2-2-2-2...을 호출한다. n<=0이 된 경우에 반환하고 printf를 수행할 수 있다. 그다음 n-1-1-1-1-1.을 호출한다.
암튼 이런 식
상향식분석은
n<=0이면 더이상 재귀호출을 하지 않으며 그것은 recur2(-1) recur2(0)에서 정리된다. 어차피 ㅇㅇ
recur(1)이면 1
recur(2)이면 21
recur(3)이면 1321
recur(4)이면 2141321









*/