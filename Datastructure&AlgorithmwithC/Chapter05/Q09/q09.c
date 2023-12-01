// ������� 8��
//#include <stdio.h>
//#include "IntStack.h"
//
//int flag_a[8];      // �� �࿡ ���� ��ġ�ߴ��� üũ�ϴ� �迭
//int flag_b[15];     // �밢�� /�� ���� ��ġ�ߴ��� üũ�ϴ� �迭
//int flag_c[15];     // �밢�� \�� ���� ��ġ�ߴ��� üũ�ϴ� �迭
//int pos[8];         // �� ������ ���� ��ġ
//
///*--- �� ������ ���� ��ġ�� ��� ---*/
//void print(void)
//{
//    for (int i = 0; i < 8; i++)
//        printf("%2d", pos[i]);
//    putchar('\n');
//}
//
///*--- i������ �˸��� ��ġ�� ���� ��ġ ---*/
//void set2(int i)
//{
//    for (int j = 0; j < 8; j++)
//    {
//        if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7])
//        {
//            pos[i] = j;
//            if (i == 7)         // ��� ���� ��ġ�� ��ħ
//                print();
//            else
//            {
//                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
//                set2(i + 1);     // ���� ���� ��ġ
//                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
//            }
//        }
//    }
//}
//
//void set(int i)
//{
//    IntStack x, y;
//    Initialize(&x, 100);
//    Initialize(&y, 100);
//
//    for (int j = 0; j < 8; j++)
//    {
//        if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7])
//        {
//            Push(&x, i);
//            Push(&y, j);
//
//            pos[i] = j;
//            if (i == 7)         // ��� ���� ��ġ�� ��ħ
//                print();
//            else
//            {
//                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
//                i++;
//                j = -1;
//                continue;
//            }
//        }
//        while (!IsEmpty(&x) && j == 7)
//        {
//            Pop(&x, &i);
//            Pop(&y, &j);
//            flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
//        }
//        if(IsEmpty(&x) && pos[0] == 7) break;
//    }
//    Terminate(&x);
//    Terminate(&y);
//}
//int main(void)
//{
//    for (int i = 0; i < 8; i++)
//        flag_a[i] = 0;
//    for (int i = 0; i < 15; i++)
//        flag_b[i] = flag_c[i] = 0;
//
//    set(0);                     // 0���� ��ġ
//
//    return 0;
//}
// ���� 5-10��8�� ������ ����������� Ǯ��
// ����: �� ���α׷��� �������Ϸ��� 'IntStack.h'�� 'IntStack.c'�� �ʿ��մϴ�.
#include <stdio.h>
#include "IntStack.h"

int flag_a[8];      // �� �࿡ ���� ��ġ�ߴ��� üũ�ϴ� �迭
int flag_b[15];     // �밢�� /�� ���� ��ġ�ߴ��� üũ�ϴ� �迭
int flag_c[15];     // �밢�� \�� ���� ��ġ�ߴ��� üũ�ϴ� �迭
int pos[8];         // �� ������ ���� ��ġ */

/*--- �� ������ ���� ��ġ�� ��� ---*/
void print(void)
{
    for (int i = 0; i < 8; i++)
        printf("%2d", pos[i]);
    putchar('\n');
}

/*--- i������ �˸��� ��ġ�� ���� ��ġ(����� ����)--- ������ goto���� ������ �ٲ㺸�ڴ�.*/
void set(int i)
{
    IntStack jstk;
    Initialize(&jstk, 8);

    while (1)
    {
        int j = 0;
        int flag = 0;
        while (1)
        {
            while (j < 8)
            {
                if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7])
                {
                    pos[i] = j;
                    if (i == 7)             // ��� ���� ��ġ�� ��ħ
                        print();
                    else
                    {
                        flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
                        i++;
                        Push(&jstk, j);     // i���� ���� Ǫ��
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
                j++;
            }
            if (flag) break;
            if (--i == -1) return;
            Pop(&jstk, &j);                 // i���� ���� ��
            flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
            j++;
        }
    }
    Terminate(&jstk);
}

int main(void)
{
    for (int i = 0; i < 8; i++)
        flag_a[i] = 0;
    for (int i = 0; i < 15; i++)
        flag_b[i] = flag_c[i] = 0;

    set(0);                     // 0���� ��ġ

    return 0;
}

