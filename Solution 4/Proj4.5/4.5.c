/* Symbolic Constants and preprocessor ��ȣ�� ����� ��ó���� #define */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.141592f // �Ź� �̰� ���� �� ���� �ȵȴ�. ��ȣ�� ����� ��� c������ ��ó���� define�� ���� ��
//��ó���Ⱑ �̸� ��ü�� �ؼ� compiler ���忡���� 3.141592f�� �ν� 
//PI = 3.141592f �̷��� ���� ����. ��ȣ���� ���� �ν��Ѵ�.
#define AI_NAME "Jarvis"
//define ���� �빮�ڷ� ����

int main()
{
	float radius, area, circum;

	printf("I'm %s. \n", AI_NAME); // �Ź� Jarvis, Friday �̷������� �̸��� �ٲٴ� �ͺ��� define�ϰ� ������ �̸��� �ٲٴ� �� �� ����.
	//�ƴ� �׷� �������� ������ ���ݾ�. float pi = 3.141592f; �� ���� �Ǽ��� �߰��� ���� �ٲ۴ٸ�? pi = 2.0f �Ŀ� ���̴� pi����� �� ����
	// ��ȣ����� const float float const�� �ϸ� �ȴ�.
	//�� define�� ����� �ʿ�� ����. �ֱٿ��� define���� const�� ���� ���� �� ������ c++������ Ư�� c������ ���������� define
	printf("Please, input radius\n");

	scanf("%f", &radius);

	area = PI * radius * radius; // area = pi*r*r
	circum = 2.0f * PI * radius; // circum = 2.0 * pi * r

	// sphere area, sphere volum, ... �̷��� ���α׷����� ������ Ȯ���� �� 3.141592�� ��� ���� �� �ִ°�?

	printf("Area is %f\n", area);
	printf("Circumference is %f\n", circum);

	//TODO: wrong usage, strings const

	return 0;
}