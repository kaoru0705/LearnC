/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* 2���� �迭�� ������ */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//���� ����
// int arr[2][3] �޸� ������ �д� �� �߿��ϴ�.
// arr + 1 == &arr[1] == &arr[0] + 1 == &arr[1][0] != arr[1][0]
// arr == arr[0] == &arr[0] == &arr[0][0] != arr[0][0] �̰��� ����Ű�� �ּڰ��� �����ϴٴ� ������ �ڷ����� ���ٴ� �� �ƴϴ�. pdf�� ����
// �̶� ���������Ͱ������� �� �� arr[0]��ü�� �����Ϳ� ���� ���±� ������ &�� ���̸� arr[0]�� �����ϰ� �ִ� �ּ� �ƴѰ� ������ �� �ִ�.
// ������ &�� ���δٰ� �ؼ� �ּҰ� ��򰡿� ������� �ʴ´�. �����Ϸ��� ���������� index�� ���� ������� ��
// ���� arr[0] == &arr[0] �迭������ ����. �������� �迭������ �ٸ� �� �ִ�. ref 10.12 d_ptr != &d_ptr
// &parr[0] != parr[0] but &arr[0] == arr[0]
//in 10.13 �迭�� �̸��� ù ��° ������ �ּ� ��, arr == &arr[0]
// arr[0](�� ��° �ε����� ���� �迭�� �̸��̶� �� �� �ֱ� ����) == &arr[0][0]
// in 10.13c printf("%p\n", arr);  // �迭�� ��ġ ù ��° ������ �ּ��� ��ó��(&arr[0]) ����� �� �ִ�.
// �׷��� �迭���� �ּҸ� ������ �� �ִ� ������ ������ ���� ������ ������ �ִ� �� �ƴ϶� C �������� arr[0]�� �ּҸ� ����� �� �ְ� ���ִ� ���� ���̴�. �������� �迭�� �������� l-value�� �ƴԤ���
// �̷� �� ���� �� ����. arr(&arr[0] �ּҵ�����) parr[0](arr[0]) parr(&parr[0])
int main()
{
	//float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f} };

	//printf("%p %p %p %p %f\n", arr2d, arr2d[0], &arr2d[0], &arr2d[0][0], arr2d[0][0]);
	//printf("%u\n", (unsigned)arr2d);		//use unsigned long long in x64
	//printf("%u\n", (unsigned)arr2d[0]); // == &arr2d[0] arr2d[0]�� �ּҰ� ����ִ� �޸� ������ ã�� �� �ƴ϶� �׳� arr2d[0]�� �ּҴ�. ���������Ͷ� �ٸ���. 
	//printf("\n");

	//// arr2d points to arr2d[0] (not arr2d[0][0] �̰� �׳� �޸� ������ ��), KNK Ch. 12.4
	////arr2d == &arr2d[0] 'points' to arr2d[0], *arr2d == arr2d[0]

	//printf("%u\n", (unsigned)* arr2d);
	//printf("%u\n", (unsigned)& arr2d[0]);	// C language allows this
	//printf("%u\n", (unsigned)& arr2d[0][0]);
	//printf("%f %f\n", arr2d[0][0], **arr2d);
	//printf("\n");

	//printf("%u\n", (unsigned)(arr2d + 1));		// ����4��(16byte) �ǳ� �� 10.15 ���Ұ� 4���� �迭�� ������
	//printf("%u\n", (unsigned)(&arr2d[1]));		// arr2d + 1
	//printf("%u\n", (unsigned)(arr2d[1]));		// 
	//printf("%u\n", (unsigned)(*(arr2d + 1)));	// *(arr2d + 1) = *(&arr2d[1]) -> arr2d[1]
	//printf("%u\n", (unsigned)(&arr2d[0] + 1));	// arr2d + 1
	//printf("%u\n", (unsigned)(&arr2d[1][0]));	// arr2d[1]
	//printf("\n");

	//printf("%f\n", *(*(arr2d + 1) + 2));		// *(arr2d[1] + 2) = *(&arr2d[1][2]) -> arr2d[1][2]
	//printf("\n");

	//int n1 = sizeof arr2d / sizeof arr2d[0];
	//int n2 = sizeof arr2d[0] / sizeof(float);

	//for (int j = 0; j < 2; ++j)
	//{
	//	printf("[%d] = %u, %u\n", j, (unsigned)(arr2d[j]), (unsigned)*(arr2d + j));
	//	for (int i = 0; i < 4; ++i)
	//	{
	//		printf("[%d][%d] = %f, %f\n", j, i, arr2d[j][i], *(*(arr2d + j) + i));
	//		*(*(arr2d + j) + i) += 1.0f; //arr2d[j][i] += 1.0f
	//	}
	//}
	//printf("\n");


	/* Pointers to Multidimensional Arrays */

	float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f} };
	float(*pa)[4]; // a SINGLE pointer to an array of 4 floats, 4���� float�� ���� �迭�� ����Ű�� pointer �� ��
	//float* pa; ���� �̰ſ��ٸ�? 2������ �Ұ��� 1����ó�� �� �� �ִ�. 10.5.có�� 10.15���� 
	float* ap[2];	// an array of TWO pointers-to-float, ���Ұ� 2���� �������� �迭 [] > *

	printf("%zu\n", sizeof(pa));	// �����Ͱ� �� ���ϱ� 4bytes, 8 in x64
	printf("%zu\n", sizeof(ap));	// �������� �迭 8bytes, 16 in x64
	printf("\n");

	pa = arr2d; // pa = &arr2d[0]�� �����ϰ� �۵�, arr2d�� 4���� float(arr2d[0])�� ����Ű�� �����Ϳ� ���� ���´�. �׷��⿡ arr2d + 1�� ���������� �Ѿ�� �� arr2d[0]�� float(arr2d[0][0])�� ����Ű�� �����Ϳ� ���� ����
	//pa[0] = arr2d[0];	// error �����Ͱ� �ϳ��� �迭ó�� �� �� ����. ����������ó�� �� �� �ִ�. 10.5c�� ptr[1] = 5;�� ���ݾ� �װ� ���̴ϱ�
	//pa[1] = arr2d[1];	// error

	//ap = arr2d;		// error not modifiable l-value �������� �迭�� �̷��� �ʱ�ȭ ap�� &ap[0] ������ �������� �ּҿ��� �� �ֳ�
	ap[0] = arr2d[0];
	ap[1] = arr2d[1];
	printf("%zu %zu\n", sizeof(&arr2d[0]), sizeof(&pa[0])); // &arr2d[0] &pa[0]�� pointer ������ like ref 10.13 arr2d[0] pa[0]�� 16byte
	printf("\n");
	printf("%u %u\n", (unsigned)pa, (unsigned)(pa + 1)); // ap ap+1���� ���̴�?
	printf("%u %u\n", (unsigned)arr2d[0], (unsigned)arr2d[1]);
	printf("%u %u\n", (unsigned)pa[0], (unsigned)(pa[0] + 1));
	printf("%f\n", pa[0][0]);
	printf("%f\n", *pa[0]);
	printf("%f\n", **pa);
	printf("%f\n", pa[1][3]);
	printf("%f\n", *(*(pa + 1) + 3));
	printf("\n");

	printf("%u %u %u\n", (unsigned)ap, (unsigned)&ap[0], (unsigned)(ap + 1)); // �������� �迭 �����͸� ��� �迭�� ���� ���� �� �������� �ּ�
	printf("%u %u\n", (unsigned)arr2d[0], (unsigned)arr2d[1]);
	printf("%u %u\n", (unsigned)ap[0], (unsigned)(ap[0] + 1));
	printf("%f\n", ap[0][0]);
	printf("%f\n", *ap[0]);
	printf("%f\n", **ap); // *(*(&ap[0])) -> *(ap[0]) = *(&ap[0][0]) -> ap[0][0]
	printf("%f\n", ap[1][3]);
	printf("%f\n", *(*(ap + 1) + 3));

	float ar[2][4];
	float(*pr)[4] = &ar[0]; // ar�� (float*)[4]��� ������ ar[0]�� float[4]�� �� �ְ� ar[0] = &ar[0][0]��� ������ float*�̱⵵ �ϴ�
	return 0;
}