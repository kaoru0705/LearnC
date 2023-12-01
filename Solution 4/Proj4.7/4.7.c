//printf() 함수의 변환 지정자들 Conversion Specifiers
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//형식지정자 중에서 data type을 어떤 형식으로 출력할지 맞춰주는 것을 변환 지정자 근데 형식지정자 formatted specifier랑 통용되는 듯 하다. 4.1언급 
int main()
{
	double d = 3.141592653589793238462643383279502884197169399;
	printf("Even if there's a small chance, \
we owe this to everyone who's not in this room to try.\n"); // \로 줄바꿈 가능
	
	printf("\n");
	printf("%f %f %lf\n", 3.141592f, d, d); // l in %lf is ignored
	// 전통적인 이유로 printf에서 %f는 double로 출력된다. float으로 출력하려고 하면 내부에서 무조건 double로 바꿔버린다.
	// scanf는 아님 
	printf("%a %A\n", d, d);
	printf("%e %E\n", d, d);

	printf("\n");
	printf("%g %g\n", 123456.789, 1234567.89); // 값에 따라서 %e %f 사용, 지수가 -4보다 작으면 %e 기본적으로 6개의 유효숫자
	printf("%G %G\n", 12345.6789, 1234567.89);
	printf("%g %g\n", 0.00012345, 0.000012345);
	printf("%G %G\n", 0.00012345, 0.000012345);

	printf("\n");
	printf("%o\n", 9);
	printf("%p\n", &d); //pointer-of operator

	printf("\n");
	printf("%9d\n", 12345);
	printf("%09d\n", 12345);
	printf("%.2f\n", 3.141592);
	printf("%.20f %.20lf\n", d, d);

	printf("\n");
	int n_printed = printf("Counting!"); // printf의 return은 출력한 문자 개수다. 
	printf("%u\n", n_printed);


	return 0;
}