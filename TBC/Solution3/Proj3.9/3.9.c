/* Fixed-width Intengers */
#include <stdio.h>
//#include <stdint.h> // also included in inttypes.h �̹� �ִ� �ڷ������� �̸��� �ٲ㼭 ����� �� �ְ� ���ش�.
#include <inttypes.h> //�����ʺ��������� ���������ڸ� �𸣴� ����ϴ� ������� PRId32
// c������ �ڷ����� �ּ� �޸� ũ�⸸ �����Ѵ�. �ѽý��ۿ��� ���� �ڵ尡 �ٸ� �ý��ۿ����� �� �۵����� ���� �� �����Ƿ� �̽ļ��� ���� ������ �ʿ��ϴ�.
//multiplatform�� �� ���� �Ű��� ����
int main() 
{
	int i;
	//
	int32_t i32;		//32 bit integer�� ��Ȯ�� ������ int32 int8 int64 �ʺ� ������Ű�� ��ó�� Ư���� ũ�⿡ ���� ��Ȯ�� ǥ���Ѵ�. 
	int_least8_t i8;	// smallest 8 bit ��� 8��Ʈ�� ���� �ִ� type���� i8����
	int_fast8_t f8;		// fastest minimum 8bit �߿��� ���� ���� ��
	intmax_t imax;		// biggest signed integers signed integers�߿��� �޸𸮸� ���� ���� ����ϴ� ��
	uintmax_t uimax;	// biggest unsigned integers

	i32 = 1004;

	printf("me32 = %d\n", i32);
	printf("me32 = %" "d" "\n", i32);//printf ���ڿ��� �ɰ��� ���� ������
	printf("me32 = %" PRId32 "\n", i32);// PRI�� print "d" = macro PRId32 scanf�� ����
										//Fixed-width Integers�� ����� �� ���������� format specifier�� �𸣴� ���� define
	printf("wow" "haha");


	return 0;
}