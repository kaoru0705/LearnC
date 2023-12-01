/* 중요한 프로젝트는 책꽂이를 해라*/
/* 포인터 변수의 크기 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
1. 포인터 변수의 크기는 운영체제에 따라 다르다(32bit OS: 4byte(32bit), 64bit OS: 8byte(64bit))

2. 포인터에 의한 함수호출을 call by pointer 라고 하며 포인터형 매개변수를 사용하는법을 숙지하자.
*/
int main()
{
    char a = 1;
    float b = 3;
    double c = 5;

    char* ptr_a = &a;
    float* ptr_b = &b; 
    /*
    0x009AFA9C  00  .
    0x009AFA9D  00  .
    0x009AFA9E  40  @
    0x009AFA9F  40  @ 0x40400000 = 3.0f
    */
    double* ptr_c = &c;

    a = 2;  // Memory 주소를 볼 때 값이 변경되므로 찾기가 쉬워짐 float double은 값을 확인하기 힘듦 ptr_a는 a의 4byte 공간중 첫번째 주소를 갖고 있다. 4byte 공간을 대표하는 메모리 주소 하나를 갖고 있다.
    b = 4;
    c = 6;
    
    printf("%zd %zd %zd\n", sizeof(a), sizeof(b), sizeof(c));
    printf("%zd %zd %zd\n", sizeof(ptr_a), sizeof(ptr_b), sizeof(ptr_c));
    printf("%zd %zd %zd\n", sizeof(&a), sizeof(&b), sizeof(&c));
    printf("%zd %zd %zd\n", sizeof(char*), sizeof(float*), sizeof(double*));

    /*
    x86은 칩 이름에서 유래되었을 뿐, 실제로 32bit 를 사용하며, x64는 이름 그대로 64bit 체계다.
    a,b,c의 크기는 32bit, 64bit 운영체제 관계없이 각각 char: 1byte float: 4byte, double: 8byte 임을 알 수 있다.
    그렇다면 포인터의 크기는 어떨까? 32bit의 경우 4byte(32bit), 64bit의 경우 8byte(64bit) 이다.
    32bit 운영체제의 경우 CPU가 데이터를 움직이는 통로 즉 Bus를 통해 한번에 전송 및 수신할 수 있는 데이터의 크기가 32bit 란 소리이다​.
    더 많은 메모리 공간을 사용할 수 있게 된다.
    만약 이 때 포인터의 크기가 32bit가 아닌 64bit 이면 Bus가 32bit 데이터를 이동할 수 밖에 없으므로 2번 작업을해야한다.(성능저하)
    따라서 BUS가 가져올수 있는 데이터와 크기가 똑같이, 32bit 운영체제는 32bit(4byte), 64bit 운영체제는 64bit(8byte)가 포인터의 크기이다.
    그렇다면, char: 1byte float: 4byte, double: 8byte로 각각 다른데 왜 포인터의 크기는 종류관계없이 같을까?
    이는 건물 크기가 달라도 우편번호는 똑같은 개수의 숫자인것과 같다고 이해하면 매우 쉽다!
	*/
    return 0;
}