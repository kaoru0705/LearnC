/* Function Pointers �Լ� �������� ��� ��� */
#define _CRT_SECURE_NO_WANRINGS

#include <stdio.h>
#include <ctype.h>  // toupper(), tolower()
// ToUpper ToLower�� �Ķ���Ϳ� ���ϰ��� ����? ������ �Լ������͸� ���ؼ� �� �� ����� �� �ִ�.
void ToUpper(char* str)
{
    while (*str)
    {
        *str = toupper(*str); // �� ���ڸ� �빮�ڷ� �ٲ���
        str++;
    }
}

void ToLower(char* str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}
// ���� �� �Լ��� toupper tolower�� �� ���� �ٸ��� ��ġ�Ѵ�. �� �� ���� �Լ��� �ϳ��� �Լ�ó�� � Ʋ�� ���� �� ���� ������?
// ����� ������ ��� �ϳ��� �Լ��� ����� �ٲ��� �ϴ� �κи� �ٲ��ָ� �ڵ��ϴ� �з��� �پ���. -> ���������� ����� ���� ��� �Ǽ��� Ȯ���� �پ���.
// ���� ���� ����ϰ� �ִ� �Լ������Ϳ� �Լ������͸� �����ؼ� ����ϴ� ��� ex)��ü������ �������� �������� ���ϸ� ���α׷����ϱ� ���������.

void UpdateString(char* str, int (*pf)(int)) // int(*pf)(int)�� ���ؼ� ����� ����� �Լ� ��ü�� �Ķ���ͷ� �ް� �ִ�.
//void UpdateString(char* str, int(__cdecl *pf)(int)) //Note: __cdecl is function calling convention(�Լ�ȣ�� �Ծ�) ��� �����Ϸ��� ���������� �����ϵǵ��� ó�����ش�. windowsapi ��� �� ���
{
    
    while (*str)
    {
        *str = (*pf)(*str);
        str++;
    }
}

int main(void)
{
    char str[] = "Hello, World!";

    void (*pf)(char*);

    pf = ToUpper;          // Name of a function is a pointer ������ ����
    // pf = &ToUpper;      // Acceptable
    // pf = ToUpper(str);  // Not acceptable in C �Լ��� ������Ѽ� ��ȯ���� �����Ѵٴ� ��

    printf("String literal %lld\n", (long long)("Hello, World!"));  // TEXT Segment
    printf("Function pointer %lld\n", (long long)ToUpper);          // TEXT Segment
    printf("Variable %lld\n", (long long)str);                      // Stack

    // �� �Լ� �Ķ���Ͷ� ��ȯ���� ���ؼ� �Լ������͸� �����ؾ� ���� �� �� �� �ְ� �ϸ� �ȵǳ�?
    (*pf)(str);//==ToUpper(str); �Լ������͸� ���� ������ ��ų���� ���� ���ۿ� ����.
    //pf(str);  // K&R(NOT OK), ANSI(OK) ������ �Լ� �̸� ��ü�� �ּ��ݾ�.

    printf("ToUpper %s\n", str);

    pf = ToLower;

    pf(str);

    printf("ToLower %s\n", str);

    /*
        Passing function pointers to functions
    */

    UpdateString(str, toupper);

    printf("toupper %s\n", str);

    UpdateString(str, tolower);

    printf("tolower %s\n", str);

    

    return 0;
}