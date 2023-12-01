/* 텍스트 인코딩(Encoding)과 코드 페이지(Code Page) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // windows에서만 가능 SetConsoleOutputCP(): 코드 페이지의 약자 CP

// 메모장 밑 상태표시줄에 Windows(CRLF) UTF-8(encoding 방식) 운영체제마다 각 라인의 끝을 나타내는 기호가 다르다. carriage return(\r) line feed(\n)
// 텍스트 파일도 결국에는 바이너리로 저장된다. 데이터가 이진수로 저장된 걸 텍스트 파일로 읽어들이도록 어떤 규칙을 정해놨다. 이진수를 어떤 숫자로 바꾸고 그 숫자가 어떤 문자에 대응된다. 이해할 수 있는 우리의 문자로 디코딩함
// 디코딩하는 표를 잘못사용하면 깨진다. utf-8로 저장하니 깨진다. 콘솔 출력할 땐 문제가 있었는데 사본으로는 저장이 제대로 돼있네? 원본에서 결국 컴퓨터는 이진수처럼 사용하기에 이진수처럼 읽었고 화면에 출력할 때 깨진 건 그 읽어들인 숫자들이 어떤 문자에 대응하는지 표를 잘못 사용해서 그렇다
// 허나 저장할 때는 어쨌든 데이터를 그대로 저장하고 텍스트 편집기에서 그것을 제대로된 인코딩으로 여니까 잘됐다.
// 텍스트 편집기에서 인코딩 방식을 UTF-8에서 ANSI로 바꾼 후 콘솔에서 읽어들이면 제대로 출력된다. 콘솔창 디코딩 방식이 ANSI
// 인코딩 방식이 다른 두 개의 파일이 텍스트 편집기 상에서 똑같은 글자들로 보이는 이유는 텍스트 편집기 프로그램이 그렇게 보이도록 만들어주기 때문이다.
// 실무에선 결국 데이터양이 많거나 빠르게 해야 되면 바이너리 위주로 사용
// 사본_ansi가 ansi인지 어떻게 알고 ansi로 열었을까 그야 운영체제가 편하게 처리
// 프로그램에서 디코딩 방식을 바꿀 수도 있다.

int main(void)
{
    const UINT default_cp = GetConsoleOutputCP();  // 현재 사용하고 있는 CP가 뭔지 알 수 있다. 기본이 949
    printf("%u\n", default_cp);

    int ch;
    FILE* fr, * fw;

    const char* in_filename = "원본.txt";
    const char* out_filename = "사본.txt";

    unsigned long count = 0;

    if ((fr = fopen(in_filename, "r")) == NULL)
    {  // Open a text file for reading
        printf("Can't open %s\n", in_filename);
        exit(EXIT_FAILURE);
    }

    if ((fw = fopen(out_filename, "w")) == NULL)
    {  // Open a text file for writing
        printf("Can't open %s\n", out_filename);
        exit(EXIT_FAILURE);
    }

    SetConsoleOutputCP(CP_UTF8);  // UTF-8 mode(콘솔에다가 문자를 출력할 때 사용하는 코드페이지를 txt file이 인코딩 되어 있는 utf-8을 사용하겠다.) windows7에서는 메모장에서 UTF-8(BOM(빅엔디안 리틀엔디안 구분하게 해줌))이라 출력이 답 없다.

    while ((ch = fgetc(fr)) != EOF)
    {
        fputc(ch, stdout);  // same as putchar(ch);
        fputc(ch, fw);
        count++;
    }

    fclose(fr);
    fclose(fw);

    SetConsoleOutputCP(default_cp);  // ISO 2022 Korean(프로그램 자체에서 사용하는 기본 설정된 CP로 콘솔창 문자 출력하도록 되돌리기) 이걸 안 하면 밑에 출력이 깨져서 나옴

    printf("FILE %s has %lu characters\n", in_filename, count);
    printf("Copied to %s\n", out_filename);

    printf("한글 출력 확인");

    return 0;
}