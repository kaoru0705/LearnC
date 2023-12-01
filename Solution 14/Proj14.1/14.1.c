/* 구조체(Structures)가 필요한 이유 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	사진 참조 
	메모리에 데이터가 저장돼 있으면 오브젝트
	자료형이 서로 다르지만 함께 사용하면 편리한 데이터 오브젝트들끼리 모아놓을 수는 없을까?
	배열같은 경우엔 같은 오브젝트들이 나열돼 있어서 포인터 연산같은 걸 할 수 있었다. 장점
	struct Patient(tag)
	{
		name이라는 변수가 patient구조체의 멤버
	};
	마치 하나의 새로운 자료형처럼 프로그래밍할 수 있다.
	struct Patient p1, p2, p3; //structure variables
	struct Patient pat[MAX_PARTIENTS]; 배열도 선언 가능
	p1.name . is 구조체의 멤버의 접근할 수 있는 연산자 structure member operator

	이해를 돕기 위해서 p1.name p1.height p1.weight p1.age의 메모리 공간이 붙어 있는 것처럼 그렸지만 컴파일러가 최적화를 위해서 메모리 패딩이란 것을 사용한다.
	struct == template(틀) p1.name p1.height p1.weight p1.age 이런 메모리를 사용할 수 있는 이런 데이터의 구조를 사용할 수 있는 그런 데이터 오브젝트들을 만들어낸다.
	여러가지 데이터 오브젝트들이 복합적으로 합쳐져서 전체적으로 하나의 커다란 자료형처럼
	template은 틀로 해석되나 c++에서는 좀더 다른 의미를 갖는다.

*/
