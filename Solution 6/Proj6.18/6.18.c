/* Use functions's return_value in Loop */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int compute_pow(int base, int exp);	// scope�� block�ȿ����� ��� �����ϴ�.
// prototype ���� �̷��� ����. ������ �ʹ�������� main�Լ� ���Ⱑ ����
// prototype�� main �Լ� result = compute_pow(base, exp); �κ��� �������� �� �̷� �Լ��� �ִ�.
// ��κ��� �������� �� �ȿ��� ��� ����ϴ����� �Ű澲�� ����. �и��ؼ� ������. linking �������� ��ü�� ã�� ��������
// GCC���� �˷����. visual studio code part ref  1.13
// ���� ���ش�. main�Լ������� ���� �Ǿ��־ ȣ���� �� �ִ�. �������� ���������� ��ŷ�ϴ� �������� �������� ref 2.9 2.10
int main()
{
	// 3 4
	// 3*3*3*3 = 81
	// �ŵ� ���� = power
	int base, exp, result;

	while (scanf("%d %d", &base, &exp) == 2)
	{
		//result = 1;
		//for (i = 0; i < exp; ++i)	// for (int i = 0) for�� �ȿ��� i���� �������� c++���� �̷��� �ϰ� �ִ�.
		//	result *= base;
		//// ... 
		//// ... ������� ��������� �����ϴ�. ������ �з��� ���� ������ �Լ��� ������
		// int j;
		result = compute_pow(base, exp); // �����̸��� ���� ���� ������ ����. scope�� �����ض�.

		printf("Result = %d\n", result);
	}

	// j = 1; //compile error
	return 0;
}

int compute_pow(int base, int exp)	// scope�� block�ȿ����� ��� �����ϴ�.
{
	int i, result;	// �ܾ� Ŀ���� ctrl + f �� �ϸ� �ش� �ܾ ã�´�. ctrl c ctrl f ctrl v�ؾߵǴ� ��쵵 ����

	result = 1;
	for (i = 0; i < exp; ++i)
		result *= base;

	return result;
}