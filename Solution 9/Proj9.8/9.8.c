/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Factorial */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	loop vs recursion ��� ����Լ��� �ݺ������� ������ �� �ִ�.
	0! = 1
	5! = 5 * 4 ! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 5 * 4 * 3 * 2 * 1 * 0!
*/
long loop_factorial(int n);
long recursive_factorial(int n);

int main()
{
	int num = 5;
	
	printf("%d\n", loop_factorial(num));
	printf("%d\n", recursive_factorial(num));


	return 0;
}
/* My answer */
long loop_factorial(int n)
{
	return (n > 1) ? n * loop_factorial(n - 1) : 1; // return �տ��� recursion�ϴ� ���� tail (end) recursion ����Լ��� tail recursion�� ���� ����. ���������Ǹ� ����ϰ� ��������
}

//long recursive_factorial(int n)
//{
//	int result = 1;
//	for (int i = n; i > 1; --i)
//		result *= i;
//
//	return result;
//}

long recursive_factorial(int n)
{
	long ans;

	for (ans = 1; n >= 1; n--) // ������ ����ȭ�� �����̰� ���������ϰ� ���� �� �Ǹ� �׶����� ����ȭ�� Ʈ���� ���ǻ� 1�� ���������� ���� ���ݾ�? �ϸ鼭 ���߿� ����ȭ�ϴ� ����
		ans *= n;

	return ans;
}