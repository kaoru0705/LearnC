/* 함수 포인터의 배열 연습문제 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> //islower tolower 기억해라 좀
#include <stdbool.h> //bool
//#include <string.h> // professor가 괜히 string.h를 안 쓴 게 아니다. strcmp는 문자열만 비교가능 char ch; strcmp(&options[0], &ch); 이 딴 건 불가능하다.

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);//TODO: add a new menu

int main(void)
{
	char options[] = { 'u', 'l', 't'};//TODO: add a new menu
	int n = sizeof(options) / sizeof(char);

	typedef void (*FUNC_TYPE)(char*);
	FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose };//TODO: add a new menu

	printf("Enter a string\n>> ");

	char input[100];

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again.\n>> ");

	

	/* My Answers */
	/*printf("Choose an option:\nu) to upper\nl) to lower\n");
	char ch; // 나도 while 안에 다 때려 박아서 실패했을 경우를 대비하려고 했음 ch도 while안에 넣어서 좀더 작은 임시변수로 쓰는 게 좋을 거라고 생각했지만... flag 쓰는 게 귀찮아서 이렇게 바꿨는데 flag도 stdbool.h로 쓰는 게 맞았다.
	scanf("%c", &ch); 

	while (getchar() != '\n');

	for (int i = 0; i < n; i++)
		if (options[i] == ch)
		{
			operations[i](input);
			printf("%s\n", input);
			break;
		}*/
	while (true)
	{
		printf("Choose an option:\n");
		printf("u) to upper\n");
		printf("l) to lower\n");
		printf("t) to transpose\n");

		char c;
		while (scanf("%c%*[^\n]%*c", &c) != 1) // 하나 입력 받고 \n전까지 지워주고 \n도 지우기 본받자.
			printf("Please try again.\n");

		bool found = false; // 이거 쓰려다 맒 문제에서는 stdbool.h를 include 했으니 나도 써야 했다.

		/*switch (c)
		{
		case 'u':
			ToUpper(input);
			found = true;
			break;
		case 'l':
			ToLower(input);
			found = true;
			break;
		}*/

		for (int i = 0; i < n; ++i) // case보단 이게 좀 더 편리함 코드로 봤을 땐 case보다 직관적이지 않을 수 있다. 허나 options[] operations[]의 패턴을 알고 있는 상태라면 가독성도 그렇게 떨어지지 않고 기능을 추가하기 더 좋음. ex> 't' 기능을 수행하는 가장 중요한 이 부분은 고칠 게 없음
			if (options[i] == c)
			{
				(*(operations[i]))(input);
				found = true;
				break;
			}
		if (found)
			break;
		else
			printf("Wrong input try again\n");
	}

	printf("%s\n", input);

	return 0;
}

void update_string(char* str, int(*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}
void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}
void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}
void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}