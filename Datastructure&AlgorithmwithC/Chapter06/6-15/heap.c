// �� ���� ���α׷�
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)
/*--- a[left] ~ a[right]�� ������ ����� �Լ� ---*/
static void downheap(int a[], int left, int right)
{
    int temp = a[left];             // ��Ʈ
    int child;
    int parent;
    for (parent = left; parent < (right + 1) / 2; parent = child) { // (right + 1) / 2? �θ�� (i - 1) /2 n���� �θ�� <= (n-1 + 1) / 2 == < n/2 ������ �θ���� q22�� �� ����
        int cl = parent * 2 + 1;    // ���� �ڽ�
        int cr = cl + 1;            // ������ �ڽ�
        child = (cr <= right && a[cr] > a[cl]) ? cr : cl;   // ū ���� ����

        if (temp >= a[child])
            break;
        a[parent] = a[child];
    }
    a[parent] = temp;
}

/*--- �� ���� �Լ� ---*/
void heapsort(int a[], int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--) // i�� (n-2)/2���� ������ �θ�ϱ� �������θ���� ���������� ����? ���� ������ n-1/2�� �ϸ� downheap���� �� for�� �ǳʶڴ�. n = 11�� �ؼ� �����غ��� 
        downheap(a, i, n - 1);

    for (int i = n - 1; i > 0; i--) { // n log n ���� n/2 log n �� n log n
        swap(int, a[0], a[i]);
        downheap(a, 0, i - 1);
    }
}

int main(void)
{
    int nx;
    puts("�� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    heapsort(x, nx);    // �迭 x�� �� ����
    puts("������������ �����߽��ϴ�.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);            // �迭 x�� ����

    return 0;
}
