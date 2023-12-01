/* 브루트-포스법으로 문자열을 검색하는 프로그램 */
#include <stdio.h>
#include <string.h>
/*--- 브루트-포스법으로 문자열을 검색하는 함수 ---*/
int bf_match(const char txt[], const char pat[])
{
	int pt = 0;		/* 텍스트 커서 */
	int pp = 0;		/* 패턴 커서 */
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
	char s1[256];		/* 텍스트 */
	char s2[256];		/* 패턴 */

	puts("브루트-포스법");
	printf("텍스트 : ");
	scanf("%s", s1);
	printf("패턴 : ");
	scanf("%s", s2);

	idx = bf_match(s1, s2);	/* 텍스트(s1)에서 패턴(s2)을 브루트-포스법으로 검색합니다. */
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);

	return 0;
}
///* Q10 브루트-포스법으로 문자열 검색(찾은 문자열의 마지막 인덱스 반환) */
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
//	char s1[256]; /* 텍스트 */
//	char s2[256]; /* 패턴 */
//
//	puts("브루트-포스법(검색 문자열의 마지막 인덱스 반환)");
//
//	printf("텍스트: ");
//	scanf("%s", s1);
//
//	printf("패턴: ");
//	scanf("%s", s2);
//
//	idx = bf_matchr(s1, s2);
//
//	if (idx == -1)
//		puts("텍스트에 패턴이 없습니다.");
//	else
//		printf("%d번째 문자와 일치합니다.\n", idx + 1);
//
//	return 0;
//}
