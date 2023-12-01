/* Boyer-Moore법을 구현한 프로그램 */
#include <stdio.h>
#include <string.h>
#include <limits.h>

/*--- Boyer-Moore 함수 ---*/
int bm_match(const char txt[], const char pat[])
{
	int pt;										/* txt 커서 */
	int pp;										/* pat 커서 */
	int txt_len = strlen(txt);					/* txt 문자 개수 */
	int pat_len = strlen(pat);					/* pat 문자 개수 */
	int skip[UCHAR_MAX + 1];					/* 건너뛰기 표 */ // 255 + 1 ASCII code 수 전체 extended ascii codes까지 포함

	for (pt = 0; pt <= UCHAR_MAX; pt++)			/* 건너뛰기 표 만들기 */
		skip[pt] = pat_len;

	for (pt = 0; pt < pat_len - 1; pt++)		// pattern의 마지막 index는 제외함 
		skip[pat[pt]] = pat_len - pt - 1;		/* pt == pat_len - 1 */

	while (pt < txt_len) {
		pp = pat_len - 1; 			/* pat의 마지막 문자부터 검사합니다. */

		while (txt[pt] == pat[pp]) {
			if (pp == 0)
				return pt;
			pp--;
			pt--;
		}
		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
		/*
		안녕하세요.
		pt += skip[txt.charAt(pt)로 해도 문제 없을 거예요.

		patLen - pp가 무슨 뜻일까요?
		patLen은 찾는 패턴의 길이고,
		그리고 pp는 pt와 pp가 가르키는 문자가 다른 위치를 나타냅니다.

		그럼 마지막 4번째 줄에서 patLen - pp의 값을 pt와 더하면 while(pt < txtLen)이 시작될 때의 pt의 시작 부분의 다음 인덱스가 됩니다.
		( 이게 글로 설명하기에는 분량이 너무 많아요 ㅜㅜ 디버깅을 해보시면 무조건 pt의 시작 부분의 다음 인덱스가 돼요 )
		pp-- pt--가 된다한들 처음 patLent-pp를 pt에 더하니 while문 조건에서의 pt의 값보다 하나가 더 많게 된다.
		그래서 마지막 4번째 줄은 혹시 pt + skip[txt.charAt(pt)가 while(pt < txtLen)이 시작될 때의 pt의 시작 부분의 다음 인덱스보다 작은 경우를 대비해서 만들어놓은 안전장치라고 생각할 수 있습니다.

		이 책은 파이썬, c언어, 자바 버전이 있는데요. 언어만 다를뿐 소스가 거의 비슷하더라구요.
		이렇게 안전장치를 만들어 놓으면 다른언어로 옮길 때 동작하지 않을 수 있는 부분을 미리 방지할 수 있기 때문에 이렇게 코드가 만들어지지 않았을까 싶어요.
		*/
	}

	return -1;
}

int main(void)
{
	int idx;
	char s1[256];		/* 텍스트 */
	char s2[256];		/* 패턴 */

	puts("Boyer-Moore법");
	printf("텍스트 : ");
	scanf("%s", s1);
	printf("패턴 : ");
	scanf("%s", s2);


	idx = bm_match(s1, s2);	/* 문자열 s1에서 문자열 s2를 Boyer-Moore법을 사용해 검색합니다. */
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);

	return 0;
}