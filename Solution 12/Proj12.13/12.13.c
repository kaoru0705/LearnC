/* Dynamic Storage Allocation 메모리 동적 할당 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// malloc(), free()

/*
	- 동적Dynamic: 컴파일 타임이 아닌 런 타임을 의미

	동적할당은 포인터만 가져오고 인식자(변수의 이름)가 없으니 저장공간 분류에 못 들어감

	- 동적 할당된 메모리는 프로그래머가 명시적으로 반환하거나 프로그램 종료 시 운영체제가 강제로 반환시킨다
		*과거에는 동적 할당 메모리를 반환하지 않은 채 프로그램을 종료하면 오류를 발생시켰다
		*동적 할당된 메모리를 꼬박꼬박 반환하는 습관이 중요하다
	
	필요한 메모리의 크기를 미리 알 수 없는 경우
	== 컴파일에 알 수 없고 런 타임이 돼봐야만 알 수 있는 경우 동적 메모리 할당을 사용하는 것이 일반적
		*스택은 자유공간으로 밀고 내려가도 크기가 제한이 있다. 물론 스택의 크기는 컴파일 옵션을 통해 확장할 수 있지만 한계가 있는 반면, 힙의 크기는 가상주소 공간 기술을 이용해 메모리를 충분히 이용할 수 있다
	memory allocation = malloc
*/
int main(void)
{
    float x;
    char str[] = "Dancing with a Star";

    int arr[100];

    /*
        malloc() returns a void type pointer,  parameter size_t = unsigned int
        void* : generic pointer 특별한 자료형을 가진 게 아니고 순수한 주소이기에 generic (void*는 자료형의 크기를 몰라서 포인터 연산을 할 수 없기 때문에 형변환 후에야 포인터 연산으로 배열처럼 사용할 수 있다 복습 9.12 int *ptr = &a; *ptr = 8; 포인터 변수가 int형이어야만 간접접근으로 int크기만큼 읽어서 8을 대입할 수 있다.)
        free() deallocates the memory
    */

    double* ptr = NULL;

    ptr = (double*)malloc(30 * sizeof(double));  //  parameter로 사이즈만 적으면 된다. 몇 바이트를 사용할지, 운영체제가 가지고 있는 메모리 중에서 다른 프로그램이 쓰고 있는 메모리까지 포함해서 남아있는 메모리 중에서 heap 공간에다가 요청한 크기만큼 메모리를 배정해줌 그리고 할당된 메모리 공간의 첫 번째 주소를 반환한다 
    // void type 주소 즉 순수한 주소를 운영체제가 리턴해주므로 casting을 해줘야 한다.
    // 형변환을 해서 특정한 자료형의 배열인 것처럼 사용할 수 있다. 대부분 배열처럼 사용함
    
    //변수 ptr은 자동변수이기 때문에 스코프를 벗어나면 사라질 수 있으나 동적 할당된 메모리 공간은 해제되기 전까지 메모리에 계속 남아 있는다(메모리는 있으나 접근할 수 있는 주소를 모르는 문제 발생 가능) ptr과 동적할당받은 메모리를 동일시 하면 안 됨
    // ptr은 주소를 받은 쪽지 같은 것

    if (ptr == NULL)  // 실무에서는 종종 malloc()함수가 너무 큰 메모리 공간을 요구하거나 프로그램을 너무 띄워서 운영체제가 연속된 메모리 공간을 줄 수 없을 때(메모리 공간이 파편화되어 있을 떄) NULL 반환
    { 
        puts("Memory allocation failed");

        /*
            exit(EXIT_FAILURE) is similar to return 1 In main()
            exit(EXIT_SUCCESS) is similar to return 0 In main()
            OS에게 return 0 return 1은 메인함수에서만 할 수 있는 건데  exit()를 쓰면 어떤 함수에서도 강제로 종료할 수 있다.
        */

        exit(EXIT_FAILURE);  // 메모리 할당이 불가능한 경우는 아주 심각해서 프로그램을 더 이상 진행할 수 없는 경우가 많으므로 프로그램을 강제로 종료시킨다(단, 어떤 경우에도 프로그램이 돌아야 하는 웹서버 같은 경우에는 오류 처리 문법을 사용한다)
        // 실제프로그램에선 이렇게 나가는 경우보단 디버깅할 때 많이 쓴다
    }

    printf("Before free %p\n", ptr);

    free(ptr);  // no action occurs when ptr is NULL

    printf("After free %p\n", ptr); // 값이 같다. 친구가 이사했는데 이사 전 주소를 아직도 갖고 있음

    ptr = NULL;  // 해당 주소가 더 이상 의미가 없음을 명시적으로 표현하는 게 안전하다

    /* Dynamically Allocated Array 길이가 변하는 배열처럼 */

    int n = 5;
    // ...(n의 값을 바꾸는 로직) ex)인터넷에서 n을 받는다든지 파일의 크기가 매번 바뀐다든지
    ptr = (double*)malloc(n * sizeof(double));  // 인수에 expression 사용(변수 n은 런타임에 확정되는 값이지만 상관없다)

    if (ptr != NULL)
    {
        for (int i = 0; i < n; ++i)
            printf("%f ", ptr[i]);  // malloc()함수를 통해 동적 할당된 메모리 공간은 자동으로 0으로 초기화되지 않는다
        printf("\n");

        for (int i = 0; i < n; ++i)
            *(ptr + i) = (double)i;

        for (int i = 0; i < n; ++i)
            printf("%f ", ptr[i]);
        printf("\n");
    }

    free(ptr);
    ptr = NULL;

    /*
        Comparison to VLA

        VLA
        - not supported by VS compilers
        - automatic duration, cannot be resized
        - limited by stack size(when compiler places VLA in stack segment)

          동적할당 메모리는 힙에 계속 존재한다 free를 요청할 때까지
          동적할당을 이용한 배열은 다른 사이즈의 메모리를 다시 받아오는 방식으로 사이즈를 바꿀 수 있다
          힙같은 경우는 크기가 크다 대신 힙에 어디에 있는지 찾기가 힘들다.
    */

    // 메모리를 할당받고 반납하는 과정이 번거로울 수 있다. 허나 다른 언어에서는 이과정을 언어에서 처리해준다.
}