/* build�� �� �ɼ����μ� ��� �������� �ٲ��� �� �ִ�. �׶� ��ó�� ���Ǹ� �̿��� �� �ִ�. */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>

#define REPORT  // ��ũ�� �̸��� ���ǵǾ� �ִ� ���� empty macro, �ڵ带 �Ź� �ٲ�� �ϴµ� �̰� ���������� �������Ѵٰ� �� �� �ֳ�?

/*
    ����� ���� ������ ����� ����
    - �������� �� �ɼ����� ����׿� �ʿ��� ������ ���忡 ���Խ�Ű��� ��ó�� �����ڿ��� ����� ���°�, �� ���°��� ����
*/

int sum(int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; ++k)
    {
        s += k;

//#ifdef _DEBUG   // ����� ��忡���� �������ϴ� �ڵ� preprocessor definition�� �̹� �� �ִ�.
#ifdef REPORT  // TODO: change in project properties(VS���� [C/C++]-[Preprocessor] [Preprocessor Definitions]���� ��ó���� ���ǰ� �̸� ���� �� �� �ִ�. �ű⼭ REPORT;)
        printf("%d %d\n", s, k);
#endif
    }

    return s;
}

int main(void)
{
    printf("\n%d \n", sum(1, 10));

    return 0;
}