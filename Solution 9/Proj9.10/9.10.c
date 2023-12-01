/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �Ǻ���ġ(Fibonaccci) ������ ��� ȣ���� ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	Fibonacci sequence
	1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89. 144

	ex ) fibonacci(5) = 3 + 2 = fibonacci(4) + fibonacci(3)
*/

int fibonacci(int number);

int main()
{
	for (int count = 1; count < 13; ++count)
		printf("%d ", fibonacci(count));

	return 0;
}

int fibonacci(int number)
{

	return (number < 3) ? 1 : fibonacci(number - 1) + fibonacci(number - 2);
	// double recursion ��ǻ�Ͱ� �����ų ���� ���ÿ� ��Ű���� �ʴ´�. debuger�� ������
	// ���� ���������� ���ǵ� ��쿡�� ������ ����������.
	// ����:	1. �޸𸮸� ���� ����. ���ȣ���� �� ������ �Ķ���Ͱ� ���ÿ� ���δ�. �翬�� ���� ���ϼ��� �޸𸮸� ���� ���
	//			stack frame���� ������ ���̴� ���� �ƴϰ� ������ ����ϱ� ���� ���α׷� �Լ��� ���� ���δ�.
	//			overhead : ������ ����ϴ� �ͺ��� �� �߰��ż� ����ϴ� ���� ������
	//		2. ��꿡 �ߺ��� �����. redundant computation printf("fibonacci with %d\n", number);
}	//			������ ���������� �������� �밡�ν� �޸𸮵� ���� ����.

//Note: memory (in)efficiency, redundant computation