/* Exit-Condition Loop 탈출조건 루프 do while*/
// while문에서는 시작을 할지 말지 판단을 하는 진입조건을 썼다.
// do while에서는 탈출을 할지 말지 판단하는 조건을 쓴다.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	const int security_number = 337;
	int my_number = 0;
	//무조건 한 번 해야 될 때는 do while문을 쓰는 게 좋다. 같은 기능이 두 번 적혀있다.

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

	// for > while > do while 대체로 많이 쓰는 순서 특정조건에서는 do while이 좋다.
	return 0;
}