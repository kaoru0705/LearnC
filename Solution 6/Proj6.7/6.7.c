/* ���� �������� �켱���� */
/* https://www.tutorialspoint.com/cprogramming/c_operators.htm */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// relational > equality
// conditional ?: �켱������ ����.
//Priority�� �ָ��ϴ� ������ ã�� ���� �ƴϸ� ��ȣ�� �Ķ�
int main()
{
	//int x = 1, y = 2, z;

	//x > y + 2;
	//x > (y + 2);	// ��ǻ� �̷��� ��

	//x = y > 2;
	//x = (y > 2);

	//z = x > y;
	//z = (x > y);

	//x != y == z;
	//(x != y) == z;

	int i = 5;
	printf("%d\n", 0 ? 6 : i ? i : 7);	// associativity(���� ��Ģ) right to left ������ �ͺ��� ���չ�Ģ �Ѵٴ� ��
	// practically 0 ? 6 : (i ? i : 7)
	// x = y = z = 6; Associativity right to left

	return 0;
}