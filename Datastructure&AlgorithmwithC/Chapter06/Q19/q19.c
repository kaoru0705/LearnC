#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- (이름 오름차순 정렬) ---*/
int ncmp(const char x[], const char y[])
{
    return strcmp(x, y);
}
/*--- (이름 오름차순 정렬) ---*/
int pcmp1(const char** x, const char** y)
{

    return strcmp(*x, *y);
}
int pcmp2(const void* x, const void* y)
{
    return strcmp(*(const char**)x, *(const char**)y);
    /*
    * casting을 어떻게 하냐에 따라 ㅈ될 수 있다.
        0x00aff9dc = 00597b30 = ASCII(00597b30) = "0{Y"

        if (const char*)y = 0x00aff9dc 
        *y = '0' = ASCII(30)  0x00aff9dc가 주소인 곳으로 가서 char형 1바이트만큼 읽음
        
        (const char **)y = 0x00aff9dc
        *y = "LISP" = 0x00597b30  0x00aff9dc가 주소인 곳으로 가서 char pointer만큼(즉, 주소로) 읽음 0x00597b30 근데 이게 "LISP" 자체임
    */
}
int main(void)
{
    char a[][7] = { "LISP", "C", "Ada", "Pascal" };     // 2차원 배열
    char *p[] = { "LISP", "C", "Ada", "Pascal" };       // 포인터 배열

    int an = sizeof(a) / sizeof(a[0]);
    int pn = sizeof(p) / sizeof(p[0]); // pointer는 정확한 사이즈를 알 수 없지만 어차피 포인터의 개수를 구하고 싶은 거기 때문에 상관없다.

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