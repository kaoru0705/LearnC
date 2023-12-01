/* calloc(), realloc() */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 10;

    int* ptr = NULL;

    //ptr = (int*)malloc(sizeof(int) * n);  // 메모리를 초기화해주지 않는다(0이 아닌 다른 값들로 초기화를 할 의도가 있는 경우 오히려 이 방식이 효율적이다)
    ptr = (int*)calloc(n, sizeof(int));  // contiguous(연속하는) allocation 씨얼록 칼록: malloc() 함수와 매개변수가 다르다. 게다가 할당한 메모리를 0으로 초기화해준다 size만큼의 연속하는 메모리가 n개 있다. 내부적으로는 어차피 곱해서 처리하겠지 
    if (!ptr) exit(1);

    for (int i = 0; i < n; ++i)
        printf("%d ", ptr[i]);
    printf("\n");

    /*
        realloc() KNK p. 422k real allocation 다시 할당 100명 분이 부족하면 200개짜리 메모리를 할당받고 100명분을 복사하고 100명치 메모리를 반납하는 절차를 한번에 처리한다.
        - doesn't initialize the bytes added 추가된 바이트는 초기화되지 않음
        - returns NULL if can't enlarge the memory block 더 이상 추가해줄 수 없다면 NULL
        - If first argument is NULL, it behaves like malloc()
        - if second argument is 0, it frees the memory block
    */

    for (int i = 0; i < n; ++i)
        ptr[i] = i + 1;

    n = 20;

    int* ptr2 = NULL;
    ptr2 = (int*)realloc(ptr, n * sizeof(int));
    //ptr = (int*)realloc(ptr, n * sizeof(int));  // 실무에서는 이렇게 사용해서 마치 포인터가 가리키는 메모리가 늘어난 것처럼 사용할 수도 있다.  이렇게 사용할 경우 아래에서 if (!ptr2) else ptr = NULL을 입력하면 안 된다

    printf("%p %p\n", ptr, ptr2); // 같을 수도 있지만 보통 다르게 나온다. 마침 메모리공간이 더 필요한데 바로 뒤에가 비어있다면 같을 수 있다. 

    printf("%d\n", ptr[0]);

    if (!ptr2)
        exit(1);
    else
        ptr = NULL;

    for (int i = 0; i < n; ++i)
        printf("%d ", ptr2[i]);  // copies data
    printf("\n");

    free(ptr2);

    return 0;
}