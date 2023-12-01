/* �̸� ���ǵ� ��ũ�ε�, #line, #error */
#include <stdio.h>
#include "DifferentFile.h"

void different_function();

int main(void)
{
    printf("__FILE__ : %s\n", __FILE__);  // __FILE__ : ���� ��ũ�ΰ� ���� ���� �̸��� ���ڿ��� �ٲ�
    printf("__DATE__ %s\n", __DATE__);    // __DATE__ : ��ó���� ����� ��¥(���� ��¥�� �ƴ�)
    printf("__TIME__ %s\n", __TIME__);    // __TIME__ : ��ó���� ����� �ð�(���� ��¥�� �ƴ�)
    printf("__LINE__ %d\n", __LINE__);    // __LINE__ : �� ��ũ�ΰ� �ڵ� �� ��° �ٿ� ��ġ���ִ��� �˷��ش�
    printf("__func__ %s\n", __func__);    // __func__ : �� ��ũ�ΰ� ���Ե� �Լ� �̸��� ���ڿ�

    different_function();

    different_function_in_different_file();

    /* Not defined in VS */

    //printf("__STDC__ %d\n", __STDC__);                // comforms to the C standard c��� ǥ���� �����ϴ°�? �����ϸ� 1
    //printf("__STDC_HOSTED__ %d\n", __STDC_HOSTED__);  // hosted vs freestanding implementation KNK p.330 ǥ���� �����ϰ� �������� �ƴϳ� hosted�� 1
    //printf("__STDC_VERSION__ %ld\n", __STDC_VERSION__); // ���� cǥ���� ������ ���̳�

//#line 7         // ���� ���� ������ 7�� �ٲ����
//    printf("__LINE__ after #line %d\n", __LINE__);
//
//#line 1 "hello.txt"     // hello.txt�� ��η� ������ �ٲ����
//    printf("__LINE__ after #line %d\n", __LINE__);
//    printf("__FILE__ : %s\n", __FILE__);

///*���ǿ� ���� �������� ���ϵ��� ���� ���*/
#if __LINE__ != 33  // �� �ڵ带 �ּ�ó���ϰ� �ϸ� �� ���� ��  1>hello.txt(6,1): fatal error C1189: #error:  Not line 33
#error Not line 33  // compile error�� ���� ���� �ǹ����� ���� �����
#endif

#if defined(_WIN64) != 1
#error Not WIN64 platform
#endif

//#if __STDC_VERSION__ != 201112L // L�� long type�� �ǹ�
//#error Not C11
//#endif

    return 0;
}

void different_function()
{
    printf("This function is %s\n", __func__);
    printf("This is line %d\n", __LINE__);
}
