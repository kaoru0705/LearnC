/* ���Ʈ-���������� ���ڿ��� �˻��ϴ� ���α׷� */
#include <stdio.h>
#include <string.h>
/*--- ���Ʈ-���������� ���ڿ��� �˻��ϴ� �Լ� ---*/
int bf_match(const char txt[], const char pat[])
{
	int pt = 0;		/* �ؽ�Ʈ Ŀ�� */
	int pp = 0;		/* ���� Ŀ�� */
	int data = -1;
	while (1)
	{
		while (txt[pt] != '\0' && pat[pp] != '\0')
		{
			if (txt[pt] == pat[pp])
			{
				pt++;
				pp++;
			}
			else
			{
				pt = pt - pp + 1;
				pp = 0;
			}
		}
		if (pat[pp] == '\0')
		{
			data = pt - pp;
			pt = pt - pp + 1;
			pp = 0;
		}

		if (strlen(txt + pt) < strlen(pat))
			break;
	}
	return data;

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
///* Q10 ���Ʈ-���������� ���ڿ� �˻�(ã�� ���ڿ��� ������ �ε��� ��ȯ) */
//#include <stdio.h>
//#include <string.h>
//
//int bf_matchr(const char txt[], const char pat[])
//{
//	int txt_len = strlen(txt);		
//	int pat_len = strlen(pat);		
//	int pt = txt_len - pat_len;		
//	int pp;							
//
//
//	while (pt >= 0) {
//		pp = 0;
//		while (txt[pt] == pat[pp]) {
//			if (pp == pat_len - 1)
//				return pt - pp;
//			pp++;
//			pt++;
//		}
//		pt = pt - pp - 1;
//	}
//
//	return -1;
//}
//
//int main(void)
//{
//	int idx;
//	char s1[256]; /* �ؽ�Ʈ */
//	char s2[256]; /* ���� */
//
//	puts("���Ʈ-������(�˻� ���ڿ��� ������ �ε��� ��ȯ)");
//
//	printf("�ؽ�Ʈ: ");
//	scanf("%s", s1);
//
//	printf("����: ");
//	scanf("%s", s2);
//
//	idx = bf_matchr(s1, s2);
//
//	if (idx == -1)
//		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
//	else
//		printf("%d��° ���ڿ� ��ġ�մϴ�.\n", idx + 1);
//
//	return 0;
//}
