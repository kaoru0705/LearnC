// �� ������ �Է��ϰ� �ִ��� ���Ͽ� ���

#include <stdio.h>

void swap(int* ptr)
{
    int b = 7;
    int* temp = ptr;
    ptr = &b;
}
int main(void)
{
    int a = 5;
    int* p = &a;

    swap(p);
    printf("%d", *p);

    return 0;
}
