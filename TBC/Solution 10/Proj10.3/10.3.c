/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Pointer Arithmetic �������� ��� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    //int* ptr = 0;// ������ ������ (int*) 0; �װͺ��� NULL�� �ʱ�ȭ�� �´�. ������ ���� �����ַ��� �׷��Ŵ�.
    ////try double*, long long*, char*, void*(void*�� �ڷ����� ���ٴ� �ǹ��̱⿡ ������ ��� ���� �Ұ��� �ϵ���� �� �ǿܷ� ����)

    ////printf("%d", *ptr);  // Error in this lecture

    //printf("%p %lld\n", ptr, (long long)ptr);

    //ptr++;  // try -=, ++, -- , - , +(������ ������ 1�� ���ϸ� �ּҰ��� 1��ŭ �������� �� �ƴ϶� �������� �ڷ��� ũ�� ��ŭ ��������)
    //ptr += 2;
    //ptr -= 2;
    //// �޸𸮰� � ���̴ٴ� ���α׷��ӿ��� �ǹ̴� ����. ��ŷ�� �� ����
    //printf("%p %lld\n", ptr, (long long)ptr);

    //ptr = -ptr;  // Not working(���� �����ڷμ��� +,- �� ��� �Ұ�) �ּ��� ���� ������ �ٲ۴ٴ� �� �ǹ̰� ����. ���Ƶ�
    //ptr = +ptr;  // Not working(���� �����ڷμ��� +,- �� ��� �Ұ�)

    /* Subtraction */
    double arr[10];
    double* ptr1 = &arr[3], * ptr2 = &arr[5];

    //ptr2 = ptr1 + ptr2;  // Not working(������ �������� ���ϴ� �� �Ұ���. �� �ǹ̸� ������ �ʱ⿡ ö���� �ּҿ� ������ �ּҸ� ���غ���)
    int i = ptr2 - ptr1;  // Working(������ �������� ���� �� ����. �� �ּ��� ���̸� �� �� �ֱ⿡. �־��� �ڷ����� ũ�� ��ŭ �� ĭ ������ �ִ����� ����� �˷��ش�)
    // index ����

    printf("%lld %lld %d\n", (long long)ptr1, (long long)ptr2, i);


	return 0;
}