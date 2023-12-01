/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Recursion & Stack */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// ���ѷ����� ����� �� ���ȣ���� ����ϸ� �� �ȴ�.
void my_func(int);
// stack overflow ������ �޸𸮰� �ƴ϶� ����ϴٰ� ������������ ����ȴ�. �ּҴ� �� �ٸ���. �����̸��� �ƴ϶� �ּҰ� �߿���
//Level 1, address of variable n = 00EFF948 32bit �̻� ���̳� ���ÿ� ���̴� �� ���α׷��� ���� ���δ�. my_func��ü��
//Level 2, address of variable n = 00EFF870 �׸����� ǥ���ҷ��� ������ ���̴� ��ó�� ǥ���� �� ��
// ���α׷��� ����Ǹ� �⺻������ ��� ���� �޸𸮿� ����ȴ�. �Լ��� �����ϱ� ���� �ʿ��� ������ �Լ��� �޸𸮿� ����ȴ�.
// �㳪 ��Ȯ���� �ʴ�. �����Ϸ��� ���� ����ȭ�� �����ֱ� ����
// �ڼ����� os compiler �������� ���� �� �� �ִ�. stack�� ������ �Բ� ����ϴ� �ڵ嵵 �Լ��� ���� ���δ�. ��Ʋ�� stack frame

int main()
{
	my_func(1);

	return 0;
}

void my_func(int n)
{
	printf("Level %d, address of variable n = %d\n", n, (int)& n); // 10������ �ٲٱ� ���ؼ� ptr -> int casting
	// == printf("Level %d, address of variable n = %d\n", n, &n); (int) cast operator int�� �⺻�� decimal


	if (n < 4) //TODO: stop condition 
		my_func(n + 1); // ������ ���·� ȣ���ϰ� �ٽ� ���ƿ�
	// ���ȣ���� ��ư� ������������ ���� �˰��򿡼��� ���� ��찡 �ִ�.
	// ���� �ݺ��Ǵ� ��Ȳ�� ���ų� ��ǻ�Ͱ� �۵��Ǵ� ȿ���� ���̰� ���� ��쿡�� �Ϲ����� for������ �ٲ� �� �ִ�.
	// ���������̶�� ���� ����̳�?
	printf("Level %d, address of variable n = %d\n", n, (int)&n);

	// ... = compiler�� OS�� ������ �츰 �� �ʿ� ���� �޸� ����
	//TODO: tail recursion
}