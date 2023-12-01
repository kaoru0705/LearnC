/* ���� ���� ����(Random Access) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
    ABCDEF ...
    Current position 0 and read -> A
    Current position 1 and read -> B
    ...
    0A1B2C3D4E5F 1��ġ ������ �������κ��� 1����Ʈ��ŭ ������ �ִ�. ���⼭ ������ �� ĭ �̵�
*/

int main(void)
{
    int ch;
    long cur;

    FILE* fp = fopen("test.txt", "r");
    
    cur = ftell(fp); // ftell() ���� ��ġ�� �˷���
    printf("ftell() = %ld\n", cur);

    fseek(fp, 2L, SEEK_SET); // SEEK_SET flag ������, 2L (byte) ���������κ��� 2����Ʈ ������ ���� �غ� �Ѵ�.
    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);
    ch = fgetc(fp); // �о �� ����Ʈ �̵�
    printf("%d %c\n", ch, ch);
    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);

    fseek(fp, -2L, SEEK_CUR);  // SEEK_CUR: ���� ��ġ�� �������� �̵� -2L ������ ����
    cur = ftell(fp);
    printf("ftell() = %ld\n", cur);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);

    /* SEEK_END */

    fseek(fp, 0L, SEEK_END); // SEEK_END ���������� ã��
    ch = fgetc(fp); // ������ �ϳ��� ������ EOF
    printf("%d %c\n", ch, ch);

    fseek(fp, -1L, SEEK_END);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);

    fseek(fp, -2L, SEEK_END);
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);

    /* fsetpos(), fgetpos() */ 
    fpos_t pt; // ������ ���ϰ� Ŭ ��� long���� fpos_t�� ����� �� �ִ�.
    pt = 10;
    fsetpos(fp, &pt);            // returns 0 OK fseek�ϰ� ���
    ch = fgetc(fp);
    printf("%d %c\n", ch, ch);
    fgetpos(fp, &pt);            // returns 0 OK fget�ϰ� ���
    printf("%lld\n", pt);        // NOTE: not meant to be read directly ���� longlong�� ���� �ִµ� fpos_t�� ���������ڴ� �������� �ʴ´�. ������ �շ����� �� ����

    return 0;
}