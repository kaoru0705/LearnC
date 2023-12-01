/* assert ���̺귯�� (������� �� �����ϰ� ����� �� �ִ�)*/
#define _CRT_SECURE_NO_WARNINGS // �̰� �� ���� �� ������ ���� ��
#include <stdio.h>
#include <assert.h>

//#include <limits.h>
//_Static_assert(CHAR_BIT == 9, "9-bit char assumed"); ������Ÿ�ӿ� ����ִ� assert MSVS������ �ȵ� CHAR_BIT�� ��κ� 8��Ʈ�̹Ƿ� assert�� ��.
//// ��Ȳ�� �������� �ٸ� �� �ִ� ��Ƽ�÷����� ��� ���� c++�� �� �ȴ�.

int main(void)
{
    int a, b;
    int f = scanf("%d%d", &a, &b);

    printf("a / b = %d", divide(a, b));

    return 0;
}

int divide(int a, int b)
{
    assert(b != 0);  // �ݵ�� �����ϴ� ���ǿ� ���� assert. ������Ű�� ���� ��� debug�� ���� ����. Release ��忡�� �����Ű�� assert�� �����Ѵ�(���忡 ���Ե��� �ʴ´�) ���ʿ� �����ϴ� ����̹Ƿ� ����
    // f5�� �ϰ� 3 0 �Է� retry�� �ϸ� debugging mode�� ���� �˷���
    // �Ʒ� �ڵ�� �������� �ּ����� ��ɸ� ���� �� �ƴ϶� ������带 �߻���Ų�� ���� ȿ������ ���α׷��� ����� �ʹٸ� �̷� ��������� ����� ��
    // assert�� ���Ƴ��� �ٺ����� ������ �ذ��ϴ� ���� �Ǵ�.
    //if(b == 0) {
    //  printf("Cannot divide\n");
    //  exit(1);
    //}

    return a / b;
}