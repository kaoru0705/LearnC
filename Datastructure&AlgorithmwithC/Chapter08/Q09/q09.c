/* ���Ʈ-���������� ���ڿ��� �˻��ϴ� ���α׷� */
#include <stdio.h>

/*--- ���Ʈ-���������� ���ڿ��� �˻��ϴ� �Լ� ---*/
int bf_match(const char txt[], const char pat[])
{
	int pt = 0;		/* �ؽ�Ʈ Ŀ�� */
	int pp = 0;		/* ���� Ŀ�� */
	int count = 0;	/* �� Ƚ�� */
	int n = 0;		/* �õ� ��°*/
	int flag = 1;
	while (txt[pt] != '\0' && pat[pp] != '\0')
	{
		count++;
		if (flag)
			printf("%d ", n);
		else
			printf("  ");
		printf("%s\n", txt);
		printf(" ");
	for (int i = 0; i <= pt; i++)
		printf(" ");

		if (txt[pt] == pat[pp])
		{
			flag = 0;
			printf("+\n");
			pt++;
			pp++;
		}
		else
		{
			flag = 1;
			printf("|\n");
			n++;
			pt = pt - pp + 1;
			pp = 0;
		}

		printf(" ");
		for (int i = 0; i <= n - flag; i++)
			printf(" ");
		printf("%s\n\n", pat);
	}

	printf("�񱳸� %dȸ �õ��մϴ�.\n", count);
	if (pat[pp] == '\0')
		return pt - pp;
	
	return -1;
}

int main(void)
{
	int idx;
	char s1[256];		/* �ؽ�Ʈ */
	char s2[256];		/* ���� */

	puts("���Ʈ-������");
	printf("�ؽ�Ʈ : ");
	scanf("%s", s1);
	printf("���� : ");
	scanf("%s", s2);

	idx = bf_match(s1, s2);	/* �ؽ�Ʈ(s1)���� ����(s2)�� ���Ʈ-���������� �˻��մϴ�. */
	if (idx == -1)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else
		printf("%d��° ���ں��� match�մϴ�.\n", idx + 1);

	return 0;
}
///* Q9 ���Ʈ-���������� ���ڿ� �˻�(�˻� ���� ���) */
//#include <stdio.h>
//#include <string.h>
//
//int bf_match(const char txt[], const char pat[])
//{
//	int i, k = -1;
//	int count = 0;
//	int tlen = strlen(txt);
//	int plen = strlen(pat);
//	int pt = 0;		
//	int pp = 0;		
//
//	while (txt[pt] != '\0' && pat[pp] != '\0') {
//		if (k == pt - pp)
//			printf("    ");
//		else {
//			printf("%2d  ", pt - pp);
//			k = pt - pp;
//		}
//		for (i = 0; i < tlen; i++)
//			printf("%c ", txt[i]);
//		putchar('\n');
//
//		printf("%*s%c\n", pt * 2 + 4, "", (txt[pt] == pat[pp]) ? '+' : '|');
//
//		printf("%*s", (pt - pp) * 2 + 4, "");
//		for (i = 0; i < plen; i++)
//			printf("%c ", pat[i]);
//		printf("\n\n");
//		count++;
//
//		if (txt[pt] == pat[pp]) {
//			pt++;
//			pp++;
//		}
//		else {
//			pt = pt - pp + 1;
//			pp = 0;
//		}
//	}
//
//	printf("�񱳸� %dȸ �߽��ϴ�.\n", count);
//	if (pat[pp] == '\0')
//		return pt - pp;
//	return -1;
//}
//
//int main(void)
//{
//	int idx;
//	char s1[256]; /* �ؽ�Ʈ */
//	char s2[256]; /* ���� */
//
//	puts("���Ʈ-������");
//
//	printf("�ؽ�Ʈ: ");
//	scanf("%s", s1);
//
//	printf("����: ");
//	scanf("%s", s2);
//
//	idx = bf_match(s1, s2); 
//
//	if (idx == -1)
//		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
//	else
//		printf("%d��° ���ڿ� ��ġ�մϴ�.\n", idx + 1);
//
//	return 0;
//}