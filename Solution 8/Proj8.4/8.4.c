/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ����� �������̽��� ģ���ϰ� */
// ����ڿ� ���α׷� ���̿� �����ϴ� ���� inter face 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
//getchar()�� �� ���ڹۿ� �� ����
int main()
{
	int count = 0;

	while (1)
	{
		printf("Current count is %d. Continue? (y/n)\n", count); // ����ڰ� � �� �Է������� �𸥴�. 
		// �װſ� �°� ���� ������ �� �ֵ��� �ؾ� ��
		// ���� �ô뿣 �������� �ؾ� �ȴ�.
		 
		int c = tolower(getchar());
		
		if (c == 'n')		// ����ڰ� �빮�� N Y�� �Է��� ���� �ִ�.
			break;
		else if (c == 'y')
		{
			//while (getchar() != '\n')
			//	continue; // else �ּ��� ���� ���۸� ����� ���� �ߺ���

			count++;
		}
		else
		{
			printf("Please input y or n\n");

			/*while (getchar() != '\n')
				continue;*/
		}
		while ((getchar()) != '\n') // ���� ���̴� ��: �ƴ� '\n'�� �� buffer�� �� ����? �ϴ� �Է¹ް� �񱳸� �ؾ� ������ �ϰ� ���� �������ݾ�. buffer�� ���� ������ ���ڸ� getchar()�� �� ���ھ� �Ծ��ְ� �ִ�.
			continue;
	}


	return 0;
}