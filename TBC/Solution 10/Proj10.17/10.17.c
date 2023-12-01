/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Variable_lenth Arrays (VLAs) ������ ���̸� ���� �� �ִ� �迭 */
/* https://www.onlinegdb.com/online_c_compiler */
#define _CRT_SECURE_NO_WARNINGS
#define ROWS 3
#define COLS 4

//- ���� ���� �迭 : compile time�� ��������� ���̸� ���� �� �ִ� �� �ƴ϶� ��Ÿ�ӿ� scanf�� ������ �Է¹޾Ƽ� ���̸� ���ϴ� �迭,
// �迭�� ���̸� ������ Ÿ���� �ƴ϶� ��Ÿ�ӿ� ���Ѵٴ� �ǹ� * ��, �� �� ���̰� ������ �迭�� ���̸� �ٽ� �����ϴ� �� ������ �Ұ���
//- ���־� ��Ʃ��������� �������� �ʴ´� * �����Ҵ� �޸𸮸� �� ���� ����ϱ⿡ VLAs �� ����� ���� ������ �ʴ´�

// ���� : VLAs �ѹ� ���̰� �����Ǹ� �ٲ� �� ����.
// �޸� �����Ҵ翡�� ���̰� �ٲ�ٱ⺸�� ���̰� �ٲ� �޸𸮸� ���Ҵ� �ٽ� �޾ƿͼ� ��ġ �迭�� ���̰� �ٲ� ��ó�� ������ ���� �ִ�.
#include <stdio.h>
int main() {
    int n = 4;

    printf("Input array length : ");
    scanf("%d", &n);

    float my_arr[n];  //Note: cannot change length after declaration 

    for (int i = 0; i < n; i++)
        my_arr[i] = i;

    for (int i = 0; i < n; i++)
        printf("%f\n", my_arr[i]);

    int data[ROWS][COLS] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 0, 1, 2 }
    };

    printf("%d\n", sum2d_4(ROWS, COLS, data));

    return 0;
}

int sum2d_4(int row, int col, int ar[row][col]) {  // �Ű��������� �迭 ���� �� VLAs Ȱ�� ���, macro�� row col �������� �ʰ� �ϰ�� ���� �Ű����������� �� ������
    int r, c, tot = 0;
    for (r = 0; r < row; r++)
        for (c = 0; c < col; c++)  // [c]������ �� ������ ���� �� ���� �޸� ����
            tot += ar[r][c];
    return tot;
}