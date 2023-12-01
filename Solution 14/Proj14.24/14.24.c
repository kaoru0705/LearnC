/* 복잡한 선언을 해석하는 요령 */
#define _CRT_SECURE_NO_WANRINGS

#include <stdio.h>

/* 실무에서는 복잡한 선언을 해석하는 일이 드물 것이다. typedef로 이해하기 쉬운 형태로 정리한다. */

int temp(int a)
{
    return 0;
}

int (*g(int a))(int)
{
    return temp;
}

int main(void)
{
    /*
        *  indicates a pointer
        () indicates a function 혹은 우선순위 표현
        [] indicates an array bracket
    */

    /** Deciphering Complex Declarations (KNK 18.4)
        - Always read declarations from the inside out 안쪽에서부터 바깥쪽으로 읽어라.
        - When there's a choice, always favor [] and () over *(asterisk)
    */

    int* ap[10];       // Identifier ap is an array of pointers

    typedef int* pint;
    pint ap2[10]; // pint가 뭔진 모르지만 그거의 10개짜리 배열이구나

    float* fp(float);  // fp is a function that returns a pointer

    typedef float* pfloat;
    pfloat fp2(float);

    void(*pf)(int);
    /*
        void (*pf)(int);
              1               1. pointer to
                   2          2. function with int argument
        3                     3. returning void
    */

    int* (*x[10])(void);
    /*
        int* (*x[10])(void); // 포인터 배열 vs 배열 포인터 여긴 포인터 배열
                 1            1. array of
              2               2. pointers to
                      3       3. functions with no arguments
        4                     4. returning pointer to int
    */

    /* A function can't return an array */

    // int f(int)[];  // Wrong

    /* BUT it can return a pointer to an array */

    int(*f(int))[]; //int를 입력받고 포인터를 반환하는 함수 f, 어떤 포인터? int형 []에 대한

    /* A function can't return a function */  // C언어에서는 불가능하지만 C++등 다른 언어에서는 가능(단, 가능한 경우에도 내부적으로는 함수포인터로 구현된다)

    // int g(int)(int);  // Wrong

    /* BUT it can return a pointer to a function */

    int (*g(int))(int);

    /* An array of functions aren't possible */

    // int a[10](int);  // Wrong

    /* BUT an array of function pointers are possible */

    int (*x2[10])(int); // 10개짜리 배열, 포인터의, int를 입력하고 int를 출력하는 함수에 대한

    /* Using typedef to simplify declarations */

    typedef int FCN(int);
    typedef FCN* FCN_PTR;
    typedef FCN_PTR FCN_PTR_ARRAY[10]; //FCN_PTR이 10개 있는 거
    FCN_PTR_ARRAY x3;
    //(int) (*x3[10])(int)

    /* More examples */

    int board[6][4];        // An array of arrays of int
    int** ptr;

    int* risks[10];         // A 10-element array of pointers to int
    int(*rusk)[10];         // A pointer to an array of 10 ints

    int* off[3][4];         // A 3x4 array of pointers to int
    int(*uff)[3][4];        // A pointer to a 3x4 array of ints
    int(*uof[3])[4];        // A 3-element array of pointers to 4-element arrays of int

    char* fump(int);        // function returning pointer to char
    char (*frump)(int);     // pointer to a function that returns type char
    char (*flump[3])(int);  // 3 arrays of pointers to functions that return type char

    typedef int arr5[5];    // 5 arrays of int
    typedef arr5* p_arr5;   // pointer to 5 arrays of int
    typedef p_arr5 arrp10[10]; // 10 arrays of pointer to 5 arrays of int

    int(*(*arr6)[10])[5]; // pointer to 10 arrays of pointer to 5 arrays of int

    arr5 togs;
    p_arr5 p2;
    arrp10 arp;
    
    arr6 = &arp;

    return 0;
}