/* ���ڿ��� ���ϴ� ���α׷� */
#include <stdio.h>

/*--- �� ���ڿ� s1�� s2�� ���ϴ� �Լ� ---*/
int str_cmpic(const char* s1, const char* s2)
{
	while (*s1 == *s2 || (*s1 >= 65 && *s1 <= 90) || (*s1 >= 97 && *s1 <= 122))
	{
		if (*s1 == '\0')		/* ���� */
			return 0;
		if (*s1 + 32 != *s2 && *s1 -32 != *s2)
			break;
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2; // unsigned char�� ������ ���Ѵ�. 
}

int main(void)
{
	char st[128];
	puts("\"ABCD\"�� ���մϴ�.");
	puts("\"XXXX\"�� ��Ĩ�ϴ�.");

	while (1) {
		printf("���ڿ� st : ");
		scanf("%s", st);

		if (str_cmpic("XXXX", st) == 0)
			break;
		printf("str_cmp(\"ABCD\", st) = %d\n", str_cmpic("ABCD", st));
	}

	return 0;
}
///* Q8 ��� ���ڸ� �������� �ʴ� ���ڿ� �� */
//#include <ctype.h>
//#include <stdio.h>
//#include <string.h>
//
//int str_cmpic(const char *s1, const char *s2)
//{
//	while (toupper(*s1) == toupper(*s2)) {
//		if (*s1 == '\0')			
//			return 0;
//		s1++;
//		s2++;
//	}
//	return (unsigned char)toupper(*s1) - (unsigned char)toupper(*s2);
//}
//
//int str_ncmpic(const char *s1, const char *s2, size_t n)
//{
//	while (n && *s1 && *s2) {
//		if (toupper(*s1) != toupper(*s2))			
//			return (unsigned char)toupper(*s1) - (unsigned char)toupper(*s2);
//		s1++;
//		s2++;
//		n--;
//	}
//	if (!n)  return 0;
//	if (*s1) return toupper(*s1);
//	return toupper(*s2);
//}
//
//int main(void)
//{
//	int n, retry;
//	char s1[256], s2[256];
//
//	puts("��/�ҹ��ڸ� �������� �ʴ� ��");
//
//	do {
//		printf("s1 : "); scanf("%s", s1);
//		printf("s2 : "); scanf("%s", s2);
//		printf("�� ���ڼ� : "); scanf("%d", &n);
//
//		printf("str_ncmp (\"%s\", \"%s\") = %d\n", s1, s2, str_cmpic(s1, s2));
//		printf("str_ncmpic (\"%s\", \"%s\", %d) = %d\n", s1, s2, n, str_ncmpic(s1, s2, n));
//		printf("�ٽ� �� ��? [0 �� No / 1 �� Yes] : ");
//		scanf("%d", &retry);
//	} while (retry == 1);
//
//	return 0;
//}
