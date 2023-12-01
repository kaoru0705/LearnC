/* �ؽ�Ʈ ���ڵ�(Encoding)�� �ڵ� ������(Code Page) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // windows������ ���� SetConsoleOutputCP(): �ڵ� �������� ���� CP

// �޸��� �� ����ǥ���ٿ� Windows(CRLF) UTF-8(encoding ���) �ü������ �� ������ ���� ��Ÿ���� ��ȣ�� �ٸ���. carriage return(\r) line feed(\n)
// �ؽ�Ʈ ���ϵ� �ᱹ���� ���̳ʸ��� ����ȴ�. �����Ͱ� �������� ����� �� �ؽ�Ʈ ���Ϸ� �о���̵��� � ��Ģ�� ���س���. �������� � ���ڷ� �ٲٰ� �� ���ڰ� � ���ڿ� �����ȴ�. ������ �� �ִ� �츮�� ���ڷ� ���ڵ���
// ���ڵ��ϴ� ǥ�� �߸�����ϸ� ������. utf-8�� �����ϴ� ������. �ܼ� ����� �� ������ �־��µ� �纻���δ� ������ ����� ���ֳ�? �������� �ᱹ ��ǻ�ʹ� ������ó�� ����ϱ⿡ ������ó�� �о��� ȭ�鿡 ����� �� ���� �� �� �о���� ���ڵ��� � ���ڿ� �����ϴ��� ǥ�� �߸� ����ؼ� �׷���
// �㳪 ������ ���� ��·�� �����͸� �״�� �����ϰ� �ؽ�Ʈ �����⿡�� �װ��� ����ε� ���ڵ����� ���ϱ� �ߵƴ�.
// �ؽ�Ʈ �����⿡�� ���ڵ� ����� UTF-8���� ANSI�� �ٲ� �� �ֿܼ��� �о���̸� ����� ��µȴ�. �ܼ�â ���ڵ� ����� ANSI
// ���ڵ� ����� �ٸ� �� ���� ������ �ؽ�Ʈ ������ �󿡼� �Ȱ��� ���ڵ�� ���̴� ������ �ؽ�Ʈ ������ ���α׷��� �׷��� ���̵��� ������ֱ� �����̴�.
// �ǹ����� �ᱹ �����;��� ���ų� ������ �ؾ� �Ǹ� ���̳ʸ� ���ַ� ���
// �纻_ansi�� ansi���� ��� �˰� ansi�� �������� �׾� �ü���� ���ϰ� ó��
// ���α׷����� ���ڵ� ����� �ٲ� ���� �ִ�.

int main(void)
{
    const UINT default_cp = GetConsoleOutputCP();  // ���� ����ϰ� �ִ� CP�� ���� �� �� �ִ�. �⺻�� 949
    printf("%u\n", default_cp);

    int ch;
    FILE* fr, * fw;

    const char* in_filename = "����.txt";
    const char* out_filename = "�纻.txt";

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

    SetConsoleOutputCP(CP_UTF8);  // UTF-8 mode(�ֿܼ��ٰ� ���ڸ� ����� �� ����ϴ� �ڵ��������� txt file�� ���ڵ� �Ǿ� �ִ� utf-8�� ����ϰڴ�.) windows7������ �޸��忡�� UTF-8(BOM(�򿣵�� ��Ʋ����� �����ϰ� ����))�̶� ����� �� ����.

    while ((ch = fgetc(fr)) != EOF)
    {
        fputc(ch, stdout);  // same as putchar(ch);
        fputc(ch, fw);
        count++;
    }

    fclose(fr);
    fclose(fw);

    SetConsoleOutputCP(default_cp);  // ISO 2022 Korean(���α׷� ��ü���� ����ϴ� �⺻ ������ CP�� �ܼ�â ���� ����ϵ��� �ǵ�����) �̰� �� �ϸ� �ؿ� ����� ������ ����

    printf("FILE %s has %lu characters\n", in_filename, count);
    printf("Copied to %s\n", out_filename);

    printf("�ѱ� ��� Ȯ��");

    return 0;
}