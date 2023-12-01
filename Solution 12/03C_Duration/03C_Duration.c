#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    Storage duration(�޸��� ���� �Ⱓ)
    - static storage duration (���α׷��� ���۵� ������ ���� ������ ��� �޸𸮿�  static�ϰ� �����ִ�. keyword�μ��� static���� �ٸ�
      (Note: 'static' keywords indicates the linkage type ������ ������ ����� �ʰ�, scope�� �о����� �ʵ��� ���� ��Ų��., not the storage duration)
    - automatic storage duration (���� ���������� �ǹ� stack)
    - allocated storage duration (�����Ҵ�)
    - thread storage duration (multi threading)
 */

void count()
{
    int ct = 0;
    printf("count = %d\n", ct);
    ct++;
}

void static_count()
{
    static int ct = 0;  // �Լ� ȣ�� �� �Ź� ������ ����/�Ҹ���� �ʰ� ���α׷� ���� �� �޸𸮰� �Ҵ�Ǿ� ���α׷� ���� �� �����ȴ�
    printf("static count = %d\n", ct);
    ct++;
}

int main() {
    count();
    count();
    static_count();
    static_count();

    return 0;
}