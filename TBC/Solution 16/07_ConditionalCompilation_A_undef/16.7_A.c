/* Conditional Compilation(compile �����) ���ǿ� ���� �ٸ��� �������ϱ� */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
/*
    #define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
*/

/*
    #undef
*/

#define LIMIT 400
//#undef LIMIT    // 16.3 ����
#undef NON_DEFINED  // It's ok to undefine previously NOT defined macro ���ǰ� �̸� �Ǿ����� ���� ��ũ�ε� ����

int main(void)
{
    printf("%d\n", LIMIT);

    return 0;
}