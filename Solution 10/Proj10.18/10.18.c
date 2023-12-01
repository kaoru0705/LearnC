/* 중요한 프로젝트는 책꽂이를 해라*/
/* Compound Literals 복합 리터럴과 배열 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//이름이 없는 literal을 넣는 것 뿐만 아니라 이름이 없는 무언가를 사용하는 것이 최근에 다양한 프로그래밍 문법으로 나타나고 있다. ramda함수

#define COLS 4

int sum_1d(int arr[], int n);
int sum_2d(int arr[][COLS], int rows);

int main() {

    int a = 1; // literal의 값을 대입
    3;  // Literals are constants that aren't symbolic(리터럴은 이름이 없는 상수)
    3.14F;
    int b[2] = { 3, 4 };// 이건 int가 두 개니까 compound(복합) literal이 아니라 multiple literal 아니냐? 의문 원래 compound literal은 다른 자료형끼리도 묶을 수 있다. 구조체
    (int[2]){3, 4};    // compound literal(배열을 복합 리터럴로 표현한 것. 바로 윗줄과 달리 이름이 없다)
    // 여기서는 같은 자료형을 묶어서 배열 literal로 사용

    //int c[2] = (int[2]) { 3, 4 };  // Error(복합 리터럴로 배열 초기화하는 건 불가능) 될만 한 것 같은데 안 됨 

    int arr1[2] = { 1, 2 };
    int arr2[2][COLS] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 } };
    &arr2[0];
    printf("%d\n", sum_1d(arr1, 2));
    printf("%d\n", sum_2d(arr2, 2));
    printf("\n");

    // 배열 선언을 하지 않고 복합 리터럴을 이용해 배열을 함수 인수로 바로 사용할 수 있다, 베열의 이름을 포인터처럼 집어 넣은 형태가 아니라 배열을 literal처럼 바로 집어 넣을 수 있음
    printf("%d\n", sum_1d((int[2]) { 1, 2, }, 2)); // 간단한 경우, 배열의 원소를 직접 집어넣는 경우 하드 코딩할 때 경우에 따라서는 간결하게 사용할 수 있다.
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