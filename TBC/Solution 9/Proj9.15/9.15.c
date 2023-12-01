/* 중요한 프로젝트는 책꽂이를 해라*/
/* NULL 포인터와 런타임 에러 */
// pointer를 사용할 때 런타임에러의 개념과 이것을 방지하기 위한 NULL 포인터를 사용하는 방법
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* Compile error */

	/*int a = 1234;
	printf("%p\n", &a);
	printf("%d\n", a);

	int* ptr;

	printf("%p\n", ptr);
	printf("%d\n", *ptr);*/
	//컴파일도 안 해준다. 컴파일 에러 맞다. 나 컴파일 시도하니까 난 컴파일 못해
	// 1>C:\Users\KDH\source\repos\Solution 9\Proj9.15\9.15.c(20): error C4700: uninitialized local variable 'ptr' used
	//포인터 변수 ptr이 선언된 순간, 변수 자체는 메모리 공간을 갖긴 한다.
	//하지만 여기에 들어가는 쓰레기 값이 포인터 변수 값이므로 '쓰레기 값에 해당하는 메모리 주소로 접근하게 된다.'
	//따라서 컴파일러가 알 수 없는 메모리의 접근을 막아 컴퓨터를 보호하는 것이다.

	/* Runtime error */

	/*int* ptr = 1234;

	printf("%p\n", ptr);
	printf("%d\n", *ptr);*/
	//C:\Users\KDH\source\repos\Solution 9\Debug\Proj9.15.exe (process 9584) exited with code -1073741819. = runtime error
	/*아래의 output을 보면 알 수 있듯이 제대로 빌드가 되지만 런타임 에러가 발생한다.
	ptr 변수값 자체는 선언된 대로 출력되지만,
	* 프로그램은 ptr이 1234에 해당하는 주소에 indirection 되므로, 1234번지로 접근을 하게 한다..
	이런 식의 사용자가 직접적으로 정해져 접근할 경우, 내가 운영체제가 된듯이 메모리를 지좆대로 쓸려고 함
	컴파일러가 OS 운영체제로부터 사용하도록 할당받지 않은 주소이기 때문에 운영체제가 강제 종료시킨다고 한다.
	즉!런타임 에러는 대부분 '주소'를 잘못 넣어줬을 때 발생한다.(이점을 알아두면 훗날 디버깅에 도움된다고 함)
	위와 같은 런타임 에러를 막기 위해 포인터 변수에 NULL 값을 넣어 초기화 해두는 버릇이 좋다.
	동적할당 자료구조할 때 런타임에러 발생하면 주소 문제일 확률이 크다. 디버깅할 때 염두에 두면 빨라짐*/

	int* safer_ptr = NULL; // 옛날에는 int *safer_ptr = 0; 이렇게도 함 c++에서는 nullptr이 생김
	int a = 123, b;

	scanf("%d", &b);

	if (b % 2 == 0) safer_ptr = &a; // runtime에 따라 지정된다. 이러면 null로 초기화 해야 된다.

	if (safer_ptr != NULL)
		printf("%p\n", safer_ptr);

	if (safer_ptr != NULL)
		printf("%d\n", *safer_ptr);

	/*위의 예시가 실제로 많이 쓰는 형식이라고 한다.
scanf를 통해 a를 어떻게 입력하냐에 따라 safer_ptr에 a의 주소가 들어갈 수 도 있지만,
못 들어 갈 시 NULL로 유지되서 이상한 주소에 간접접근되는것을 막는다.
그래서 실제로 NULL 을 사용하는 목적은 (safer_ptr != NULL) 을 써서
이 포인터 변수를 '사용해도 되는지 아닌지'를 판별하는데 쓴다고 한다.
*/
	return 0;
}