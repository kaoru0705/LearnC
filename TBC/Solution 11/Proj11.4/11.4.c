/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ���ڿ��� �Է� �޴� �پ��� ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

char* custom_string_input(char* st, int n);

int main()
{
    /* Creating Space */ //�Է¹��� ���ڿ��� ������ �޸� ������ Ȯ���� ������ �Է¹޾ƾ� �Ѵ�

    //char* name = "";  // Error at RUN-TIME
    //char name[128];
    //int result = scanf("%s", name); //(%s, pointer)

    /*
        scanf() vs gets()
        scanf() reads one word
        gets() reads one line and removes \n and add \0
    */

    
    //char words[STRLEN] = "";             // Warning without initialization
    ////gets(words);                         // gets(char * str) receives pointer. No idea when string ends(�������� �˰� ���� ���� ���Ѵ�) ������ �ϳ��� �޴� �Լ��� �������� ���� �޸� ù�ּҸ� �˰� ���� �� warning
    //gets_s(words, sizeof(words));      // C11(�����ϸ� gets() ��� �� �Լ� ����ϱ�)
    ////int result = scanf("%s", words);
    //printf("START\n");
    //printf("%s", words);                 // No \n at the end
    //puts(words);                         // puts() adds \n at the end �ڵ����� �ٹٲ�
    //puts("END.");

     
     //TODO: try char words[5];  // gets(), gets_s() �Լ��� ����ؼ� "Hello World" �Է½� ��Ÿ�� ���� �߻�

     /* fgets() and fputs() */
     // fgets() �Լ��� ���� ������� �޴� �Լ����� �� ��° �μ��� ������ �����͸� �޴´�(��, stdin�� �Է��ϸ� �ܼ� �Էµ� ���� �� �ִ�)
     // �о���̴� �����Ͱ� ���� ������ �𸥴ٴ� ���� �̸� ���ο� �ΰ� �޾Ƶ��̱⿡ ũ�� �Ѿ�� �Է� �ÿ��� ��Ÿ�� ���� �߻����� �ʴ´�(gets() �Լ����� ����)

    //char words[STRLEN] = "";
    //fgets(words, STRLEN, stdin);  // does NOT remove \n(��������¿����� �Է¹޴� ������ ������ ���̰��� �޾Ƶ鿩�� �ϱ⿡ ���� ���� �㳪 stdin(macro)�� �ܼ� �Է��� ���� �� ���ŷο� �� �ִ�.)

    ////////TODO: replace '\n' with '\0'(fgets() �Լ��� �Է¹����� ���๮�ڰ� ���ԵǾ� �ֱ⿡ �̸� �����ִ� ���� ������)
    //int i = 0;
    //while (words[i] != '\n' && words[i] != '\0')
    //    i++;
    //if (words[i] == '\n')
    //    words[i] = '\0';

    //fputs(words, stdout);  // does NOT add \n ������ �ʿ��� �����͸� �����ؾߵǱ� ������ /n�� ����.
    //fputs("END", stdout);

    /* Small array */

    //char small_array[5];
    //puts("Enter long strings:");
    ////fgets(small_array, 5, stdin);  // FILE * _Stream. ���ڿ��� ������ '\0'�� �����ؼ� 5���� ���ڸ� �Է¹޴´�
    //printf("%p\n", small_array);
    //printf("%p\n", fgets(small_array, 5, stdin));  // Return value of fgets() (���������� �Է¹޾Ҵٸ� �Է°��� �����ϴ� �����͸� �״�� ��ȯ. EOF�� �����ٸ� '\0' ��ȯ. EOF�� �ܼ� �Է¿��� ǥ���Ϸ��� ctrl+zŰ �̿�)
    //fputs(small_array, stdout);

    /* Repeating short reading */ //��Ʈ��ŷ �� ���� ���� ���۸� ���� �� ��Ȱ���ϸ鼭 ū ������ �޾Ƶ��δ�. �� ���ڿ��� �� ���� �Է¹޾Ƽ� �� ���� ����ϴ� ��ó�� ����� �� �ִ�(���۸� ����ϱ⿡)
    //char small_array[5];
    //puts("Enter long strings:");
    //while (fgets(small_array, 5, stdin) != NULL && small_array[0] != '\n')
    //    fputs(small_array, stdout);
    //    //puts(small_array);  //What if we use puts()

    /* scanf() */
    //char str1[6], str2[6];
    //int count = scanf("%5s %5s", str1, str2); // 5���ڸ� �Է¹ް� ��
    ////int count = scanf("%6s %6s", str1, str2);  // run-time error
    ////int count = scanf_s("%5s %5s", str1, 6, str2, 6); // string pointer, ���� ū ������
    //printf("%s|%s \n", str1, str2);

    ///* As an example of custom input function */
    char word[11];
    puts(custom_string_input(word, 11));

    return 0;
}

char* custom_string_input(char* st, int n)  // �ٸ� �� �����ϸ� ���� �� ���� ���̺귯���� ���� ���� �ִ�.
{
    char* ret_ptr;
    int i = 0;

    ret_ptr = fgets(st, n, stdin);
    if (ret_ptr) // ret_ptr != '\0'== 0
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')  // clear buffer
                continue;
    }
    return ret_ptr;
}