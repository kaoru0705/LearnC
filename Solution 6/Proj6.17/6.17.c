/* for loop�� �迭�� �Բ� ����ϱ� */
// �ϵ���� ����ó���� ������ ��쵵�� ����.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 5

int main()
{
	/* Motivation */
	//int i1 = 0;
	//int i2 = 1;
	//int i3 = 2;
	//// ...

	//printf("%d\n", i1);
	//printf("%d\n", i2);
	//printf("%d\n", i3);
	//// ...


	/* prepare for array data */

	int my_arr[SIZE];
	for (int i = 0; i < SIZE; ++i)	//debug watch�� ������ �Է��ؼ� ���� Ȯ���� ���� �ִ�.
									//�迭�� �ʹ� ���� �� ���� Ȯ���ϱ� ����� ���
	{
		my_arr[i] = i * i;
		// 1 + 2; // dummy debug�� �� �̺κп� �ɸ��� �ؼ� �Ҵ�Ǵ� �� ��Ȯ�ϰ� Ȯ���ϱ� ���� ����.
		// �ٵ� �̰� 1 + 2; �� R-value �����̶� (�� ��������� �� �� ���� �ӽø޸𸮶�) �� �ɸ��� �� �մϴ�.
		// ����� �����帮�ڸ�, ���� ���������� ������ ���̷� ���� �� �̸��׸� printf(""); �̷� ����Լ��� ���� �ִ� ���Դϴ�.
	}
	// printf array data
	for (int i = 0; i < SIZE; ++i)
		printf("%d ", my_arr[i]);	// �� for���̶� ��� �ѹ��� �ϴ� �� ���� �ʳ���? �׷��� �ȴ�.
	// �㳪 size�� �þ�� ���� ���� �ִ�. ��ȿ�������� ���� �� ������... c++ �ϵ���� ���� ����ó�� �̷� �� ���� �������� ��İ� �ٸ� ���α׷��� ������� ���� �ȴ�.

	//TODO: try debugger

	/* my answer */
	/*int your_number[SIZE];
	int sum = 0;

	printf("Enter 5 numbers : ");
	for (int i = 0; i < SIZE; ++i)
	{
		scanf("%d", &your_number[i]);
		sum += your_number[i];
	}

	printf("Sum = %d\n", sum);*/

	int number[SIZE];
	int sum = 0;
	int i;

	printf("Enter %d numbers : ", SIZE);

	for (i = 0; i < SIZE; ++i)		//for�� �ɰ��� ���� �� ����
		scanf("%d", &number[i]);

	for (i = 0; i < SIZE; ++i)
		sum += number[i];

	printf("Sum = %d\n", sum);
	printf("Average = %d\n", sum / SIZE);

	return 0;
}