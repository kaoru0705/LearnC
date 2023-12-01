/* 중요한 프로젝트는 책꽂이를 해라*/
/* 변수의 영역(Scope)과 지역 변수(Local Variable) */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// int a; // file영역 변수 file전체에서 접근 가능 권장하진 않나보다.

int int_max(int i, int j);


int int_max(int i, int j)
{
	//a = 456;
	int m; // m이 block 밖을 나가면 사라짐. 내부적으로 이렇게 따로 돌아가는 이유는 stack frame이란 개념을 알아야 됨
	return m = i > j ? i : j;
}

int main()
{
	//m = 123; error

	int a; // 전역변수의 변수와 겹칠 경우 안쪽에 있는 변수로 주인이 바뀐다.
	// 변수는 메모리 공간을 의미하는 명칭, 메모리 주소자체를 직접 다루는 게 어렵기 때문에
	// 사람이 이해할 수 있는 인식자로서 컴퓨터 메모리 상의 공간에 접근해서 사용할 수 있게 해줌
	// 허나 변수를 통해 접근하는 것은 메모리 공간이고 메모리는 결국 주소를 통해서 접근
	a = int_max(1, 2);

	printf("%d\n", a);
	printf("%p\n", &a); //ampersand 주소 operater

	{
		// //int a;일 경우 셋 다 같은 결과
		int a; // 큰 영역에서 작은 영역을 만들고 변수를 만드니 다른 변수가 나온다. 
		// 변수를 지을 때 더 많은 변수를 쓸 수 있도록 하기 위해
		// 모든 영역에 변수의 이름이 겹치지 않게 만드는 것은 힘들다. 
		a = int_max(4, 5);

		printf("%d\n", a);
		printf("%p\n", &a);

		int b = 123;
	}

	//b = 456; error

	printf("%d\n", a);
	printf("%p\n", &a);

	return 0;
}

