/* ����� ���� */
#include <stdio.h>

void say_hello(void);// f12 go to definition

int main()
{
	int x, y, z; //�����Ⱚ OS�� �� �� ������ �츮�� �� �� ���� ���� ����� ���ÿ� �ʱ�ȭ ���ִ� �� ����.
	// step into(�Լ����ٸ� ������ ���� �ƴϸ� �� �� ������)���� �� f11
	// step over(�Լ��� ������) f10
	// step out shift f11
	x = 1; //f9 toggle
	y = 20;
	z = 3;

	z = x + y; // ���� �������� � ���� ���� �ֳ� state ���� ���� ���α׷��� ����
	// ����Ű� �츮�� ���α׷��� ���¸� �����ְ� �ִ�.
	
	say_hello();//go to definition f12

	return 0;

}
void say_hello(void) 
{
	int x = 1;
	x = 10;

	printf("Hello World!\n");//f11�� �ص� ǥ���Լ��� �ǳʶ� shift f5 stop debugging

	return;
}
