/* 텍스트 파일을 바이너리처럼 읽어보기 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>  // SetConsoleOutputCP()

int main(void)
{
    FILE* fp = fopen("test.txt", "rb"); // test 파일을 바이너리로 열고 있다.

    unsigned char ch;
    unsigned char str[4] = { '0', };

    SetConsoleOutputCP(CP_UTF8);  // UTF-8 mode

    // 한글을 포함한 국제어에는 1바이트 보다 많은 데이터가 사용되기에 여기서 정상적으로 출력하려면 연속으로 출력해야 한다 한글을 표현할 땐 3바이트씩 묶어서
    // 국제어 특히 한글을 인코딩할 때는 바이트를 하나만 사용하는 게 아니라 가짓수가 많은 글자들을 표현할 때는 여러 개의 바이트를 조합해서 사용할 수 있다.
    // 바이너리 데이터를 저장할 때는 순수하게 바이너리 데이터를 저장하지만 텍스트 파일을 저장할 때는 추가적인 요소가 붙고 이 요소들이 운영체제에 따라 다르다 13 10 알 수 없는 거(콘솔창에는 3칸씩 띄고 있다)
    while (fread(&ch, sizeof(unsigned char), 1, fp) > 0) // fread의 반환값 읽어들인 데이터 양이 0? EOF
    {
        printf("%hhu %c\n", ch, ch);  // windows의 경우 carriage return(아스키코드 13), line feed(아스키코드 10)도 함께 출력된다 ch == '\n' 일 때 띄어쓰기가 두 번 돼서 이렇게 빈 줄이 생기는 거다.
        if (ch == 'c')
        {
            fread(str, sizeof(unsigned char), 3, fp);
            printf("%s\n", str);
            fread(str, sizeof(unsigned char), 3, fp);
            printf("%s\n", str);
            break;
        }
    }

    fclose(fp);

    return 0;
}