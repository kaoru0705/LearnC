#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
11.2 참조
https://en.wikipedia.org/wiki/Data_segment#rodata
https://blog.naver.com/techref/222270185816
https://www.tutorialspoint.com/compile_c_online.php
https://stackoverflow.com/questions/10818761/gcc-why-constant-variables-not-placed-in-rodata
https://blog.naver.com/rhkdals1206/221519863419 정확한지 확실하지 않다. 실험해봐야 함 부정확한 부분이 다소 있는 듯 하다
https://blog.naver.com/oddish0513/222632469583 문자열 외 리터럴 상수는 역시 text segment에 저장되지 않는 듯

사진 참조
프로그램이 시작될 때 "Banana" 함수자체도 바뀌면 안되는 부분 text segment에 남아 있다 프로그램 코드 자체도 메모리에 올라가고 한번 메모리에 올라가면 프로그램이 끝날 때까지 계속 있어야 된다 예외로 프로그램을 동적으로 읽어들이면 다르다

프로그램 전체에서 계속 사용되는 변수들 프로그램이 끝날 때까지 남아있다.

프로그램의 일부에서 큰 메모리가 필요한 경우 운영체제, 컴파일러 입장에선 여러 프로그램을 관리해야 한다. 큰메모리를 일시적으로 사용한다면 게속 사용하게 둘 필요가 없다.
-> stack 지역변수 블럭에 속하는 코드가 실행할 때만 메모리에 들어감 그외에 경우는 차지하지 않는다 엄밀히 말하면 메모리를 차지하지 않는다기보단 그메모리를 다른 곳에서 사용할 수 있도록 관리 권한을 넘겨준다
main함수에 변수를 선언한다면 가장 먼저 실행하고 마지막으로 끝나니 사실상 끝날 때까지 메모리에 남는 거다
stack 메모리가 늘어났다 줄어드는 건 원칙적으론 운영체제하는 게 맞지만 허나 메모리 사이즈는 컴파일할 때 이미 결정이 남 스택에 선언된 지역변수들은 빠르다.

궁극적으로 만들 프로그램들은 대부분 메모리의 크기를 미리 알 수 없다. n from files, internet, scanf, etc. Heap
컴파일할 때 메모리 공간을 알 수 없기 때문에 heap을 사용한다.
stack은 내려가고 heap은 올라가는데 충돌이 일어나지 않을까 가상 주소 공간 사용 허나 메모리 할당 반납과정이 좀 느리다.
다 썼어요 free(arr);
*/
int main()
{
	char *ptr = "fdasfdaaeoriuewqporadskflads";
	int a = 5;
	printf("\n");

	return 0;
}