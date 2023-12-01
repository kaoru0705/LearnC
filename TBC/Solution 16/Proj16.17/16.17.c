/* Variable Arguments �Լ��� �޾Ƶ��̴� �μ��� ������ �׶��׶� �޶��� �� �ִ� */
#include <stdio.h>
#include <string.h>
#include <stdarg.h>  // Variable Arguments

/*
    Variable Arguments
    - int printf(char const* const _Format, ...); , ... : ellipsis

    1. Provide a function prototype using an ellipsis

    void    vaf1(int n, ...);                  // OK
    int     vaf2(const char * s, int k, ...);  // OK
    char    vaf3(char c1, ..., char c2);       // Not OK, ellipsis should be the last
    double  vaf4(...);                         // Not OK, no parameter(������ǥ ������ �ִ� �μ��� �������� ������ǥ�� ������ �μ����� �ּҸ� üũ�� �� �ֱ⿡ ������ǥ �̿��� �μ��� �ϳ� �̻� �־�� �Ѵ�)

    2. Create a va_list type variable in the function definition
    3. Use a macro to initialize the variable to an argument list
    4. Use a macro to access the argument list

    �����μ��� �ǹ����� ����� �ϵ� ���� ���������� �ʴ´�. debugging�� ����� �����̴�. 
    ������ �������� �ϵ��� ������ ���α׷����ϰų� �ü��, ���α׷��� �� ����ٸ� �̷� ���� ����ؼ� ���α׷��������� �𸥴�.
    �������α׷��Ӵ� �� ��
*/

double average(int, ...); // parameter���忡�� �� �� int�� 2��
double average2(char* format_string, ...);

int main(void)
{
    double a, b;

    //a = average(3, 1.1, 2.2, 3.3);      // ���̰� ���� �� �ִ� ���� ���� argument���� �ϳ��� parameter�� �޾Ƶ��� 
    //b = average(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
    a = average2("dd", 1.1, 2.2, 3.3);
    b = average2("ddd", 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

    printf("%lf\n%lf\n", a, b);

    return 0;
}

double average(int num, ...)
{
    va_list ap;
    double sum = 0.0;
    int i;

    va_start(ap, num);      // ... �տ� �ִ� ������ �Ķ���͸� ������ �ȴ�. ���⼱ num
    for (i = 0; i < num; i++)
        sum += va_arg(ap, double); // ...�� ������ Ÿ���� � Ÿ������ �˾ƾ� ��
    va_end(ap);

    return sum / (double)num;
}

double average2(char* format_string, ...) // printf�� �̷� ������ ���ڿ��� �м��ؼ� ��½�Ű�� ������ ��ȯ���� ���̴�.
{
    int num = strlen(format_string);

    va_list ap;
    double sum = 0.0;
    int i;

    va_start(ap, format_string);    // va_start�� format_string�� ���� ������ ���� ��ü�� �߿��� �� �ƴ϶� ������ variable argument�� ���� �ڸ���� �� �˷��ֱ� ���ؼ���.
    for (i = 0; i < num; i++)
        sum += va_arg(ap, double);
    va_end(ap);

    return sum / (double)num;
}