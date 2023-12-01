/* Type Qualifiers �ڷ��� �����ڵ� const, volatile, restrict */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // memcpy
#include "constants.h"

// ���� ����ϴ� ����� ������Ͽ� ��Ƴ��� �ٸ� ���Ͽ��� ����� �� �� ����� �����ϴ� ������� ���ϰ� ��� ����. ex) #include "constants.h"
// ��� ����(constants.h) �ȿ��� ������ ���� static�� ���δ�(static�� ������ ���� ������ include �� �� ������ ���� �� �ִ� include�� ������ ���������� ��� �����ϴ� �Ŷ� �׷� ��)
//const double gravity = 9.8; // �̷��� �ϸ� �ٸ� ���α׷��� ���� �� ���ŷο�����. �� �̰� ����� �ϴ� �׷��� ��Ȱ���� �� �ֵ��� ��������� �����.
//const double PI = 3.141592;

int main(void)
{
    double area_circle = PI * 2.0f * 2.0f;

    /*
        Qualified types
        const, volatile, restrict, _Atomic in gcc
    */

    /*
        const ���� ����
    */

    // C99 idempotent(�����ڸ� ���� �� �ߺ��ؼ� ����ϴ� �� �����ϴ�)
    const const const int n = 6;  // const int n = 6;

    typedef const int zip;  // ������ const�� ���� �ڷ����� ����ڰ� ������ �ڷ������� ������ �� const�� �ٽ� �ٿ��� ������ ������ �ʴ´�
    const zip q = 8;  // const const int zip �̶� �������� �ȵǴ� ������ �����ϱ� ���ؼ� ���� �� ����ص� ����

    //const int i;  // Not initialized!(const Ű���带 ����� ������ ���� �ٲ� �� ���� ������ �ݵ�� ����� ���ÿ� �ʱ�ȭ�ؾ� �Ѵ�)
    //i = 12;  // Error
    //printf("%d\n", i);  // Error

    const int j = 123;
    const int arr[] = { 1, 2, 3 };

    float f1 = 3.14F, f2 = 1.2F;

    const float* pf1 = &f1;
    //*pf1 = 5.0F;  // Error
    pf1 = &f2;  // Allowed

    float* const pf2 = &f1;

    *pf2 = 6.0F;  // Allowed
    //pf2 = &f2;  // Error

    const float* const pf3 = &f1;
    //*pf3 = 7.0F;  // Error
    //pf3 = &pf2;  // Error

    /*
        Global constants: �ֻ�ܺ� ����
    */

    /*
        Volatile �ֹ߼�
        - Do not optimize(ex. hardware clock �Ӻ����) ����ȭ�� �� �� ������.
    */

    volatile int vi = 1;  // volatile location
    volatile int* pvi = &vi;  // points to a volatile location

    int i1 = vi;

    // ...(�����Ϸ��� �� �� ���� ������� ���� vi�� ���� �ٲ� ���� �ִ�. ex) �ü���� ������ ������ ���� �ٲ� �����͸� �̿��� ����, �ٸ� ��⿡���� ����)

    int i2 = vi;  // �����Ϸ��� �⺻������ �޸𸮷κ��� vi�� ���� �޾ƿ;� ������ ������ ���� vi�� ���� ������ vi�� ���� �����Ŷ�� ���� �Ͽ�(�����Ϸ� ���忡�� // ... ���⿡ vi������ �ٲٴ� �ڵ尡 ������ ���� �� �ٲ�����ϰ�) vi�� �ӽ� ����������� ��� �����ؼ� vi ���� �޾ƿ��� ������� ����ȭ�� �����ϱ⵵ �Ѵ�. volatile Ű����� �̷��� ����ȭ�� ���� �ʵ���(= ĳ��(�ӽ� ����������� ��� �����ؼ� �ӵ��� ������ �ϴ� ��)�� ���� �ʵ���) �����Ѵ�

    /*
        restrict (__restrict in VS)
        - sole initial means of accessing a data object(�����͸� ����� �ٸ� �������� �������� �ش� �����Ϳ� ������ �� ������ �����) ������ ������Ʈ�� �����ϴ� �� �̰� �ϳ� ���̴�. ��� �ǹ�
        - compiler can't check this restriction(restrict Ű���带 �ٿ��ٰ� �ؼ� �����Ϸ��� �������� ����(ex �����Ҵ���� �޸𸮿� ���ؼ� �����Ͱ� ���� restar�ۿ� ������)�� üũ�������� �ʴ´�)
        ���α׷��Ӱ� ������ restrict�� �پ����� �ٸ� �����͸� ���� �������� ���ڰ� ���Ѿ� ��
    */

    int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* par = ar;

    int* __restrict restar = (int*)malloc(10 * sizeof(int)); //�����Ҵ� �޾ƿ� �޸𸮸� �ٸ� �����ͳ� �ٸ� �������� �������� �ʰڴ� restar�� ���ؼ��� �����ϰڴ�.
    if (!restar) exit(1);

    ar[0] += 3;  // �迭�� ���ؼ� ���� �ٲٴ� ���
    par[0] += 5;  // �����͸� ���ؼ� ���� �ٲٴ� ���
    // == par[0] += 8; par�� ar�� ����Ű�� �ֱ⿡ ���� �� �ٰ� ��� ���Ƽ� �����Ϸ��� �̷��� ����ȭ�� �ϰ� ���� �� �ִ� �㳪 ��·�� �ٸ� �̸��̶� ����ȭ�� ������ ���Ѵ�. 

    restar[0] += 3;
    restar[0] += 5;
    //restar[0] += 8;  // Equivalent(�����Ϸ��� �����Ҵ� ���� �޸𸮸� ������ �� �ִ� ����� restar�ۿ� ���� �ؼ� �ٷ� ���� �ڵ� �� ���� �� �� �ٷ� ����ȭ�� ���� �ִ�)

    //free(restar);

    return 0;
}