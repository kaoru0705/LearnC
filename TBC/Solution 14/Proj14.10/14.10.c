/* 복합 리터럴 Compound Literals */
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
    struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25F };  // 초기화

    /*
      Compound literals
      - Temporary structure values
    */

    //book_to_read = { "Alice in Wonderland", "Lewis Carroll", 20.3F };  // Error(초기화할 때를 제외하고는 문법적으로 허용 X)

    // 방법 1
    strcpy(book_to_read.title, "Alice in Wonderland");
    strcpy(book_to_read.author, "Lewis Carroll");
    book_to_read.price = 20.3F;

    // 방법 2
    struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3F }; // 방법 1이 번거롭다면 바꾸고 싶은 값으로 초기화 하고 대입할 수도 있다. book2를 만드는 게 낭비라고 생각될 수도 있다.
    book_to_read = book2;

    // 방법 3(복합 리터럴)
    book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3F }; // literal 의 묶음 구조체는 특성상 멤버들이 다양한 자료형을 가질 수 있다. 즉 다양한 자료형의 literal를 묶어둠 복합 리터럴 rvalue가 아니라 lvalue다.

    printf("%s %s\n", book_to_read.title, book_to_read.author);

    // 방법 1
    struct rectangle rec1 = { 1.0, 2.0 }; // 구조체 변수의 용도가 계산하는 것 외에는 아무 것도 없다면? 방법2가 낫다.
    double area = rect_area(rec1);

    // 방법 2
    area = rect_area((struct rectangle) { 1.0, 2.0 });

    // 방법 3(복합 리터럴은 L-Value, 즉 메모리에 공간을 차지하고 있는 데이터이기 떄문에 주소를 가져올 수 있다)
    area = rect_area_ptr(&(struct rectangle) { .height = 3.0, .width = 2.0 });  // Designated initializers
    printf("%f\n", area);

    return 0;
}