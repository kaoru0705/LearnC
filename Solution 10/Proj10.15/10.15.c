/* 중요한 프로젝트는 책꽂이를 해라*/
/* 포인터의 호환성 Compatibility */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{

    /* Pointer Compatibility */

    //int n = 5;
    //double x;
    //x = n;          // no error(promotion)
    //int* p1 = &n;
    //double* pd = &x;
    ////pd = p1;  // warning(incompatible type) compile에서 warning을 error 바꿀 수 있다.
    ////pd = (double*) p1;  // 작동하지만 이렇게 사용할 경우 주석으로 상황을 설명하는 게 좋다 허나 코딩실력이 의심된다.
    //// in c++ dynamic casting static casting로 포인터 형변환하는 경우가 있음 그래도 권장하진 않음

    //// 복잡한 포인터를 사용하는 것은 본 적이 없다. 연습문제나 그럴 수 있는 거다. 사람이 쉽게 이해하는 게 중요함
    //// 오히려 복잡한 포인터를 피하려고 회유함

    //int* pt;
    //int(*pa)[3];  // int형 3개짜리 원소를 가진 배열에 대한 포인터 변수 pa를 선언하는 코드(배열 선언이 아님에 주의)
    //int ar1[2][3] = { 3, };
    //int ar2[3][2] = { 7, };
    //int** p2;  // a pointer to a pointer

    //pt = &ar1[0][0];  // pointer-to-int 1차원 배열로도 다차원 배열 접근 가능 10.5
    ////pt = ar1[0];    // pointer-to-int(윗줄과 같은 의미)
    ////pt = ar1;       // warning(error. 이 경우 2차원 배열의 배열명은 int(*)[3] 타입이다)
    //// 2차원배열(2차원 배열을 대표하는 주소 ar1)이라 그냥포인터에는 담을 수 없다. 이렇게까지 compatible하진 않다.

    //// 포인터를 이용해 다차원 배열의 모든 원소에 접근할 수 있다(다차원 배열이라도 메모리는 1차원으로 나열되어 있기 때문)
    //for (int i = 0; i < 6; i++) // 다만 포인터pt만 가지고는 원소가 몇 개인지 알 수 없다. 6?
    //    printf("%d ", *(pt + i)); // or printf("%d ", pt[i]);

    //pa = ar1;         // pointer-to-int[3] pa = 원소가 3개짜리인 배열의 포인터, ar1 = 원소가 3개짜리인 배열의 배열 그래서 가능
    ////pa = ar2;       // warning or error arr2[3][2] 원소가 2개짜리인 배열의 포인터
    //p2 = &pt;         // pointer-to-int *
    //*p2 = ar2[0];     // pointer-to-int
    ////p2 = ar2;       // warning C4047: '=': 'int **' differs in levels of indirection from 'int (*)[2]'
    //
    ////if ((p2 != ar2) && (pt == *ar2)) // 배열명은 별도의 데이터 공간을 갖고 있는 게 아니다. 
    ////    printf("You're right!\n");
                    
                    
    //Notes
    // pointer to ??? dereferencing *을 했을 때 ???가 나와야 됨
    // - p2: pointer to pointer to int == p2 = &pt, pt = &ar2[0][0] = ar2[0] = pointer to int
    // - ar2: a pointer to array-of-two-ints 원소(int)가 2개짜리인 배열에 대한 포인터(주소), *ar2 = ar2[0]
    // - ar2[0]: pointer-to-int 원소에 대한 포인터 *ar2[0] = ar2[0][0]

    /* Pointer and const */

    //int x = 20;
    //const int y = 23;
    //int* p1 = &x;
    //const int* p2 = &y;			// *p2 = 123; 못하게함. indirection하고 값 변경 안됨 이 p2의 const 때문에 값을 못바꾸는 것 
    ////즉 p2 자체를 못바꾸는게 아니라 indirection시 못바꾸게 하는것.
    //const int** pp2 = &p1;
    ////p1 = p2;  // warning (error)  - 대입 가능(쓰지마라!) *p1 = 7; printf("%d", y);

    ////*p2 = 123; // error in 10.10 const int* p2 = &y 때문
    //p2 = p1; //이건 가능. p2 자체가 못바꾸게하고싶다면?? cont int* const p2 로 선언해줘야함
    //    
    //int x2 = 30;
    //int* p3 = &x2;
    //*pp2 = p3;		// 이중포인터에선 const int** pp2 에서 pp2의 indirection 바꿀수 있음. **p2 = 5; 이걸 못 바꿈 막고 싶으면 int* const * pp2 = &p1; const int** dereferncing 2번 한 걸 막겠다.
    //pp2 = &p1; // int** const pp2 = &p1;

    /* const 이런식으로 그냥 아예 쓰지마라 compiler가 허용해 주든 해주지 않든*/
    //{
    //    const int** pp2;
    //    int* p1;
    //    const int n = 13;
    //    pp2 = &p1;		// const?
    //    *pp2 = &n;		// p1 = &n, sets p1 to point at n
    //    *p1 = 10;		// change n
    //}

    /* c const and c++ const */
    //{
    //    const int y;
    //    const int* p2 = &y;
    //    int* p1;
    //    p1 = p2; //warning (error in cpp) cpp는 const 더 엄격하게 막음
    //    *p1 = 5;
    //}

	return 0;
}