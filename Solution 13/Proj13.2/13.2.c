/* �ؽ�Ʈ ���� ����� ���� */
/* 8.9 ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int ch;
    FILE* fr, * fw; // FILE Ÿ���� ������ ó���� �� �ʿ��� �����͵��� ��Ƴ���(����ü) �������̴�
    // txt������ notepad���� ���α׷����� ���� ���� �� �ֱ� ������ text�����̶� �θ��� �Ű� ������� ���� �� �ְ� �ؽ�Ʈ���Ϸ� ������ ��ó���� ���Ե� �ᱹ�� notepad��� ���α׷��� ����ؾ����� ���� �� �ִ�. �̷��� �ü���� ������ �ʿ���

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
     } FILE; // FILE�̶� �ڷ����� �ִ� ��ó�� ����� �� �ְ� ���� �ű⿡ ���� �����͸� ������
     */

    const char* out_filename = "output.txt";  // TODO: Use this

    unsigned long count = 0;

    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]); // ����� ������� �˷��ִ� �� c���� �Ϲ����� ���
        exit(EXIT_FAILURE);
    }

    if ((fr = fopen(argv[1], "r")) == NULL) // Open a text file for reading fopen ������ ó���� �� �ʿ��� �����͵��� ������ ���� ������ ��ȯ, ���̶�� ������ ���� ���ߴ� ��Ʈ���� ���� ���ߴ�. fopen�� f12�� ������  _fileno �κп� _Stream�̶�� ��� �ϳ��� �ᱹ ����� ��Ʈ���� ���Ͻ�Ʈ���� �Ͽ�ȭ���ִ�. �� ������ ������ ��ΰ� �ִ� ��ó�� ó���� �� �ֵ��� c�� ��������
    { // ���Ͽ� � �����͸� �����Ϸ��� �ü���� �ϵ��ũ �̷��� �����͸� �����϶�� ��� �ϵ��ũ�� ����� ����Ʈ��� ��� �۵��ؼ� �ϵ��� �ִ� ���� ���� �μ�ǰ�� �̿��ؼ� �����͸� �����ϱ⵵ �ϰ� �о���⵵ ��
        printf("Can't open %s\n", argv[1]); // NULL �����Ͱ� ��ȯ�Ǵ� ��츦 ������ ���� �ʴ� ex) �ϵ��ũ ������ �б� ��带 ������ ������� �Ѵٵ簡 �ϸ� �ü���� ���ƹ���
        exit(EXIT_FAILURE);
    }

    /*
        fopen mode strings( ex)"r" ���ڿ���) for text files(�� �� ������ �� �ƴ϶� +�� �ٴ� ��쵵 �ֱ� ������ �����ǥ�� ����Ѵ�)
        - r: reading
        - w: creating-and-writing or over-writing ������ ����� �� ������ ��� ������ �ִ� �͵��� ����� ������ �� �ִ�. �׷��� append�� ���� ������
        - a: creating-and-writing or appending
        - r+: both reading and writing
        - w+: reading and writing, over-writing or creating 2����
        - a+: reading and writing, appending or creating
     */

    //fw = fopen(out_filename, "w"); // my poor answer
    if ((fw = fopen(out_filename, "w")) == NULL)
    {
        printf("Can't open %s\n", out_filename);
        exit(EXIT_FAILURE);
    }

    // fgetc(), fputc()�Լ��� getc(), putc()�Լ����� ���������� �����Ѵ�
    while ((ch = fgetc(fr)) != EOF) // fgetc return int parameter(ascii code) 11.4 ����
    { 
        //putc(ch, stdout);  // same as putchar(ch); ch�� ������ stdoutput�� ���� stderr�� ������ error��Ʈ������ ����� ��(��κ� ȭ�鿡 ����) redirection�� �Ұ�� stdout stderr ������ redirection�� �� �ִ�.
        fputc(ch, stdout);  // stdout�� �ƴ϶� �ٸ� ��Ʈ������ �ٲ� �� �ִ�
        
        fputc(ch, fw);//TODO: use fputs() to write a file stream!
        
        count++;
    }

    fclose(fr);  // ���� ��Ʈ���� �������� �ݾ�����Ѵ�. fclose�� Ȥ�ø� ���ۿ� ���� �ִ� �����͵� ó�����ش�
    fclose(fw);

    printf("FILE %s has %lu characters\n", argv[1], count);
    printf("Copiede to %s", out_filename);

    return 0;
}