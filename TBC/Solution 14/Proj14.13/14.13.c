/* 구조체의 배열을 사용하는 함수 */
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
    if (my_books == NULL) // 이걸 작성하지 않으면 my_books가 NULL이면 어떡하냐고 경고를 준다. 
    {
        printf("Malloc failed");
        exit(1);
    }
    //struct book my_books[3];  // = { { "The Great Gatsby", "F. Scott Fitzgerald"}, ... }; // 구조체의 배열이 너무 많은 경우 이렇게 초기화 하는 경우는 거의 없다.
    my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" }; // 이런 식으로 따로 사용
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
    *ptr = 7;*/ //복습

    return 0;
}

//void print_books(const struct book books[], int n) // 사실 my_books를 구조체 포인터 변수로 선언하고 이걸 써도 잘 돌아간다. 문법상 조금 더 정확하게 하려면 후자 함수처럼
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

void print_books(const struct book* books, int n) // const struct book* books 멤버들의 값을 고정
{
    for (int i = 0; i < n; i++)
        printf("Book %d : \"%s\" written by \"%s\"\n",
            i + 1, books[i].name, books[i].author);
}