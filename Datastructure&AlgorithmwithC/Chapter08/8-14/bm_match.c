/* Boyer-Moore���� ������ ���α׷� */
#include <stdio.h>
#include <string.h>
#include <limits.h>

/*--- Boyer-Moore �Լ� ---*/
int bm_match(const char txt[], const char pat[])
{
	int pt;										/* txt Ŀ�� */
	int pp;										/* pat Ŀ�� */
	int txt_len = strlen(txt);					/* txt ���� ���� */
	int pat_len = strlen(pat);					/* pat ���� ���� */
	int skip[UCHAR_MAX + 1];					/* �ǳʶٱ� ǥ */ // 255 + 1 ASCII code �� ��ü extended ascii codes���� ����

	for (pt = 0; pt <= UCHAR_MAX; pt++)			/* �ǳʶٱ� ǥ ����� */
		skip[pt] = pat_len;

	for (pt = 0; pt < pat_len - 1; pt++)		// pattern�� ������ index�� ������ 
		skip[pat[pt]] = pat_len - pt - 1;		/* pt == pat_len - 1 */

	while (pt < txt_len) {
		pp = pat_len - 1; 			/* pat�� ������ ���ں��� �˻��մϴ�. */

		while (txt[pt] == pat[pp]) {
			if (pp == 0)
				return pt;
			pp--;
			pt--;
		}
		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
		/*
		�ȳ��ϼ���.
		pt += skip[txt.charAt(pt)�� �ص� ���� ���� �ſ���.

		patLen - pp�� ���� ���ϱ��?
		patLen�� ã�� ������ ���̰�,
		�׸��� pp�� pt�� pp�� ����Ű�� ���ڰ� �ٸ� ��ġ�� ��Ÿ���ϴ�.

		�׷� ������ 4��° �ٿ��� patLen - pp�� ���� pt�� ���ϸ� while(pt < txtLen)�� ���۵� ���� pt�� ���� �κ��� ���� �ε����� �˴ϴ�.
		( �̰� �۷� �����ϱ⿡�� �з��� �ʹ� ���ƿ� �̤� ������� �غ��ø� ������ pt�� ���� �κ��� ���� �ε����� �ſ� )
		pp-- pt--�� �ȴ��ѵ� ó�� patLent-pp�� pt�� ���ϴ� while�� ���ǿ����� pt�� ������ �ϳ��� �� ���� �ȴ�.
		�׷��� ������ 4��° ���� Ȥ�� pt + skip[txt.charAt(pt)�� while(pt < txtLen)�� ���۵� ���� pt�� ���� �κ��� ���� �ε������� ���� ��츦 ����ؼ� �������� ������ġ��� ������ �� �ֽ��ϴ�.

		�� å�� ���̽�, c���, �ڹ� ������ �ִµ���. �� �ٸ��� �ҽ��� ���� ����ϴ��󱸿�.
		�̷��� ������ġ�� ����� ������ �ٸ����� �ű� �� �������� ���� �� �ִ� �κ��� �̸� ������ �� �ֱ� ������ �̷��� �ڵ尡 ��������� �ʾ����� �;��.
		*/
	}

	return -1;
}

int main(void)
{
	int idx;
	char s1[256];		/* �ؽ�Ʈ */
	char s2[256];		/* ���� */

	puts("Boyer-Moore��");
	printf("�ؽ�Ʈ : ");
	scanf("%s", s1);
	printf("���� : ");
	scanf("%s", s2);


	idx = bm_match(s1, s2);	/* ���ڿ� s1���� ���ڿ� s2�� Boyer-Moore���� ����� �˻��մϴ�. */
	if (idx == -1)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else
		printf("%d��° ���ں��� match�մϴ�.\n", idx + 1);

	return 0;
}