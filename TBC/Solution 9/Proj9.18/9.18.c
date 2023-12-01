/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �������� �Ű����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// pointer�� ���ŷ����� �ڷᱸ�� ��� ���� ���� �� �����ϴ� �� ������ �ȴ�. 
// ��� ������ �Ű����� ����� �ֱٿ� c++ java python �̷� ���鿡���� ���� ������� �ʴ´�. �� ���� ������� �ڵ��Ѵ�.
// �״�� �� ������
// ȿ���� ���� ���α׷��� �ۼ��Ϸ��� ���������� ������, �����Ϳ� �����ϴ� ������ ����ؾ� �ȴ�. �ʺ��� ���ϼ��� ���� ���

/* try 1*/
//void swap(int u, int v)
//{
//	printf("%p %p\n", &u, &v); // �ٸ� ����, �ٸ� ������Ʈ�̹Ƿ� ������ �̷������ �ʴ´�.
//	// ���� ���� ȣ�� call by value
//
//	// swap
//	int temp = u;
//	u = v;
//	v = temp;
//}

/*try 2*/
void swap(int* u, int* v) // call by pointer 
{
	printf("%p %p\n", u, v); // &u &v = pointer��ü�� �ּ� ���������� ��� �� ���
	// swap
	int temp = *u;
	*u = *v;
	*v = temp;
}

int main()
{
	int a = 123;
	int b = 456;

	printf("%p %p\n", &a, &b);

	swap(&a, &b); //swap(a, b) = ���ƿ���

	//swap(a, b); // ���� ���� ���縸 �ƴ�. �쿬�� �̸��� ���� �� �򰥸��� u, v�� �ٲ�

	printf("%d %d\n", a, b);

	
	return 0;
}