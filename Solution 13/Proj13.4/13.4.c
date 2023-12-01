/* 텍스트 파일 모드 스트링과 다양한 입출력 함수들 fprintf(), fscanf(), fgets(), fputs() */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 31

int main(void)
{
    FILE* fp;
    char words[MAX] = { '\0', };

    const char* filename = "record.txt";  // 스트림을 열 때 해당 이름으로 파일이 만들어지는 경우 .txt를 추가로 붙여줘야지 자동으로 텍스트 편집기로 연결된다. 아니면 처음부터 "record.txt"로 입력하는 것도 가능하다 record파일을 visual studio에 드래그해서 볼 수도 있다. 메모장에 드래그해서 볼 수도 있다.

    /*
     fopen() mode strings for text files
     - r: reading
     - w: creating-and-writing or over-writing
     - a: creating-and-writing or appending
     - r+: both reading and writing(해당 파일이 존재하지 않으면 스트림을 열지 못하며, 해당 파일이 있다면 기존 내용 위에다 새로운 내용만큼만 덮어쓴다)
     - w+: reading and writing, over-writing or creating(해당 파일이 존재하지 않으면 새로 생성하며, 해당 파일이 있다면 기존 내용을 모두 지우고 새로운 내용으로 덮어쓴다)
     - a+: reading and writing, appending or creating
     */

    if ((fp = fopen(filename, "a+")) == NULL) // Try r+, w+, a+
    {
        fprintf(stderr, "Can't open \"%s\" file.\n", filename);
        exit(EXIT_FAILURE);
    }
    //// 123 4567 abc . 입력해봐라
    //// fgets() 어디에 담을지, 최대 몇 개, fputs()함수: 매개변수 FILE*의 위치가 맨 끝에 위치한다. 성공적으로 입력을 받았을 때 포인터 첫 주소 반환하므로 EOF인 경우 NULL이 반환될 수 있다 line단위 gets() vs scanf()랑 비슷
    //// fscanf(), fprintf()함수: 매개변수 FILE*의 위치가 맨 처음에 위치한다. EOF가 반환될 수 있다
     
    //while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.')) // fscanf()함수의 스트림을 stdin으로 지정하면 scanf()함수와 거의 동일하게 작동한다 띄어쓰기로 구분
    //    fprintf(fp, "%s\n", words);

    while ((fgets(words, MAX, stdin) != NULL) && (words[0] != '.'))
        fputs(words, fp);
    
    rewind(fp);  // go back to beginning of file

    //while (fscanf(fp, "%s", words) == 1) // file을 rewind해서 다시 출력하고 있다.
    ////while(fscanf(fp, "%s", words) != EOF)  // 윗줄과 같은 의미
    //{
    //    fprintf(stdout, "%s\n", words);  // fprinf()함수의 스트림을 stdout으로 지정하면 printf()함수와 거의 동일하게 작동한다
    //}

    while(fgets(words, MAX, fp) != NULL)
        fputs(words, stdout);

    if (fclose(fp) != 0) // 0 on success
        fprintf(stderr, "Error closing file\n");

    return 0;
}