/* ���� ������ ��� ����� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>  // srand()
#include <time.h>  // time()
#include "my_rand.h"

int main()
{
    /*
        rand()
        - 0 to RAND_MAX (typically INT_MAX)
        - defined in stdlib.h
    */

    //srand(1);  // random seed
    //srand((unsigned int)time(0));  // �ݺ��ؼ� �������� �� �ٸ� ���� ��ȯ�ϵ��� �ð����� �õ�� ����Ѵ�

    //for (int i = 0; i < 10; ++i)
    //{
    //    printf("%d\n", rand());  // �� �ڵ�� �ݺ��ؼ� �����ص� ������ 10���� ���� ����Ѵ� ��ǻ�ʹ� ������ ������ ����� �ɷ��� ����.
    //    //printf("%d\n", my_rand() % 6 + 1);  // ��� ������ ��: 1, 2, 3, 4, 5, 6
    //}

    //unsigned int next = (unsigned int)time(0);  // ���������� ����ϴ� �˰��� next(�õ�)�� ���� �ٲٸ� �����ϴ�  ������ ��ȭ�Ѵ�

    //for (int i = 0; i < 10; ++i)
    //{
    //    next = next * 1103515245 + 1234;    // ���� ���� pseudo random number overflow �̿�
    //    next = (unsigned int)(next / 65536) % 32768;    // �ڸ��� �����ֱ� ���ؼ� ������ ������ �ȵǴϱ�
    //    printf("%d\n", (int)next);
    //}
    ////���̺귯�������� ����������� �� ������ ������ ������ �� �ִ�.

    my_srand((unsigned int)time(0));

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", my_rand() % 6 + 1); // my_rand() % 6 == 0 ~ 5
    }

	return 0;
}