/* �ε��Ҽ����� �Ѱ� */
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include<float.h> //FLT_MAX DBL_MAX double
#include<math.h> // asinf
// �̷��� ���輺�� �����Ѵ�.

int main()
{
	//round-off errors (ex1) ������ �ʹ� �ٸ� ���ڳ��� �����ϸ� �̷���. round-off error�� �ݿø�������� �����ϴ� �� �� �׷���.
	
	//float a, b;
	//a = 1.0E20f + 1.0f;
	//b = a - 1.0E20f;
	//printf("%f\n", a);
	//printf("%f\n", b);

	
	////round-off errors (ex2)
	
	//float a = 0.0f;
	//for (int i = 0; i < 100; i++)
	//	a += 0.01f;//0.01�� �Ϻ��ϰ� ���� �� ���� ����
	//
	//printf("%f\n", a);

	// overflow
	
	//float max = 3.402823466e+38F;// FLT_MAX go to definition �ִ�� ã�Ƽ� ������ double�̸� �ذ�ǰ���
	//printf("%f\n", max);
	//max = max * 100.0f;
	//printf("%f\n", max);//infinite exponent 128�� ���� ��

	//underflow

	//float f = 1.401298464e-45F;//FLT_TRUE_MIN 2^(-126)*2^(-23) subnormal number�߿����� ���� ���� ��� min positive
	//printf("%e\n", f);
	//f = f / 2.0f; // subnormal ���ڰ� ����������� �� �̷��� �θ� �ε��Ҽ��� ���е��� ǥ���� �� ���� ���� ����
	//// ������ subnormal�ε� ǥ���� �ȵǴ� ���ڴ�. float������ ǥ�� �Ұ��� ���ڴ�.
	////f = 1.501298464e-45f; �����԰��� ������ �׳��� ������ ���� �� �־���. 
	//printf("%e\n", f);

	//float f = 104.0f;
	//printf("%f\n", f);
	//f = f / 0.0f;//potential divide by 0 �̷� ���� ������ ����
	//printf("%f\n", f);

	float f = asinf(1.0f); // pi/2
	printf("%f\n", f);

	f = asinf(2.0f);// arcsin �� -1<=x<=1
	printf("%f\n", f);//-nan(ind) not a number ���������� �������� �ʴ� ��

	return 0;
}