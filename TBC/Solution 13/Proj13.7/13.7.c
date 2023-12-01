/* 기타 입출력 함수들 ungetc(), fflush(), setvbuf() */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	ungetc() https://modoocode.com/49
	표준 입력 버퍼를 들여다 보면서 공부하는 방법
	https://www.youtube.com/watch?v=-23JdCHXuVc&list=PLNfg4W25Tapyl6ahul_8VS_8Tx3_egcTI&index=29
*/
int main()
{
	FILE* fp;
	int ch;

	/* ungetc() */ // getc() 거꾸로 함 한 글자 읽고 그 글자를 버퍼에 넣음
	fp = fopen("input.txt", "r");

	ch = fgetc(fp);
	printf("%u\n", ftell(fp));
	fputc(ch, stdout); // _Placeholder = 0x0128c079
	printf("\n%u\n", ftell(fp));
	ungetc((int)'A', fp);		// 버퍼에 ch를 넣어버림 try another characters ungetc((int)'A', fp); 'H'를 읽어들인다음 버퍼에서 꺼내고 그자리(스트림에 마지막으로 문자가 읽어들여졌던 자리에)에다 'A'가 들어감 파일 위치 표시자가 감소하여 이전 위치를 가리키게 한다. 그래서 'A'를 갖고 오고 출력하고 'e'를 갖고 오고 출력하고

	printf("%u\n", ftell(fp));

	ch = fgetc(fp);		// 버퍼에 ch가 남아있으니 ㅋㅋ  _Placeholder = 0x0128c078
	fputc(ch, stdout);	// _Placeholder = 0x0128c079

	ch = fgetc(fp);
	fputc(ch, stdout);	// _Placeholder = 0x0128c07a

	fclose(fp);

	/* setvbuf() */ // 이함수를 정확하게 설명하는 것은 기본 강의를 벗어남  지금까지의 강의는 버퍼를 실제로 보여준 적은 없음

	//// change the settings of buffer setvbuf 버퍼에 채워주는 함수가 아니라 버퍼링 방식을 변경해주는 함수
	//fp = fopen("input.txt", "r");

	//char buffer[32] = { '\0', }; // setvbuf() use this array as a buffer
	//setvbuf(fp, buffer, _IOFBF, sizeof(buffer)); // _IOLBF (Line 하나씩 버퍼에 꺼내서 저장 read할 땐 별차이 없댄다), _IOFBF (FULL buffer) , _IONBF 이거 써보셈 (N no)
	//for (int i = 0; i < sizeof(buffer); ++i)
	//	printf("%hhd", buffer[i]); // null 출력
	//printf("\n");

	//ch = fgetc(fp); // Read just only a single character 분명히 한 글자만 읽었는데? 버퍼가 꽉 찼노
	//// 버퍼라는 것은 이 프로그램이 파일의 내용을 계속 읽을 것으로 예상되면 미리 버퍼에 넣어 놓는다. 파일에서 갖고 오는 것보다 버퍼에서 갖고 오면 훨씬 빠르다. 그다음에 fget() 같은 걸 이용하면 버퍼로부터 한 글자를 가져오거나 여러 글자를 갖고 오는 건 비교적 빠르니 미리 채움
	//
	//// dump buffer
	//for (int i = 0; i < sizeof(buffer); ++i)
	//	printf("%c", buffer[i]);
	//printf("\n");

	//fclose(fp);


	/* fflush() */

	//// flush 변기 Writing a large amount of data 버퍼에 쌓여있던 데이터를 쫙 내려보내라 실무에서는 종종 쓰게 될 수도 있다.
	//// ex) wrting할 데이터가 너무 많아서 writing하라고 명령을 내리는데 프로그램과 OS가 같이 일하는 입장에서 버퍼에 있는 데이터를 미처 파일이나 디스플레이나 스트림으로 완벽하게 출력을 못 하는 경우가 생길 수 있다.
	//// 그때 반드시 다 출력해라 buffer가 빌 때까지. 이거다.
	//fflush(fp);

	return 0;
}