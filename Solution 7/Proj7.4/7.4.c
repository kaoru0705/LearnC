/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ���� ���� else if */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/* ���ռҵ漼 ����ϴ� ���� */

// assessment standard tax base assessment �򰡾�
#define BASE1  12000000.0
#define BASE2  46000000.0
#define BASE3  88000000.0	// ū ���� �� �����
#define BASE4 150000000.0
#define BASE5 300000000.0
#define BASE6 500000000.0

#define RATE1 (	6.0 / 100.0)		// percent to rate
#define RATE2 (15.0 / 100.0)
#define RATE3 (24.0 / 100.0)
#define RATE4 (35.0 / 100.0)
#define RATE5 (38.0 / 100.0)
#define RATE6 (40.0 / 100.0)
#define RATE7 (42.0 / 100.0)

#define BASIC_DEDUCTION 1500000.0

int main()
{
	/* My poor answer */	// ������ �ѵ� ������ �͵� �ǿܷ� ������.
	double income = 0.0;
	double tax = 0.0;
	double calc = 0.0;

	scanf("%lf", &income);
	
	income -= BASIC_DEDUCTION;
	calc = income;

	while (calc > BASE1)
	{
		if (calc > BASE6)
		{
			tax += (calc - BASE6) * RATE7;
			calc = BASE6;
		}
		else if (calc > BASE5)
		{
			tax += (calc - BASE5) * RATE6;
			calc = BASE5;
		}
		else if (calc > BASE4)
		{
			tax += (calc - BASE4) * RATE5;
			calc = BASE4;
		}
		else if (calc > BASE3)
		{
			tax += (calc - BASE3) * RATE4;
			calc = BASE3;
		}
		else if (calc > BASE2)
		{
			tax += (calc - BASE2) * RATE3;
			calc = BASE2;
		}
		else if (calc > BASE1)
		{
			tax += (calc - BASE1) * RATE2;
			calc = BASE1;
		}
	}
	if (calc <= BASE1)
		tax += calc * RATE1;

	printf("Tax is = %f\n", tax);
	printf("Your income after tax deduction = %f", income - tax);

	//double income = 0.0;
	//double tax = 0.0;

	//scanf("%lf", &income);

	//income -= BASIC_DEDUCTION;

	//if (income <= BASE1)
	//{
	//	tax = income * RATE1;
	//}
	//else if (income <= BASE2)
	//{
	//	tax = BASE1 * RATE1 + (income - BASE1) * RATE2;
	//}
	//else if (income <= BASE3)
	//{
	//	tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (income - BASE2) * RATE3;
	//}
	//// ... ��� �迭�� ���� �� ���̴�.
	//printf("Tax is = %f\n", tax);
	//printf("Your income after tax deduction = %f", income - tax);

	return 0;
}