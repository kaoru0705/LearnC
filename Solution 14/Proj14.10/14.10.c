/* ���� ���ͷ� Compound Literals */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    //char* title;   // Not recommended
    //char* author;  // Not recommended
    float price;
};

struct rectangle
{
    double width;
    double height;
};

double rect_area(struct rectangle r)
{
    return r.width * r.height;
}

double rect_area_ptr(struct rectangle* r)
{
    return r->width * r->height;
}

int main(void)
{
    struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25F };  // �ʱ�ȭ

    /*
      Compound literals
      - Temporary structure values
    */

    //book_to_read = { "Alice in Wonderland", "Lewis Carroll", 20.3F };  // Error(�ʱ�ȭ�� ���� �����ϰ�� ���������� ��� X)

    // ��� 1
    strcpy(book_to_read.title, "Alice in Wonderland");
    strcpy(book_to_read.author, "Lewis Carroll");
    book_to_read.price = 20.3F;

    // ��� 2
    struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3F }; // ��� 1�� ���ŷӴٸ� �ٲٰ� ���� ������ �ʱ�ȭ �ϰ� ������ ���� �ִ�. book2�� ����� �� ������ ������ ���� �ִ�.
    book_to_read = book2;

    // ��� 3(���� ���ͷ�)
    book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3F }; // literal �� ���� ����ü�� Ư���� ������� �پ��� �ڷ����� ���� �� �ִ�. �� �پ��� �ڷ����� literal�� ����� ���� ���ͷ� rvalue�� �ƴ϶� lvalue��.

    printf("%s %s\n", book_to_read.title, book_to_read.author);

    // ��� 1
    struct rectangle rec1 = { 1.0, 2.0 }; // ����ü ������ �뵵�� ����ϴ� �� �ܿ��� �ƹ� �͵� ���ٸ�? ���2�� ����.
    double area = rect_area(rec1);

    // ��� 2
    area = rect_area((struct rectangle) { 1.0, 2.0 });

    // ��� 3(���� ���ͷ��� L-Value, �� �޸𸮿� ������ �����ϰ� �ִ� �������̱� ������ �ּҸ� ������ �� �ִ�)
    area = rect_area_ptr(&(struct rectangle) { .height = 3.0, .width = 2.0 });  // Designated initializers
    printf("%f\n", area);

    return 0;
}