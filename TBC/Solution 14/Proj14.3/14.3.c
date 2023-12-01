/* ����ü�� �޸� �Ҵ� Memory Allocation */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* https://stackoverflow.com/questions/4306186/structure-padding-and-packing padding ���� */
int main(void)
{
    /*
        well aligned structure
    */

    struct Aligned
    {
        int a;
        float b;
        double c;
    };

    /*
     0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|
     |int a |float b|double c             |
     4 + 4 + 8 = 16
     */

    struct Aligned a1, a2;

    printf("struct aligned a1\n");
    printf("Sizeof %zd\n", sizeof(struct Aligned));
    printf("%lld\n", (long long)&a1);
    printf("%lld\n", (long long)&a1.a);
    printf("%lld\n", (long long)&a1.b);
    printf("%lld\n", (long long)&a1.c);

    printf("\nstruct Aligned a2\n");
    printf("Sizeof %zd\n", sizeof(a2));
    printf("%lld\n", (long long)&a2);
    printf("%lld\n", (long long)&a2.a);
    printf("%lld\n", (long long)&a2.b);
    printf("%lld\n", (long long)&a2.c);

    /* padding (struct member alignment(�ٸ���))
        ������ ǥ���ϴ� �ּ� ���� 1��Ʈ, �޸𸮿��� �ּҸ� �����ϴ� �ּҴ��� 1����Ʈ
       - 1 word: 4 bytes in x86, 8 bytes in x64 �޸𸮿� CPU�� �����͸� �ְ���� �� 1����Ʈ�� 1��Ʈ�� �ְ� ���� ������ ������ �� ������ �ְ� ���� �� �ؾ��ϴ� �ΰ����� �ϵ��� �ֱ� ������ �������� ������ �����͸� ��� ������ ���� ȿ������ ����.
       - �޸𸮿� CPU�� �����͸� �ְ� ���� ���� �ּ� ���� = word
       - struct member alignment�� 1byte�� �����ϸ� �е� �ɼ��� ������� ���� �� �ִ�
    */

    struct Padded1
    {
        char a;
        float b;
        double c;
    };

    /* Without padding // ���࿡ 8����Ʈ�� �����ϰ� �е��� ���� �ʴ´ٸ� double���� 3������ 5����Ʈ�� �������� ������ �ȴ� �׸��� ???�� �ָ������� ȿ������ ���� ���� ������ ������� ���� �Ŷ�� ???�� a �ٷ� �ڿ� �־ ���� �����ڶ�� �� �⺻���� ���̵��
     0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
    |char a|float b|double c          | ?  ?  ?
     1 + 4 + 8 = 13
     */

     /* With padding
      0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 // char �ڿ� ???�� ���� �־ ����ϰ� 4����Ʈ �����ְ� double�� ©���� ������ cpu ���忡�� ����ϰ� ������ ����ϰ� ����� �� ����
     |char a|float b|double c             |
      4(char?) + 4 + 8 = 16
      */

    struct Padded1 p1; // char�� 1����Ʈ�ε�? �����Ϸ��� 3����Ʈ�� �� �������
    printf("\nstruct Padded p1\n");
    printf("Sizeof %zd\n", sizeof(p1));  // 4 + 4 + 8
    printf("%lld\n", (long long)&p1); // �迭�� ���������� ����ü ���� ��ü�� �ּҿ� ù ��° ����� �ּҰ� ����
    printf("%lld\n", (long long)&p1.a);
    printf("%lld\n", (long long)&p1.b);
    printf("%lld\n", (long long)&p1.c);

    struct Padded2
    {
        float a;
        double b;
        char c;
    };

    /*
     |0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
     |float a        |double b             |char c                 |
     8(float?) + 8 + 8(char?) = 24 �����Ϸ��� double�� �� ���� �� ���忡 ��°�� ������ �ϱ� ���� 2���� �е��� ����
     // padding�� a�� c�� ��� ���⿡ ������ ���� �������� �ұ��ϰ� Padded1�� ���� ��ȿ�����̴� �̰ͱ��� ����ؼ� ����ü�� �����ض�
    */

    struct Padded2 p2;
    printf("\nstruct Padded p2\n");
    printf("Sizeof %zd\n", sizeof(p2));
    printf("%lld\n", (long long)&p2);
    printf("%lld\n", (long long)&p2.a);
    printf("%lld\n", (long long)&p2.b);
    printf("%lld\n", (long long)&p2.c);

    struct Padded3
    {
        char a;
        double b;
        double c;
    };

    /*
    |0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
    | char a        | double b            | double c              |
    8(char?) + 8 + 8 = 24
    */

    struct Padded2 p3;
    printf("\nstruct Padded p3\n");
    printf("Sizeof %zd\n", sizeof(p3));
    printf("%lld\n", (long long)&p3);
    printf("%lld\n", (long long)&p3.a);
    printf("%lld\n", (long long)&p3.b);
    printf("%lld\n", (long long)&p3.c);

    struct Person
    {
        char name[41];  // member
        int age;        // member
        float height;   // member
    };

    struct Person mommy;

    printf("\nstruct Person\n");
    printf("%lld\n", (long long)&mommy.name[0]);
    printf("%lld\n", (long long)&mommy.age);
    printf("%lld\n", (long long)&mommy.height);
    printf("Sizeof %zd\n", sizeof(mommy));  // 41 + 4 + 4 = 49 ?(������ 52. char �迭�� �е��� ������ 44����Ʈ�� �����ϱ� ����

    /*
        �ƴ� �׷� �ù� �� 8����Ʈ ���� �����ε� height�� 4����Ʈ�� ? height�� �ǳ��̶� �׷� �� ���� ������ ���� 8����Ʈ������ ���Ҹ��� �ݷ� padded2)

        struct Person mommy �� ũ�⸦ �����ϸ� 52�� 8�ǹ���� �ƴѰ��� ����̵˴ϴ�.
        �е��� 3(char[41] �ڿ�)byte��ŭ �������� ���̴µ���,
        �ش��ϴ� ����ü�� �޸𸮸� �Ҵ��Ҷ��� Struct Member Alignment �� ������ 8����Ʈ�� (4����Ʈ�� ���ذ� ���ڴµ�) , X64������ ���忡 ���߱����� �е��� ���ٴ°��� ����Ҷ� ���ذ� �����ʴµ��� , �ֱ׷��� �� �� �������?

        https://stackoverflow.com/questions/4306186/structure-padding-and-packing
        ���� �����Ͻø� �� �� �����ϴ�. padding rule�� ���� �����Դϴ�.

        struct�� ���� rule���� ���� ū individual member�� ���ؼ� �������ٰ� �մϴ�.
        mommy�� ���� int or float�� ���� ū member�̹Ƿ� 4byte�� ������ �˴ϴ�.
        member �� �ϳ��� double�� �ٲ㺸����.

    */
    struct Person f[4];

    printf("Sizeof a structure array %zd\n", sizeof(f));
    /*
     | f[0].name        | f[0].age | f[0].height |... ... | f[3].name        | f[3].age | f[3].height |
    */

    // c/c++ all options - struct member alignment default �̰� 1����Ʈ�� �ٲ۴ٸ�? �е��� �� ����� ����
    return 0;
}
