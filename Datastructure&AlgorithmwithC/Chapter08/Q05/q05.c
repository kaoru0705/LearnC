///* ���ڿ����� ���� �˻��ϴ� ���α׷� */
//#include <stdio.h>
//
///*--- ���ڿ� s���� ���� c�� �˻��ϴ� �Լ� ---*/
//char* str_chr(const char* s, int c)
//{
//	int i = 0;
//	c = (char)c;
//	while (s[i] != c)
//	{
//		if (s[i] == '\0')		/* �˻� ���� */
//			return '\0';
//		i++;
//	}
//	return &s[i];			/* �˻� ���� */
//}
//
//int main(void)
//{
//	char str[64];	/* �� ���ڿ����� �˻�*/
//	char tmp[64];
//	int ch;			/* �˻��� ���� */
//	char* idx;
//
//	printf("���ڿ� : ");
//	scanf("%s", str);
//
//	printf("�˻��� ���� : ");
//	scanf("%s", tmp);		/* ���� ���ڿ��� �˻��� ���ڸ� �о� ���Դϴ�. */
//	ch = tmp[0];			/* ù ��° ���ڸ� �˻��� ���ڷ� �����մϴ�. */
//
//	if ((idx = str_chr(str, ch)) == '\0')		/* ó�� ������ ���ڸ� �˻��մϴ�. */
//		printf("���� '%c'�� ���ڿ��� �����ϴ�.\n", ch);
//	else
//		printf("���� '%c'��(��) %d ��°�� �ֽ��ϴ�.\n", ch, idx - str + 1); //��°�ϱ� �ϳ� ����
//
//	return 0;
//}

/* Q5 strchr �Լ� ���� */
#include <stdio.h>

char *str_chr(const char *s, int c)
{
	c = (char)c;
	while (*s != c) {
		if (*s == '\0')				/* �߰ߵ��� ������ */
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

	printf("���ڿ���");
	scanf("%s", str);

	printf("�˻���");
	scanf("%s", tmp);		
	ch = tmp[0];				

	if ((idx = str_chr(str, ch)) == '\0')
		printf("���� '%c'�� ���ڿ� �ȿ� �����ϴ�.\n", ch);
	else
		printf("���� '%c'�� %d��°�� �ֽ��ϴ�.\n", ch, (idx - str) + 1);

	return 0;
}
