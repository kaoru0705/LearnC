/* Conditional Compilation(compile 명사형) 조건에 따라 다르게 컴파일하기 */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
/*
    #define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
*/

/*
    #undef
*/

#define LIMIT 400
//#undef LIMIT    // 16.3 참조
#undef NON_DEFINED  // It's ok to undefine previously NOT defined macro 정의가 미리 되어있지 않은 매크로도 가능

int main(void)
{
    printf("%d\n", LIMIT);

    return 0;
}