/* _Bool �ڷ��� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>

int main()
{
	int i;
	//i = 5;
	//i == 5;
	//5 = i;	// literal constant�� memory������ ���� ���� ����
	//5 == i;	// ���İ� ���ϴ� �ű� ������ ���������� �� ����
	
	//while (i = 5) {/*do something*/ };		// 5�� �����ϰ� 5�ϱ� true�� ����
	//while (i == 5) {/* do something*/ };

	//_Bool boolean_true = (2 > 1); // �ᱹ ������ ó�� in c, c++������ ���� ���������� ������ ó������ bool�̶� ������Ÿ���� ���� ����
	//_Bool boolean_false = (1 > 2); // ��κ��� ������� �̹� bool type�� ���� ����ϰ� �ֱ� ������ _Bool��� ������
	//
	//printf("True is %d\n", boolean_true); // boolean�� ���� format specifier�� ����
	//printf("False is %d\n", boolean_false);

	//printf(boolean_true ? "true" : "false"); // continual operator �켱������ ����.
	//printf("\n");
	//printf(boolean_false ? "true" : "false");		//	bool�ڷ���ó�� ����� �ʹ�. �� �� stdbool.h �� ����

	bool bt = true; //c++�� �޸� keyword�� �ƴϴ� define�� keyword�� �Ķ� ��
	bool bf = false;
	
	printf("\n");
	printf("True is %d\n", bt);
	printf("False is %d\n", bf);

	return 0;
}