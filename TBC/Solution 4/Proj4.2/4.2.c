/* sizeof 연산자 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h> // malloc()

struct MyStruct
{
	int i;
	float f;
	char c;
};

int main()
{
	/* 1. sizeof basic types */

	int a = 0;
	unsigned int int_size1 = sizeof a; // sizeof는 unsigned니 
	unsigned int int_size2 = sizeof(int); // sizeof는 함수인 것처럼 보이지만 연산자
	unsigned int int_size3 = sizeof(a);

	size_t int_size4 = sizeof(a); //size_t 시스템에 따라 sizeof가 알려주는 값의 자료형이 unsigned int가 아닐 경우가 있을 수 있어서
	// 이식성을 높이기 위해 size_t 사용 점점 추세
	size_t float_size = sizeof(float);

	printf("Size of int type is %u bytes. \n", int_size1);
	printf("Size of int type is %zu bytes.\n", int_size4);// size_t 에 해당하는 형식지정자 %zu sizeof 연산자의 반환값의 자료형
	printf("Size of float type is %zu bytes.\n", float_size);

	/* 2. sizeof arrays */

	int int_arr[30]; // int_arr[0] = 1024; ... 30개의 메모리 공간을 대표하는 메모리의 주소 맨 앞 주소 
	int *int_ptr = NULL;
	int_ptr = (int*)malloc(sizeof(int) * 30); // int_ptr[0] = 1024; ...
	//120byte 메모리 공간을 할당하고 그 메모리 공간을 대표하는 첫 번째 주소를 할당받음

	printf("Size of array = %zu bytes\n", sizeof(int_arr));//30*4라고 지정됐기 때문에 int_arr는 주소라고 생각하는 게 좋음 
	printf("Size of pointer = %zu bytes\n", sizeof(int_ptr)); //동적할당이라 어느정도의 사이즈일지 모르기때문에 int_ptr메모리를 출력한다.

	// int_arr은 컴파일할 때 120byte로 결정이 나고 compile time
	// int_ptr은 일단 선언을 하고 나중에 메모리 공간을 얼마나 할당받을지 runtime에 결정된다.
	// 수동으로 sizeof(int)*30으로 적어주긴 했지만 컴파일러 입장에서는 얘가 대표할 공간에 메모리사이즈가 얼마가 될지 모른다.

	/* 3. sizeof character array */

	char c = 'a'; //정수 97로 바꿔서 저장됨
	char string[10]= "1234567890"; // maximally 9 character + '/0' (null character)
	// in C language 문자를 저장할 때 마지막 배열에 널 캐릭터를 추가함 실용적으로 문자열을 처리하기 위해서는 용법상 마침표가 필요
	// string[10] = "1234567890" 이렇게 하고 %c로 하면 뽑힘 허나 %s로 하면 쓰레기들 출력됨
	printf("%s\n", string);

	size_t char_size = sizeof(char);
	size_t str_size = sizeof(string);

	printf("Size of char type is %zu bytes.\n", char_size);
	printf("Size of string type is %zu bytes.\n", str_size);

	///* 4. sizeof structure */

	printf("%zu\n", sizeof(struct MyStruct)); // int float 8bytes char 4byte? 시발년아 이거 나중에 나옴 어차피

	return 0;
}