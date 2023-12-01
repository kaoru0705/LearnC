/* 중요한 프로젝트는 책꽂이를 해라*/
/* Variable_lenth Arrays (VLAs) 변수로 길이를 정할 수 있는 배열 */
/* https://www.onlinegdb.com/online_c_compiler */
#define _CRT_SECURE_NO_WARNINGS
#define ROWS 3
#define COLS 4

//- 가변 길이 배열 : compile time에 상수만으로 길이를 정할 수 있는 게 아니라 런타임에 scanf로 변수를 입력받아서 길이를 정하는 배열,
// 배열의 길이를 컴파일 타임이 아니라 런타임에 정한다는 의미 * 단, 한 번 길이가 정해진 배열의 길이를 다시 변경하는 건 문법상 불가능
//- 비주얼 스튜디오에서는 지원하지 않는다 * 동적할당 메모리를 더 많이 사용하기에 VLAs 의 기능은 많이 쓰이지 않는다

// 단점 : VLAs 한번 길이가 결정되면 바꿀 수 없다.
// 메모리 동적할당에선 길이가 바뀐다기보다 길이가 바뀐 메모리를 재할당 다시 받아와서 마치 배열의 길이가 바뀐 것처럼 사용법이 따로 있다.
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

int sum2d_4(int row, int col, int ar[row][col]) {  // 매개변수에서 배열 선언 시 VLAs 활용 방식, macro로 row col 선언하지 않고 완결된 형식 매개변수만으로 잘 정리됨
    int r, c, tot = 0;
    for (r = 0; r < row; r++)
        for (c = 0; c < col; c++)  // [c]차원이 안 쪽으로 도는 게 좋다 메모리 순서
            tot += ar[r][c];
    return tot;
}