/* ������ ����(Scope)�� ���� ����(Linkage), ��ü�� ���� �Ⱓ(Duration) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    variable scopes (visibility ������ ���ü�)
    - block, function, function prototype, file(��� �Լ��� �ٱ� ����)
*/

// function scope
double func_block(double d) {
    double p = 0.0;

    int i;
    for (i = 0; i < 10; i++) {
        //for(int i = 0; i < 10; i++)  // C99
        double q = d * i;
        p *= q;

        if (i == 5)
            goto hello;  // goto���� ���̺��� ���������� �Լ� �� ��𿡼��� �� �� �ִ�
    }

hello:
    printf("Hello, world");

    return p;
}

// function prototype
void f1(int hello, double world);  // to the end of the prototype declaration(hello�� world�� ������ ������Ÿ�� ���κб�����. ���� �ĺ��ڰ� ���� �ʿ����� �ʴ�. ������Ÿ�Կ� �ĺ��ڸ� ����� ���� �Լ� �ٵ� ���� �ĺ��ڿ� ������ �̸��� ���̴� �� ���������� �����ϴ�. VLA�� ��� ���̸� ��������� �ϱ� ������ ������Ÿ�Կ��� �ĺ��ڸ� ������ �� ����)
void via_param(int n, int m, double ar[n][m]);  // gcc only

// file scope
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
    printf("%d\n", g_j);  // Not initialized?(�ʱ�ȭ ���� ���� ����/���� ������ BSS �޸� ���׸�Ʈ�� ��ġ�ϸ� ���α׷� ���� �� 0���� �ڵ� �ʱ�ȭ�ȴ�)
    printf("%d\n", local);

    return 0;
}