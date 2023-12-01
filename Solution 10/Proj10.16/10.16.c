/* 중요한 프로젝트는 책꽂이를 해라*/
/* 다차원 배열(Multidimensional Arrays)을 함수에게 전달해주는 방법 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ROWS 3 //전처리기 symbolic constant macro
#define COLS 4

int sum2d_1(int ar[ROWS][COLS]); // 컴파일러는 매개변수로 사용되는 2차원 배열의 첫 번째 차원 원소 개수는 무시된다 넣어주더라도 내부적으로는 사용할 수 없음 정의한 함수로부터 전달이 안 된다. like 10.7 배열을 사용할 땐 symbolic constant, consant를 사용하는 경우가 대부분
int sum2d_2(int ar[][COLS], int row); // 또는 다른 parameter로 접근 int row 이유: 배열의 이름은 변수가 아니라 첫 원소의 주소기 때문에 포인터로 변환된다 문법이 그렇게 되어있다고 ㅋㅋ 동적할당에서는 어차피 일차원 포인터를 다차원 배열처럼 쓰기 때문에 괜찮다.
// 단, 두 번째 차원 원소 개수는 입력해야 한다)  
//int sum2d_2(int [][COLS], int row);  // 프로토타입에서는 매개변수 이름 생략 가능
//int sum2d_2(int (*ar)[COLS], int row);  // int 10.15 ar is a SINGLE pointer to the array of COLS ints 개인적으로 이렇게 복잡하게 쓰는 건 선호하지 않음
int sum2d_3(int* ar, int row, int col);  // 다차원 배열을 다룰 때 주로 사용하는 방식 동적할 때 사용하는 방법 특히 deep running, c++에서는 더 쉽게 할 수 있다.
//int sum2d_3(int*, int, int);

int main()
{
    int data[ROWS][COLS] = {    // ROWS COLS 매크로이기 때문에 컴파일 할때 이미 개수 결정, data의 총 사용하는 메모리는 컴파일할 때 결정 동적할당 중요
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 0, 1, 2 }
    };

    printf("%d\n", data[2][3]);

    int* ptr = &data[0][0];
    printf("%d\n", *(ptr + 3 + COLS * 2));  // 연속된 데이터(1차원 array)를 다차원인 배열(2차월 array)인 것처럼 다루는 방법, 동적할당 메모리를 배열처럼 사용하는 방법에서 다시 알려줌

    printf("Sum of all elements = %d\n", sum2d_1(data));
    printf("Sum of all elements = %d\n", sum2d_2(data, ROWS));
    printf("Sum of all elements = %d\n", sum2d_3(&data[0][0], ROWS, COLS));

    return 0;
}

int sum2d_1(int ar[ROWS][COLS]) // 배열자체를 parameter로 쓰겠냐 포인터지 in 10.7,
{
    int r, c, tot = 0;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)  // [c]차원이 안 쪽으로 도는 게 좋다 메모리 순서
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

int sum2d_3(int* ar, int row, int col)  // row col을 변수로 넘겨줘서 symbolic constant가 필요 없음 동적할당 방법
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

 int my_function(int ar[][3][5][8], int rows); 일반적인 용법
 int my_function(int (*ar)[][3][5][8], int rows);
*/