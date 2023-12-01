//Manifest Constants ����� ����� define���� ����� ��ȣ�� ����� Manifest Constants��� �θ� ���� ���� ������ ����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h> // INT_MAX, ... , etc. // ��ǥ���� manifest �����
#include <float.h> // FLT_MAX, ... , etc.

#define PI 3.141592 // manifest constants, symbolic constants
// macro�� ����� �����ϱ⺸�ٴ� ���� �� ����ϴ� ����� �Լ��� �ݺ���뵵 ���� �Ŀ� ����

int main()
{
	printf("PI is %f\n", PI);
	printf("Biggest int: %d\n", INT_MAX);
	printf("One byte in this system is %d bits\n", CHAR_BIT);
	printf("Smallest normal float %e\n", FLT_MIN);


	return 0;
}