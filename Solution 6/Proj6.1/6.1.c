// while �ݺ� �������� scanf() ��ȯ�� ����ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num, sum = 0;
	char ch;

	// nothing instead of int status;
	/* My poor answer */
	//// �ݺ��� ������ �ʾ�! conversion specifier�� data type�� ����� �Ѵ�.
	// printf("%d", 'A');�� ������ scanf("%d", &num); num�� ���� �Է��� �ȵȴ�.
	//printf("Enter an integer (q to quit) : ");
	//scanf("%d", &i);
	//while (i != (int)'q')
	//{
	//	printf("Enter next integer (q to quit) : ");
	//	scanf("%d", &i);
	//	sum += i;
	//}
	//sum -= (int)'q';
	//printf("Sum = %d", sum);
	printf("Enter an integer (q to quit) : ");
	// nothing instead of status = scanf("%d", &num);
	while(scanf("%d", &num) == 1) // instead of while (status == 1) // '==' equality operator ���� ������
	{
		sum += num;
		printf("Enter next integer (q to quit) : ");
		// nothing instead of status = scanf("%d", &num);
	}
	// scanf�� �� �� �Է��ؾ� �Ǵٴ�, �Է¹��� ������ �ø��� �� �κ� �� ���ľ� ���ݾ�. �Ǽ��� Ȯ���� �þ
	// ������ �����ϰ� �ݺ��Ǵ� �κ��� �� ���� �̻� ������ �ȵȴ�.
	// while(scanf("%d", &num) == 1) ��ġ�ϱ� ��������� while ���ǹ����� �񱳸��� �ƴ϶� �Լ�ȣ����� �ϰ� �ִ�.�̷��� �����ϰ� ���� �� �ִ�.
	// �ٸ� �ݺ����� ���� �� ���� ������?
	printf("Sum : %d\n", sum);

	//q�� ���ۿ� ���� ����
	scanf("%c", &ch);
	printf("%c", ch);

	return 0;
}