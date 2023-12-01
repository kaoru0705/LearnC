/* 정수와 오버플로우 Overflow */

#include <stdio.h>
#include<limits.h>//이걸 포함하면 unsigned의 가장 큰 값 signed의 가장 작은 값을 알려줌
//자료형과 변수 메모리의 관계에 대해 좀 더 이해할 수 있는 오버플로우
#include <stdlib.h> // itoa() int to string

int main() 
{
	/*unsigned int i = 0;
	sizeof(unsigned int);*///cursor를 갖다대면 4u(4byte)라는 뜻 visual studio가 알려줌

	//unsigned int i = 0b11111111111111111111111111111111;//0b는 literal이 binary다를 표현, c언어에서는 0b는 표준이 아님 하지만 대부분의 컴파일에서 사용가능
	//unsigned int u_max = UINT_MAX;
	//unsigned int u_min = 0; //UINT_MIN은 없다.
	//signed int i_max = INT_MAX;
	//signed int i_min = INT_MIN;//go to definition

	//printf("%u\n", i);
	//printf("%d\n", i); //-1이 나옴 형식지정자를 제대로 해야 됨 
	//printf("max of uint = %u\n", u_max);
	//printf("min of uint = %u\n", u_min);
	//printf("max of int = %d\n", i_max);
	//printf("min of int = %d\n", i_min);

	unsigned int u_max = 0 - 1; //UINT MAX + 1 시 0 출력됨
	// 0000 - 1 = 1111
	// i to binary representation 2진수로 바꿔줌
	int i_max = INT_MAX + 1;// Severity	Code	Description	Project	File	Line	Suppression State Warning	C26450	Arithmetic overflow : '+' operation causes overflow at compile time. Use a wider type to store the operands(io.1).Proj3.6
	int i_min = INT_MIN + 1;//2의 보수는 부호비트까지 바꿔야 된다. 당연한 말 2의보수는 컴퓨터가 뺄셈을 못 해서 만들어진 거기 때문
	//+(-0011)->1101       -1-1111(2의보수 하기 전으로 되돌리기) = -0011
	// 1111 + 1 -0011 -> 1101 계산할 때 다시 -10000
	//7 - 4 = 0111 - 0100 = 0111 + 1100 = 1 0011 = 0011 = 3
	//더 정확히 7 - 4 = 0111 - 0100 = 0111 + 10000 - 0100 - 10000 = 0111 + 1100 - 10000 = 10011 - 10000 = 0011
	char buffer[33];
	_itoa(u_max, buffer, 2); // int to string

	printf("%d\n", i_max);
	printf("%d\n", i_min);
	//print decimal and binary
	printf("decimal: %u\n", u_max);
	printf("binary: %s\n", buffer);//2진수 형태로 출력

	//범위에 있는 값을 사용하지 않고 넘어가면 메모리가 감당할 수 없다. Overflow
	
	//unsigned int i;
	//printf("%u\n", sizeof(unsigned int));
	//printf("%u", sizeof(i));//if unsigned %u

	printf("%hhd", 300);

	return 0;
}