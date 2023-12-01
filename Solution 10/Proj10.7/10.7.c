/* 중요한 프로젝트는 책꽂이를 해라*/
/* 배열을 함수에게 전달해주는 방법 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 무수히 많은 배열의 데이터를 많은 함수에서 사용한다면? 주소를 써야된다.
double average(double array[], int n);
//double average(double *arr, int n);  // 위 코드와 같음 결국 포인터를 많이씀 배열로 표시해봤자 포인터니
//double average(double *, int);  // 위 코드와 같음(일반적으로 매개변수가 이와 같이 선언되어 있으면 배열을 전달받는 함수로 판단한다)
//double average(double [], int);  // 위 코드와 같음

int main()
{
    double arr1[5] = { 10, 13, 12, 7, 8 };
    //double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
    double arr2[3] = {1.8, -0.2, 6.3}; //size is different

    printf("Address = %p\n", arr1);
    printf("Size = %zd\n", sizeof(arr1));
    printf("Address = %p\n", arr2);
    printf("Size = %zd\n", sizeof(arr2));
    printf("Avg = %f\n", average(arr1, sizeof(arr1) / sizeof(arr1[0])));
    printf("Avg = %f\n", average(arr2, sizeof(arr2) / sizeof(arr2[0])));

	return 0;
}

//double arerage(double* data_array) {  // 아래 코드와 같음
double average(double data_array[], int n) {  // 아래 코드와 같음(배열을 인수로 전달 받는다는 것을 명확히하는 목적으로 포인터 대신 이렇게 표현할 수 있다)
//double average(double data_array[5], int n) {// 배열은 특성상 데이터가 아주 많기 때문에 통째로 복사해서 받는 게 아니라 포인터로 받는다. 5는 의미 없음
    // 보다 일반적인 함수로 사용하기 위해 매개변수 n을 통해 배열의 크기를 따로 전달 받는다 매개변수화
    printf("Size = %zd in function average\n", sizeof(data_array));  // 출력값 : 4, 8(포인터 변수의 크기가 출력된다. 매개변수로 배열을 선언하면 크기와 상관없이 인수로 입력한 배열의 주소를 전달받기 때문이다.)
    double avg = 0.0;
    for (int i = 0; i < n; ++i) {
        avg += data_array[i];
    }
    avg /= (double)n;
    printf("%p ", data_array);
    printf("%p\n", ++data_array); // data_array가 배열이었다면 불가능
    // in c++에서는 배열보다 동적할당을 많이 사용하고 동적할당은 포인터로 쓴다.

    return avg;
}