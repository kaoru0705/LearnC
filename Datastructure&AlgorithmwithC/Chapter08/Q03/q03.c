/* Q3 �� ���ڿ��� ������ �ٲٱ� */
#include <stdio.h>

/*--- �� ���ڿ� x, y�� ��ȯ�մϴ�. ---*/
void swap_str(char *x, char *y)
{
	char *temp;
	while (*x && *y) {					/* ª�� ���ڿ��� ������ ���ڿ��� ��ȯ */
		char t = *x; *x++ = *y; *y++ = t;
	}
	if (*x) {							/* x�� �� �� ���ڿ��̶�� */
		temp = x;
		while (*x) { *y++ = *x++; }		/* x�� �������� y�� ���� */
		*temp = *y = '\0';
	}
	else if (*y) {						/* y�� �� �� ���ڿ��̶�� */
		temp = y;
		while (*y) { *x++ = *y++; }		/* y�� �������� x�� ���� */
		*temp = *x = '\0';
	}
	else {
		*x = *y = '\0';
	}
}

int main(void)
{
	char s1[128], s2[128];

	printf("���ڿ� S1 :");	scanf("%s", s1);
	printf("���ڿ� S2 :");	scanf("%s", s2);

	swap_str(s1, s2);	

	printf("�� ���ڿ��� ��ȯ�߽��ϴ�.\n");
	printf("���ڿ� S1 : %s\n", s1);
	printf("���ڿ� S2 : %s\n", s2);

	return 0;
}
