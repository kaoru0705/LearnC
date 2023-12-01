#include <stdio.h>
#include <stdlib.h>
void ary_copy(int a[], const int b[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}
int main()
{
	int n;
	scanf("%d", &n);
	
	int* a = (int*)calloc(n, sizeof(int));
	int* b = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	
	ary_copy(a, b, n);
	for (int i = 0; i < n; i++)
		printf("%d", a[i]);

	free(a);
	free(b);

	return 0;
}
//// ����2-7���迭�� ��� ��Ҹ� ����
//#include <stdio.h>
//#include <stdlib.h>
//
///*--- ��� ������ n�� �迭 b�� ��� ��Ҹ� �迭 a�� ���� ---*/
//void ary_copy(int a[], const int b[], int n)
//{
//    for (int i = 0; i < n; i++)
//        a[i] = b[i];
//}
//
//int main(void)
//{
//    int n;      // �迭 x�� y�� ��� ����
//
//    printf("��� ����: ");
//    scanf("%d", &n);
//    int* x = calloc(n, sizeof(int));    // ��� ������ n�� int�� �迭 x�� ����
//    int* y = calloc(n, sizeof(int));    // ��� ������ n�� int�� �迭 y�� ����
//
//    printf("%d���� ������ �Է��ϼ���.\n", n);
//    for (int i = 0; i < n; i++) {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//
//    ary_copy(y, x, n);                  // �迭 x�� ��� ��Ҹ� �迭 y�� ����
//
//    printf("�迭 x�� ��� ��Ҹ� �迭 y�� �����߽��ϴ�.\n");
//    for (int i = 0; i < n; i++)
//        printf("y[%d] = %d\n", i, y[i]);
//
//    free(x);                            // �迭 x�� ����
//    free(y);                            // �迭 y�� ����
//
//    return 0;
//}