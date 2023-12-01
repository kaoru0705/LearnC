/* �ڷ������� ������ �ٿ��ִ� typedef */
#define _CRT_SECURE_NO_WANRINGS

#include <stdio.h>
#include <time.h>  // time()
#define yoyo char *
int main(void)
{
    /*
        typedef specifier type definition
        - Give symbolic names(or aliases) to types
        - Does not create new types �̸��� �ٲ��ִ� �� ��
    */

    typedef unsigned char BYTE;       // Note the scope of BYTE
    // 1. ������ �� �ڷ����� �ݺ��ؼ� ����� ��� ���̱� ����
    // 2. � �о߿����� unsigned char�� ���ڷ� ����ϱ⺸�ٴ� ����Ʈ��� ������ ���� �����ϴ� �����ν� 1����Ʈ¥�� �ڷḦ �����ϴ� �⺻ �ڷ������θ� �����ϰ� �;

    BYTE x, y[10] = { 0, }, * z = &x;

    {
        typedef unsigned char byte;   // You can use lowercases as well

        /* Portable data types */

        size_t s = sizeof(byte);  // sizeof�������� ��ȯ��: unsigned int (x86), unsigned long long (x64) 
        // x64�� �ٲٸ� size_t�� �˾Ƽ� unsigned long long���� �ٲ� f12 #ifdef ��ó���� �ٲ� ������ ������� ���� �� �� �ִ�.
        // unsigned int s = sizeof(byte);        // x86
        // unsigned long long s = sizeof(byte);  // x64
    }

    //byte b;  // error. typedef definition has a scope

    /*
        This function returns the time since 00:00:00 UTC, January 1, 1970 (Unix timestamp) in seconds.
    */

    time_t t = time(NULL); // �̰͵� f12�� �غ��� x64 x86�� ���� �ٲ��.

    printf("%lld\n", t);

    /*
        typedef vs #define �⺻�����δ� typdef�� �����Ѵ�.
    */

    typedef char* STRING;

    STRING name = "John Wick", sign = "World";

    /*
        - typedef interpretation is performed by the compiler, not the preprocessor
        - More flexible than #define

     #define STRING char *

     STRING name, sign; sign�� ������ ������ STRING���� ��������
     char* name, sign;  // Note the type of sign ������ sign�� *�� �����Ƿ� ���������� ������ �����Ͱ� �ƴϴ�. ū ������ ���� �� �ִ� �Ǽ�
    */

    typedef struct complex {
        float real;
        float imag;
    } COMPLEX;  // typedef struct complex COMPLEX

    typedef struct { double width; double height; } rect;  // No tag
    rect r1 = { 1.1, 2.2 };
    rect r2 = r1;
    printf("%f %f\n", r2.width, r2.height);

    return 0;
}