/* ���ڿ� ���̸� ���մϴ�.(3) */
#include < stdio.h > 

/*--- ���ڿ� s�� ���̸� ���մϴ�.(3) ---*/
int str_len(const char* s)
{
	const char* p = s;

	while (*s)
		s++;

	return s - p;
}

int main(void)
{
	char str[256];

	printf("���ڿ�: ");
	scanf("%s", str);

	printf("�� ���ڿ��� %d �����Դϴ�.\n", str_len(str));

	return 0;
}