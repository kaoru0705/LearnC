/* Complex Types ���Ҽ��� */
#include <stdio.h>
#include <complex.h>
int main() 
{
	_Dcomplex z; // double type fcomplex dcomplex lcomplex �� ���� ����
	z._Val[0] = 1.0;
	z._Val[1] = 1.0;
	//�����ڵ��� ���Ҽ��� ���� ����� ��찡 ���� visual studio�� �Ĳ����� ����
	// GCC�� ���� �� ������ ������ �㳪 imaginary number�� ������ �ȵ�����
	
	return 0;
}