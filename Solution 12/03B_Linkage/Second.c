#include <stdio.h>

extern int el;  // extern 키워드를 통해 다른 파일에 선언된 전역변수를 끌어와서 사용할 수 있다(해당 변수와 오브젝트를 공유한다)
// fil scope에 있는 변수는 마치 프로그램 전체에서 사용할 수 있는 것처럼 해서 전역변수라 부름
// 다른 곳에서 extern을 사용할 수 있으니 그냥 전역변수라고 부른다.
//extern int il;  // 링커가 해당 변수를 못 찾기에 링킹 에러 발생
//1>C:\Users\user\Desktop\Solution 12\Debug\03B_Linkage.exe : fatal error LNK1120: 1 unresolved externals
void testLinkage() {
    printf("DoSomething something called\n");
    printf("%d\n", el);
    //printf("%d\n", il); // 가져다 쓸려니까 링킹에러 발생
    //printf("%d", dodgers);

    el++;
}