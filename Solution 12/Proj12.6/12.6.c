/* Register 레지스터 변수 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 크게 보면 자동변수와 묶일 수도 있음 메모리에서의 위치 레지스터(또는 스택)
// register 키워드를 double 타입에 붙일 경우 컴파일러에 따라서 컴파일 자체가 안 되는 경우도 있다
void temp(register int r)
{
    // do something with r
}

int main()
{
    register int r; // 가급적 레지스터에 둬주세요 요청, 거의 안 씀 임베디드, 하드웨어에서는 사용할 수도 있다.
    r = 123;

    //printf("%p\n", &r);
    //int* ptr = &r;  // Error: '&' on register variable 메모리가 아니라 레지스터에 저장된 변수의 주소는 가져올 수 없다 레지스터에 들어갈지는 모르지만 아무튼 주소는 못 가져옴 위도 마찬가지
    // double은 컴파일러에 따라서 안 될 수도 있다.

    return 0;
}