/* ������ �����÷ο� Overflow */

#include <stdio.h>
#include<limits.h>//�̰� �����ϸ� unsigned�� ���� ū �� signed�� ���� ���� ���� �˷���
//�ڷ����� ���� �޸��� ���迡 ���� �� �� ������ �� �ִ� �����÷ο�
#include <stdlib.h> // itoa() int to string

int main() 
{
	/*unsigned int i = 0;
	sizeof(unsigned int);*///cursor�� ���ٴ�� 4u(4byte)��� �� visual studio�� �˷���

	//unsigned int i = 0b11111111111111111111111111111111;//0b�� literal�� binary�ٸ� ǥ��, c������ 0b�� ǥ���� �ƴ� ������ ��κ��� �����Ͽ��� ��밡��
	//unsigned int u_max = UINT_MAX;
	//unsigned int u_min = 0; //UINT_MIN�� ����.
	//signed int i_max = INT_MAX;
	//signed int i_min = INT_MIN;//go to definition

	//printf("%u\n", i);
	//printf("%d\n", i); //-1�� ���� ���������ڸ� ����� �ؾ� �� 
	//printf("max of uint = %u\n", u_max);
	//printf("min of uint = %u\n", u_min);
	//printf("max of int = %d\n", i_max);
	//printf("min of int = %d\n", i_min);

	unsigned int u_max = 0 - 1; //UINT MAX + 1 �� 0 ��µ�
	// 0000 - 1 = 1111
	// i to binary representation 2������ �ٲ���
	int i_max = INT_MAX + 1;// Severity	Code	Description	Project	File	Line	Suppression State Warning	C26450	Arithmetic overflow : '+' operation causes overflow at compile time. Use a wider type to store the operands(io.1).Proj3.6
	int i_min = INT_MIN + 1;//2�� ������ ��ȣ��Ʈ���� �ٲ�� �ȴ�. �翬�� �� 2�Ǻ����� ��ǻ�Ͱ� ������ �� �ؼ� ������� �ű� ����
	//+(-0011)->1101       -1-1111(2�Ǻ��� �ϱ� ������ �ǵ�����) = -0011
	// 1111 + 1 -0011 -> 1101 ����� �� �ٽ� -10000
	//7 - 4 = 0111 - 0100 = 0111 + 1100 = 1 0011 = 0011 = 3
	//�� ��Ȯ�� 7 - 4 = 0111 - 0100 = 0111 + 10000 - 0100 - 10000 = 0111 + 1100 - 10000 = 10011 - 10000 = 0011
	char buffer[33];
	_itoa(u_max, buffer, 2); // int to string

	printf("%d\n", i_max);
	printf("%d\n", i_min);
	//print decimal and binary
	printf("decimal: %u\n", u_max);
	printf("binary: %s\n", buffer);//2���� ���·� ���

	//������ �ִ� ���� ������� �ʰ� �Ѿ�� �޸𸮰� ������ �� ����. Overflow
	
	//unsigned int i;
	//printf("%u\n", sizeof(unsigned int));
	//printf("%u", sizeof(i));//if unsigned %u

	printf("%hhd", 300);

	return 0;
}