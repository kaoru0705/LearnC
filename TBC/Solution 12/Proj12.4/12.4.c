/* Five Storage Classes 저장 공간의 다섯 가지 분류*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
03C_Duration 참조
사진 참조
크게 2가지로 나눌 수도 있음 ( 자동 레지스터 Static과 Static이 아닌것)

자동변수: 지금까지 사용했던 모든 지역변수 지속기간과 영역이 자동으로 해결
사고방식의 차이 운영체제 설계자의 관점: 자동변수는 스택에 위치하기 때문에 이런 성질을 가진다(X) 프로그래머가 지속기간과 영역을 편리하게 관리하도록 하기 위해서 스택을 만듦

레지스터변수:
- 메모리는 CPU와 물리적으로 분리되어 있는 반면 레지스터는 CPU 안에 임시 작업공간으로서 존재하기에 처리속도가 훨씬 빠르다
*변수명 앞에 register 키워드를 붙이면 레지스터에 저장될 가능성이 높아진다
*프로그래머가 register 키워드를 붙인다고 해서 항상 레지스터에 저장되지는 않으며 컴파일러의 판단에 따라 스택에 저장되기도 한다
*최근 컴파일러는 성능이 좋아져서 register를 붙이지 않아도 레지스터에 저장하기도 한다
*실무에서 가속을 할 때에는 레지스터를 많이 쓰기 보다는 캐쉬, 병렬처리, 분산처리, GPU 가속, 인라인 어셈블리 등을 활용한다
*일반적인 프로그래밍에서는 register는 잘 쓰이지 않으며 임베디드, 하드웨어 관련 프로그래밍에서 주로 쓰인다
실질적으로 잘 안 쓰임

Static(고정적 보통 정적이라 표현): 메모리에 "고정" 되어 있음. (컴파일러가 번역하는 단위: 파일) 번역단위 외부냐 내부냐 
추가로 저장공간에 포함되진 않지만 할당메모리도 알아두자.

할당메모리: 저장공간에는 포함되지 않는다. heap 런타임에서 운영체제에게 요청해서 "포인터"만 받음. (즉, 식별자가 없음) ref 12.2c
다른 언어를 공부하면 동적할당도 마치 식별자가 있는 것처럼 프로그래머가 편하게 쓸 수 있게 도와줌 허나 결국 내부적으로는 이렇게 작동

*/