/* 중요한 프로젝트는 책꽂이를 해라*/
/* 두 개의 포인터로 배열을 함수에게 전달해주는 방법 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double average(double*, double*);

int main()
{
    double arr1[5] = { 10, 13, 12, 7, 8 };

    printf("Avg = %f\n", average(arr1, arr1 + 5));  // 배열이지만 포인터로 사용되기 때문에 arr1 + 5 가능

    return 0;
}

// 첫 번째 원소의 주소와 마지막 원소 주소의 다음 주소를 넣어야 정상 작동하는 함수
double average(double* start, double* end)
// 일반적으로 앞강의에 쓰던 방식을 많이 씀 허나 c++에서 iterator를 배우는 데 좋다.
{
    int count = end - start;  // start가 while문 안에서 계속 변화하기에 미리 배열의 개수를 구해놓는다 5 * 8 이 나오지 않는다. ref 10.3
    double avg = 0.0;
    while (start < end) {
        avg += *start++; // ++ > *
        //count++; // while문 안에서 count하는 게 부담스러울 수 있다.
    }
    avg /= (double)count;

    return avg;
}