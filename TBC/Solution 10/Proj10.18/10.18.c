/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Compound Literals ���� ���ͷ��� �迭 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�̸��� ���� literal�� �ִ� �� �Ӹ� �ƴ϶� �̸��� ���� ���𰡸� ����ϴ� ���� �ֱٿ� �پ��� ���α׷��� �������� ��Ÿ���� �ִ�. ramda�Լ�

#define COLS 4

int sum_1d(int arr[], int n);
int sum_2d(int arr[][COLS], int rows);

int main() {

    int a = 1; // literal�� ���� ����
    3;  // Literals are constants that aren't symbolic(���ͷ��� �̸��� ���� ���)
    3.14F;
    int b[2] = { 3, 4 };// �̰� int�� �� ���ϱ� compound(����) literal�� �ƴ϶� multiple literal �ƴϳ�? �ǹ� ���� compound literal�� �ٸ� �ڷ��������� ���� �� �ִ�. ����ü
    (int[2]){3, 4};    // compound literal(�迭�� ���� ���ͷ��� ǥ���� ��. �ٷ� ���ٰ� �޸� �̸��� ����)
    // ���⼭�� ���� �ڷ����� ��� �迭 literal�� ���

    //int c[2] = (int[2]) { 3, 4 };  // Error(���� ���ͷ��� �迭 �ʱ�ȭ�ϴ� �� �Ұ���) �ɸ� �� �� ������ �� �� 

    int arr1[2] = { 1, 2 };
    int arr2[2][COLS] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 } };
    &arr2[0];
    printf("%d\n", sum_1d(arr1, 2));
    printf("%d\n", sum_2d(arr2, 2));
    printf("\n");

    // �迭 ������ ���� �ʰ� ���� ���ͷ��� �̿��� �迭�� �Լ� �μ��� �ٷ� ����� �� �ִ�, ������ �̸��� ������ó�� ���� ���� ���°� �ƴ϶� �迭�� literaló�� �ٷ� ���� ���� �� ����
    printf("%d\n", sum_1d((int[2]) { 1, 2, }, 2)); // ������ ���, �迭�� ���Ҹ� ���� ����ִ� ��� �ϵ� �ڵ��� �� ��쿡 ���󼭴� �����ϰ� ����� �� �ִ�.
    printf("%d\n", sum_2d((int[2][COLS]) { { 1, 2, 3, 4 }, { 5, 6, 7, 8 } }, 2));
    printf("\n");

    int* ptr1;
    int(*ptr2)[COLS];

    ptr1 = (int[2]){ 1, 2 };
    ptr2 = (int[2][COLS]){ { 1, 2, 3, 4 } , { 5, 6, 7, 8 } };

    printf("%d\n", sum_1d(ptr1, 2));
    printf("%d\n", sum_2d(ptr2, 2));

    printf("\n");

    return 0;

}

int sum_1d(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; ++i)
        total += arr[i];
    return total;
}

int sum_2d(int arr[][COLS], int rows) {
    int total = 0;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < COLS; c++)
            total += arr[r][c];
    return total;
}