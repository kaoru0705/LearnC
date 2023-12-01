/* 중요한 프로젝트는 책꽂이를 해라*/
/* 배열의 기본적인 사용방법 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MONTHS 12	// symbolic constant, macro = symbolic constant를 macro로서 정의했다라고 말하기도 함
/*
1. 배열은 선언과 동시에 초기화 하지 않으면 따로 한번에 초기화는 불가능(for문 이용해야함)

2. 배열명 와 &배열명[0]는 같은 주소를 표현하는 방식이다, 하지만 sizeof는 각각 다르다

3. 배열의 인덱싱을 잘못하더라도 빌드는 된다.(런타임에러)

4.배열도 #define과 const 로 선언 가능하다.

5. 배열은 부분적으로 초기화 시키면 나머진 0으로 대입된다.

6. arr[10]={ 1, 2, [5]=3} 식으로 지정해서 초기화 가능하다 ( [5]에 3 대입)

7. Variable-Length Array(VLA) 는 C11 부터 optional 하다.(vs2019는 막아놈)

*/

int main()
{
	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; //48byte 선언과 동시에 초기화

	/* Basic usage */
	//for (int i = 0; i < MONTHS; ++i)
	//	printf("%d ", high[i]); // 배열의 장점  for문으로 처리가능하다.
	//printf("\n");

	//float avg = 0.0;
	//for (int i = 0; i < MONTHS; ++i)
	//	avg += high[i];
	//printf("Average = %f\n", avg / (float)MONTHS);

	//high[0] = 1; //index를 통해 변수처럼 사용
	//high[1] = 2;
	//high = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; // not working 선언이 끝나면 동시에 초기화 불가능
	//high[12] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; // not working
	// 실전에서는 for문으로 초기화가 대부분 script file에서 값을 가져와 배열에 저장 및 초기화 배열의 저장된 값을 파일에 저장

	/* Addresses */
	//printf("%p %p\n", high, &high[0]); //high가 마치 포인터처럼 작동, 전체 대표하는 주소의 첫 번째 주소다.
	//for (int i = 0; i < MONTHS; ++i)
	//	printf("%lld\n", (long long)&high[i]); //x64는 주소의 크기가 8byte이므로 longlong으로 casting하는 게 좋다. (long long)을 안 붙일 경우 똥값 출력
	//printf("\n");

	/* Compiler doesn't check whether indices are valid/ */
	//high[12] = 4; // Error Runtime error 빌드는 되니까 위험 visual studio 밑줄 경고
	//high[-1] = 123; // runtime Error
	// C언어 자체는 프로그래머를 믿는다는 게 기본 철학
	// 컴파일러가 체크해줄 수 있다 허나 매번 체크하면 너무 느려진다. 특히 빅데이터에서는 효율성때문에 안 함
	/* Visual Studio에 있는 IntelliSense가 알아서 밑줄 경고
	C++의 STL을 이용하거나 다른 언어들에 있는 도구를 이용하면 런타임에러를 사전에 잡아줄 수 있다.
	하지만 그렇게 하면 퍼포먼스가 저하된다. 큰 데이터를 다루는 분야에서는 이런 곳에서 소비되는 시간이 전체 퍼포먼스에 큰 영향을 끼치므로 주의해줘야 한다.*/
	// runtime error는 작동원리에 대해 공부할 때 매우 도움이 된다.

	/* const and array */
	/*const int temp = 0;
	temp = 4;*/
	/*const int low[12] = { -7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5 };
	low[0] = 123;*/

    /* When array is not initialized */
    //static int not_init[4];  // storage class(초기화를 안 해줘도 자동으로 0으로 초기화된다)
    //int not_init[4];  // 프로그래머가 추후에 초기화할 것이라고 가정하고 쓰레기값을 넣어둔다
    //for (int i = 0; i < 4; ++i)
    //    printf("%d\n", not_init[i]);  // 배열을 초기화하지 않으면 쓰레기값이 출력된다(쓰레기값은 운영체제, 컴파일러, 디버그/릴리즈 모드 등에 따라 다르다)

    /* Partially initialized */
    //int insuff[4] = { 2, 4 };  // 배열을 부분적으로 초기화한 경우에는 프로그래머가 여기에서 초기화할 의도가 있다고 가정하고 나머지를 자동으로 0으로 초기화한다
    //for (int i = 0; i < 4; ++i)
    //    printf("%d\n", insuff[i]);

    /* Overlly initialized */
    //int over[2] = { 2, 4, 8, 16 };  // Compile Error

    /* Omitting size */
    //const int power_of_twos[] = { 1, 2, 4, 8, 16, 32, 64 };  // 원소의 개수를 일일이 세지 않아도 컴파일러가 자동으로 원소 개수만큼 배열을 선언한다 프로그래머가 실수할 확률 줄어듦
    //printf("%d\n", sizeof(power_of_twos)); // 단점: 사이즈를 모름 ㅋㅋ, 주의 동적할당할 땐 작동안됨
    //printf("%d\n", sizeof(int));
    //printf("%d\n", sizeof(power_of_twos[0]));

    //for (int i = 0; i < sizeof power_of_twos / sizeof power_of_twos[0]; ++i)  // 배열의 크기를 연산을 통해 알 수 있는 방법
    //    printf("%d ", power_of_twos[i]);

    /* Designated initializers */
	//int days[MONTHS] = { 31, 28,[4] = 31, 30, 31,[1] = 29 };  // 출력값: 31 29 0 0 31 30 31 0 0 0 0 0(지정이 안 된 원소는 모두 0으로 채워진다)
	//for (int i = 0; i < MONTHS; ++i)
	//	printf("%d ", days[i]);

    /* Specifying array sizes */
    //int arr1[MONTHS];  // Symbolic integer constant index = 양의 정수만
    //double arr2[123];  // Literal integer constant
    //float arr3[3 * 4 + 1];  // 컴파일 타임에 미리 계산해서 값을 확정할 수 있기 때문에 사용 가능
    //float arr4[sizeof(int) + 1];  // 컴파일 타임에 값이 확정되기에 사용 가능
    ////float arr5[-10];  // No
    ////float arr6[0];  // No
    ////float arr7[1.5];  // No
    //float arr8[(int)1.5];  // Yes


    /* 변수를 이용해서 배열 사이즈를 지정하는 방식 */
    //int n = 8;
    //float arr9[n];  // Variable-Length array is optional from C11(C99에서는 필수였으나 C11부터는 선택사항이 되었다. 비주얼 스튜디오 컴파일러는 구현하고 있지 않다. 거의 똑같은 기능을 동적할당을 이용하면 구현할 수 있다)
	// 다른 컴파일러는 가능한 경우도 있다.
	
	return 0;
}