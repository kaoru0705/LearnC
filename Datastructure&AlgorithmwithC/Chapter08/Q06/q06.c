#include <stdio.h>

char* str_rchr(const char* s, int c)
{
	c = (char)c;
	const char* ptr = '\0';
	while (*s != '\0')
	{
		if (*s == c)
			ptr = s;
		s++;
	}
	return (*s == c) ? (char *)s : ptr;
}

int main(void)
{
	char str[64];
	char tmp[64];
	int  ch;
	char* idx;

	printf("���ڿ���");
	scanf("%s", str);

	printf("�˻���");
	scanf("%s", tmp);
	ch = tmp[0];

	if ((idx = str_rchr(str, ch)) == '\0')
		printf("���� '%c'�� ���ڿ� �ȿ� �����ϴ�.\n", ch);
	else
		printf("���� '%c'�� %d��°�� �ֽ��ϴ�.\n", ch, (idx - str) + 1);

	return 0;
}
///* Q6 strchr �Լ� ���� */
//#include <stdio.h>
//
//char *str_rchr(const char *s, int c)
//{
//	const char *p = NULL;			
//
//	c = (char)c;
//	while (1) {
//		if (*s == c)				
//			p = s;
//		if (*s == '\0')				
//			break;
//		s++;
//	}
//	return (char *)p;
//}
//
//int main(void)
//{
//	char str[64];				
//	char tmp[64];
//	int  ch;					
//	char *idx;
//	
//	printf("���ڿ���");
//	scanf("%s", str);
//
//	printf("�˻���");
//	scanf("%s", tmp);
//	ch = tmp[0];
//
//	if ((idx = str_rchr(str, ch)) == -1)
//		printf("���� '%c'�� ���ڿ� �ȿ� �����ϴ�.\n", ch);
//	else
//		printf("���� '%c'�� %d��°�� �ֽ��ϴ�.\n", ch, (idx - str) + 1);
//
//	return 0;
//}