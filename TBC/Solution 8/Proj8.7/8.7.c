/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �Է� ��Ʈ���� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
		Assume that your input is :
		Hello 123 3.14
	*/

	// console���� �� ���ͷ� �Էµǰ� �� �ų� �� �߶� ���ϱ� �������� ��� buffer�� ���⸸ �ϰ� ���α׷����� �Ѿ�� �ʾұ� ������ 
	// �����ϰ� �ٽ����� �� �ִ� �Ŵ�. abc > abf

	char str[255];
	int i, i2;
	double d;

	scanf("%s %d %lf", str, &i, &d);
	printf("%s %d %f\n", str, i, d);

	//// or (see the difference)

	scanf("%s %d %d", str, &i, &i2);
	printf("%s %d %d\n", str, i, i2);	// str[0] != '\n' char ch; %c������ ch == '\n' 
	//									// %s�� whitespace�� �þ�Դ´�? %d����?
	//									// ���� �׸��� whitespace�� ���� %c ������ ��κ���  whitespace�� �����Ѵ�

	// �⺻������ ���α׷��� �ܼ�â�� �Է��� ���� �� ���� �� ���� ���ڷ� �޾Ƶ��δ�.
	// getchar()���� ���� ��ĭ���� �ϳ��ϳ� �޾Ƶ��̰� scanf���� ���� ��ĭ�� ������ �Ѱ��� �׸��� �Է��߳����� �ϰ� ������
	/*
	* hello 123 3.14
	* hello 123 3.140000 ���α׷��� �޾Ƶ��� ���� ���ڷ� �޾Ƶ��̴µ� scanf ���ο��� ���ڷ� ��ȯ�� �� �ִ� ���ڱ����ϰ�
	* abcd 456 1.234567 456���� ��ĭ�� �־ �� �ι�° �Է��� ��������
	scanf�� ������ �� ���� ������ �޾ƶ��ϰ� �����߰� ������ ���α׷��� 1�̶�� ���ڸ� �������·� �޾Ƽ� �� ���ڰ� �� �� �ֱ��� ������� ������ �ٵ� .�� scanf�� �����ϱ� ���ڰ� �ƴϱ��� �ϰ�
	�޾Ƶ����� �ʰ� �ѱ�
	� �ڷ����̳Ŀ� ���� �Ȱ��� �Էµ� �ٸ��� �޾Ƶ��δ�.
	getchar putchar�� ���ڷ� �޾Ƶ鿩�� ���̰��� ���
	scanf printf ���������� �������·� ���� ���ڿ�, ���ڵ��� stream�� �츮�� ���ϴ� ���·� �޾Ƶ��̰� ����Ѵ�.
	������ ��ȯ�� �� ���� ���ڰ� ���´ٸ� �Է��� �ߴ��ϰ� �������� buffer�� ���ܵд�.
	*/


	// or (see the difference)

	char c;
	while ((c = getchar()) != '\n')
		putchar(c);
	printf("\n");

	// �ܼ�����¿����� �������·� data�� ��Ʈ���� ���� �Դٰ����Ѵٰ� ����������
	// �ᱹ ���������δ� 2������ ��ȯ�� data�� stream���� �Դٰ��� �Ѵ�.

	return 0;
}