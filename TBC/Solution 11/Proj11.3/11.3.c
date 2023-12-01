/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ���ڿ��� �迭 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    /* Arrays of Character Strings */

    const char* mythings[5] = { //�������� �迭 debug�ؼ� �޸𸮸� ���� �������� �پ� �ִ�. ������ �پ����� ������
        "Dancing in the rain",  // �޸� �� �� ī�Ǹ� �����Ѵ� in 11.2 �޸𸮸� �Ƴ��ٴ� ������ �ִ� ���� �� �ٲ�����
        "Counting apples",
        "Watching movies with friends",
        "Writing sad letters",
        "Studying the C language"
    };

    char yourthings[5][40] = {
        "Studying the C++ language",  // rodata(text) segment�μ� ���α׷��� ����Ǿ� �ִٰ� �� �纻�� �� �迭�� �����Ѵ�(�޸� �� ����, �纻 �� ī�ǰ� �����ϰ� �ȴ�)
        "Eating", // in debug mode ���콺 ���ٴ�� ȭ��ǥ ������ ���� �� �� �� �ִ�.
        "Watching Netflix",
        "Walking around till dark",
        "Deleting spam emails"
    };

    /*
    * ...�� 40���ڶ� �׷��� ó�� 00�� null character �������� �����Ϸ��� �־���
    0x00FAFC2C  53 74 75 64 79 69 6e 67 20 74 68 65 20 43 2b 2b 20 6c  Studying the C++ l
    0x00FAFC3E  61 6e 67 75 61 67 65 00 00 00 00 00 00 00 00 00 00 00  anguage........... 
    0x00FAFC50  00 00 00 00 45 61 74 69 6e 67 00 00 00 00 00 00 00 00  ....Eating........
    */

    const char* temp1 = "Dancing in the rain";
    const char* temp2 = "Studying the C++ language";

    printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)temp1); //pointing�� �Ǿ������� ����
    printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)temp2); // �����ؼ� �����ϴ� �ٸ�
    //printf("%u %u\n", (unsigned)&yourthings[0][0], (unsigned)temp2);
    printf("\n");

    printf("%-30s %-30s\n", "My Things:", "Your Things:");  //format specifier�� ã�ư��鼭 ��� �ʹ� ����. �� �ܿ�
    for (int i = 0; i < 5; i++)
        printf("%-30s %-30s\n", mythings[i], yourthings[i]);

    printf("\nsizeof mythings: %zd sizeof yourthings: %zd\n",
        sizeof(mythings), sizeof(yourthings)); // pointer 5��, ��ü �޸𸮰��� ũ��

    for (int i = 0; i < 100; i++)
        printf("%c", mythings[0][i]);
    printf("\n");
    printf("\n");

    for (int i = 0; i < 200; i++)
        printf("%d", (int)yourthings[0][i]); //���� ���̿� null �ִ�
    printf("\n");

    for (int i = 0; i < 200; i++)
        printf("%c", yourthings[0][i]);
    printf("\n");
    printf("\n");

    // �޸𸮿� �ִ� �� �� �����
    // Not a good idea to take advantage of this property(�޸𸮿� �ִ� �͵��� �� ����ϴ� ����̱⿡ �۵��� ������ �迭�� ũ�⸦ �Ѿ�� ����̹Ƿ� ���������� �ʴ´�. C����� ö��)

    return 0;
}