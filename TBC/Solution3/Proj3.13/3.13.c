/* Boolean Types */
#include <stdio.h>
#include <stdbool.h>

int main() 
{
	printf("%u\n", sizeof(_Bool)); // 1 byte �ڷ����� ���� �� �ִ� ���� ���� ����� ����Ʈ�� 1 byte
	// �ֳ��ϸ� ����Ʈ�� �ּҸ� �������� �� �ִ� �ּҴ���
	// �׷�, ������ 7bit�� ���� �ƴϳ�? ��Ʈ�����ڿ��� ���� ������ 7��Ʈ
	
	_Bool b1;
	b1 = 0; //false
	b1 = 1; //true;

	printf("%d\n", b1); // ���ٸ� format specifier�� ���� %d����.

	bool b2, b3;//stdbool.h �߰� �� ���� ����
	b2 = true;
	b3 = false; //����� ����ó�� �� �� �ִ�.
	//������ ������ ��ǻ�ʹ� true�� false�İ� �ƴ϶� false�� �ƴϸ� true��. �̷������� �Ǵ���
	printf("%d %d\n", b2, b3);


	return 0;
}