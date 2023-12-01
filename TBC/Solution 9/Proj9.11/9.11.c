/* 중요한 프로젝트는 책꽂이를 해라*/
/* 헤더 파일(Header Files) 만들기 비주얼 스튜디오 */
#define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h> 이미 my_print.h 에서 include함
// 
// 하나의 파일을 여러 개로 나누는 법을 배워보자.
// 선언과 정의를 분리해서 하는 건 강의 초반부에만 하는 거다. 헤더파일을 만들어서 분리하는 게 좋다.
// main 함수는 main.c src_main.c 등 main이라는 걸 알 수 있는 이름으로 짓는 게 원래는 맞다.
// 객체지향 c++ 할 때는 헤더파일의 이름을 클래스 이름과 동일하게 하고 클래스 이름의 첫글자는 대문자로 하는 것이 일반적
// Proj9.11 add new item header file. containing folder main.c 와 같이 있음
// 유닉스나 리눅스나 다른 개발환경에서 하면 파일도 수동으로 만들고
// 컴파일할 때 컴파일러한테 이런 파일도 같이 컴파일해야 된다고 알려주는 작업도 수동으로 해야 된다.
// 특히 c파일을 컴파일 할 때는 이런 c도 저런 c도 다 컴파일 해줘 해야 된다.
// 비주얼 스튜디오는 이러한 과정이 자동이다. 허나 다른 환경에서는 주의할 것
// c개발자들은 보통 이름이 똑같은 c파일을 하나 더 만든다. 헤더파일을 책 목록 차례로 씀
// 헤더파일에 와서 이런 파일들이 있구나 이걸 가져다 쓰면 되겠구나 해야 됨
// "Header Files" 같은 폴더를 비주얼 스튜디오에서는 filter라고 함 실제로 폴더가 생기지는 않음 코드 정리할 때 유용하게 쓰임
// add new filter
// "Resource Files" ex) Icon code가 아닌 정보 이미지 사운드
#include "my_print_functions.h" //header file만 include하고 있으므로 stdio.h를 include해야 된다.
#include <stdio.h>

/* main 함수 (호출) 헤더파일 (선언), 헤더파일이름.c (정의) */
int main()
{
	print_hello();
	print_hi();
	print_hello();
	print_hi();
	print_str("No one lives forever.");
	print_str("Valar morghulis");

	printf("Hello ");

	return 0;
}