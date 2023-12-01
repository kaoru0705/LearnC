/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �迭 �Ű������� const */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_array(const int arr[], const int n) // print�� print�� �ϴϱ�
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void add_value(int arr[], const int n, const int val) //�̰͵� �������� �㳪 const int arr[]�� �ȵȴ�. , ���п��� ���� ���� �Լ�
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] += val;
}

int sum(const int ar[], const int n) // const�� ���� ���� ���� �迭 ������ ���� �������� ���ϵ��� ����. �迭 ũ�⵵ ������ �����Ƿ� const�� ����
{
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
        total += ar[i];
    //total += ar[i]++;  // wrong implementation const
    //const int ar[]�� �ƴ϶� int ar[]�̾��ٸ�? ���α׷��Ӵ� ����̱⿡ �Ǽ��� �Ѵ� �����Ͻð� �̸� ����ؾ��Ѵ�. ���������� �����Ϸ��� ������ ã�� �� �ֵ��� �Ѵ�.

    return total;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 }; // ���⿡ const�� ���̸�? add_value���� ���
    const int n = sizeof(arr) / sizeof(arr[0]); 

    print_array(arr, 5);
    add_value(arr, 5, 100);
    print_array(arr, 5);

    int s = sum(arr, n);
    printf("sum is %d\n", s);
    print_array(arr, 5);

	return 0;
}