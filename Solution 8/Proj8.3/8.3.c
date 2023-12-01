/* 중요한 프로젝트는 책꽂이를 해라*/
/* 입출력 방향 재지정 Redirection */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
 명령 프롬프트 화살표 방향 위 를 누르면 방금 전에 입력한 게 뜬다. 
C:\Users\KDH\source\repos\Solution 8\Debug>Proj8.3.exe > output.txt
//Proj8.3.exe의 출력방향을 콘솔창이었던 걸 output.txt로 redirection
// console 창으로 출력할 것을 file로 redirection한 것 output.txt가 생성되는 걸 확인 할 수 있다.
C:\Users\KDH\source\repos\Solution 8\Debug>output.txt

C:\Users\KDH\source\repos\Solution 8\Debug>Proj8.3.exe>output.txt	붙여 써도 됨

C:\Users\KDH\source\repos\Solution 8\Debug>output.txt

C:\Users\KDH\source\repos\Solution 8\Debug>explorer

C:\Users\KDH\source\repos\Solution 8\Debug>explorer . 현재 위치를 나타내는 .

C:\Users\KDH\source\repos\Solution 8\Debug>notepad output.txt 이렇게도 열 수 있다.

출력할 것을 file로 보내는 건데 입력을 받을 수는 없나요?
C:\Users\KDH\source\repos\Solution 8\Debug>Proj8.3.exe < input.txt
Proj8.3.exe에다 input.txt를 보내줌
input.txt를 Proj8.3.exe의 입력으로 redirection
C:\Users\KDH\source\repos\Solution 8\Debug>Proj8.3.exe<input.txt>output.txt 이런식으로도 할 수 있다.
C:\Users\KDH\source\repos\Solution 8\Debug>Proj8.3.exe>>output.txt linux unix 에서 많이 배움
Banana 
I love Melon 뒤에 I love Banana가 덧붙인 상태로 file 생성

printf("Programming");으로 rebuild
C:\Users\KDH\source\repos\Solution 8\Debug>Proj8.3
Programming
C:\Users\KDH\source\repos\Solution 8\Debug>copy Proj8.3.exe test.exe
		1개 파일이 복사되었습니다.
Proj8.3.exe 복사해서 보관함 그다음 다시 str[100]을 rebuild
C:\Users\KDH\source\repos\Solution 8\Debug>test.exe | Proj8.3.exe
I love Programming
test.exe의 실행 결과가 pipe key(|) 를 타고 Proj8.3.exe로 흘러감

linux unix 에서 많이 배움

data의 흐름을 콘솔출력으로 보내던 걸 파일출력으로 리디렉션 할 수 있다. 
그리고 data의 흐름의 끝에는 EOF가 있었을 것이다.
*/

int main()
{
	/*printf("Programming");*/
	char str[100];
	scanf("%s", str);
	printf("I love %s\n", str);

	return 0;
}