#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- (�̸� �������� ����) ---*/
int ncmp(const char x[], const char y[])
{
    return strcmp(x, y);
}
/*--- (�̸� �������� ����) ---*/
int pcmp1(const char** x, const char** y)
{

    return strcmp(*x, *y);
}
int pcmp2(const void* x, const void* y)
{
    return strcmp(*(const char**)x, *(const char**)y);
    /*
    * casting�� ��� �ϳĿ� ���� ���� �� �ִ�.
        0x00aff9dc = 00597b30 = ASCII(00597b30) = "0{Y"

        if (const char*)y = 0x00aff9dc 
        *y = '0' = ASCII(30)  0x00aff9dc�� �ּ��� ������ ���� char�� 1����Ʈ��ŭ ����
        
        (const char **)y = 0x00aff9dc
        *y = "LISP" = 0x00597b30  0x00aff9dc�� �ּ��� ������ ���� char pointer��ŭ(��, �ּҷ�) ���� 0x00597b30 �ٵ� �̰� "LISP" ��ü��
    */
}
int main(void)
{
    char a[][7] = { "LISP", "C", "Ada", "Pascal" };     // 2���� �迭
    char *p[] = { "LISP", "C", "Ada", "Pascal" };       // ������ �迭

    int an = sizeof(a) / sizeof(a[0]);
    int pn = sizeof(p) / sizeof(p[0]); // pointer�� ��Ȯ�� ����� �� �� ������ ������ �������� ������ ���ϰ� ���� �ű� ������ �������.

    printf("a[0]: %p\n", a[0]);
    qsort(a, an, sizeof(a[0]), (int (*)(const void*, const void*))ncmp);
    printf("p[0]: %p\n", p[0]);
    printf("\"LISP\": %p\n", "LISP");
    //qsort(p, pn, sizeof(p[0]), (int (*)(const void*, const void*))pcmp1);
    qsort(p, pn, sizeof(p[0]), pcmp2);
    
    for (int i = 0; i < an; i++)
        printf("%s\n", a[i]);
    for (int i = 0; i < pn; i++)
        printf("%s\n", p[i]);

    return 0;
}