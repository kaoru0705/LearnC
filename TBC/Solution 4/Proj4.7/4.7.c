//printf() �Լ��� ��ȯ �����ڵ� Conversion Specifiers
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//���������� �߿��� data type�� � �������� ������� �����ִ� ���� ��ȯ ������ �ٵ� ���������� formatted specifier�� ���Ǵ� �� �ϴ�. 4.1��� 
int main()
{
	double d = 3.141592653589793238462643383279502884197169399;
	printf("Even if there's a small chance, \
we owe this to everyone who's not in this room to try.\n"); // \�� �ٹٲ� ����
	
	printf("\n");
	printf("%f %f %lf\n", 3.141592f, d, d); // l in %lf is ignored
	// �������� ������ printf���� %f�� double�� ��µȴ�. float���� ����Ϸ��� �ϸ� ���ο��� ������ double�� �ٲ������.
	// scanf�� �ƴ� 
	printf("%a %A\n", d, d);
	printf("%e %E\n", d, d);

	printf("\n");
	printf("%g %g\n", 123456.789, 1234567.89); // ���� ���� %e %f ���, ������ -4���� ������ %e �⺻������ 6���� ��ȿ����
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
	int n_printed = printf("Counting!"); // printf�� return�� ����� ���� ������. 
	printf("%u\n", n_printed);


	return 0;
}