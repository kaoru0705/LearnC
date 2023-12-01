// ����4-1 int�� ���� IntStack�� ���
#include <stdio.h>
#include "IntStack2.h"

int main(void)
{
    IntStack s;

    if (Initialize(&s, 64) == -1)
    {
        puts("���� ������ �����߽��ϴ�.");
        return 1;
    }

    while (1)
    {
        int menu, x;
        int idx;
        int sw;

        printf("���� A ������ ��:%d / %d B ������ ��:%d / %d\n", Size(&s, 1), Capacity(&s), Size(&s, 2), Capacity(&s));
        printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (5)�˻� (6) Ŭ���� (7) ������� ���� (0) ����: ");
        scanf("%d", &menu);

        if (menu == 0) break;

        switch (menu) {
        case 1: /*--- Ǫ�� ---*/
            printf("������: ");
            scanf("%d", &x);
            printf("(1)Stack A (2)StackB: ");
            scanf("%d", &sw);
            if (Push(&s, sw, x) == -1)
                puts("\a����: Ǫ�ÿ� �����߽��ϴ�.");
            break;

        case 2: /*--- �� ---*/
            printf("(1)Stack A (2)StackB: ");
            scanf("%d", &sw);
            if (Pop(&s, sw, &x) == -1)
                puts("\a����: �˿� �����߽��ϴ�.");
            else
                printf("�� �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 3: /*--- ��ũ ---*/
            printf("(1)Stack A (2)StackB: ");
            scanf("%d", &sw);
            if (Peek(&s, sw, &x) == -1)
                puts("\a����: ��ũ�� �����߽��ϴ�.");
            else
                printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 4: /*--- ��� ---*/
            printf("(1)Stack A (2)StackB: ");
            scanf("%d", &sw);
            Print(&s, sw);
            break;

        case 5: /*--- �˻� ---*/
            printf("�˻��� ������: ");
            scanf("%d", &x);
            printf("(1)Stack A (2)StackB: ");
            scanf("%d", &sw);
            if ((idx = Search(&s, sw, x)) == -1)
                puts("\a����: �˻��� �����߽��ϴ�.");
            else
                printf("�� �����ʹ� �ε���%d�� ��ġ�� �ֽ��ϴ�.\n", idx);
            break;

        case 6: /*--- Ŭ���� ---*/
            printf("(1)Stack A (2)StackB: ");
            scanf("%d", &sw);
            Clear(&s, sw);
            break;

        case 7: /*--- ����ִ��� ���� ---*/
            printf("(1)Stack A (2)StackB: ");
            scanf("%d", &sw);
            printf("������ %s��\n", IsEmpty(&s, sw) ? "��� �ֽ��ϴ�" : "��� ���� �ʽ��ϴ�");
            printf("������ %s��\n", IsFull(&s) ? "���� á���ϴ�" : "���� ���� �ʾҽ��ϴ�");
            break;
        }
    }

    Terminate(&s);

    return 0;
}
//// ����4-2 �迭 ���� int�� ���� IntStack2 ��� 
//#include <stdio.h>
//#include "IntStack2.h"
//
//int main(void)
//{
//    IntStack s;
//
//    if (Initialize(&s, 64) == -1) {
//        puts("���� ������ �����߽��ϴ�.");
//        return 1;
//    }
//
//    while (1) {
//        int menu, x;
//        int idx;
//
//        printf("���� ������ ��:A:%d B:%d / %d\n", Size(&s, StackA), Size(&s, StackB), Capacity(&s));
//        printf(" 1)A�� Push  2)A���� Pop  3)A���� Peek  4)A�� ���  5)A���� �˻�  6)A�� Ŭ����\n"
//            " 7)B�� Push  8)B���� Pop  9)B���� Peek 10)B�� ��� 11)B���� �˻� 12)B�� Ŭ����\n"
//            "13)������� ���� 0) ����: ");
//        scanf("%d", &menu);
//
//        if (menu == 0) break;
//
//        switch (menu) {
//        case 1: /*--- A�� Ǫ�� ---*/
//            printf("������: ");
//            scanf("%d", &x);
//            if (Push(&s, StackA, x) == -1)
//                puts("\a����: Ǫ�ÿ� �����߽��ϴ�.");
//            break;
//
//        case 2: /*--- A���� �� ---*/
//            if (Pop(&s, StackA, &x) == -1)
//                puts("\a����: �˿� �����߽��ϴ�.");
//            else
//                printf("�� �����ʹ� %d�Դϴ�.\n", x);
//            break;
//
//        case 3: /*--- A���� ��ũ ---*/
//            if (Peek(&s, StackA, &x) == -1)
//                puts("\a����: ��ũ�� �����߽��ϴ�.");
//            else
//                printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
//            break;
//
//        case 4: /*--- A�� ��� ---*/
//            Print(&s, StackA);
//            break;
//
//        case 5: /*--- A���� �˻� ---*/
//            printf("�˻��� ������: ");
//            scanf("%d", &x);
//            if ((idx = Search(&s, StackA, x)) == -1)
//                puts("\a����: �˻��� �����߽��ϴ�.");
//            else
//                printf("�� �����ʹ� �ε���%d�� ��ġ�� �ֽ��ϴ�.\n", idx);
//            break;
//
//        case 6: /*--- A�� Ŭ���� ---*/
//            Clear(&s, StackA);
//            break;
//
//        case 7: /*--- B�� Ǫ�� ---*/
//            printf("������: ");
//            scanf("%d", &x);
//            if (Push(&s, StackB, x) == -1)
//                puts("\a����: Ǫ�ÿ� �����߽��ϴ�.");
//            break;
//
//        case 8: /*--- B���� �� ---*/
//            if (Pop(&s, StackB, &x) == -1)
//                puts("\a����: �˿� �����߽��ϴ�.");
//            else
//                printf("�� �����ʹ� %d�Դϴ�.\n", x);
//            break;
//
//        case 9: /*--- B���� ��ũ ---*/
//            if (Peek(&s, StackB, &x) == -1)
//                puts("\a����: ��ũ�� �����߽��ϴ�.");
//            else
//                printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
//            break;
//
//        case 10: /*--- B�� ��� ---*/
//            Print(&s, StackB);
//            break;
//
//        case 11: /*--- B���� �˻� ---*/
//            printf("�˻��� ������: ");
//            scanf("%d", &x);
//            if ((idx = Search(&s, StackB, x)) == -1)
//                puts("\a����: �˻��� �����߽��ϴ�.");
//            else
//                printf("�� �����ʹ� �ε���%d�� ��ġ�� �ֽ��ϴ�.\n", idx);
//            break;
//
//        case 12: /*--- B�� Ŭ���� ---*/
//            Clear(&s, StackB);
//            break;
//
//        case 13: /*--- ����ִ��� ���� ---*/
//            printf("���� A�� %s��\n", IsEmpty(&s, StackA) ? "��� �ֽ��ϴ�" : "��� ���� �ʽ��ϴ�");
//            printf("���� B�� %s��\n", IsEmpty(&s, StackB) ? "��� �ֽ��ϴ�" : "��� ���� �ʽ��ϴ�");
//            printf("������%s��\n", IsFull(&s) ? "���� á���ϴ�" : "���� ���� �ʾҽ��ϴ�");
//            break;
//        }
//    }
//
//    Terminate(&s);
//
//    return 0;
//}
