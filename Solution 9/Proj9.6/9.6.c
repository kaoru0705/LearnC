/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Recursion ���ȣ�� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// ���ѷ����� ����� �� ���ȣ���� ����ϸ� �� �ȴ�.
void my_func(int);
// stack overflow ������ �޸𸮰� �ƴ϶� ����ϴٰ� ������������ ����ȴ�. �ּҴ� �� �ٸ���. �����̸��� �ƴ϶� �ּҰ� �߿���
//Level 1, address of variable n = 00EFF948 32bit �̻� ���̳� ���ÿ� ���̴� �� ���α׷��� ���� ���δ�. my_func��ü��
//Level 2, address of variable n = 00EFF870 �׸����� ǥ���ҷ��� ������ ���̴� ��ó�� ǥ���� �� ��
// stack�� ���̴� �� �������� ����.

int main()
{
	my_func(1);

	return 0;
}

void my_func(int n)
{
	printf("Level %d, address of variable n = %p\n", n, &n);
	
	if (n < 4) //TODO: stop condition // if (n < 4) runtime stack overflow
		my_func(n + 1); // ������ ���·� ȣ���ϰ� �ٽ� ���ƿ�
	// ���ȣ���� ��ư� ������������ ���� �˰��򿡼��� ���� ��찡 �ִ�.
	// ���� �ݺ��Ǵ� ���� ���ų� ��ǻ�Ͱ� �۵��Ǵ� ȿ���� ���̰� ���� ��쿡�� �Ϲ����� for������ �ٲ� �� �ִ�.
	// �������� ������ �� ��ġ�� �����. step out�� �Ѵ��ѵ�  f5�� �������������� ����
	// �������� line21�� ������ �ű⿡ ���� �̷� �� �������� ����� step out�� �Ѵ�.
	// f5�� debug�� ������ ����� �����ִ� �� �ƴϴ�. ���״�� continue�Ӥ���
	printf("Level %d, address of variable n = %p\n", n, &n);

}