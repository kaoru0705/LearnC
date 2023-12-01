/* ������ ����(Scope)�� ���� ����(Linkage), ��ü�� ���� �Ⱓ(Duration) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    variable scopes (visibility ������ ���ü�)
    - block, function, function prototype, file(��� �Լ��� �ٱ� ����)
*/

// file scope 03A_0FileScope.c��� ���Ͽ��� �ڵ��ϰ� ������
int g_i = 123;  // global variable(file scope)
int g_j;        // global variable(file scope)

void func1()
{
    g_i++;

    {
        g_i = 123;
    }
}

void func2()
{
    g_i += 2;  // uses g_i

    //local = 456;  //  local scope�� func2������ ������ �ʴ´�. visibility Error
}

int main()
{
    int local = 1234;

    func1();
    func2();

    printf("%d\n", g_i);  // uses g_i
    printf("%d\n", g_j);  // warning�� �� �� Not initialized?(�ʱ�ȭ ���� ���� ����/���� ������ BSS �޸� ���׸�Ʈ�� ��ġ�ϸ� ���α׷� ���� �� 0���� �ڵ� �ʱ�ȭ�ȴ�)
    printf("%d\n", local);

    return 0;
}