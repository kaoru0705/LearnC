/* ����ü�� �迭�� ����ϴ� �Լ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SLEN 101

struct book
{
    char name[SLEN];
    char author[SLEN];
};

//void print_books(const struct book books[], int n);
void print_books(const struct book* books, int n);

int main(void)
{
    struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3);
    if (my_books == NULL) // �̰� �ۼ����� ������ my_books�� NULL�̸� ��ϳİ� ��� �ش�. 
    {
        printf("Malloc failed");
        exit(1);
    }
    //struct book my_books[3];  // = { { "The Great Gatsby", "F. Scott Fitzgerald"}, ... }; // ����ü�� �迭�� �ʹ� ���� ��� �̷��� �ʱ�ȭ �ϴ� ���� ���� ����.
    my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" }; // �̷� ������ ���� ���
    my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
    my_books[2] = (struct book){ "The Odyssey", "Homer" };

    int a;
    char* p = "asdfdasf";
    printf("%zu\n", sizeof(my_books));
    printf("%lld\n", (long long)&a);
    printf("%lld\n", (long long)my_books);
    printf("%lld\n", (long long)&my_books);
    printf("%lld\n", (long long)&my_books->name);
    printf("%lld\n", (long long)my_books->name);
    printf("%lld\n", (long long)p); 

    print_books(my_books, 3); 
    /*int a = 5;
    int b = 9;
    const int* ptr = &a;
    *ptr = 7;*/ //����

    return 0;
}

//void print_books(const struct book books[], int n) // ��� my_books�� ����ü ������ ������ �����ϰ� �̰� �ᵵ �� ���ư���. ������ ���� �� ��Ȯ�ϰ� �Ϸ��� ���� �Լ�ó��
//{
//    for (int i = 0; i < n; i++)
//        printf("Book %d : \"%s\" written by \"%s\"\n",
//            i + 1, books[i].name, books[i].author);
//}
/* my answer */
//void print_books(const struct book* books, int n)
//{
//    for (int i = 0; i < n; i++)
//        printf("Book %d : \"%s\" written by \"%s\"\n",
//            i + 1, (books + i)->name, (books + i)->author);
//}

void print_books(const struct book* books, int n) // const struct book* books ������� ���� ����
{
    for (int i = 0; i < n; i++)
        printf("Book %d : \"%s\" written by \"%s\"\n",
            i + 1, books[i].name, books[i].author);
}