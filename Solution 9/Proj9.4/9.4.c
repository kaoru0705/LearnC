/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ������ ����(Scope)�� ���� ����(Local Variable) */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// int a; // file���� ���� file��ü���� ���� ���� �������� �ʳ�����.

int int_max(int i, int j);


int int_max(int i, int j)
{
	//a = 456;
	int m; // m�� block ���� ������ �����. ���������� �̷��� ���� ���ư��� ������ stack frame�̶� ������ �˾ƾ� ��
	return m = i > j ? i : j;
}

int main()
{
	//m = 123; error

	int a; // ���������� ������ ��ĥ ��� ���ʿ� �ִ� ������ ������ �ٲ��.
	// ������ �޸� ������ �ǹ��ϴ� ��Ī, �޸� �ּ���ü�� ���� �ٷ�� �� ��Ʊ� ������
	// ����� ������ �� �ִ� �ν��ڷμ� ��ǻ�� �޸� ���� ������ �����ؼ� ����� �� �ְ� ����
	// �㳪 ������ ���� �����ϴ� ���� �޸� �����̰� �޸𸮴� �ᱹ �ּҸ� ���ؼ� ����
	a = int_max(1, 2);

	printf("%d\n", a);
	printf("%p\n", &a); //ampersand �ּ� operater

	{
		// //int a;�� ��� �� �� ���� ���
		int a; // ū �������� ���� ������ ����� ������ ����� �ٸ� ������ ���´�. 
		// ������ ���� �� �� ���� ������ �� �� �ֵ��� �ϱ� ����
		// ��� ������ ������ �̸��� ��ġ�� �ʰ� ����� ���� �����. 
		a = int_max(4, 5);

		printf("%d\n", a);
		printf("%p\n", &a);

		int b = 123;
	}

	//b = 456; error

	printf("%d\n", a);
	printf("%p\n", &a);

	return 0;
}
