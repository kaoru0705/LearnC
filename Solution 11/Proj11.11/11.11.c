/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ���ڿ��� ���ڷ� �ٲٴ� ��� Command-Line Arguments ���� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//exe������ ���� �����ų �ʿ䰡 ������? c�� c++�� ���� ���������� �ٸ� scripting�� �̿��ؼ� �ݺ��ؼ� �����ų �� �ִ�. ex) python
// ������Ʈâ �� ���� property - debugging - command argument�� 3 hello �Է��ϰ� �����ص� ��

int main(int argc, char* argv[])
{
    /*
      string to integer, double, long
      atoi(), atof(), atol()
    */

    //if (argc < 3)
    //    printf("Wrong usage of %s\n", argv[0]);  // �������� �̸��� �׻� ù ��° �μ��� ���޵ȴ�
    //else
    //{
    //    /* Example 1 */
    //    //int times = atoi(argv[1]);
    //    ////atof(), atol()

    //    //for (int i = 0; i < times; i++)
    //    //    puts(argv[2]);

    //    /* Example 2 */
    //    printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));

    //}

    /*
     // atoi() �Լ��� 10������ ��ȯ ������ �ݸ� strtol(), strtoul() �Լ��� 8, 16������ ��ȯ �����ϴ�
     string to long, unsigned long, double
     strtol(), strtoul(), strtod()

     strtod() converts base 10 only 10������ �����ؼ� ���
    */

    //char str1[] = "-1024Hello";
    //char* end;
    //long l = strtol(str1, &end, 10); // ���� ǥ���ϴ� ���� �����͸� �־��� ���������� 10������ �ٲ� �� ���� H �����͸� �־���
    //printf("%s %ld %s %d\n", str1, l, end, (int)*end);

    //char str2[] = "10FFHello";
    //l = strtol(str2, &end, 16); // 0x10FF = 4351
    //printf("%s %ld %s %d\n", str2, l, end, (int)*end);

    /*
     Numbers to strings
     Use sprintf() instead of itoa() and ftoa()
    */

    char temp[100];
    puts(_itoa(10, temp, 16));  // itoa ǥ�ؿ��� �̸��� �ٲ� ����, 10�� 16������ ��ȯ �� ���ڿ��� ����(�� �Լ��� itoa ftoa ǥ���� �ƴϱ⿡ ����� ���������� �ʴ´�)

    sprintf(temp, "%x", 10);    // 11.6 ���� �̰� �� ���� ��
    puts(temp);

    return 0;
}
