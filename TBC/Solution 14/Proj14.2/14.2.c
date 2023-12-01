/* 구조체의 기본적인 사용법 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

struct person // person is a tag of structure(변수처럼 식별자 명명 규칙이 적용된다. ex. 맨 앞에 숫자가 올 수 없다)
{      
    char name[MAX];  // member(구조체를 선언하는 시점에서의 멤버변수는 아직 메모리를 할당 받지 않으며 이 구조체가 변수로 선언될 때 비로소 메모리를 할당 받는다) 이런 형태로 구조체가 만들어질 거다라는 걸 선언만 해놓는 형태
    int age;         // member
    float height;    // member
};

int main(void)
{
    int flag;  // Receives return value of scanf()

    /* Structure variable */

    struct person genie;  // 이 시점에 person structure의 멤버변수들의 메모리가 할당된다

    /* dot(.) is structure membership operator (member access operator, member operator) */

    strcpy(genie.name, "Will Smith");
    //strncpy(genie.name, "Will Smith", MAX); // 11.6 MAX 개수만큼 복사 끝에 NULL 집어 넣지 않음 주의
    genie.age = 1000; //age에 마우스를 갖다 대면 person::age age라는 변수가 person이라는 구조체의 멤버라는 것을 표현 

    printf("%s\n", genie.name);
    // 기본적으로 그냥 변수들을 사용하는 것과 비슷하다. 차이가 있다면 age를 genie라는 structure variable을 통해서 접근하고 있다는 거 name age height가 구조체를 이루고 그 구조체 안에서 각각에 맴버에 접근해서 사용하는 개념
    // dot(.) has higher precedence than &
    flag = scanf("%f", &genie.height);  // &(genie.height). 같은 의미
    printf("%f\n", genie.height);

    /* Initialization */

    // 선언과 동시에 초기화하는 방식
    struct person princess = { "Naomi Scott", 18, 160.0F };  // 배열의 초기화 방식과 동일(단, 멤버를 선언한 순서대로 초기화해야 한다)

    // 선언과 동시에 초기화하는 방식(다른 표현) 각각의 자료형이 다르니까 헷갈려서 이렇게 사용도 가능
    struct person princess2 =
    {
        "Naomi Scott",
        18,
        160.0F
    };

    // 선언 후 초기화하는 방식
    strcpy(princess.name, "Naomi Scott");
    princess.age = 18;
    princess.height = 160.0F;

    /* Designated initializers(C99, C11) */ //서로 다른 자료형이 여러 개 있기에 헷갈리니 만들어짐

    // 멤버를 선언한 순서와 상관없이 초기화할 수 있다 어떤 멤버에게 어떤 값을 넣을지 designated지정돼 있기 때문 
    struct person beauty =
    {
        .age = 19, // .age designated 
        .name = "Bell",
        .height = 150.0F
    };

    // 다른 표현(콤마와 닷이 헷갈릴 수 있으므로 위의 방식처럼 개행하면 가독성이 좋다)
    //struct person beauty = { .age = 19, .name = "Bell", .height = 150.0F };

    /* Pointer to a structure variable */

    struct person* someone; // person이라는 태그를 갖는 구조체 변수의 포인터

    someone = &genie;
    //someone = (struct person*)malloc(sizeof(struct person));  // and free later

    /* Indirect member(ship) operator (or structure pointer operator) */
    // 포인터를 통해 구조체의 멤버변수에 접근할 때는 점(.)이 아니라 화살표(->)를 이용한다

    someone->age = 1001;  // arrow(->) operator 포인터면 화살표 쳐주고 변수면 . 찍어주면 멤버의 접근할 수 있다. 
    printf("%s %d\n", someone->name, (*someone).age); // (*someone).age이것도 쓰임 둘 다 쓰임

    /* Structure declaration in a function */

    struct book // 함수 안에서 선언된 구조체는 함수를 벗어나면 더 이상 사용할 수 없다 함수 안에서만 구조체를 사용
    {  
        char title[MAX];
        float price;
    };

    /* No tag */

    struct // 잠깐 동안만 쓰이는 구조체에 유용 종종 쓰임
    {  
        char farm[MAX];
        float price;
    } apple, apple2; // 일반적인 structure variable과 동일하게 쓰일 수 있다.

    struct // 태그가 없는 구조체를 반복해서 사용할 때는 내용물을 반복해서 적어줘야하기 때문에 번거로울 수 있다
    {  
        char farm[MAX];
        float price;
    } apple3;

    strcpy(apple.farm, "Trade Joe");
    apple.price = 1.2F;

    strcpy(apple2.farm, "Safeway");
    apple2.price = 5.6F;

    /* typedef and structure */ //type define 자료형 선언

    typedef struct person my_person; // struct person이라는 type을 my_person으로 선언

    my_person p3; // 내부적으로는 struct perosn이라는 structure의 변수지만 마치 my_person이라는 자료형에 대한 변수

    typedef struct person person; // 이렇게 더 많이 씀

    person p4;

    typedef struct // tag가 없고 struct{char[] ,char[]}를 friend라는 type이름으로 선언
    {
        char name[MAX];
        char hobby[MAX];
    } friend;

    friend f4;

    return 0;
}