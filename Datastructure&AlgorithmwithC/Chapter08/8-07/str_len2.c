/* ���ڿ� ���̸� ���մϴ�.(2) */
#include < stdio.h > 

/*--- ���ڿ� s�� ���̸� ���մϴ�.(2) ---*/
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

	printf("���ڿ�: ");
	scanf("%s", str);

	printf("�� ���ڿ��� %d �����Դϴ�.\n", strlen(str));

	return 0;
}