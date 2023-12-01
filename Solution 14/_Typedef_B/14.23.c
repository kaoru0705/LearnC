/* 복잡한 선언을 이해할 때 typedef를 어떻게 사용할 수 있는지 */
#define _CRT_SECURE_NO_WANRINGS

#include <stdio.h>

/*
    "One good way to synthesize declaration is  복잡한 선언을 이해할 때 typedef로 잘게 쪼개면 편하다
     in small steps with typedef, ..."
    - K&R book Chapter 5.12
*/

/* Complicated Function Declarations */

char char3[3] = { 'A', 'B', 'C' };

char* ptrarray[3];  // 포인터 배열
char(*arrayptr)[3]; // 배열 포인터

char(*complicated_function1())[3]  // Function returns pointer to char[3] 다음강의를 봐야 해석 가능 char (*)[3]
{
    return &char3;  // returns to a pointer to char[3]
}

typedef char(*FRPTC3())[3];  // Function returns pointer to char[3]
typedef char(*(*PTFRPTC3)())[3];    // Function pointer to function returns poitner to char[3]

char(*(*fptr1)())[3] = complicated_function1; // 이렇게 할 걸 밑처럼 간결하게 할 수 있다.

FRPTC3* fptr2 = complicated_function1; //
PTFRPTC3 fptr3 = complicated_function1;

/* Use typedef to make declarations simpler */

typedef char c3[3]; // 이 용법은 char [3]개짜리 배열을 c3라는 이름의 자료형으로 선언 [3]이 왜 뒤에 가 있나? 용법이 그렇다.

c3* complicated_function2() // 위에서 char[3]의 포인터를 반환하는 함수를 이렇게 줄일 수 있다. 훨씬 쉬워짐
{
    return &char3;  // Returns a pointer to char[3]
}

int main(void)
{
    char(*ret_val)[3] = fptr1();

    printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);

    c3* my_c3 = fptr2(); // 전자에 비해 직관적 배열 포인터는 사실 2차원 배열이상일 때 효율적

    printf("%c %c %c\n", (*my_c3)[0], (*my_c3)[1], (*my_c3)[2]); // char3[0], char3[1], char3[2]

    return 0;
}