//��ȯ �������� ���ľ�� Modifiers
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <limits.h>

int main()
{
	printf("%10i\n", 1234567);
	printf("%-10i\n", 1234567); //�������� ����
	printf("%+i %+i\n", 123, -123); //��ȣ�� �°� +-���
	printf("% i % i\n", 123, -123); //������ - ����� ��ĭ ���
	printf("%X\n", 17);
	printf("%#X\n", 17);
	printf("%05i\n", 123); // ������� ���� �̸��� ����ϰ��� �� �� ��� 
	printf("%*i\n", 7, 456); // �տ� ���ڰ� *�ڸ��� �� scanf������ �ǹ̰� �ٸ�

	printf("\nPrecision\n");
	printf("%.3d\n", 1024);
	printf("%.10d\n", 1024); //������ 0���� ä��
	printf("%010d\n", 1024);
	printf("%.3f\n", 123456.1234567); //�Ҽ��� �Ҽ��ڸ���
	printf("%.3f\n", 123456.1235);// �ݿø�
	printf("%10.3f\n", 123.45678);
	printf("%010.3f\n", 123.45678); // 10�� ��ü �� �Ҽ��� ���� 
	printf("%.5s\n", "ABCDEFGHIJKLMN");
	printf("%.s\n", "ABCDEFGHIJKLMN"); // assumes .0
	printf("hip" "%" "d" "da hop\n", 2);

	printf("\nLength\n");
	printf("%hhd %hd %d\n", 257, 257, 257);
	printf("%lld\n", 2147483648LL);
	printf("%d %lld %lld\n", INT_MAX + 1, INT_MAX + 1, 2147483648LL); // x86 �� x64�� ��°��� �ٸ���.
	// ���콺�� ���� ��ϱ� 2147483648'i64'��� ���´�.  64�ڷ�����
	// �̰� ����� �� ���� ������ 64��Ʈ�� �ƴ϶� INT_MAX�� int������ �޾Ƶ��δ�. 
	// �׷��� 4.9�� ���������� 4 8 8�̶� �з��� ������ �� ����� �� ����.
	// x86�̾ long long �� 8����Ʈ, long long�� x86�̶� �� ������ �Ŷ�� �򰥸��� ���� �е� ���� ���ص�
	printf("%lld %d\n", INT_MAX + 1, INT_MAX + 1); //x86 �����Ⱚ
	printf("%lld\n", 2147483648LL);
	printf("%lld\n", 32); // x86�����Ⱚ int�� �����Ⱑ �پ ����
	// 1000 0000 0000 0000 0000 0000 0000 0000 1000 0000 0000 0000 0000 0000 0000 0000���� �з� %lld�� ��
	return 0;
}