/* Exit-Condition Loop Ż������ ���� do while*/
// while�������� ������ ���� ���� �Ǵ��� �ϴ� ���������� ���.
// do while������ Ż���� ���� ���� �Ǵ��ϴ� ������ ����.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	const int security_number = 337;
	int my_number = 0;
	//������ �� �� �ؾ� �� ���� do while���� ���� �� ����. ���� ����� �� �� �����ִ�.

	/*printf("Enter secret code : ");
	scanf("%d", &my_number);

	while (my_number != security_number)
	{
		printf("Enter secret code : ");
		scanf("%d", &my_number);
	}*/

	do
	{
		printf("Enter secret code : ");
		scanf("%d", &my_number);
	}
	while (my_number != security_number);

	printf("Good!");

	// for > while > do while ��ü�� ���� ���� ���� Ư�����ǿ����� do while�� ����.
	return 0;
}