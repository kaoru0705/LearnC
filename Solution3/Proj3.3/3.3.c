/* scanf() �Լ��� �⺻���� ���� */

//#define _CRT_SECURE_NO_WARNINGS // define macro
//project right click -  properties���� �ٲ� ���� �ִ�. preprocessor�κп� �ڷᱸ�� �˰����� ���� �Ǹ� Configuration Release ������ �ؾ� �ȴ�.
//microsoft visual studio������ ����
//�ַ� project setting���� �ٲٴ� ���� ����
#include <stdio.h>

int main() 
{
	int i = 0;

	scanf("%d", &i);// & : ampersand scan formatted ��� �Է¹����� formatting �ϰ� ����
	//&������ �ּҸ� �Ѱ��༭ ����ڰ� �ܼ�â�� �Է��� ���� �ش� �ּ� �޸� ���� ���(��� c���� ���� ��ü�� �Ѱ��ִ°��� ����)
	// scanf�� ��ü�� ���� i�� ���� ������ ���� ����. �׷��� �ּҸ� �ѱ� ����?
	// (scanf�� �ٸ� �ּ��� ������ �ٲܱ� �� ��ŷ���� window�� �������� ����)
	// �� �̷��� �ϴ°�? c ���������� �Լ��� ����� �ϳ��ۿ� �ȵȴ�. scanf�� ���� ���� �Է��� �ް� ���� �ٲ� �� ���� ������� �Ұ���
	// c�� ������ ��ÿ��� �翬�� ���̾���
	// scanf�� �Է����� �� printf ���� �̹� ���� �ٲ�� �ִ�. �ȵǴ� ���� ���߿� �˷��ְڴ�.

	printf("Value is %d\n", i);//print formatted ����� ��� ���� formatting�ϰ� ����

	return 0;
}