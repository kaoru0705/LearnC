/* ����ü�� �迭 �������� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_TITLE 40   // �ִ� 39���� + null character
#define MAX_AUTHOR 40  // �ִ� 39���� + null character
#define MAX_BOOKS 3 /* maximum number of books */

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);  // vs. scanf() fgets() n�� ũ�⸦ �Ѿ ��Ÿ�� ������ ���� ���� ������ in 11.4 ����� �Է� ���� �� st ���ڿ��� ������ ��ȯ �ƴ� �� NULL ��ȯ
    if (ret_val)
    {
        find = strchr(st, '\n');  // look for newline in 11.6 ã�� ��ġ�� �ּ� ��ȯ
        if (find)                  // if the address is not NULL
            *find = '\0';         // place a null character there
        else                      // �� ���ڸ� �Է��� ��� ó���ϱ� ����
            while (getchar() != '\n')
                continue;         // dispose(ó���ϴ�) of rest of line
    }

    return ret_val;
}

struct book
{
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    float price;
};

int main(void)
{
    struct book library[MAX_BOOKS] = { { "Empty", "Empty", 0.0F }, };  // �ʱ�ȭ�Ǿ������ ��������� ǥ�� �� ������ visual studio�� ����ϴ� ��쵵 �ִ�
    int count = 0;

    while (1)
    {
        printf("Input a book title or press [Enter] to stop.\n>>");
        /* my poor answer */
        //s_gets(library[count].title, max_title);
        //if ((library[count].title[0]) == '\0') break; // �̷��� �ϸ� ret_val = null �� �� EOF�� ���� �� �׳� �Ѿ�ݾ�
        if (s_gets(library[count].title, MAX_TITLE) == NULL) break;
        if ((library[count].title[0]) == '\0') break; // == *(library[count].title)

        printf("Input the author.\n>>");
        s_gets(library[count].author, MAX_AUTHOR);

        printf("Input the price.\n>>");
        scanf("%f", &library[count].price);
        
        while (getchar() != '\n')   // scanf������ '\n' ���ֱ�
            continue;

        count++;

        if (count == MAX_BOOKS)
        {
            printf("No more books.\n");
            break;
        }
    }

    if (count > 0)
    {
        printf("\nThe list of books:\n");
        for (int index = 0; index < count; index++)
        {
            printf("\"%s\" written by %s: $%.1f\n", library[index].title, library[index].author, library[index].price);
        }
    }
    else
    {
        printf("No book to show.\n");
    }

    return 0;
}