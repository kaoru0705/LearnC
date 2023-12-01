/* 중요한 프로젝트는 책꽂이를 해라*/
/* 사용자 인터페이스는 친절하게 */
// 사용자와 프로그램 사이에 존재하는 것을 inter face 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
//getchar()는 한 글자밖에 못 먹음
int main()
{
	int count = 0;

	while (1)
	{
		printf("Current count is %d. Continue? (y/n)\n", count); // 사용자가 어떤 걸 입력할지는 모른다. 
		// 그거에 맞게 전부 대응할 수 있도록 해야 됨
		// 요즘 시대엔 음성까지 해야 된다.
		 
		int c = tolower(getchar());
		
		if (c == 'n')		// 사용자가 대문자 N Y를 입력할 수도 있다.
			break;
		else if (c == 'y')
		{
			//while (getchar() != '\n')
			//	continue; // else 주석을 봐라 버퍼를 지우는 일이 중복됨

			count++;
		}
		else
		{
			printf("Please input y or n\n");

			/*while (getchar() != '\n')
				continue;*/
		}
		while ((getchar()) != '\n') // 가끔 낚이는 거: 아니 '\n'는 왜 buffer에 안 남지? 일단 입력받고 비교를 해야 진입을 하고 말고가 정해지잖아. buffer에 남은 나머지 문자를 getchar()가 한 글자씩 먹어주고 있다.
			continue;
	}


	return 0;
}