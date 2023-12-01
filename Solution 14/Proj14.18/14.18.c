/* Enumerated Types ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Motivation : ���������� ���Ǽ��� �������� ���鿡�� enumŸ���� ����ϴ� �� ����
 int c = 0;  // red:0, orange:1, yellow:2, green:3, ... ������ ���ڸ� �ڵ��ϱ⺸�� ���ڸ� ������. �Ǽ��� Ȯ���� ������ ���� 0�� red�� �� ��� ����ؾ� �� ���������� �ϴٰ� �ڵ尡 �������? ������ red�� �� ���� ���� Ȯ��
 if(c == 0)
    printf("red");
 else if(c == 1)
    printf("orange");
 else if(c == 2)
    printf("yellow");
*/

/** �� ����� copy&paste�ϴ� ��(���� ������ ��ü���� ��ó������ Ư¡)�̱⿡ �����Ϸ��� ������ ������� ���Ѵ� �����Ϸ� ���忡�� �׳� c = 3�� ��
 #define RED 1
 #define ORANGE 2
 #define YELLOW 3

 int c = YELLOW;
 if(c == YELLOW)
    printf("yellow");
 */

int main(void)
{
    /*
        Enumerated type enumerate �����ϴ�
        - Symbolic names to represent integer constants
        - Improve readability and make it easy to maintain
        - enum-specifier (struct-specifier(��üȭ), union-specifier)

        Enumerators
        - The symbolic constants
    */

    // �������� ���������� ������ ó���ȴ�
    enum spectrum { red, orange, yellow, green, blue, violet };
    //              0    1       2       3      4     5

    enum spectrum color;
    color = blue;
    if (color == yellow)
        printf("yellow");   // Note: enumerators are not strings ������ �� 2��� �������� yellow��� �̸��� �ٿ��� ��

    for (color = red; color <= violet; color++)  // Note: ++ operators doesn't allowed in C++
        printf("%d\n", color);

    printf("red = %d, orange = %d\n", red, orange);

    enum kids { jackjack, dash, snoopy, nina, pitz };
    // nina has a value of 3
    enum kids my_kid = nina;
    printf("nano %d %d\n", my_kid, nina);

    enum levels { low = 100, medium = 500, high = 2000 }; // low�� 200���� �ٲ۴ٸ�? ���������� ����.

    int score = 800;
    if (score > high) // �������� ����.
        printf("High scores!\n");
    else if (score > medium)
        printf("Good job!\n");
    else if (score > low)
        printf("Not bad\n");
    else
        printf("Do your best\n");

    enum pet { cat, dog = 10, lion, tiger };
    // lion has a value of 11 ������ ������ 1 ���� �� ���� cat = 0;
    printf("cat %d\n", cat);
    printf("lion %d\n", lion);

    return 0;
}