/* 중요한 프로젝트는 책꽂이를 해라*/
/* 숫자와 문자를 섞어서 입력 받기 */ /* 4.10 참조 해라 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(char cr, int lines, int width);

int main()
{
	char c;
	int rows, cols;
	// char yo;
	/* try 1 */
	//while (1)	// program을 종료할 때 줄바꿈으로 달성하기 힘듦 " %d %d"까지 입력하고 display로 출력하고 종료하기 때문
	//{
	//	scanf("%c %d %d", &c, &rows, &cols);	// scanf는 원래 남은 문자'\n'를 buffer에 남겨둠
	//	//while (getchar() != '\n')		//  a 3 3 '\n' b 1 2 입력시 이걸 적지 않는다면 c = '\n'가 들어가고 그다음 b를 rows와 cols가 받아들이지 못 해 둘 다 값이 3 그대로가 된다.
	//	//	continue;
	//	display(c, rows, cols);
	//	if (c == '\n')
	//		break;		//doesn't work well
	//}

	/* try 2 */

	printf("Input one character and two integers:\n");
	while ((c = getchar()) != '\n')
	{
		scanf("%d %d", &rows, &cols);
		while (getchar() != '\n') continue;

		display(c, rows, cols);
		printf("Input another character and two integers:\n");
		printf("Press Enter to quit.\n");
	}

	return 0;
}
/* my answer */
//void display(char cr, int lines, int width)
//{
//	for (int i = 0; i < lines; i++)
//	{
//		for (int j = 0; j < width; j++)
//			printf("%c", cr);
//
//		printf("\n");
//	}
//}
void display(char cr, int lines, int width)
{
	int row, col;
	for (row = 1; row <= lines; row++)
	{
		for (col = 1; col <= width; col++)
			putchar(cr);

		putchar('\n');
	}
}
