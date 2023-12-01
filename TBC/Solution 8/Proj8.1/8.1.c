/* 중요한 프로젝트는 책꽂이를 해라*/
/* 입출력 버퍼 buffer */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h> // in Windows 버퍼 사용하지 않는 함수 제공, _getch(), _getche() linux도 가능하긴 함

// buffer 사이즈는 컴파일러, 시스템에 따라 다르다. 조절도 가능
	// 우리가 프로그래밍 할 때 가장 느린 작업이 입출력 그다음이 메모리 할당 해제 
	// 그래서 나온 게 버퍼 입력한 내용이 버퍼로 가는 건 꽤 빠르다. 게임은 더블버퍼 트리플버터로 렌더링 속도를 빠르게 하는 등 이용
	// 버퍼에 모았다가 때가 되면 버퍼를 통째로 보냄 버스
	// 때가 되는 2가지 경우
	// 1. 버퍼가 다 찼을 때 // 버퍼는 효율성좋게 사이즈가 미리 조정돼있다 data가 큰 사이즈의 file을 전송하거나 읽는다거나 인터넷프로그래밍 
	// 2. '\n' 
int main()
{
	char c;

	// 분명히 하나 입력 하나 출력인데 마치 한덩어리처럼 입력받고 출력됐다.
	while ((c = _getche()) != '.')	//getch echo 메아리 (컴퓨터가 콘솔창에 그려줌) buffer를 통하지 않으면 원래 이렇게 작동하는 게 맞다.
		putchar(c);                 //_getch()메아리가 없음 getch()이제 deprecated(형용사 신조어 중요도가 떨어져 더 이상 사용되지 않고 앞으로는 사라지게 될 (컴퓨터 시스템 기능 등) 안 쓴다.


	//char a, b, c;
	//scanf("%c %c %c", &a, &b, &c);
	//printf("%c, %c, %c", a, b, c); // enter 여러번 하고 입력 시 a만 enter 입력됨

	return 0;
}