/* ����/���� ������ */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/* https://en.cppreference.com/w/c/language/operator_precedence */
int main()
{
	int a = 0;
	a++; // a = a + 1 or a += 1(shorthand assignment operator); ++�� �����ϴ� ���� ����� �������� a++ �ڿ�������
	 // programming���� +1�� ���� ���ȴ�. ���̽㿡�� ����.
	printf("%d\n", a);

	++a; // a = a + 1 or a += 1;
	printf("%d\n", a);

	/*double b = 0;
	b++; 
	printf("%f\n", b);

	++b;
	printf("%f\n", b);*/

	//int count = 0;
	//while (count < 10) // ++count(���� ������) or count++(���� ������) while (count++ < 10) toggle f9
	//{
	//	printf("%d ", count++); // ++count or count ++ // ����ϰ� ���߿� �����ϳ�? �򰥸��� �ʳ�? �̷� ��� ����ض�.
	//	// �ǿܷ� ���� �� �򰥸� �� ������ ȿ���� ������ ����Ѵ�.
	//	// ���ʿ� c���� ȿ������ ���Ϸ��� ����ϱ� ����
	//
	//	//count++;
	//}
	//printf("\n");

	/*int i = 1, j = 1;
	int i_post, pre_j;

	i_post = i++;
	pre_j = ++j;

	printf("%d %d\n", i, j);
	printf("%d %d\n", i_post, pre_j);*/

	/*int i = 3;
	int l = 2 * --i; //���� �����ڴ� �������� �켱������ �ſ� ����. ��ȣ �����ϰ� ���� ����
	printf("%d %d\n", i, l);

	i = 1;
	l = 2 * i--;
	printf("%d %d\n", i, l);*/

	/* very high precedence */
	//int x, y, z;
	//x = 3, y = 4;
	//z = (x + y++) * 5; // (x+y)++ or x+(y++) ?
	//printf("%d %d %d", x, y, z);

	/* ++ and -- affect modifiable L-values ���������� lvalue���� ��� ���� */ 
	//int x = 1, y = 1, z;
	//z = x * y++; // (x) * (y++), not (x*y)++      (x*y)�� �޸� ������ ���� ���� ���ϰ� �ӽ÷� ���� ������ ���� ��
	//printf("%d %d %d", x, y, z);
	////z = (x * y)++; // error
	////z = 3++; // error

	/* Bad practices */// ���α׷��� �Ƿ��� �������� �̷� �� �ǿܷ� ���� �� �� �ִ�.
	// �㳪 �������� ����. �ʹ� �����ϰ� ���� ���� �ʴ�. �̷� ���� �ְ� ���� ���� �ִ� ��쿣 ���� ���� �� ��
	int n = 1;
	printf("%d %d\n", n, n * n++); // ���� ��� �Լ� ȣ���� �� ���ڷμ� �� �� n�� ���� �� ����� �� system���� ����� �ٸ��� ���� �� �ִ�.
	int x = n / 3 + 5 * (1 + n++); //system�� �ٸ� ���� ���� �� �ִ�. �̷� ��쿣 �ɰ��� ���. �ǵ��� ��Ȯ�� �ض�.
	int y = n++ + n++; // �򰥸��� �ǵ��� ���� �𸣰ڴ�.
	printf("%d %d", x, y);

	return 0;
}