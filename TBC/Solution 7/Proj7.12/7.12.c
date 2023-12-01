/* 중요한 프로젝트는 책꽂이를 해라*/
/* 다중 선택 switch & case */
// 정수형 변수가 어떤 값을 갖느냐에 따라 달라지는 switch case
// switch 는 if로 구현할 수 있다.
// 허나 코드가 몇 가지에 가짓수로 사람이 하나하나 코딩할 수 있는 가짓수 일 때는 switch case를 많이 사용
// switch case로 구현하면 if 문보다 간결 간단한 알고리즘인 경우에는 많이 사용할 수 있다.
// 복잡한 경우에는 아무래도 if
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char c;

	while ((c = getchar()) != '.') // apple입력 시 c = 'a'
	{
		printf("You love ");

		switch (c) //Note: integer types only
		{
		case 'a':	// 문자도 int형
		case 'A':		// case 'a': case 'A': 이렇게도 가능
			printf("apple");	// break; 가 없으면 전부 출력된다. 아 나머지 case까지 쭉 이어가서 그런거임
			break;
		case 'b':
		case 'B':
			printf("baseball");
			break;
		case 'c':
		case 'C':
			printf("cake");
			break;
		default:
			printf("nothing");
		}


		printf(".\n");

		while (getchar() != '\n')
			continue;	// 첫글자 빼고 전부 무시, 나머지 buffer에 있는 것들pple '\n'도 소멸
	}
	// buffer에 . 다음 '\n'가 남아 있다.
	//TODO: upper letters ? (use tolower()?)

	return 0;
}