/* ���̳ʸ�(Binary) ���� ����� */
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

         C11 'x' mode fails if the file exists, instead of overwriting it. ������ �̹� �����Ѵٸ� ����� �ʰ� �׳� ����
         - "wx", "wbx", "w+x", "wb+x", "w+bx"
     */

     // Writing example
    {
        FILE* fp = fopen("binary_file", "wb"); //.txt���ϸ��� �츮�� �˰� �ִ� ��κ��� ������ ���̳ʸ� �����̴�. .hwp .doc�̷� �͵� ���� ���� �ۼ��� ������ ��Ʈ ũ�⳪ ��Ʈ�� ���� ǥ ���� �̷� �����͵��� �� ���̳ʸ��� ���Ͽ� ����Ǿ� �ִ�.
        // �츮�� ������� ���� ���Ǽ� ������ .txt������ ���� ������ �ǹ������� ���̳ʸ� ������ ��κ�

        double d = 1.0 / 3.0;
        int n = 123; // �迭�� �д� �ʿ��� �� ������ ��Ȯ�ϰ� �𸥴ٸ� �������� ���� �����ϴ� �� �Ϲ���
        int* parr = (int*)malloc(sizeof(int) * n);
        if (!parr) exit(1);
        for (int n = 0; n < 123; ++n)
            *(parr + n) = n * 2;

        fwrite(&d, sizeof(d), 1, fp);
        fwrite(&n, sizeof(n), 1, fp);
        fwrite(parr, sizeof(int), n, fp);

        fclose(fp);
        free(parr);

        // Total size is 8 * 1 + 4 * 1 + 123 * 4 = 504 bytes binary file�� ��Ȯ�� 504����Ʈ
    }

    // �ؽ�Ʈ ���Ͽ� ���� ���̳ʸ� ������ ������ �� ���� ����. ��üũ�������� �� �д� �ʿ��� �� ������ � �������� ������� �ִ��� double�� ����Ǿ��ִ��� char�� ����Ǿ��ִ��� � �����͸� ��� �ִ��� ������ ��� �Ǵ��� �˰� �־�� ��
    // Reading example, feof(), ferror()
    {
        FILE* fp = fopen("binary_file", "rb"); // ���� �츰 double �ϳ��� int �ϳ��� int ������ŭ�� int�� ����ִ� ���� �˰� �ִ�.
        double d;
        int n = 0;
        fread(&d, sizeof(d), 1, fp);
        fread(&n, sizeof(n), 1, fp); // �����Ҵ��� �߿��� ��� �� �ϳ� ex) ���ϸ��� �����ڼ� �о���� n�� ���缭 �޸𸮸� �ʱ�ȭ�ϰ� �� �޾Ƶ���

        int* parr = (int*)malloc(sizeof(int) * n);
        if (!parr) exit(1);

        fread(parr, sizeof(int), n, fp); //n�� ũ�ٸ� �� �Ⱑ ���� ���۸��� �۵� ���۰� �� ���� �ٽ� �о���� �� ����

        printf("feof = %d\n", feof(fp)); //feof() EOF�� �����°� �㳪 ����ϰ� ����� ������ŭ �Ա� ������ 

        printf("%f\n", d);
        printf("%d\n", n);
        for (int i = 0; i < n; ++i)
            printf("%d ", *(parr + i));
        printf("\n");

        printf("feof = %d\n", feof(fp));

        fread(&n, sizeof(n), 1, fp);          // read one more toward EOF

        printf("feof = %d\n", feof(fp));      // returns non-zero at EOF
        printf("ferror = %d\n", ferror(fp));  // returns 0 : OK ferror() ���Ͻ�Ʈ���� �о�µ� ������ �ֳ� ����

        fwrite(&n, sizeof(n), 1, fp);         // try writing to make an error(because it is opened with "r" mode)

        printf("ferror = %d\n", ferror(fp));  // 0 is OK, non-zero otherwise

        fclose(fp);
        free(parr);
    }
}