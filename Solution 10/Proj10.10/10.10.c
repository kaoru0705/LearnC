/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* const�� �迭�� ������ */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// ������ ����� �ٲٵ�
int main()
{
    // type qualifiers(������, �ڰ� �ο�): const, volatile ...

    //const double PI = 3.14159;  // const�� �ڷ��� ��,�쿡 ��� ���� �� �ְ� �Ϲ� �������� �־� ����� �����ϴ�
    //double const PI = 3.14159;  // const �� ���� �� �ִ� ������ ������ ���� �ٿ��� �Ǽ��� �����ϱ� �������� ����.
    const double PI = 3.14159;
    //PI = 2.14159;
    
    //const int arr[5] = { 1, 2, 3, 4, 5 };  // �迭�� const�� ���̸� �迭�� ������ ������ ������ �� ���� �ȴ�
    int arr[5] = { 1, 2, 3, 4, 5 };
    arr[1] = 123;

    const double arr2[3] = { 1.0, 2.0, 3.0 };
    //arr2[0] = 100.0;

    double* pd = arr2;  // warning C4090: 'initializing': different 'const' qualifiers pro10.10 right click project only rebuild�� �ٽ� �� �� ����
    //�迭�� const�� ���������� �����ͷ� ������ ���� �� �����ͷ� �迭 ���ҿ� �����ؼ� ���� ������ �� �ִ� �������� ����(�����Ϸ��� ���Ƴ��� ��쵵 �ִ�)
    //const double* pd = arr2;  // ������ �ڷ��� ���ʿ� const�� �ٿ��� dereferencing�� ���� �� ������ �����Ѵ�(������ ���� ���� ���� ������ �ּҰ��� �����ϴ� �� ������ ���� pd++;)
    //double* const pd = arr2;  // ������ ���� �� �ٲ۴�. (������ ���� ���� ���� ������ �ּҰ� ���� �Ұ�)
    //const double* const pd = arr2;  // ������ �ڷ��� ���ʿ� const�� �ٿ��� dereferencing�� �ּҰ� ���� ��� ���� �ǿܷ� ���� ��

    printf("%f %f\n", pd[2], arr2[2]);

    *pd = 3.0;  // ������ ǥ��: pd[0] = 3.0; or arr2[0] = 3.0;
    pd[2] = 1024.0;  // ������ ǥ��: arr2[2] = 1024.0;

    printf("%f %f\n", pd[2], arr2[2]);

    //pd++;  // allowed
    printf("%f %f\n", pd[2], arr2[2]);

    int a = 5;
    int* aptr = &a;
    aptr += 5;
    printf("%p %p\n", aptr, &a);

	return 0;
}