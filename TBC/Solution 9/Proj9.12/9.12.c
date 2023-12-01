﻿/* 중요한 프로젝트는 책꽂이를 해라*/
/* Pointer의 작동 원리 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 초보 프로그래머를 위한 컴퓨터의 작동원리 복습
// 사진 참조
/* https://blog.naver.com/cuorej/221629376633 */

/*
[꼭 기억하기]
1. int* a_ptr = &a; 의 의미
     : 주 메모리에 저장된 정수형 주소값(int*)인, 포인터변수(a_ptr)에  a변수의 첫번째 주소값("&a)을 대입한다.
2. *a_ptr = 20; 의 의미    
     : 포인터변수(a_ptr)의 주소값에 해당되는 주소에 저장되어 있는 메모리 값에 "간접접근(*a_ptr)" 하여 20을 대입
     : 간접접근(indirection), 역참조(dereferencing), 방향재지정(redirection)
3. 1, 2의 *은 다른 *이다!
*/

/*
변수를 선언한단 것은, "변수를 통해 메모리공간을 사용하는 것이다."

이를 위해선

1. 어디에 있는 메모리를 사용하는지. (첫 번째 주소를 변수가 내부적으로 알고있음:a는 128, b는 104, c는 100...)

2. 얼마큼의 메모리를 사용하는지. (자료형으로 알고있음: int는 4byte이므로 128~131)

a라는 변수가 128이라는 메모리주소를 가지고 있고 int형으로 4byte의 크기를 가지고 있음. b도 마찬가지

c=a+b; 는 a와 b가 내부적으로 알고있는 주메모리의 주소의 자료를 가져오고, (128번지 부터 4byte 값 7, 104번지로부터 4byte 값 8)

CPU의 임시메모리(Register)에 저장해두고 더해서 변수 c에 사용하는 메모리주소에 데이터를 저장한다.

어셈블리를 사용하게 되면 이 과정을 다 사용해야 한다. 주소 사용

지금까지의 설명은 우리의 C언어로 c=a+b; 를 하였을 경우 컴퓨터 내부적으로 일어나는 일들을 설명했다.

그렇다면, 주소를 직접 사용하고 싶다면 ? ?

주소 연산자(Address-of operator)를 사용하면 된다. & 단항연산자 unary a; 를 쓰면 변수의 주소값을 다른 변수에 저장할 수 있다.

주소의 값을 저장하는 변수를 선언 할 때는, * (asterisk)를 앞에 붙여준다.

int* a_ptr 은 "int"형 변수의 주소값만 저장가능하다.(int형 선언했으므로)

간접적으로 가리키는(pointing) 역할

함수의 매개변수 배열 동적할당에서 중요하게 사용

엄청나게 많은 양의 데이터를 사용한다면? 많은 양의 데이터를 복사해서 사용하는 것은 낭비다.
많은 양의 데이터가 저장되어 있는 주소를 직접적으로 알 필요가 있다.

a_ptr 도 어떤 값을 저장하는 '변수' 이다. = > 변수이기 때문에 메모리의 공간을 갖고 있고, 주소'값'을 가지고 있다.

포인터 변수 : 주소를 저장할 수 있는 변수를 선언하는방법(변수 앞에*)

그런데, 실제로 그 주소를 따라가서 그 주소의 데이터를 가져올려면 변수 앞에* 를 넣으면됨(위의 포인터 선언에 대한* 과 동일)

* a_ptr = 8;이라면 a_ptr의 저장되어있는 주솟값 128을 보고 *가 붙어있으니 그에 해당하는 메모리에 찾아간다.
int형 포인터 변수이므로 4바이트 공간만큼 작업한다.

a_ptr의 주소값을 통해 안에 메모리공간을 사용 하는것이 int a = 7 과 * a_ptr = 8;​는 
기능상 컴퓨터의 작동원리에 따라서 똑같이 작동하고 있다. 결국 메모리주소를 따라가서 데이터를 저장하므로

앞의* 과는 다른 의미의* 로서

이렇게 메모리값에 주소값을 통해 접근하는 것을 refer(저기 가서 저거 찾아 봐)

간접접근(indirection), 역참조(dereferencing), 방향재지정(redirection 이건 c++에서 많이 쓰는 표현) 이라고 한다.

a_ptr이란 변수가 가지고 있는 값은 128 인데, 포인터 변수이므로 "간접접근 indirection" 연산자가 붙어있으면 주소 값을 보고 주소를 찾아가 거기있는 메모리 공간을 가져온다!!그 값이 8!

포인터 변수도 사이즈가 있다.
*/
int main()
{



	return 0;
}