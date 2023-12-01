////// ��Ϳ� ���� ���ظ� ���̱� ���� ������ ����� �Լ�(��� ����)
////#include <stdio.h>
//
//// ���� 5-5 ������ ����� �Լ� recur�� �޸������̼����� ����
//#include <stdio.h>
//#include "intstack.h"
//
///*--- ��� ȣ���� ������ recur3 �Լ� ---*/
//void recur3(int n)
//{
//    IntStack stk;                   // ����
//    Initialize(&stk, 100);
//    while (1)
//    {
//        if (n > 0)
//        {
//            Push(&stk, n);          // n���� Ǫ��
//            n = n - 1;
//            continue;
//        }
//        if (!IsEmpty(&stk))         // ������ ��� ���� ������
//        {
//            Pop(&stk, &n);          // ���� �����ߴ� n�� ��
//            printf("%d\n", n);
//            n = n - 2;
//            continue;
//        }
//        else
//            break;
//    }
//    Terminate(&stk);
//}
//
//int counter = 0;                    // recur �Լ��� ȣ�� Ƚ��
//static char memo[128][1024];        // �޸�� ���ڿ� �迭
//
///*--- ��� �Լ� recur ---*/
//void recur_a(int n)
//{
//    counter++;
//    if (n > 0) {
//        recur_a(n - 1);
//        printf("%d\n", n);
//        recur_a(n - 2);
//    }
//}
//
///*--- �޸������̼��� ������ recur �Լ� ---*/
//void recur_b(int n) {
//    counter++;
//    if (memo[n + 1][0] != '\0')
//        printf("%s", memo[n + 1]);              // �޸� ������� �׳� �Ѱܹ���
//    else {
//        if (n > 0) {
//            recur_b(n - 1);
//            printf("%d\n", n);
//            recur_b(n - 2);
//            sprintf(memo[n + 1], "%s%d\n%s", memo[n], n, memo[n - 1]);
//        }
//        else {
//            strcpy(memo[n + 1], "");
//        }
//    }
//}
//
//int main(void)
//{
//    int x;
//
//    printf("������ �Է��ϼ���.: ");
//    scanf("%d", &x);
//
//    recur3(x);
//    printf("\n");
//
//    recur_a(x);
//    printf("recur �Լ��� %dȸ ��µǾ����ϴ�.\n", counter);
//    counter = 0;
//    printf("\n");
//
//    recur_b(x);
//    printf("recur �Լ��� %dȸ ��µǾ����ϴ�.\n", counter);
//
//
//    return 0;
//}

// ���� 5-6��recur3 �Լ��� ������� ����
// ����: �� ���α׷��� �������Ϸ��� 'IntStack.h'�� 'IntStack.c'�� �ʿ��մϴ�.
#include <stdio.h>
#include "IntStack.h"

/*--- recur3 �Լ�(��͸� ����) ---*/
void recur3(int n)
{
    int sw = 0;
    IntStack nstk, sstk;            // ����

    Initialize(&nstk, 100);
    Initialize(&sstk, 100);

    while (1) {
        if (n > 0) {
            Push(&nstk, n);
            Push(&sstk, sw);

            if (sw == 0)
                n = n - 1;
            else if (sw == 1) {
                n = n - 2;
                sw = 0;
            }
            continue;
        }
        do {
            Pop(&nstk, &n);
            Pop(&sstk, &sw);
            sw++;

            if (sw == 2) {
                printf("%d\n", n);
                if (IsEmpty(&nstk))
                    return;
            }
        } while (sw == 2);
    }

    Terminate(&nstk);
    Terminate(&sstk);
}

int main(void)
{
    int x;

    printf("������ �Է��ϼ���.: ");
    scanf("%d", &x);

    recur3(x);

    return 0;
}
