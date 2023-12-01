// ����4-6 int�� ��ť IntDequeue�� ����ϴ� ���α׷�
#include <stdio.h>
#include "IntDequeue.h"

int main(void)
{
    IntDequeue que;

    if (Initialize(&que, 6) == -1) {
        puts("ť�� ������ �����߽��ϴ�.");
        return 1;
    }

    while (1) {
        int m, x;
        int idx;

        printf("���� ������ ��:%d/%d\n", Size(&que), Capacity(&que));
        printf("(1)�� �տ� ��ť (2)�� �տ������� ��ť (3)�� �տ������� ��ũ (4)���\n"
            "(5)�� �ڿ� ��ť (6)�� �ڿ������� ��ť (7)�� �ڿ������� ��ũ (8)�˻�\n"
            "(9)Ŭ����          (10)��� �ִ��� ����       (0) ����: ");
        scanf("%d", &m);

        if (m == 0) break;

        switch (m) {
        case 1: /*--- �� �տ� ��ť ---*/
            printf("������: ");   scanf("%d", &x);
            if (EnqueFront(&que, x) == -1)
                puts("\a����: ��ť�� �����߽��ϴ�.");
            break;

        case 2: /*--- �� �տ������� ��ť ---*/
            if (DequeFront(&que, &x) == -1)
                puts("\a����: ��ť�� �����߽��ϴ�.");
            else
                printf("��ť �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 3: /*--- �� �տ������� ��ũ ---*/
            if (PeekFront(&que, &x) == -1)
                puts("\a����: ��ũ�� �����߽��ϴ�.");
            else
                printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 4: /*--- ��� ---*/
            Print(&que);
            break;

        case 5: /*--- �� �ڿ� ��ť ---*/
            printf("������: ");   scanf("%d", &x);
            if (EnqueRear(&que, x) == -1)
                puts("\a����: ��ť�� �����߽��ϴ�.");
            break;

        case 6: /*--- �� �ڿ������� ��ť ---*/
            if (DequeRear(&que, &x) == -1)
                puts("\a����: ��ť�� �����߽��ϴ�.");
            else
                printf("��ť �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 7: /*--- �� �ڿ������� ��ũ ---*/
            if (PeekRear(&que, &x) == -1)
                puts("\a����: ��ũ�� �����߽��ϴ�.");
            else
                printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 8: /*--- �˻� ---*/
            printf("�˻��� ������: ");
            scanf("%d", &x);
            if ((idx = Search(&que, x)) == -1)
                puts("\a����: �˻��� �����߽��ϴ�.");
            else {
                printf("�� �����ʹ� �ε���%d�� ��ġ�� �ֽ��ϴ�.\n", idx);
                printf("ť�� �� �� ��ҷκ��� %d�� ���� ��ġ�Դϴ�.\n", Search2(&que, x));
            }
            break;

        case 9: /*--- Ŭ���� ---*/
            Clear(&que);
            break;

        case 10: /*--- ��� �ִ��� ���� ---*/
            printf("ť�� %s��\n", IsEmpty(&que) ? "��� �ֽ��ϴ�" : "��� ���� �ʽ��ϴ�");
            printf("ť�� %s��\n", IsFull(&que) ? "���� á���ϴ�" : "���� ���� �ʾҽ��ϴ�");
            break;
        }
    }

    Terminate(&que);

    return 0;
}
