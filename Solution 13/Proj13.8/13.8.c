/* �ؽ�Ʈ ������ ���̳ʸ�ó�� �о�� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>  // SetConsoleOutputCP()

int main(void)
{
    FILE* fp = fopen("test.txt", "rb"); // test ������ ���̳ʸ��� ���� �ִ�.

    unsigned char ch;
    unsigned char str[4] = { '0', };

    SetConsoleOutputCP(CP_UTF8);  // UTF-8 mode

    // �ѱ��� ������ ������� 1����Ʈ ���� ���� �����Ͱ� ���Ǳ⿡ ���⼭ ���������� ����Ϸ��� �������� ����ؾ� �Ѵ� �ѱ��� ǥ���� �� 3����Ʈ�� ���
    // ������ Ư�� �ѱ��� ���ڵ��� ���� ����Ʈ�� �ϳ��� ����ϴ� �� �ƴ϶� �������� ���� ���ڵ��� ǥ���� ���� ���� ���� ����Ʈ�� �����ؼ� ����� �� �ִ�.
    // ���̳ʸ� �����͸� ������ ���� �����ϰ� ���̳ʸ� �����͸� ���������� �ؽ�Ʈ ������ ������ ���� �߰����� ��Ұ� �ٰ� �� ��ҵ��� �ü���� ���� �ٸ��� 13 10 �� �� ���� ��(�ܼ�â���� 3ĭ�� ��� �ִ�)
    while (fread(&ch, sizeof(unsigned char), 1, fp) > 0) // fread�� ��ȯ�� �о���� ������ ���� 0? EOF
    {
        printf("%hhu %c\n", ch, ch);  // windows�� ��� carriage return(�ƽ�Ű�ڵ� 13), line feed(�ƽ�Ű�ڵ� 10)�� �Բ� ��µȴ� ch == '\n' �� �� ���Ⱑ �� �� �ż� �̷��� �� ���� ����� �Ŵ�.
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