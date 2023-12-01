//변환 지정자의 수식어들 Modifiers
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <limits.h>

int main()
{
	printf("%10i\n", 1234567);
	printf("%-10i\n", 1234567); //왼쪽으로 정렬
	printf("%+i %+i\n", 123, -123); //부호에 맞게 +-출력
	printf("% i % i\n", 123, -123); //음수면 - 양수면 빈칸 출력
	printf("%X\n", 17);
	printf("%#X\n", 17);
	printf("%05i\n", 123); // 순서대로 파일 이름을 출력하고자 할 때 등등 
	printf("%*i\n", 7, 456); // 앞에 숫자가 *자리로 들어감 scanf에서는 의미가 다름

	printf("\nPrecision\n");
	printf("%.3d\n", 1024);
	printf("%.10d\n", 1024); //정수면 0으로 채움
	printf("%010d\n", 1024);
	printf("%.3f\n", 123456.1234567); //소수면 소수자릿수
	printf("%.3f\n", 123456.1235);// 반올림
	printf("%10.3f\n", 123.45678);
	printf("%010.3f\n", 123.45678); // 10은 전체 수 소수점 포함 
	printf("%.5s\n", "ABCDEFGHIJKLMN");
	printf("%.s\n", "ABCDEFGHIJKLMN"); // assumes .0
	printf("hip" "%" "d" "da hop\n", 2);

	printf("\nLength\n");
	printf("%hhd %hd %d\n", 257, 257, 257);
	printf("%lld\n", 2147483648LL);
	printf("%d %lld %lld\n", INT_MAX + 1, INT_MAX + 1, 2147483648LL); // x86 과 x64는 출력값이 다르다.
	// 마우스를 갖다 대니까 2147483648'i64'라고 나온다.  64자료형임
	// 이게 제대로 안 나온 이유는 64비트가 아니라 INT_MAX를 int형으로 받아들인다. 
	// 그래서 4.9와 마찬가지로 4 8 8이라 밀려서 마지막 게 제대로 안 나옴.
	// x86이어도 long long 은 8바이트, long long이 x86이라 안 나오는 거라고 헷갈리지 마라 패딩 배우면 이해됨
	printf("%lld %d\n", INT_MAX + 1, INT_MAX + 1); //x86 쓰레기값
	printf("%lld\n", 2147483648LL);
	printf("%lld\n", 32); // x86쓰레기값 int와 쓰레기가 붙어서 망함
	// 1000 0000 0000 0000 0000 0000 0000 0000 1000 0000 0000 0000 0000 0000 0000 0000까지 밀려 %lld에 들어감
	return 0;
}