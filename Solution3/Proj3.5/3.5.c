/* ������ �Ǽ� */
#include <stdio.h>

int main() 
{
	//2�� 2.0�� �޸𸮿� ����� �� �����ϰ� �Ǿ�����
	//�ε��Ҽ��� floating point, point�� �Դٰ��� �ϱ� ����
	//3.14 = 3.14E0 = 3.14e0 = 0.314E1 = 31.4E-1 Exponent
	//32bit Single Precision �ƴ� �� float�� �ƴϰ� single��? ��?�׳� 64bit Double(float�� �� ��) Precision
	// float double �� �翬�� floating point���� ������ �� ������. float���� double�� �� ���� �Ű�
	//���߿� ������ ���α׷��� ���� �� double ������ ���������� �𸥴�.
	float i = 0.1234567f;
	printf("%f", i);

	return 0;
}