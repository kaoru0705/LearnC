/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Functions's proto-type */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	// strlen()
#include <stdbool.h>
#define WIDTH 40
#define NAME "Jeong-Mo Hong"
#define ADDRESS "Seoul, Korea"
// ��� �Լ��� ���ο��� ��� �۵��ϴ����� �ܿ� �ʿ䰡 ����.
// ��ǲ �ƿ�ǲ�� �˰� ���(��ǰ)�� �����ϴ� �������� �� ������ ���α׷���
// ���ΰ� ���ڽ� �㳪 ��ǲ �ƿ�ǲ�� �˸� ��
void print_multiple_chars(char c, int n_stars, bool print_newline); // �̷��Ը� �ص� �������� �ǰ� ��ŷ�� �ȵȴ�.
/* ref 2.9 �������� ������ ��ŷ�ϴ� �������� ��Ŀ�� ��ü�� �������ش�. 
1>------ Build started: Project: Proj9.2, Configuration: Debug Win32 ------
1>9.2.c
1>9.2.obj : error LNK2019: unresolved external symbol _print_multiple_chars referenced in function _main
*/	// �������ϴ� �ܰ迡���� ������Ÿ��(�Է°� ��¸� ���� ���ڽ��μ��� �Լ�)�� ������ ������ ��
	// ���������� ����� ��ŷ�ܰ迡�� ��Ŀ�� ��ü�� ã�Ƽ� ������� �ش�. �����ϰ� ��ŷ�� �и��Ǿ� �ִ�.
	// �̷��� ������ ��ü���� ���α׷����� �� �������� �����ϴ� �� ������ �ȴ�.
//{
//	for (int i = 0; i < n_stars; ++i)
//		printf("%c", c);
//
//	if (print_newline == true)
//		printf("\n");
//
//}
void print_centered_str(char str[]); // prototype���� �ٲٴ� ��
// ��Ŭ�� quick actions and refactoriongs create declaration / definition ����� ���� ���� �Ѵ�.
// change signature ���� = ���ڽ��μ��� �Լ� ������Ÿ��, �Է��� ���� ����� ���� �Լ��� Ư¡�� ǥ���Ѵٰ� �ؼ� signature
// file�� ���� ���� ����� ������ �� �ܼ��ϰ� �����ϰ� �� �� �ִ�.

//void print_centered_str(); // ���� ���α׷��ֿ����� �̷��� �ص� �ƾ���.
//void print_centered_str(void); // �̷��� ������ ������ ������ warning () != (void)
//void print_centered_str(char[]);
//void print_multiple_chars(char, int, bool);
// ��� ������Ÿ�Կ��� �������� ��� �ȴ�. �ڷ����� ������ �� ���� ������
// ���ڽ� �������� �� �� � �ڷ����� ���� ���������� �˸� �Ǳ� ����
// ������Ÿ�Կ��� �� �ڷ����� ��� ���������� ����ϴ����� �� �ʿ� ����.
// �㳪 ��������� ���缭 ����ϴ� �� �� ����. ȥ���� �ٿ��� �㳪 �����ϴ� ��쵵 �ǿܷ� ���� ��
// 1 �ڵ尡 �ʹ� ����� ��� 2 �̸��� ���� �Լ��� �Ű������� �ٸ� ���·� ���� �� ������ ���
// ������ ��� �������� �����ϴ� ��찡 �ִ�.


int main()	// program�� ������ �� main�Լ��κ��� ����
{
	print_multiple_chars('*', WIDTH, true); // actual parameter/argument(���� ����) or argument

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("I love you");
	
	print_multiple_chars('*', WIDTH, false);
	return 0;
}

void print_multiple_chars(char c, int n_stars, bool print_newline)
// formel(������) argument/parameter(���� ����) or parameter(�Ű�����)
// �Լ��� ����� �Ϲ�ȭ ��Ų��. = �Ű�����ȭ  �Ű������� ���� ���� �޶����� 
// �Ű������� ���� ���������� ������Ÿ�Կ� ������ִ� �� ����. �� �ؾ� �ȴٰ� �� �� �ߴ�.
{
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c);

	if (print_newline == true)
		printf("\n");

}

void print_centered_str(char str[])
{
	int n_blanks = 0;
	n_blanks = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blanks, false); // debug error ���� Ŭ���ؼ� �� �������� �� �� �ִ�.
	printf("%s\n", str);
}