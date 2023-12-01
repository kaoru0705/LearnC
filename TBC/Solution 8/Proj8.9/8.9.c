/* 중요한 프로젝트는 책꽂이를 해라*/
/* 텍스트 파일 읽기 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit()
#include <string.h>
int main()
{
	int c;
	FILE *file = NULL;	// pointer 주소가 담김 file을 읽어들이는 stream을 담을 수 있는 어떤 정보가 변수에 담겨있다.
	//char file_name[] = "my_file.txt";
	//TODO: use scanf(...) 위처럼 하드코딩하지 않고 scanf를 받아서 입력한다거나 GUI를 통해 한다거나 유연한 방식으로도 할 수 있다.
	char file_name[100];
	scanf("%s", file_name);

	// 8.9c open containing folder my_file.txt 생성
	// command prompt로 실행하는 경우엔 Solution 8 debug에서 my_file.txt를 만들어야 실행 가능

	file = fopen(file_name, "r"); // "my_file.txt"라는 이름을 가진 file의 읽거나 저장하는 통로 stream을 열어준다.
	// "r" option read의 약자 이미 저장해 놓은 데이터를 읽어들이려고 할 때 사용 가능
	// "w" write 파일에 데이터를 저장하려고 한다면 저장할 수 있는 모드로 stream을 열게 된다.
	// 별도로 옵션이 없는 경우는 text파일을 열게 된다. ascii, binary 등등의 포맷으로 열게 된다.
	if (file == NULL)	// 이런 파일이 없을 경우
	{
		printf("Failed to open file.\n");
		exit(1004);	// ref 8.8.c 이 코드에 파일을 못 여는 건 아주 치명적인 문제다. 1 -1이 일반적
		// 더이상 할 수 있는 게 없을 때 exit(1)
		// exit(1004) C:\Users\KDH\source\repos\Solution 8\Debug\Proj8.9.exe (process 6292) exited with code 1004.
		// Press any key to close this window . . .
	}

	while ((c = getc(file)) != EOF)	// getc(FILE *_Stream)
		/* file을 읽어들이고 출력하는 게 console을 입력을 읽어들이고 출력하는 것과 비슷한 측면이 있다.*/
		putchar(c);
	fclose(file);	// file stream을 열었으니 이젠 닫기
	// 닫아야 OS가 아 이 프로그램이 이 파일을 다 사용했구나 경우에 따라선 다른 프로그램이 접근하고 싶어하기도 하니 닫아준다.

	
	return 0;
}