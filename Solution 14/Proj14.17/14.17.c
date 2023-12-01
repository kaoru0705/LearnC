/* Anonymous Unions 익명 공용체 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    Unions And Structures
*/

struct personal_owner {
    char rrn1[7];       // Resident Registration Number
    char rrn2[8];       // ex: 830422-1185600
};

struct company_owner {
    char crn1[4];       // Company Registration Number 첫 번째자리 + 널
    char crn2[3];       // ex: 111-22-33333 두 번째
    char crn3[6];       // 세 번째
};

struct car_data {
    char model[15];
    int status;  /* 0 = personal, 1 = company */

    union { // 훨씬 간결해짐
        struct personal_owner po;
        struct company_owner co;
    };
};

void print_car(struct car_data car)
{
    printf("-------------------------\n");
    printf("Car model : %s\n", car.model);

    if (car.status == 0)                            // ctrl + h 글자 바꾸기
        printf("Personal owner : %s-%s\n",
            car.po.rrn1, car.po.rrn2);
    else
        printf("Company owner : %s-%s-%s\n",
            car.co.crn1, car.co.crn2, car.co.crn3);

    printf("-------------------------\n");
}

int main(void)
{
    struct car_data my_car = { .model = "Avante", .status = 0, .po = { "830422", "1185600" } };
    struct car_data company_car = { .model = "Sonata", .status = 1, .co = { "111", "22", "33333" } };

    print_car(my_car);
    print_car(company_car);

    /* One more example */
    struct Vector2D {       // vector라고 하면 x,y i,j array로 사용하고 싶을 때가 다를 것이다.
        union {
            struct { double x, y; };
            struct { double i, j; };
            struct { double arr[2]; };
        };
    };

    //struct Vector2d
    //{
    //    double x, y; // x, y에서 i,j 를 쓸까하고 바꾸는 그런 고민을 없애줌
    //};

    typedef struct Vector2D vec2; // 많이 쓰는 표현은 이름을 줄이는 게 편하다.

    vec2 v = { 3.14, 2.99 };        // 뭘로 출력해도 잘 나올 것이다. 
    printf("%.2f, %.2f\n", v.x, v.y);
    printf("%.2f, %.2f\n", v.i, v.j);
    printf("%.2f, %.2f\n", v.arr[0], v.arr[1]);

    for (int d = 0; d < 2; d++) // 배열로 바꾸면 for문을 돌릴 수 있다.
        printf("%.2f ", v.arr[d]);

    return 0;
}