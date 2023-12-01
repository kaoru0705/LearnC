/* ����ü�� �⺻���� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

struct person // person is a tag of structure(����ó�� �ĺ��� ��� ��Ģ�� ����ȴ�. ex. �� �տ� ���ڰ� �� �� ����)
{      
    char name[MAX];  // member(����ü�� �����ϴ� ���������� ��������� ���� �޸𸮸� �Ҵ� ���� ������ �� ����ü�� ������ ����� �� ��μ� �޸𸮸� �Ҵ� �޴´�) �̷� ���·� ����ü�� ������� �Ŵٶ�� �� ���� �س��� ����
    int age;         // member
    float height;    // member
};

int main(void)
{
    int flag;  // Receives return value of scanf()

    /* Structure variable */

    struct person genie;  // �� ������ person structure�� ����������� �޸𸮰� �Ҵ�ȴ�

    /* dot(.) is structure membership operator (member access operator, member operator) */

    strcpy(genie.name, "Will Smith");
    //strncpy(genie.name, "Will Smith", MAX); // 11.6 MAX ������ŭ ���� ���� NULL ���� ���� ���� ����
    genie.age = 1000; //age�� ���콺�� ���� ��� person::age age��� ������ person�̶�� ����ü�� ������ ���� ǥ�� 

    printf("%s\n", genie.name);
    // �⺻������ �׳� �������� ����ϴ� �Ͱ� ����ϴ�. ���̰� �ִٸ� age�� genie��� structure variable�� ���ؼ� �����ϰ� �ִٴ� �� name age height�� ����ü�� �̷�� �� ����ü �ȿ��� ������ �ɹ��� �����ؼ� ����ϴ� ����
    // dot(.) has higher precedence than &
    flag = scanf("%f", &genie.height);  // &(genie.height). ���� �ǹ�
    printf("%f\n", genie.height);

    /* Initialization */

    // ����� ���ÿ� �ʱ�ȭ�ϴ� ���
    struct person princess = { "Naomi Scott", 18, 160.0F };  // �迭�� �ʱ�ȭ ��İ� ����(��, ����� ������ ������� �ʱ�ȭ�ؾ� �Ѵ�)

    // ����� ���ÿ� �ʱ�ȭ�ϴ� ���(�ٸ� ǥ��) ������ �ڷ����� �ٸ��ϱ� �򰥷��� �̷��� ��뵵 ����
    struct person princess2 =
    {
        "Naomi Scott",
        18,
        160.0F
    };

    // ���� �� �ʱ�ȭ�ϴ� ���
    strcpy(princess.name, "Naomi Scott");
    princess.age = 18;
    princess.height = 160.0F;

    /* Designated initializers(C99, C11) */ //���� �ٸ� �ڷ����� ���� �� �ֱ⿡ �򰥸��� �������

    // ����� ������ ������ ������� �ʱ�ȭ�� �� �ִ� � ������� � ���� ������ designated������ �ֱ� ���� 
    struct person beauty =
    {
        .age = 19, // .age designated 
        .name = "Bell",
        .height = 150.0F
    };

    // �ٸ� ǥ��(�޸��� ���� �򰥸� �� �����Ƿ� ���� ���ó�� �����ϸ� �������� ����)
    //struct person beauty = { .age = 19, .name = "Bell", .height = 150.0F };

    /* Pointer to a structure variable */

    struct person* someone; // person�̶�� �±׸� ���� ����ü ������ ������

    someone = &genie;
    //someone = (struct person*)malloc(sizeof(struct person));  // and free later

    /* Indirect member(ship) operator (or structure pointer operator) */
    // �����͸� ���� ����ü�� ��������� ������ ���� ��(.)�� �ƴ϶� ȭ��ǥ(->)�� �̿��Ѵ�

    someone->age = 1001;  // arrow(->) operator �����͸� ȭ��ǥ ���ְ� ������ . ����ָ� ����� ������ �� �ִ�. 
    printf("%s %d\n", someone->name, (*someone).age); // (*someone).age�̰͵� ���� �� �� ����

    /* Structure declaration in a function */

    struct book // �Լ� �ȿ��� ����� ����ü�� �Լ��� ����� �� �̻� ����� �� ���� �Լ� �ȿ����� ����ü�� ���
    {  
        char title[MAX];
        float price;
    };

    /* No tag */

    struct // ��� ���ȸ� ���̴� ����ü�� ���� ���� ����
    {  
        char farm[MAX];
        float price;
    } apple, apple2; // �Ϲ����� structure variable�� �����ϰ� ���� �� �ִ�.

    struct // �±װ� ���� ����ü�� �ݺ��ؼ� ����� ���� ���빰�� �ݺ��ؼ� ��������ϱ� ������ ���ŷο� �� �ִ�
    {  
        char farm[MAX];
        float price;
    } apple3;

    strcpy(apple.farm, "Trade Joe");
    apple.price = 1.2F;

    strcpy(apple2.farm, "Safeway");
    apple2.price = 5.6F;

    /* typedef and structure */ //type define �ڷ��� ����

    typedef struct person my_person; // struct person�̶�� type�� my_person���� ����

    my_person p3; // ���������δ� struct perosn�̶�� structure�� �������� ��ġ my_person�̶�� �ڷ����� ���� ����

    typedef struct person person; // �̷��� �� ���� ��

    person p4;

    typedef struct // tag�� ���� struct{char[] ,char[]}�� friend��� type�̸����� ����
    {
        char name[MAX];
        char hobby[MAX];
    } friend;

    friend f4;

    return 0;
}