/* 중요한 프로젝트는 책꽂이를 해라*/
/* 배열 매개변수와 const */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_array(const int arr[], const int n) // print도 print만 하니까
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void add_value(int arr[], const int n, const int val) //이것도 마찬가지 허나 const int arr[]은 안된다. , 수학에서 많이 쓰는 함수
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] += val;
}

int sum(const int ar[], const int n) // const를 통해 전달 받은 배열 원소의 값을 수정하지 못하도록 제한. 배열 크기도 변하지 않으므로 const로 제한
{
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
        total += ar[i];
    //total += ar[i]++;  // wrong implementation const
    //const int ar[]이 아니라 int ar[]이었다면? 프로그래머는 사람이기에 실수를 한다 가정하시고 미리 배려해야한다. 가급적으로 컴파일러가 에러를 찾을 수 있도록 한다.

    return total;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 }; // 여기에 const를 붙이면? add_value에서 경고
    const int n = sizeof(arr) / sizeof(arr[0]); 

    print_array(arr, 5);
    add_value(arr, 5, 100);
    print_array(arr, 5);

    int s = sum(arr, n);
    printf("sum is %d\n", s);
    print_array(arr, 5);

	return 0;
}