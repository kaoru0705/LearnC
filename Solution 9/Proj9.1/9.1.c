/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �Լ��� �ʿ��� �� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	// strlen()
#include <stdbool.h>

// ���α׷����� �� �� ���Ѿ� �� �� ����
// �Ϲ�ȭ��� �������� �� ���� ��쿡 ���� ���� �۵��� �� �ֵ��� �ϱ�
// ���� ����� ���� �� ������ �� �� - ���������� �������
// �Լ��� �̸��� �� �����
/* My poor answers */
//void staroutput(int starcount)
//void yourinfo(char name[], char location[]);
#define WIDTH 40
#define NAME "Jeong-Mo Hong"
#define ADDRESS "Seoul, Korea"
/* try 2 */
//void print_bar(int n_stars) // �󸶵��� ���� �Է��� �� �ִ�.
//{
//	for (int i = 0; i < n_stars; ++i)
//		printf("*");
//	printf("\n");
//}
//
//void print_blank(int n_blank) // �󸶵��� ���� �Է��� �� �ִ�.
//{
//	for (int i = 0; i < n_blank; ++i) // ctrl + R ctrl + R
//		printf(" ");
//}
/* try 4*/
//void print_multiple_chars(char c, int n_stars) // �Լ� �ϳ��� ��ħ
//{
//	for (int i = 0; i < n_stars; ++i)
//		printf("%c", c);
//
//}
void print_multiple_chars(char c, int n_stars, bool print_newline) // �Լ� �ϳ��� ��ħ
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
int main()
{
	/* try 1 */
	//printf("*********************\n");
	//printf("	Jeong-Mo Hong	\n);
	//printf("	Seoul, Korea	\n");
	//printf("*********************\n");	// ����� ��ģ��.
	
	/* try 2 */
	//print_bar(WIDTH); // ���� print_bar()�� input ���� �� �Է��ؾ� �Ѵ�. c++������ �⺻���̶� �� ���� �� �ְ� �ȴ�.
	//print_blank(10);
	//printf("   %s\n", NAME);
	//printf("   %s\n", ADDRESS);
	//print_bar(WIDTH);

	/* try 4 ������ ������ stdbool Ȱ�� */
	/*print_multiple_chars('*', WIDTH);
	printf("\n");

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("I love you");

	print_multiple_chars('*', WIDTH);
	printf("\n");*/
	
	print_multiple_chars('*', WIDTH, true);

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("I love you");

	print_multiple_chars('*', WIDTH, false);

	/* try 3 �� ��� �ߺ� */
	/*int n_blanks = 0;
	n_blanks = (WIDTH - strlen(NAME)) / 2;
	print_multiple_chars(' ', n_blanks);
	printf("%s\n", NAME);

	n_blanks = (WIDTH - strlen(ADDRESS)) / 2;
	print_multiple_chars(' ', n_blanks);
	printf("%s\n", ADDRESS);*/

	// �Լ��� ������� �ʴ� �ڵ带 ����ϴ� ������ �ٲٰ� �ִ�. REFACTORING

	return 0;
}