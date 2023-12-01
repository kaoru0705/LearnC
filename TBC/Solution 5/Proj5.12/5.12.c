/* �Լ��� �μ��� �Ű�����.Arguments vs.Parameters */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void draw(int n); // ANSI function prototype declaration

int main()
{
	int i = 5;
	char c = '#'; // 35
	float f = 7.1f;

	draw(i);	// ���� ���� ���̹Ƿ� values �� arguments
	draw((int)c);	// draw(c)�� promotion������ ������ �̷��� �Ѵ�.
	draw((int)f);	// instead of draw(f); warning C4244 : 'function' : conversion from 'float' to 'int', possible loss of data

	/* Arguments(����, �μ�) vs. Parameters(�Ű�����) */
	// actual argument, actual parameter -> argument (values)
	// formal argument, formal parameter -> parameter (variables)

	return 0;
}

void draw(int n) // int n variables�� �Ķ���� function draw�� �Ű�����ȭ �Ǿ��ִ�.
{
	/* My answers */
	//int i = 0;
	//while (i < n)
	//{
	//	printf("*"); // asterisks
	//	i++;
	//}
	while (n-- > 0)
		printf("*");
	printf("\n");
}