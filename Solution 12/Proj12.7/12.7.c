/*��� ������ ����(Static) ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Static with no linkage: ���� �����̱⿡ ���α׷��� ���ۺ��� ������ ��� �޸𸮿� ���������� ��� �ȿ����� �� �� �ִ�(visible)
// ��, �����͸� �̿��� ��� �ۿ����� ���������� ������ ���� ������ �׷��� ����Ϸ��� ��� ���� ��� �ۿ� ������ �����ϴ� �� ����
// �ǿܷ� ���� ����.

int* count()
{
    int ct = 0;  // ���ÿ� ����
    printf("count = %d %lld\n", ct, (long long)&ct);
    ct++;

    return &ct;  // ���� ���� ��ȯ������ �����͸� ��ȯ�ϴ� ��쵵 �� �ִ�. ex) API, �ϵ����, ���콺�� ������ �� �㳪
    // �Լ� ��ȯ���� int*�� �ٲ㺸��(warning C4172: returning address of local variable or temporary: ct ���� ct�� duration�� �Լ� ���� ������ �������. �����̱⿡ �Լ��� ����� ���Ŀ� �ش� �ּҸ� �����Ϸ� �ϱ⿡ ��� �߻�.
    // ���� ������ ��ü�� ����� �޸𸮸� �̸� ��� �ִ� ��찡 �ֱ� ������ �����ͷ� �����ؼ� ������ ��쵵 �ִ�. �����Ϸ��� ����ȭ ����� �����ϴ� �� �㳪 �����ؾ� �Ѵ�.
}

int* static_count()
{
    static int ct = 0;  // ������ �Ǵ� BSS�� static�ϰ� �ִ� ������ ����. initialized only once(���� ����� �ʱ�ȭ�� �и��� ��� �ǹ̰� ������ �޶�����)

    printf("static count = %d %lld\n", ct, (long long)&ct);
    ct++;

    return &ct;  // ������ �� ������ �̰� �� ���� ���� �Լ� ��ȯ���� int*�� �ٲ㺸��(�Լ��� ����� ���Ŀ��� �����͸� ���� �����ϴ� ����� ����ϱ⵵ ������ ���������� ������ �׷��� ������ �ʿ��ϴٸ� ���� ���� ������ �����ϴ� �� ����)
}

//int func(static int i)
//{  // Warning(Error in GCC): parameter�� �Լ��� ����� �� ���� �����ӿ� �����ȴ� �׷��� static�� ���δٴ� �� static�� �޸� ������ �Ķ���͸� ����ְڴٴ� ��
//}

void counter_caller()
{
    count();
}

void static_counter_caller()
{
    static_count();
}

int main()
{
    count();
    count(); //Ư���� �޸𸮸� ���� �� �ƴ϶� ����Ǵ� �Լ��� count()�ۿ� ������ �ö�Դ� ������ �ϸ鼭 ���� �޸𸮸� ����� ��
    counter_caller(); // counter_caller() ���� �ȿ��� �ٽ� �ѹ� count()�� ȣ���ؼ� �׿��ִ� ���� 12.5c ����

    static_count();
    static_count();
    static_counter_caller(); // �� �� ȣ���ص� ������ �����̴�. �� ���� �޸� static ct �׳� ct �޸� ���̾ƿ��� �ٸ���.

    return 0;
}