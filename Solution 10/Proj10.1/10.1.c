/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Array & Memory */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// array ����� ���� �� ������ �ִ� ��
// array�� ���ӵ� �޸� ������ �Ҵ����
/*
�迭�� �ε����� (�ش� ���� �ּ� - ù ���� �ּ�) / sizeof(�ڷ���)�� ����
[0] [1] [2] [3] �ȿ� 0 1 2 3�� ù��° �ּҷκ����� �Ÿ� �� �ǹ��Ѵ�.
C��� ���ۿ����μ� �迭�� �� �ּҸ� ù��° �ּҸ�ŭ ���� �� sizeof(�ڷ���)���� ������ ���� �ش� data�� index�̴�.
*/
int main()
{
	/* Monthly temeperatures */
	int high[12] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; // []bracket square bracket {}brace
	int low[12] = { -7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5 };
	// array�� 4000�� 40000�� �޴� ��쵵 ���� array = pointer
	// index = subscript = offset
	// &arr[1] 1�� ������  �ü���κ��� �Ҵ���� ù��° �ּҺ��� �ڷ����� �����ŭ ����. ���������δ� 2�� 3�̸� �ѹ��� �� ����.
	// &arr[0] = &(arr[0])
	// int arr[4] 4byte�̹Ƿ� [0] [1] [2] 4byte �ǳʶ� �ּ�
	const int a = 5;

	return 0;
}