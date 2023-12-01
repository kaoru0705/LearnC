/* 중요한 프로젝트는 책꽂이를 해라*/
/* 포인터의 배열과 2차원 배열 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 배열과 포인터는 비슷하다. 그러나 주의할 점이 있다. 동적할당할 때 실수할 수 있는 부분
// 원소(element)
int main()
{
    /* Two of 1D arrays */
    //int arr0[3] = { 1, 2, 3 };
    //int arr1[3] = { 4, 5, 6 };

    //int* parr[2] = { arr[0], arr[1] };  // an array of pointers int* pointer가 담길 수 있는 메모리공간을 두 개를 확보한 배열, * > []
    ////사실상 * parr[2] = {parr1* = arr = &arr0[0], parr2*}
    ////arr[0] 다차원 배열에서 첫 번째 index만 포함된 배열, 다음 차원에 대한 첫 번째 원소의 포인터(메모리의 주소)
    //
    //for (int j = 0 ; j < 2; ++j) { // arr0 arr1이라면 for문을 두 개를 써야 되나 parr을 이용해서 이중 for문으로 하나로 구현함 마치 이중배열처럼
    //    for (int i = 0; i < 3; ++i)
    //        printf("%d(==%d, %d, %d) ", parr[j][i], *(parr[j] + i), *(*(parr + j) + i), (*(parr + j))[i]);
    //    // parr[j]은 배열이고 배열의 담겨있는 게 포인터니 배열의 몇번째 원소에다 i 더하고 indirection *(parr[j] + i) 가능 포인터 연산
    //    // parr 배열의 이름이 포인터처럼 사용가능하므로 이중포인터처럼 사용 *(*(parr + j) + i) arr[2][3] *(*(arr + 2) + 3)
    //    // (*(parr + j))[i]) 기본적으로 parr이 배열이기 때문에 이렇게도 가능 
    //    // 과거에는 []을 이용한 접근보다 포인터 산술 연산이 조금 더 빠르다는 말이 있었으나 최근에는 이걸로 구분짓는 게 큰 의미는 없다
    //    printf("\n");
    //}
    //printf("\n");


    /* 2D arrays are arrays of 1D arrays */
    //int arr[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

    //int *parr0 = arr[0]; // arr[0] == &arr[0][0]
    //int *parr1 = arr[1];

    //printf("%zu %zu\n", sizeof arr[0], sizeof arr[1]); // 12 12

    //for (int i = 0; i < 3; ++i)
    //    printf("%d ", parr0[i]);
    //printf("\n");

    //for (int i = 0; i < 3; ++i)
    //    printf("%d ", parr1[i]);
    //printf("\n");


    /* arrays of pointers work like a 2D array */
    int arr[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

    //int* parr[2] = { arr[0], arr[1] };  // 아래와 같은 의미
    int* parr[2];   // parr 포인터를 담을 수 있는 8byte 메모리공간의 첫 번째 주소를 가라키게 된다.
    parr[0] = arr[0];
    parr[1] = arr[1];

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 3; ++i)
            printf("%d %d %d %d %d\n",
                arr[j][i], parr[j][i], *(parr[j] + i), *(*(parr + j) + i), (*(parr + j))[i]);
        //동적할당을 사용할 경우 *(*(parr + j) + i)를 많이 씀
        //이차원 배열은 컴파일러가 2차원으로 쓰고 싶어하는 걸 알지만 동적할당은 OS로부터 할당받을 때 어쨌거나 기본적으로 일차원이기 때문에
        printf("\n");
    }
    printf("\n");

    ///*
    //   Notes
    //   - parr[0] and parr[1] do not point valid memory by default 포인터의 배열의 원소는 포인터이기 때문에 쓰레기값 주의
    //   - &parr[0] != &arr[0] but parr[0] == arr[0]
    //   - &parr[0] != parr[0] but &arr[0] == arr[0]
    //*/

    //printf("%p\n", parr);
    //printf("%p\n", &parr[0]); // different with parr[0] 포인터 배열 자체의 주소, 포인터의 배열의 첫 번째 포인터 parr[0] 이놈의 주소는? parr
    //printf("%p\n", parr[0]); // 가리키고 있는 주소
    //// 배열의 이름은 첫 번째 원소의 주소
    //printf("%p\n", arr);  // 배열명 마치 첫 번째 원소의 주소인 것처럼(&arr[0]) 사용할 수 있다. 그러나 주소를 저장할 수 있는 별도의 데이터 저장 공간을 가지고 있는 게 아니라 C 문법에서 arr[0]의 주소를 사용할 수 있게 해주는 것일 뿐이다 빈면에 포인터 배열은 저장공간을 갖고 있다. 허나 parr은 당연히 안 갖고 있다.
    //printf("%p\n", &arr[0]);  // address of array name is equal to the address of the first
    //printf("%p\n", arr[0]); // arr[0]는 &arr[0][0]와 동등
    //printf("%p\n", &arr[0][0]);
    //printf("%p\n", &arr);
    //printf("%zu %zu %zu %zu\n", sizeof(&arr), sizeof(arr), sizeof(&arr[0]), sizeof(arr[0])); // 4, 24, 4, 12 or 8, 24, 8, 12

    /* Array of string of diverse lengths example */ //포인터의 배열을 사용하는 이유중 하나 문자열
    char* name[] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie" };
    //name이라는 char타입의 포인터의 배열의 원소는 A가 저장된 위치 J가 저장된 위치 ...다
    const int n = sizeof(name) / sizeof(char*); // x86 16 / 4 
    //name만 가지고는 name의 원소들이 가리키고있는 메모리공간의 사이즈를 알 수 없다. 글자 수를 알 수 없다. 반면에 aname은? ㅇㅇ
    for (int i = 0; i < n; ++i)
        printf("%s at %u\n", name[i], (unsigned)name[i]);  // Use llu in x64 build
    // Null 잊지 마라. 글자 수만큼 주소가 차이가 안 나네? 운영체제 컴파일러가 주도하는 질서
    //printf("%c\n", *name[i]); A J M C
    printf("\n");

    char aname[][15] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie", "Jafar" };

    const int an = sizeof(aname) / sizeof(char[15]); // sizeof(char[15]) size를 명확하게 알 수 있다.

    for (int i = 0; i < an; ++i) // 정해진 사이즈에 맞춰서 메모리가 배정됐다.
        printf("%s at %u\n", aname[i], (unsigned)&aname[i]);  // Use ull in x64 build
    printf("\n");

	return 0;
}