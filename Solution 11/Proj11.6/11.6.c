/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �پ��� ���ڿ� �Լ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fit_str(char*, unsigned int);
char* my_strcat(char*, const char*);
int my_strcmp(char*, char*);

int main()
{
    /* strlen() : returns length of the string */

    // TODO: use debugger
    /*char msg[] = "Just,"" do it!";
    puts(msg);
    printf("Length %d\n", strlen(msg));
    fit_str(msg, 4);
    puts(msg);
    printf("Length %d\n", strlen(msg));*/

    // TODO: implement fit_str() function

    /* strcat() and strncat() : string concatenation(���� ���� ����) ���α׷��ֿ��� cat�� ���� �� ���̴�.  str'n'cat() number ���� ����*/

    //char str1[100] = "First string";
    //char str2[] = "Second string";

    //strcat(str1, ", ");
    //strcat(str1, str2);
    ////strncat(str1, str2, 2);  // Append 2 characters warning: str1�� ���� null�� �ʱ�ȭ�Ǿ����� �ʴ�. �㳪 �̰� ������ visual studio�� ������
    //puts(str1);
    

    // TODO: implement strcat() function! google�˻� 

   /* char str1[100] = "First string";
    char str2[] = "Second string";

    puts(my_strcat(str1, str2));*/

    /* strcmp() and strncmp() : compare strings (not characters (���ڳ��� ���ϴ� �� �ƴ� �׷��Ÿ� �񱳿�����) */
    // ��ȯ��: ���� ������ 0, �տ� �ִ� ���ڿ��� �ƽ�Ű �ڵ� �������� �� ���� ����� -1, �� ū ����� 1

    //printf("%d\n", strcmp("A", "A"));  // ��ȯ��: 0
    //printf("%d\n", strcmp("A", "B"));  // ��ȯ��: -1
    //printf("%d\n", strcmp("B", "A"));  // ��ȯ��: 1
    //printf("%d\n", strcmp("Hello", "Hello"));  // ��ȯ��: 0
    //printf("%d\n", strcmp("Banana", "Bananas"));  // ��ȯ��: -1
    //printf("%d\n", strcmp("Bananas", "Banana"));  // ��ȯ��: 1
    //printf("%d\n", strncmp("Bananas", "Banana", 6));  // ��ȯ��: 0

    // TODO: implement strcmp!
    /*printf("%d\n", my_strcmp("Bananas", "Banana"));*/

    /*
    strcpy() and strncpy() : �޸𸮸� ������ �� ���ڿ� ���縦 �̿��ϴ� ����� �ִµ� �� �� �� �Լ����� ���� �� �ִ�
    ��Ʈ��ũ ����) �޸𸮸� ��ü�� �����ϴ� �ٸ� �뵵�ε� ���� ���Ǳ� ������ null�� ���� �־����� �ʴ´�.
    */

    //char dest[100] = "";  // make sure memory is enough
    //char source[] = "Start programming!";
    ////dest = source;  // Error
    ////dest = "Start programming!";  // Error
    //strcpy(dest, source);   // Destination(������), Source(��õ ����) �츮�� ���� ���� �� ���
    //strncpy(dest, source, 5);  // '\0' is NOT added(�� �ٰ� �ٷ� ���ٸ� �����Ű�� ������ �۵� Start programming!�� ���� ��µ�. null character ���� 'S','t','a','r','t' �� �ټ� ���ڸ� ����Ǳ⿡ ���� �� �� ����) �� �ٸ� ���� ��Ű�� Start�� ������. dest�� null�� �̹� ����ֱ� ����
    ////strcpy(dest, source + 6);
    ////strcpy(dest, source);
    ////strcpy(dest + 6, "coding!");  // ��°�: Start Coding!(strcpy() �Լ��� dest�� ��� ����� ����̱� ����)
    //puts(dest);

    /* sprintf() capture00000.png, capture00001.png, ... ���ӵǴ� ������ ����� �� �����̸��� ���α׷����� �ڵ����� ��������� �� �� ���*/

    //char str[100] = "";
    //int i = 123;
    //double d = 3.14;
    //sprintf(str, "%05d.png %f", i, d); // printf�� ���ڿ��� ���ش�.
    //puts(str);

    /* There are more functions ... */

    printf("%s\n", strchr("Hello, World", 'W')); // �ش� ���ڷ� ���۵Ǵ� �����͸� ����

    printf("%s\n", strpbrk("Hello, World", "ABCDE")); // �ش������ ���۵Ǵ� �κ��� ã�� ������ ��
    printf("%s\n", strpbrk("Hello, World", "abcde"));

    printf("%s\n", strrchr("Hello, World, Hello, World", 'l'));  // last occurrence(�� ���ڰ� ��Ÿ���� ������ �����͸� ����)

    printf("%s\n", strstr("Hello, World", "wor")); //���ڿ����� �� ������ ��
    printf("%s\n", strstr("Hello, World", "Wor"));

    return 0;
}
/* my poor answer */
//void fit_str(char* starray, unsigned int chsize)
//{
//    *(starray + chsize) = '\0';
//}
//void my_strcat(char* firstchar, const char* secondchar)
//{
//    unsigned int firstsize = strlen(firstchar), i, j = 0;
//
//    for (i = firstsize; i < firstsize + strlen(secondchar); i++)
//    {
//        firstchar[i] = secondchar[j];
//        j++;
//    }
//    firstchar[i] = '\0';
//}
//int my_strcmp(char* firstcmp, char* secondcmp)
//{
//    int flag = 0;
//    unsigned int count = 0;
//
//    while (firstcmp[count] >= 0)
//    {
//        if (firstcmp[count] > secondcmp[count])
//        {
//            flag = 1;
//            return flag;
//        }
//        else if (firstcmp[count] < secondcmp[count])
//        {
//            flag = -1;
//            return flag;
//        }
//        else
//        {
//            count++;
//            continue;
//        }
//    }
//
//    return flag;
//}

void fit_str(char* str, unsigned int size)
{
    if (strlen(str) > size)  // ���ڿ� ��� �� �Ҵ�� �޸� ������ Ȯ���ϴ� ������ �߿��ϴ�
        str[size] = '\0';
}
char* my_strcat(char* destination, const char* source) //legend
{
    char* ptr = destination + strlen(destination);

    while (*source != '\0')
        *ptr++ = *source++;

    *ptr = '\0';

    return destination;
}