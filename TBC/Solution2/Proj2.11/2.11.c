/* Syntax Errors Semantic[si maentic] Errors ���������� ���ƿ��� */
#include <stdio.h>

int main() 
{
	int n1, n2, n3, n4;

	//n5 = 3; //compile �� = 1>C:\Users\KDH\source\repos\Solution2\Proj2.11\2.11.c(7,5): error C2065: 'n5': undeclared identifier
	// ������ visual studio ����ȯ�濡�� ����ִ� ��
	// output message compiler�� ���� �ϴ� ��
	// �ƹ�ư ���������� ��� ����.

	n1 = 1;
	n2 = n1 * n1;
	n3 = n2 * n1;
	n4 = n2 * n1; //���� ������ ��� �ذ��ϳ� 1. ����׷� �� ����
				  // 2.�ڵ��� �� �� compiler�� �ִ��� �����ִ� ������� ���α׷����� �� ���� ex) assault �ܾ��ϱ� ���߿� ����

	
	return 0;
}