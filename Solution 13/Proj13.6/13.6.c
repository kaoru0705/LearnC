/* 파일 임의 접근(Random Access) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
    ABCDEF ...
    Current position 0 and read -> A
    Current position 1 and read -> B
    ...
    0A1B2C3D4E5F 1위치 파일의 시작으로부터 1바이트만큼 떨어져 있다. 여기서 읽으면 한 칸 이동
*/

int main(void)
{
    int ch;
    long cur;

    FILE* fp = fopen("test.txt", "r");
    
    cur = ftell(fp); // ftell() 시작 위치를 알려줌
    printf("ftell() = %ld\n", cur);

    fseek(fp, 2L, SEEK_SET); // SEEK_SET flag 시작점, 2L (byte) 시작점으로부터 2바이트 떨어져 읽을 준비 한다.
    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);
    ch = fgetc(fp); // 읽어서 한 바이트 이동
    printf("%d %c\n", ch, ch);
    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);

    fseek(fp, -2L, SEEK_CUR);  // SEEK_CUR: 현재 위치를 기준으로 이동 -2L 음수도 가능
    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);

    /* SEEK_END */

    fseek(fp, 0L, SEEK_END); // SEEK_END 끝에서부터 찾기
    ch = fgetc(fp); // 끝에서 하나를 읽으니 EOF
    printf("%d %c\n", ch, ch);

    fseek(fp, -1L, SEEK_END);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);

    fseek(fp, -2L, SEEK_END);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);

    /* fsetpos(), fgetpos() */ 
    fpos_t pt; // 파일이 어마어마하게 클 경우 long말고 fpos_t를 사용할 수 있다.
    pt = 10;
    fsetpos(fp, &pt);            // returns 0 OK fseek하고 비슷
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);
    fgetpos(fp, &pt);            // returns 0 OK fget하고 비슷
    printf("%lld\n", pt);        // NOTE: not meant to be read directly 지금 longlong을 쓰고 있는데 fpos_t의 형식지정자는 존재하지 않는다. 강제로 롱롱으로 한 거임

    return 0;
}