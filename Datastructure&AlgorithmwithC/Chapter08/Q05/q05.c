///* 문자열에서 문자 검색하는 프로그램 */
//#include <stdio.h>
//
///*--- 문자열 s에서 문자 c를 검색하는 함수 ---*/
//char* str_chr(const char* s, int c)
//{
//	int i = 0;
//	c = (char)c;
//	while (s[i] != c)
//	{
//		if (s[i] == '\0')		/* 검색 실패 */
//			return '\0';
//		i++;
//	}
//	return &s[i];			/* 검색 성공 */
//}
//
//int main(void)
//{
//	char str[64];	/* 이 문자열에서 검색*/
//	char tmp[64];
//	int ch;			/* 검색할 문자 */
//	char* idx;
//
//	printf("문자열 : ");
//	scanf("%s", str);
//
//	printf("검색할 문자 : ");
//	scanf("%s", tmp);		/* 먼저 문자열로 검색할 문자를 읽어 들입니다. */
//	ch = tmp[0];			/* 첫 번째 문자를 검색할 문자로 지정합니다. */
//
//	if ((idx = str_chr(str, ch)) == '\0')		/* 처음 나오는 문자를 검색합니다. */
//		printf("문자 '%c'는 문자열에 없습니다.\n", ch);
//	else
//		printf("문자 '%c'는(은) %d 번째에 있습니다.\n", ch, idx - str + 1); //번째니까 하나 더함
//
//	return 0;
//}

/* Q5 strchr 함수 수정 */
#include <stdio.h>

char *str_chr(const char *s, int c)
{
	c = (char)c;
	while (*s != c) {
		if (*s == '\0')				/* 발견되지 않으면 */
			return NULL;
		s++;
	}
	return (char *)s;
}

int main(void)
{
	char str[64];				
	char tmp[64];
	int  ch;					
	char *idx;

	printf("문자열：");
	scanf("%s", str);

	printf("검색：");
	scanf("%s", tmp);		
	ch = tmp[0];				

	if ((idx = str_chr(str, ch)) == '\0')
		printf("문자 '%c'는 문자열 안에 없습니다.\n", ch);
	else
		printf("문자 '%c'는 %d번째에 있습니다.\n", ch, (idx - str) + 1);

	return 0;
}
