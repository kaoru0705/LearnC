/* 바이너리(Binary) 파일 입출력 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*
         fopen() mode string for binary IO
         - "rb", "wb", "ab"
         - "rb+", "r+b"
         - "wb+", "w+b"
         - "ab", "a+b"

         C11 'x' mode fails if the file exists, instead of overwriting it. 파일이 이미 존재한다면 덮어쓰지 않고 그냥 실패
         - "wx", "wbx", "w+x", "wb+x", "w+bx"
     */

     // Writing example
    {
        FILE* fp = fopen("binary_file", "wb"); //.txt파일말고 우리가 알고 있는 대부분의 파일은 바이너리 파일이다. .hwp .doc이런 것도 ㅋㅋ 문서 작성한 내용을 폰트 크기나 폰트의 종류 표 구성 이런 데이터들이 다 바이너리로 파일에 저장되어 있다.
        // 우리가 디버깅할 때는 편의성 때문에 .txt파일을 많이 쓰지만 실무에서는 바이너리 파일이 대부분

        double d = 1.0 / 3.0;
        int n = 123; // 배열은 읽는 쪽에서 몇 개인지 정확하게 모른다면 개수까지 같이 저장하는 게 일반적
        int* parr = (int*)malloc(sizeof(int) * n);
        if (!parr) exit(1);
        for (int n = 0; n < 123; ++n)
            *(parr + n) = n * 2;

        fwrite(&d, sizeof(d), 1, fp);
        fwrite(&n, sizeof(n), 1, fp);
        fwrite(parr, sizeof(int), n, fp);

        fclose(fp);
        free(parr);

        // Total size is 8 * 1 + 4 * 1 + 123 * 4 = 504 bytes binary file이 정확히 504바이트
    }

    // 텍스트 파일에 비해 바이너리 파일은 꺼내도 알 수가 없다. 전체크기정도만 앎 읽는 쪽에서 이 파일이 어떤 형식으로 만들어져 있는지 double이 저장되어있는지 char이 저장되어있는지 어떤 데이터를 담고 있는지 순서가 어떻게 되는지 알고 있어야 함
    // Reading example, feof(), ferror()
    {
        FILE* fp = fopen("binary_file", "rb"); // 지금 우린 double 하나랑 int 하나랑 int 개수만큼의 int가 들어있는 것을 알고 있다.
        double d;
        int n = 0;
        fread(&d, sizeof(d), 1, fp);
        fread(&n, sizeof(n), 1, fp); // 동적할당의 중요한 용법 중 하나 ex) 매일매일 가입자수 읽어들인 n에 맞춰서 메모리를 초기화하고 쭉 받아들임

        int* parr = (int*)malloc(sizeof(int) * n);
        if (!parr) exit(1);

        fread(parr, sizeof(int), n, fp); //n이 크다면 몇 기가 마냥 버퍼링이 작동 버퍼가 꽉 차고 다시 읽어오고 꽉 차고

        printf("feof = %d\n", feof(fp)); //feof() EOF를 만났는가 허나 깔끔하게 저장된 개수만큼 왔기 때문에 

        printf("%f\n", d);
        printf("%d\n", n);
        for (int i = 0; i < n; ++i)
            printf("%d ", *(parr + i));
        printf("\n");

        printf("feof = %d\n", feof(fp));

        fread(&n, sizeof(n), 1, fp);          // read one more toward EOF

        printf("feof = %d\n", feof(fp));      // returns non-zero at EOF
        printf("ferror = %d\n", ferror(fp));  // returns 0 : OK ferror() 파일스트림을 읽어가는데 문제가 있냐 없냐

        fwrite(&n, sizeof(n), 1, fp);         // try writing to make an error(because it is opened with "r" mode)

        printf("ferror = %d\n", ferror(fp));  // 0 is OK, non-zero otherwise

        fclose(fp);
        free(parr);
    }
}