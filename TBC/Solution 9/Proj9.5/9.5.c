﻿/* 중요한 프로젝트는 책꽂이를 해라*/
/* 지역변수와 Stack */
/* https://blog.naver.com/cuorej/221627892924 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 사진 영상 참조
// ... = compiler나 OS는 알지만 우린 알 필요 없는 메모리 공간 실행하는데 필요한 최소한의 메모리
// stack이라는 메모리에 a라는 메모리가 쌓이게 된다.  a = int_max(1, 2); 대입해주면서 m은 stack에서 사라짐
// 그러면 m이 존재할 때 a의 값을 읽어오거나 할 수 있겠네요 예아 포인터를 이용 b도 마찬가지
// abb 다 사용할 수 있다. 다만 이름이 같지만 스택에 맨 마지막에 쌓인 b를 사용하는 것 뿐
// 같은 영역에 존재하는 것을 우선적으로 사용하는 것 뿐
// 프로그램의 간결성을 위해 의도적으로 이름을 같이 쓰기도 함

/*
1. Stack Frame 이란 절차, 함수의 호출에 따라서 그와 관계된 모든 데이터를 저장해 두는 스택 영역

2. Stack 구조(메모리를 쌓았다 뺌-push/pop)를 사용하면 메모리를 더 효율적으로 사용할 수 있다.

메모리를 더 효율적으로 사용하기 위해서, 사용되는 메모리의 양을 최소한으로 줄이기 위해서 스택 이라는 구조를 사용한다고 한다.

스택의 자세한 의미는 나중에 배운다고 한다. 또한 동적할당을 배우면 내용이 좀 틀려진다고 한다.(이 강의는 맛보기)

​

위의 그림을 자세히!!! 보자.

우선 Stack 이란 컴퓨터에 사용되는 기본 데이터 구조로, 데이터를 쌓았다 치우며(push/pop) 후입선출 구조로 유지하는 추상 데이터형을 말한다.

우선 Stack Frame 이란, 프로그래머가 사용할려고 하는 메모리의 사이즈, 그리고 그 외 실제로 실행을 시키기 위해서 필요한 메모리 크기를 의미한다.  (네이버 검색: 어떤 절차(또는 함수)의 호출에 따라서 그와 관계되는 모든 데이터를 저장해 두는 스택 영역. 호출된 프로그램의 프레임은 스택 상에 순차 겹쳐 쌓여지고, 나중에 그 순서로 꺼내진다.)

main()문이 실행되기 위해선, main 문에 필요한 충분한 메모리 stack frame을 가지고 있어야만 main 문이 실행이 된다.

main 함수가 실행이 될때 필요한 내용들을 전부 Stack Frame이 가지고 있는 것이다ㅣ.(예외: 동적할당.)

​

따라서 10번째 줄이나, 16번재 줄처럼 int_max 함수를 호출하게 되면 추가적으로 메모리가 필요하게 되고,

이에 따라 추가적인 메모리를 stack! 하게 된다(그림상으론 아래로) - 좀더 고급용어론 push 한다.(뺄 때는 pop)

​

결론은 이 함수가 사용할 메모리가 추가로 "할당", 즉 주어진다.(동적 할당의 할당과 다른 의미-여기서의 할당은 단순히 메모리를 주어진단 것)

그리고 이 함수가 반환값을 던져주면, 이 메모리는 스택에서 빠지고(POP되고) 다시 빈 공간이 된다.

​

13번째 줄에서 int_max() 함수의 stack frame이 해제가 되었기 때문에 'm' 이라는 변수에 접근을 할수가 없다.

(사실 실무에서 메모리 주소는 컴파일러나 장비, 개발환경에 따라 다르다고함.-이건 공부용)

​

15번째 줄에서 int b; 로 인해 main() 함수의 Stack Frame에 새로운 b가 추가되었다.

(하지만 실제로, 모든 main 함수의 stack Frame에선 이미 사용될 메모리가 정해져 있기 때문에 예측되어 메모리가 잡혀져 있다)

​

16번째 줄은 앞의 내용과 동일

​

19번째 줄은 변수 이름만 같고, 메모리가 다르다!.  따라서 여기서 b를 호출할 경우, 이 메모리의 b가 사용되어진다.

(앞에 선언된 b는 스택된 메모리 아래에 쌓여져 있지만 문법상, 이름이 똑같을 경우 더 가까운 영역의 이름을 사용하게된다.)

​

21번째 줄은 영역이 끝났기 때문에 이전에 선언된 b의 메모리가 파괴되어 사라진다.

(c++의 생성자 소멸자의 소멸이 이에 해당된다고 함- 이런 메커니즘이 있다정도... 나중에 공부)

​

23번째 줄에  int c로 선언시 이전에 파괴된 공간 556을 다시 재활용 한다.

결국 실제로 a,b,b,c 네개의 변수를 사용했지만 스택구조상 3칸의 메모리만 씀-메모리의 효율화

​
그림의 오른쪽에 GCC의 주소를 보며 다시한번 숙지해 보자.
*/
int main()
{



	return 0;
}