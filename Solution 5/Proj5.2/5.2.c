/* ���� �����ڿ� �� ���� ���� Object, L - value, R - value, �ǿ�����(operand) */
// � �����Ͱ� �޸𸮿� �����ϰ� �ִٸ� data object 
// L-value (object locator value) �޸� �ּҸ� ��Ÿ���� ������ �޸𸮸� �����ϰ� �ִ� Ư�� ������ ��ü(��ü)
// R-value (value of an expression) ���� ������ L-value���� ���Ե� ���� ������ �ڱ� �ڽ��� L-value�� �� �� ���� �͵� ����� ������ �����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	// L-value�� R-value�Ĵ� data object�� �޸𸮿� �ڱ� �ڸ��� �ֳ�
	/*const int TWO = 2; // ���� �Ұ����� L-value  ���⼭ ������ ������ �� =�� ������ �ƴ϶� �ʱ�ȭ

	int a; // ���� ������ L-value
	int b;
	int c;

	a = 42; // 42�� �Ͻ������� ���ܳ� literal constant data object�� �ƴ�
	b = a; // (L-value�� �ӽ������� R-value�� ������ �� �� �ִ�.)
	c = TWO * (a + b);*/ //(a+b)�� R-value(���α׷��� ����ϴ� �ӽ� ��, ������ �����) register�� �ӽ÷� �ִ� �Ŵ�. ����


	return 0;
}