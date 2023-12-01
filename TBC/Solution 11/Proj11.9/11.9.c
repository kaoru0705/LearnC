/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ctype.h ���� �Լ��� ���ڿ��� ����ϱ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>  // toupper(), ispunct() ...

#define NUM_LIMIT 1024

void ToUpper(char*);
int PunctCount(const char*);

int main() {
    char line[NUM_LIMIT];
    char* new_line = NULL;
    fgets(line, NUM_LIMIT, stdin);
    new_line = strchr(line, '\n');  // find first newline 11.6 for ������ �� �� ������ �ذ�
    if (new_line)
        *new_line = '\0';

    ToUpper(line);
    puts(line);
    printf("%d\n", PunctCount(line));

    return 0;
}

void ToUpper(char* str) {  // C���� char* Ÿ���� �Ű������� ����ϴ� ��κ��� ���� ���ڿ� ���� �����ͷ� �ޱ⺸�� ���ڿ��� �ޱ� ���� ���̴�
    //while(*str){
    //    if(*str >= 'a' && *str <= 'z')
    //        *str -= 32;
    //    str++;
    //}

    while (*str) {  // null character �� ������ �ݺ����� �����ȴ�
        *str = toupper(*str);
        // �ҹ������� Ȯ���ϴ� ������ toupper() �Լ� �ȿ� �̹� �����Ǿ� �ֱ⿡ ���� �����ϴ�(��, ������ �ſ� �߿��� ���α׷������� �� ���� ���ؿ����� ����ȭ�� ����ؾ� �Ѵ�)
        // if(islower(*str))
        //     *str = toupper(*str);
        str++;
    }
}

int PunctCount(const char* str) {
    int ct = 0;
    while (*str) {
        if (ispunct(*str))
            ct++;
        str++;
    }

    return ct;
}