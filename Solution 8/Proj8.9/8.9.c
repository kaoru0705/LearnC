/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �ؽ�Ʈ ���� �б� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit()
#include <string.h>
int main()
{
	int c;
	FILE *file = NULL;	// pointer �ּҰ� ��� file�� �о���̴� stream�� ���� �� �ִ� � ������ ������ ����ִ�.
	//char file_name[] = "my_file.txt";
	//TODO: use scanf(...) ��ó�� �ϵ��ڵ����� �ʰ� scanf�� �޾Ƽ� �Է��Ѵٰų� GUI�� ���� �Ѵٰų� ������ ������ε� �� �� �ִ�.
	char file_name[100];
	scanf("%s", file_name);

	// 8.9c open containing folder my_file.txt ����
	// command prompt�� �����ϴ� ��쿣 Solution 8 debug���� my_file.txt�� ������ ���� ����

	file = fopen(file_name, "r"); // "my_file.txt"��� �̸��� ���� file�� �аų� �����ϴ� ��� stream�� �����ش�.
	// "r" option read�� ���� �̹� ������ ���� �����͸� �о���̷��� �� �� ��� ����
	// "w" write ���Ͽ� �����͸� �����Ϸ��� �Ѵٸ� ������ �� �ִ� ���� stream�� ���� �ȴ�.
	// ������ �ɼ��� ���� ���� text������ ���� �ȴ�. ascii, binary ����� �������� ���� �ȴ�.
	if (file == NULL)	// �̷� ������ ���� ���
	{
		printf("Failed to open file.\n");
		exit(1004);	// ref 8.8.c �� �ڵ忡 ������ �� ���� �� ���� ġ������ ������. 1 -1�� �Ϲ���
		// ���̻� �� �� �ִ� �� ���� �� exit(1)
		// exit(1004) C:\Users\KDH\source\repos\Solution 8\Debug\Proj8.9.exe (process 6292) exited with code 1004.
		// Press any key to close this window . . .
	}

	while ((c = getc(file)) != EOF)	// getc(FILE *_Stream)
		/* file�� �о���̰� ����ϴ� �� console�� �Է��� �о���̰� ����ϴ� �Ͱ� ����� ������ �ִ�.*/
		putchar(c);
	fclose(file);	// file stream�� �������� ���� �ݱ�
	// �ݾƾ� OS�� �� �� ���α׷��� �� ������ �� ����߱��� ��쿡 ���� �ٸ� ���α׷��� �����ϰ� �;��ϱ⵵ �ϴ� �ݾ��ش�.

	
	return 0;
}