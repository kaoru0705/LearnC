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
����ĺм���
recur2(n)�� ȣ���� �� n-2�� ȣ���Ѵ�. n-2�� n>0�̶�� ��� n-2-2-2-2...�� ȣ���Ѵ�. n<=0�� �� ��쿡 ��ȯ�ϰ� printf�� ������ �� �ִ�. �״��� n-1-1-1-1-1.�� ȣ���Ѵ�.
��ư �̷� ��
����ĺм���
n<=0�̸� ���̻� ���ȣ���� ���� ������ �װ��� recur2(-1) recur2(0)���� �����ȴ�. ������ ����
recur(1)�̸� 1
recur(2)�̸� 21
recur(3)�̸� 1321
recur(4)�̸� 2141321









*/