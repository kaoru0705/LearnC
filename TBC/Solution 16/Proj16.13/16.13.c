/* ǥ�� ���� ���̺귯�� */
/* https://www.onlinegdb.com/online_c_compiler */
#include <stdio.h>
#include <math.h>
//#include <tgmath.h>  // type generic macros

// Generic Selection Expression
#define SQRT(X) _Generic((X),\
long double: sqrtl, \
default: sqrt, \
float: sqrtf)(X)


int main(void)
{
    printf("%f\n", cos(3.141592));

    /*
        Pythagorean theorem
        https://en.wikipedia.org/wiki/Pythagorean_theorem
    */

    double c = 5.0, b = 4.0, a;  // a?
    a = sqrt(c * c - b * b);     // sqrtf() �Լ� ���� ���е��� ����
    printf("a = %f\n", a);

    float cf = 5.0F, bf = 4.0F, af;
    af = sqrtf(cf * cf - bf * bf);
    printf("af = %f\n", af);

    /* ���� �ڵ� VS�� ���� �Ұ��� */
    /*
        Type Variants
    */

    double t1 = SQRT(2.0F);  // float�� ����� �� double�� ĳ���õȴ�(=sqrtf()�� ���е��� ���´�)
    double t2 = SQRT(2.0);   // double�� ����Ѵ�(=sqrt()�� ���е��� ���´�)

    if (t1 == t2)
        printf("Identical\n");
    else
        printf("Not identical\n");

    /*
        tgmath.h Library
        tgmath.h �� sqrt()�Լ��� �μ��� Ÿ�Կ� ���� sqrt()�� sqrtf() �߿� �ڵ����� ������ �� ȣ��ȴ�(���� �Ʒ� ��°���� Not identical�� �ȴ�)
    */

    double a1 = sqrt(2.0F); // tgmath.h include �� �� ��� 2.0f�� double�� promotion�ż� �ԷµǹǷ� indentical ���
    double a2 = sqrt(2.0);

    // ���е��� �޶����⿡ �Ʒ� ��� ����� Not identical�� �ȴ�
    //double a1 = sqrt(1.0F / 3.0F);
    //double a2 = sqrt(1.0 / 3.0);

    if (a1 == a2)
        printf("Identical\n");
    else
        printf("Not identical\n");

    return 0;

    // ���̺귯�� ������ �ʼ����� �͸� ����ִ� c������ ������ �� �˾ƺ��� �����. ���۸��ض� cppreference ��õ�Ѵ�.
}