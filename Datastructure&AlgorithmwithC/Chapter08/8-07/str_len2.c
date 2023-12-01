/* 문자열 길이를 구합니다.(2) */
#include < stdio.h > 

/*--- 문자열 s의 길이를 구합니다.(2) ---*/
int str_len(const char * s)
{
	int len = 0;

	while (*s++)
		len++;

	return len;
}
size_t strlen(const char* s)
{
	size_t len = 0;

	while (*s++)
		len++;

	return len;
}
int main(void)
{
	char str[256];

	printf("문자열: ");
	scanf("%s", str);

	printf("이 문자열은 %d 문자입니다.\n", strlen(str));

	return 0;
}