/* ǥ�� ��ƿ��Ƽ Utilities ���̺귯��*/
/* https://www.onlinegdb.com/online_c_compiler */
#include <stdio.h>
#include <stdlib.h>  // rand(), srand(), malloc(), free(), ...
//#include <stdnoreturn.h>

void goodbye(void)
{
    printf("Goodbye\n");
}
void thankyou(void)
{
    printf("Thankyou\n");
}

//// causes undefined behaviour if i <= 0 MSVC������ �� ��
//// exits if i > 0
//_Noreturn void stop_now(int i)  // _Noreturn : �� �Լ��� ������ �ٽ� � ���α׷��� ����Ǵ� ������ ���ư��� �ʴ� ���α׷��� �����Ű�� function specifier
//{ 
//    if (i > 0) exit(i);
//    //exit(i);
//}

int main(void)
{
    printf("Purchased?\n");
    if (getchar() == 'y')
        atexit(thankyou);  // ���α׷��� ����� �� � �Լ��� ȣ������ ����� �� �ִ�. � �Լ��� ������ �� �����ų�� runtime�� ���� ���������� �Լ��������� list�� ������ �ִ�.

    while (getchar() != '\n') {};

    printf("Goodbye message?\n");
    if (getchar() == 'y')
        atexit(goodbye);

    /*
        exit(0);
        puts("Preparing to stop ...");
        stop_now(2);
        puts("This code is never executed.");
    */

    /*
        qsort();
    */

    return 0;
}