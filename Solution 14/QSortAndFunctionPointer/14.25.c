/* qsort �Լ� ������ �������� */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <stdlib.h>

//TODO: try increasing/decreasing order
int compare(const void* first, const void* second) // �԰��� ����������
{
	if (*(int*)first > *(int*)second) // �ٷ�� �� ������ int casting��
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main(void)
{
	int arr[] = { 8, 2, 5, 3, 6, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, n, sizeof(int), compare); // quick sort�Լ��� �̹� stdlib���� �����Ǿ� �ִ�. �� ������ int ���� �Լ��� �� �������? �ٸ� �ڷ����� �����ϴ� �� ����� �� �ִ�.
	// �Լ��� �־��ָ� qsort�� �Լ������͸� ����ؼ� ������ ��
	// float�� �ٲٰų� ������������ �ٲ� �� �ִ�.
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}