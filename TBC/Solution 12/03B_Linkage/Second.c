#include <stdio.h>

extern int el;  // extern Ű���带 ���� �ٸ� ���Ͽ� ����� ���������� ����ͼ� ����� �� �ִ�(�ش� ������ ������Ʈ�� �����Ѵ�)
// fil scope�� �ִ� ������ ��ġ ���α׷� ��ü���� ����� �� �ִ� ��ó�� �ؼ� ���������� �θ�
// �ٸ� ������ extern�� ����� �� ������ �׳� ����������� �θ���.
//extern int il;  // ��Ŀ�� �ش� ������ �� ã�⿡ ��ŷ ���� �߻�
//1>C:\Users\user\Desktop\Solution 12\Debug\03B_Linkage.exe : fatal error LNK1120: 1 unresolved externals
void testLinkage() {
    printf("DoSomething something called\n");
    printf("%d\n", el);
    //printf("%d\n", il); // ������ �����ϱ� ��ŷ���� �߻�
    //printf("%d", dodgers);

    el++;
}