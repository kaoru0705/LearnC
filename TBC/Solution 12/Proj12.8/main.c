/* Static Variables with External Linkage ���� ������ �ܺ� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* �����Ϸ��� ���ϵ��� ���� ���� �������ϰ� ���������� ����� ���� �װ��� ��Ŀ�� �������ش�. �׶� external linkage�� ���� �������� ���� ����� �� �ֵ��� �������ش�. �������� �Լ��� �׷���. */
/*
    Static with external linkage
    - File scope(���� ������ � ������������ ���� ����), external linkage(�ٸ� ���Ͽ����� ���� ����), static storage duration
    - External storage class
    - External variables
    - ���� ����(.c ����) �ܺη� ���� ����
    - ��Ŀ�� ���� ���� �� ������ �Լ��� ����
*/

// defining declaration: �������̸� defining declaration���� �ʱ�ȭ�� �ϴ� �� ���� 0���� �ڵ����� �ʱ�ȭ�� �ȴ� �ϴ��� �ʱ�ȭ�� �ϴ� �� ����.
int g_int = 0;  // ���������� ���ÿ� ������ ������ �����Ϸ��� �ڵ����� �ʱ�ȭ�ϰ� �Ǹ� ������尡 �߻��ϴ� �ݸ� ����/���� ������ ó���� �� �� ���� �ʱ�ȭ�ϸ� �Ǳ⿡ �����Ϸ��� �ڵ����� �ʱ�ȭ���ش�. �׷����� ���� 0���� �ʱ�ȭ�ϴ��󵵸�������� �ʱ�ȭ�ϴ� ���� ���̱⸦ �����Ѵ�
// int g_int = 7;
double g_arr[1000] = { 0.0, };  // ���� ���������� array�� ���� �ص� �����Ϸ��� �ڵ����� �ʱ�ȭ���ش�

/*
    Initializing external variables
*/
int x = 5;               // Ok. constant expression(������ Ÿ�ӿ� Ȯ���Ǵ� ��)  ���� https://en.cppreference.com/w/c/language/constant_expression
int y = 1 + 2;           // Ok. constant expression(������ Ÿ�ӿ� Ȯ���Ǵ� ��)
size_t z = sizeof(int);  // Ok. constant expression(������ Ÿ�ӿ� Ȯ���Ǵ� ��)
//int x2 = x * 2;        // Not ok. x is a variable

void fun()
{
    printf("g_int in fun() %d %p\n", g_int, &g_int);
    g_int += 10;
}

void fun_sec();  // �ٸ� ���Ͽ� ���ǵǾ� �ִ� �Լ��� ����ϱ� ���� �����ϸ� �� �Ʒ��ٺ��ʹ� �Լ��� ����� �� �ִ�(�Ŀ� ��Ŀ�� �������ش�)

int main()
{
    /*
        defining declaration vs referencing declaration
    */

    // referencing declaration
    extern int g_int;         // Optional , referencing declaration. (���� ������ �ٱ��� �ִ� ������ �����Ѵ� -> ó���� ������ ���������� ����Ѵ�. �� �ĺ��ڰ� ���� �������� �ִ� �ĺ������� ����ϱ� ���� �̷��� extern ����ϴ� ���� ���̱� 
    // ���� ���Ͽ� �ֱ� ������ ���� ��Ŀ�� ������ �ʿ�� ����. �����Ϸ��� ��.
    // ����/���� ������ ��ó�� ���ξ�ex)g_�� �����ϱ⵵ �Ѵ�)
    //extern int g_int = 1024;  // Error in block scope

    //int g_int = 123;          // name hiding hides global g_int(�������� extern int g_int; ���Ŀ� �� ���� �ڵ带 �Է��ϸ� 'int g_int': redefinition �߻�. ���� ���������� �ش� �ĺ��ڰ� �̹� ���ǵǾ� �ֱ� ����)

    extern double g_arr[];      // Optional, size is not necessary(ũ��� �̹� defining declaration�� ���� ������ �ֱ⿡)
    // extern�� �� �̷� �� ������ �� �ſ���.��� ���� ���ִ� �� ������ �ʿ� ����.
    printf("g_int in main() %d %p\n", g_int, &g_int);
    g_int += 1;

    fun();
    fun_sec();

    return 0;
}