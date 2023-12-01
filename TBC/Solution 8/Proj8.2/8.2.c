/* 중요한 프로젝트는 책꽂이를 해라*/
/* 파일의 끝 end of file eof */
/* https://www.asciitable.com/ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // EOF in stdio.h

int main()
{
	int c;

	//// getchar() 반환값을 int로 넘겨주고 있다 내부적으로 ascii code를 사용해서 문자 표현 ascii code에는 음수가 없는데?
	//while ((c = getchar()) != EOF)	// End Of File #define EOF (-1)
	//	putchar(c);				// != '.'라면 만약에 입력하다가 중간에 '.'을 입력하고 싶어진다면? 다른 기호를 써야 하나
	//// 입력이 끝났다는 걸 프로그램에게 알리고 싶을 때 운영체제가 알려준다 그때 getchar는 -1을 return
	//// 콘솔입력과 파일입력은 끝내는 방법이 동일하다. 지금까진 인위적으로 (마침표) 종료했을 뿐
	//// console창에서 ctrl z 누르면 종료
	//// ctrl c = OS가 실행중인 프로그램을  강제종료

	/* ctrl z 누른게 입력이 제대로 됐는지 확인 */

	// stream 흘러감 콘솔입출력은 시냇물 data가 흘러서 프로그램으로 들어감
	// file의 저장된 데이터가 흘러흘러 우리의 프로그램으로 들어감 반대방향으로도 
	// putchar() 프로그램에서 데이터가 흘러 나와 콘솔로 옴 
	// data를 흘러보낼 때 파일에서 stream이 언제 끝나는지를 표시하는 게 EOF 
	while (1)
	{
		c = getchar();
		printf("%d\n", c);
		if (c == EOF)
			break;
	}

	return 0;
}