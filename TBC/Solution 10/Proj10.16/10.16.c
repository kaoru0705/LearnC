/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ������ �迭(Multidimensional Arrays)�� �Լ����� �������ִ� ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ROWS 3 //��ó���� symbolic constant macro
#define COLS 4

int sum2d_1(int ar[ROWS][COLS]); // �����Ϸ��� �Ű������� ���Ǵ� 2���� �迭�� ù ��° ���� ���� ������ ���õȴ� �־��ִ��� ���������δ� ����� �� ���� ������ �Լ��κ��� ������ �� �ȴ�. like 10.7 �迭�� ����� �� symbolic constant, consant�� ����ϴ� ��찡 ��κ�
int sum2d_2(int ar[][COLS], int row); // �Ǵ� �ٸ� parameter�� ���� int row ����: �迭�� �̸��� ������ �ƴ϶� ù ������ �ּұ� ������ �����ͷ� ��ȯ�ȴ� ������ �׷��� �Ǿ��ִٰ� ���� �����Ҵ翡���� ������ ������ �����͸� ������ �迭ó�� ���� ������ ������.
// ��, �� ��° ���� ���� ������ �Է��ؾ� �Ѵ�)  
//int sum2d_2(int [][COLS], int row);  // ������Ÿ�Կ����� �Ű����� �̸� ���� ����
//int sum2d_2(int (*ar)[COLS], int row);  // int 10.15 ar is a SINGLE pointer to the array of COLS ints ���������� �̷��� �����ϰ� ���� �� ��ȣ���� ����
int sum2d_3(int* ar, int row, int col);  // ������ �迭�� �ٷ� �� �ַ� ����ϴ� ��� ������ �� ����ϴ� ��� Ư�� deep running, c++������ �� ���� �� �� �ִ�.
//int sum2d_3(int*, int, int);

int main()
{
    int data[ROWS][COLS] = {    // ROWS COLS ��ũ���̱� ������ ������ �Ҷ� �̹� ���� ����, data�� �� ����ϴ� �޸𸮴� �������� �� ���� �����Ҵ� �߿�
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 0, 1, 2 }
    };

    printf("%d\n", data[2][3]);

    int* ptr = &data[0][0];
    printf("%d\n", *(ptr + 3 + COLS * 2));  // ���ӵ� ������(1���� array)�� �������� �迭(2���� array)�� ��ó�� �ٷ�� ���, �����Ҵ� �޸𸮸� �迭ó�� ����ϴ� ������� �ٽ� �˷���

    printf("Sum of all elements = %d\n", sum2d_1(data));
    printf("Sum of all elements = %d\n", sum2d_2(data, ROWS));
    printf("Sum of all elements = %d\n", sum2d_3(&data[0][0], ROWS, COLS));

    return 0;
}

int sum2d_1(int ar[ROWS][COLS]) // �迭��ü�� parameter�� ���ڳ� �������� in 10.7,
{
    int r, c, tot = 0;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)  // [c]������ �� ������ ���� �� ���� �޸� ����
            tot += ar[r][c];
    return tot;
}

int sum2d_2(int ar[][COLS], int row)
{
    int r, c, tot = 0;
    for (r = 0; r < row; r++)
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];
    return tot;
}

int sum2d_3(int* ar, int row, int col)  // row col�� ������ �Ѱ��༭ symbolic constant�� �ʿ� ���� �����Ҵ� ���
{
    int r, c, tot = 0;
    for (r = 0; r < row; r++)
        for (c = 0; c < col; c++)
            tot += *(ar + c + col * r);  // ar[c + col * r]
    return tot;
}

/*
 In higher dimensions, deep running tenser flow
 you may omit the value in the left-most bracket

 int my_function(int ar[][3][5][8], int rows); �Ϲ����� ���
 int my_function(int (*ar)[][3][5][8], int rows);
*/