/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ������ �� end of file eof */
/* https://www.asciitable.com/ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // EOF in stdio.h

int main()
{
	int c;

	//// getchar() ��ȯ���� int�� �Ѱ��ְ� �ִ� ���������� ascii code�� ����ؼ� ���� ǥ�� ascii code���� ������ ���µ�?
	//while ((c = getchar()) != EOF)	// End Of File #define EOF (-1)
	//	putchar(c);				// != '.'��� ���࿡ �Է��ϴٰ� �߰��� '.'�� �Է��ϰ� �;����ٸ�? �ٸ� ��ȣ�� ��� �ϳ�
	//// �Է��� �����ٴ� �� ���α׷����� �˸��� ���� �� �ü���� �˷��ش� �׶� getchar�� -1�� return
	//// �ܼ��Է°� �����Է��� ������ ����� �����ϴ�. ���ݱ��� ���������� (��ħǥ) �������� ��
	//// consoleâ���� ctrl z ������ ����
	//// ctrl c = OS�� �������� ���α׷���  ��������

	/* ctrl z ������ �Է��� ����� �ƴ��� Ȯ�� */

	// stream �귯�� �ܼ�������� �ó��� data�� �귯�� ���α׷����� ��
	// file�� ����� �����Ͱ� �귯�귯 �츮�� ���α׷����� �� �ݴ�������ε� 
	// putchar() ���α׷����� �����Ͱ� �귯 ���� �ַܼ� �� 
	// data�� �귯���� �� ���Ͽ��� stream�� ���� ���������� ǥ���ϴ� �� EOF 
	while (1)
	{
		c = getchar();
		printf("%d\n", c);
		if (c == EOF)
			break;
	}

	return 0;
}