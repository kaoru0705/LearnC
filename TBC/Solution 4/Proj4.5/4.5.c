/* Symbolic Constants and preprocessor 기호적 상수와 전처리기 #define */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.141592f // 매번 이걸 쓰는 건 말이 안된다. 기호적 상수를 써라 c언어에서는 전처리기 define을 많이 씀
//전처리기가 미리 교체를 해서 compiler 입장에서는 3.141592f로 인식 
//PI = 3.141592f 이렇게 적지 마라. 등호까지 같이 인식한다.
#define AI_NAME "Jarvis"
//define 관습 대문자로 선언

int main()
{
	float radius, area, circum;

	printf("I'm %s. \n", AI_NAME); // 매번 Jarvis, Friday 이런식으로 이름을 바꾸는 것보다 define하고 위에서 이름을 바꾸는 게 더 낫다.
	//아니 그럼 변수에다 적으면 되잖아. float pi = 3.141592f; 응 누가 실수로 중간에 값을 바꾼다면? pi = 2.0f 후에 쓰이는 pi계산은 다 ㅈ됨
	// 기호적상수 const float float const를 하면 된다.
	//꼭 define을 사용할 필요는 없다. 최근에는 define보다 const를 쓰는 것을 더 권장함 c++에서는 특히 c에서는 전통적으로 define
	printf("Please, input radius\n");

	scanf("%f", &radius);

	area = PI * radius * radius; // area = pi*r*r
	circum = 2.0f * PI * radius; // circum = 2.0 * pi * r

	// sphere area, sphere volum, ... 이렇게 프로그래밍할 범위를 확장할 때 3.141592를 계속 적을 수 있는가?

	printf("Area is %f\n", area);
	printf("Circumference is %f\n", circum);

	//TODO: wrong usage, strings const

	return 0;
}