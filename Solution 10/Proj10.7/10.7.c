/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �迭�� �Լ����� �������ִ� ��� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// ������ ���� �迭�� �����͸� ���� �Լ����� ����Ѵٸ�? �ּҸ� ��ߵȴ�.
double average(double array[], int n);
//double average(double *arr, int n);  // �� �ڵ�� ���� �ᱹ �����͸� ���̾� �迭�� ǥ���غ��� �����ʹ�
//double average(double *, int);  // �� �ڵ�� ����(�Ϲ������� �Ű������� �̿� ���� ����Ǿ� ������ �迭�� ���޹޴� �Լ��� �Ǵ��Ѵ�)
//double average(double [], int);  // �� �ڵ�� ����

int main()
{
    double arr1[5] = { 10, 13, 12, 7, 8 };
    //double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
    double arr2[3] = {1.8, -0.2, 6.3}; //size is different

    printf("Address = %p\n", arr1);
    printf("Size = %zd\n", sizeof(arr1));
    printf("Address = %p\n", arr2);
    printf("Size = %zd\n", sizeof(arr2));
    printf("Avg = %f\n", average(arr1, sizeof(arr1) / sizeof(arr1[0])));
    printf("Avg = %f\n", average(arr2, sizeof(arr2) / sizeof(arr2[0])));

	return 0;
}

//double arerage(double* data_array) {  // �Ʒ� �ڵ�� ����
double average(double data_array[], int n) {  // �Ʒ� �ڵ�� ����(�迭�� �μ��� ���� �޴´ٴ� ���� ��Ȯ���ϴ� �������� ������ ��� �̷��� ǥ���� �� �ִ�)
//double average(double data_array[5], int n) {// �迭�� Ư���� �����Ͱ� ���� ���� ������ ��°�� �����ؼ� �޴� �� �ƴ϶� �����ͷ� �޴´�. 5�� �ǹ� ����
    // ���� �Ϲ����� �Լ��� ����ϱ� ���� �Ű����� n�� ���� �迭�� ũ�⸦ ���� ���� �޴´� �Ű�����ȭ
    printf("Size = %zd in function average\n", sizeof(data_array));  // ��°� : 4, 8(������ ������ ũ�Ⱑ ��µȴ�. �Ű������� �迭�� �����ϸ� ũ��� ������� �μ��� �Է��� �迭�� �ּҸ� ���޹ޱ� �����̴�.)
    double avg = 0.0;
    for (int i = 0; i < n; ++i) {
        avg += data_array[i];
    }
    avg /= (double)n;
    printf("%p ", data_array);
    printf("%p\n", ++data_array); // data_array�� �迭�̾��ٸ� �Ұ���
    // in c++������ �迭���� �����Ҵ��� ���� ����ϰ� �����Ҵ��� �����ͷ� ����.

    return avg;
}