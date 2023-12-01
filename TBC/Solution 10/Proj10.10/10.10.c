/* 중요한 프로젝트는 책꽂이를 해라*/
/* const와 배열과 포인터 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 변수를 상수로 바꾸듯
int main()
{
    // type qualifiers(한정자, 자격 부여): const, volatile ...

    //const double PI = 3.14159;  // const는 자료형 좌,우에 모두 붙일 수 있고 일반 변수에게 있어 기능이 동일하다
    //double const PI = 3.14159;  // const 를 붙일 수 있는 곳에는 가능한 전부 붙여서 실수를 방지하기 ㅈㄴ많이 쓴다.
    const double PI = 3.14159;
    //PI = 2.14159;
    
    //const int arr[5] = { 1, 2, 3, 4, 5 };  // 배열에 const를 붙이면 배열의 원소의 값들을 변경할 수 없게 된다
    int arr[5] = { 1, 2, 3, 4, 5 };
    arr[1] = 123;

    const double arr2[3] = { 1.0, 2.0, 3.0 };
    //arr2[0] = 100.0;

    double* pd = arr2;  // warning C4090: 'initializing': different 'const' qualifiers pro10.10 right click project only rebuild로 다시 볼 수 있음
    //배열을 const로 선언했지만 포인터로 대입한 이후 그 포인터로 배열 원소에 접근해서 값을 변경할 수 있다 권장하지 않음(컴파일러에 막아놓은 경우도 있다)
    //const double* pd = arr2;  // 포인터 자료형 왼쪽에 const를 붙여서 dereferencing을 통한 값 수정을 제한한다(포인터 연산 등을 통해 포인터 주소값을 변경하는 건 여전히 가능 pd++;)
    //double* const pd = arr2;  // 포인터 값을 못 바꾼다. (포인터 연산 등을 통해 포인터 주소값 변경 불가)
    //const double* const pd = arr2;  // 포인터 자료형 양쪽에 const를 붙여서 dereferencing과 주소값 변경 모두 제한 의외로 많이 씀

    printf("%f %f\n", pd[2], arr2[2]);

    *pd = 3.0;  // 동일한 표현: pd[0] = 3.0; or arr2[0] = 3.0;
    pd[2] = 1024.0;  // 동일한 표현: arr2[2] = 1024.0;

    printf("%f %f\n", pd[2], arr2[2]);

    //pd++;  // allowed
    printf("%f %f\n", pd[2], arr2[2]);

    int a = 5;
    int* aptr = &a;
    aptr += 5;
    printf("%p %p\n", aptr, &a);

	return 0;
}