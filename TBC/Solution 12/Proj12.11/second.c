#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int g_int;// referencing declaration

static void tool(void)
{
	//
}
//static void fun_second(void);

void fun_second(void) // �տ� static�� ���δٸ�? prototype���� �ٿ��� linking�� �Ǵ� �� ���ƹ��� �� �ִ�.
/*
1>main.obj : error LNK2019: unresolved external symbol _fun_second referenced in function _main
1>C:\Users\user\Desktop\Solution 12\Debug\Proj12.11.exe : fatal error LNK1120: 1 unresolved externals
*/
//���� �Լ��� static���� ���� �ʿ䰡 ������? ���� ������ �з��� ���� ���� �з��Ѵ�. � ����� �ϴ� �Լ����� ��Ƶΰ� �� �ٸ� ����� �ϴ� �Լ����� ��� ��
//� ����� ������µ� �ܺο��� ����� ���� fun_second�� �����ؼ� ����� �� �ְ� �ϰ� �Ͱ� fun_second���� ����ϴ� � ������ �Ǵ� �Լ��� �ִٸ�
// �׸��� tool()�̶�� �Լ��� �ٸ� ������ ���� ����� ���� ���ٰ� �Ǵܵȴٸ�? static�� ����
{
	tool();

	g_int += 1;
	printf("g_int is fun_second() %d %p\n", g_int, &g_int);
}