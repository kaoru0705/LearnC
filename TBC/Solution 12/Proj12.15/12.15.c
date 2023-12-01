/* 동적 할당 메모리를 배열처럼 사용하기 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*
        One variable 근데 변수하나를 위해 동적할당을 쓰진 않겠지
    */

    /*int* ptr = NULL;

    ptr = (int*)malloc(sizeof(int) * 1);
    if (!ptr) exit(1);

    *ptr = 1024 * 3;
    printf("%d\n", *ptr);

    free(ptr);
    ptr = NULL;*/


    /*
        1D array
    */

    //int n = 3;
    //int* ptr = (int*)malloc(sizeof(int) * n);  // 실용적인 측면에서 일반적으로 배열은 스택에 저장되므로 힙에 저장되는 동적할당 메모리에 비해 사용할 수 있는 공간이 적다. 따라서 연속하는 큰 메모리가 필요한 경우 동적할당 메모리를 배열처럼 사용한다
    //if (!ptr) exit(1);  //특히 x64일 경우는 사용할 수 있는 메모리가 더 크다.

    //ptr[0] = 123;
    //*(ptr + 1) = 456; // 형변환을 했기 때문에 포인터 연산도 가능하다.
    //*(ptr + 2) = 789;

    //free(ptr);
    //ptr = NULL;

    /* 이젠 다차원 배열을 ㅈㄴ 많이 쓴다. 딥러닝 그래픽스 로보틱스 4차원 5차원을 넘어간다. */

    /*
        2D array
    */

    //int row = 3, col = 2;
    //int(*ptr)[2] = (int(*)[2])malloc(sizeof(int) * row * col);  // 배열 포인터 index를 2개 가지고 있는 배열, https://blockdmask.tistory.com/56 배열타입을 가리키는 하나의 포인터
    //// 실용적인 측면에서 동적할당 쓰는 게 당연히 VLA쓰는 것보다 편하다. 근데 여기서 배열 개수로 상수를 사용한다면 동적할당 메모리를 사용하는 의미가 거의 없다.
    //// 그래서 실용적인 측면에서 밑에 예시처럼 1차원 배열을 2차원 배열처럼 3차원배열처럼 쓴다. 어차피 결국 우리가 사용하는 메모리 구조는 1차원이기 때문에 상관없다.
    ////int(*ptr)[col] = (int(*)[col]malloc(sizeof(int) * row * col));  // VLA
    //if (!ptr) exit(1);

    //for (int r = 0; r < row; r++)
    //    for (int c = 0; c < col; c++)
    //        ptr[r][c] = c + r * col;

    //for (int r = 0; r < row; r++)
    //{
    //    for (int c = 0; c < col; c++)
    //        printf("%d", ptr[r][c]);
    //    printf("\n");
    //}

    /*
        Using 1D arrays as 2D arrays

        row = 3, col = 2

        (r, c)

        2D
        (0, 0) (0, 1)
        (1, 0) (1, 1)
        (2, 0) (2, 1)

        1D
        (0, 0) (0, 1) (1, 0) (1, 1) (2, 0) (2, 1)
        0      1      2      3      4      5      = c + col * r
    */

    /*int row = 3, col = 2;
    int* ptr = (int*)malloc(row * col * sizeof(int));
    if (!ptr) exit(1);

    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            ptr[c + col * r] = c + col * r;

    for (int r = 0; r < row; r++) 
    {
        for (int c = 0; c < col; c++)
            printf("%d ", *(ptr + c + col * r));
        printf("\n");
    }*/

    /*
        Using 1D arrays as 3D arrays

        row = 3, col = 2, depth = 2

        (r, c, d)

        3D
        -------------------
        (0, 0, 0) (0, 1, 0)
        (1, 0, 0) (1, 1, 0)
        (2, 0, 0) (2, 1, 0)
        -------------------
        (0, 0, 1) (0, 1, 1)
        (1, 0, 1) (1, 1, 1)
        (2, 0, 1) (2, 1, 1)
        -------------------

        1D
        (0, 0, 0) (0, 1, 0) (1, 0, 0) (1, 1, 0) (2, 0, 0) (2, 1, 0) (0, 0, 1) (0, 1, 1) (1, 0, 1) (1, 1, 1)
        0         1         2         3         4         5         6         7         8         9

        index = c + col * r + (col * row) * d
        (1, 1, 1) index = 1 + 2 * 1 + (2 * 3) * 1 = 9

        // 4D:
        row, col, depth, height(이건 걍 이름을 붙인 것)
        (r, c, d, h)
        index = c + col * r + (col * row) * d + (row * col * depth) * h
     */

    int row = 3, col = 2, depth = 2;
    int* ptr = (int*)malloc(row * col * depth * sizeof(int));
    if (!ptr) exit(1);

    for (int d = 0; d < depth; d++)
        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++)
                ptr[c + col * r + (col * row) * d] = c + col * r + (col * row) * d; // 1차원적으로 증가하면서 접근한다 그러면 ptr에다 1씩 더해가면서 빠르게 접근하는 방법도 있다.

    /*
        매번 c + col * r + (col * row) * d 이걸 할 순 없으니 실제로는 이렇게 함수 만들어서 쓴다.
        int idx2(int c, int r) inline을 써서 가속하는 경우도 있는데 최근 코드에서는 안 그럼 예전 코드는 아주 빈번하게 사용되는 경우 그랬다.
        {
            return c + col * r;
        }

        int idx3(int c, int r, int d)
        {
            static const int cr = col * row; //연산 시간이 아깝다. static으로 ㅋㅋ 
            return c + col * r + cr * d;
        }
    */

    for (int d = 0; d < depth; d++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
                printf("%d ", *(ptr + c + col * r + (col * row) * d));
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}