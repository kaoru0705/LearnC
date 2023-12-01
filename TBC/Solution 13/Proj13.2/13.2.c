/* 텍스트 파일 입출력 예제 */
/* 8.9 참조 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int ch;
    FILE* fr, * fw; // FILE 타입은 파일을 처리할 때 필요한 데이터들을 모아놓은(구조체) 포인터이다
    // txt파일을 notepad같은 프로그램으로 직접 읽을 수 있기 때문에 text파일이라 부르는 거고 사람들이 읽을 수 있게 텍스트파일로 저장함 어처구니 없게도 결국은 notepad라는 프로그램을 사용해야지만 읽을 수 있다. 이렇게 운영체제의 도움이 필요함

    /*
     typedef struct _iobuf
     {
        char* _ptr;
        int _cnt;
        char* _base;
        int _flag;
        int _file;
        int _charbuf;
        int _bufsiz;
        char* _tmpfname;
     } FILE; // FILE이란 자료형이 있는 것처럼 사용할 수 있게 해줌 거기에 대한 포인터를 선언함
     */

    const char* out_filename = "output.txt";  // TODO: Use this

    unsigned long count = 0;

    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]); // 명령줄 사용방법을 알려주는 게 c에서 일반적인 방식
        exit(EXIT_FAILURE);
    }

    if ((fr = fopen(argv[1], "r")) == NULL) // Open a text file for reading fopen 파일을 처리할 때 필요한 데이터들의 묶음에 대한 포인터 반환, 널이라면 파일을 열지 못했다 스트림을 열지 못했다. fopen에 f12를 누르면  _fileno 부분에 _Stream이라는 용어 하나로 결국 입출력 스트림도 파일스트림도 일원화돼있다. 한 가지의 데이터 통로가 있는 것처럼 처리할 수 있도록 c언어가 제공해줌
    { // 파일에 어떤 데이터를 저장하려면 운영체제가 하드디스크 이러한 데이터를 저장하라고 명령 하드디스크의 내장된 소프트웨어가 어떻게 작동해서 하드웨어에 있는 여러 가지 부속품들 이용해서 데이터를 저장하기도 하고 읽어오기도 함
        printf("Can't open %s\n", argv[1]); // NULL 포인터가 반환되는 경우를 만나기 쉽지 않다 ex) 하드디스크 문제나 읽기 모드를 강제로 쓰기모드로 한다든가 하면 운영체제가 막아버림
        exit(EXIT_FAILURE);
    }

    /*
        fopen mode strings( ex)"r" 문자열임) for text files(꼭 한 글자인 게 아니라 +가 붙는 경우도 있기 때문에 겹따옴표를 사용한다)
        - r: reading
        - w: creating-and-writing or over-writing 없으면 만들고 씀 있으면 덮어씀 기존의 있던 것들이 사라짐 위험할 수 있다. 그래서 append도 있음 덧붙임
        - a: creating-and-writing or appending
        - r+: both reading and writing
        - w+: reading and writing, over-writing or creating 2글자
        - a+: reading and writing, appending or creating
     */

    //fw = fopen(out_filename, "w"); // my poor answer
    if ((fw = fopen(out_filename, "w")) == NULL)
    {
        printf("Can't open %s\n", out_filename);
        exit(EXIT_FAILURE);
    }

    // fgetc(), fputc()함수가 getc(), putc()함수보다 안정적으로 동작한다
    while ((ch = fgetc(fr)) != EOF) // fgetc return int parameter(ascii code) 11.4 참조
    { 
        //putc(ch, stdout);  // same as putchar(ch); ch의 내용을 stdoutput에 저장 stderr을 넣으면 error스트림으로 출력이 됨(대부분 화면에 나옴) redirection을 할경우 stdout stderr 나눠서 redirection할 수 있다.
        fputc(ch, stdout);  // stdout이 아니라 다른 스트림으로 바꿀 수 있다
        
        fputc(ch, fw);//TODO: use fputs() to write a file stream!
        
        count++;
    }

    fclose(fr);  // 파일 스트림을 열었으면 닫아줘야한다. fclose는 혹시모를 버퍼에 남아 있는 데이터도 처리해준다
    fclose(fw);

    printf("FILE %s has %lu characters\n", argv[1], count);
    printf("Copiede to %s", out_filename);

    return 0;
}