/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ����� ���� ������ Redirection */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
 ��� ������Ʈ ȭ��ǥ ���� �� �� ������ ��� ���� �Է��� �� ���. 
C:\Users\KDH\source\repos\Solution 8\Debug>Proj8.3.exe > output.txt
//Proj8.3.exe�� ��¹����� �ܼ�â�̾��� �� output.txt�� redirection
// console â���� ����� ���� file�� redirection�� �� output.txt�� �����Ǵ� �� Ȯ�� �� �� �ִ�.
C:\Users\KDH\source\repos\Solution 8\Debug>output.txt

C:\Users\KDH\source\repos\Solution 8\Debug>Proj8.3.exe>output.txt	�ٿ� �ᵵ ��

C:\Users\KDH\source\repos\Solution 8\Debug>output.txt

C:\Users\KDH\source\repos\Solution 8\Debug>explorer

C:\Users\KDH\source\repos\Solution 8\Debug>explorer . ���� ��ġ�� ��Ÿ���� .

C:\Users\KDH\source\repos\Solution 8\Debug>notepad output.txt �̷��Ե� �� �� �ִ�.

����� ���� file�� ������ �ǵ� �Է��� ���� ���� ������?
C:\Users\KDH\source\repos\Solution 8\Debug>Proj8.3.exe < input.txt
Proj8.3.exe���� input.txt�� ������
input.txt�� Proj8.3.exe�� �Է����� redirection
C:\Users\KDH\source\repos\Solution 8\Debug>Proj8.3.exe<input.txt>output.txt �̷������ε� �� �� �ִ�.
C:\Users\KDH\source\repos\Solution 8\Debug>Proj8.3.exe>>output.txt linux unix ���� ���� ���
Banana 
I love Melon �ڿ� I love Banana�� ������ ���·� file ����

printf("Programming");���� rebuild
C:\Users\KDH\source\repos\Solution 8\Debug>Proj8.3
Programming
C:\Users\KDH\source\repos\Solution 8\Debug>copy Proj8.3.exe test.exe
		1�� ������ ����Ǿ����ϴ�.
Proj8.3.exe �����ؼ� ������ �״��� �ٽ� str[100]�� rebuild
C:\Users\KDH\source\repos\Solution 8\Debug>test.exe | Proj8.3.exe
I love Programming
test.exe�� ���� ����� pipe key(|) �� Ÿ�� Proj8.3.exe�� �귯��

linux unix ���� ���� ���

data�� �帧�� �ܼ�������� ������ �� ����������� ���𷺼� �� �� �ִ�. 
�׸��� data�� �帧�� ������ EOF�� �־��� ���̴�.
*/

int main()
{
	/*printf("Programming");*/
	char str[100];
	scanf("%s", str);
	printf("I love %s\n", str);

	return 0;
}