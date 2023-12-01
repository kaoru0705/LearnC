/* inline �Լ�(���� �Լ��� ���� ���� �ݺ������� ���� �� ����ӵ��� ������ ����ø� �� �ִ� �Լ�) */
#include <stdio.h>

/*
    Function call has overhead(�Լ��� ȣ���� ���� �Լ��� ������ �����ϴ� ���� �ܿ� �߰������� �� �ٴ� �ϵ��� �ִ�.)
    - set up the call(ȣ�� �غ�), pass arguments(call by value�� �⺻. argument�� �����ָ� ���縦 �ϰ� ��. �����͸� �����ִ��� �ּҰ��� �����Ѵ�), jump to the function code(�Լ��� �ڵ尡 �����ְ� extern linkage���� ���� ���� ���� ���� translation unit���� �Լ��� �����ؼ� �Լ��ڵ带 �����ٰ� �����ϴ� ����), and return
    �̷� ������带 ���� �� �ִ� ù ��° ����� ��ũ�ο���. �ڵ带 ���� �ٿ��ֱ��ϸ� �Լ��� ��������� �� �ƴ϶� ��ɸ� ������ �Լ� ȣ�� ������尡 ����
    �װ� ���ٴ� 
    inline function specifier
    - Suggests inline replacements(�����Ϸ����� �����ϴ� ��. ���� �����Ϸ��� �� ���� �ʿ�� ����)
    - inline functions should be short(����� ū �Լ����� �ζ����� �������� �ʴ� �� �Ϲ����̴�. ������尡 ����� �����ϴ� �ſ� ���� �����Ҹ� �ϱ� ����)
    - A function with internal linkage can be made inline (GCC, clang) inline�Լ��� internal linkage�� �� �Ϲ����̾�� �Ѵ�. VS�� �� ��
    - You can't take its address ���״�� in line. �ڵ忡�� ���� �ٿ��ֱ� ���ִ� �� �⺻ ����(���α׷��Ӱ� �Լ� �� ������带 ��ġ�� �ʴ� ���� ���). �׷��Ƿ� �ٸ� �Լ���� �޸� �ּҸ� �� ������
    function pointer���� ���� �޸� ��򰡿� function�� �ڸ��� ��� �־��.
*/

//inline static int foo() {  // GCC, clang /* https://www.onlinegdb.com/online_c_compiler */
inline int foo()
{
    return 5;
}

// Driver code
int main(void)
{
    int ret;

    // inline function call
    // [Properites]-[C/C++]-[All Options]���� (�⺻�� default) inline ���¸� Disabled�� �ٲ� �� breaking point�� ��� 'alt + 8' �� ������ ����� Ȯ���غ���. ���� �Ŀ��� Only _inline���� ��������(Any suitable �� �츮�� inline���� �� �ص� �����Ϸ��� �˾Ƽ� �Ǵ��ؼ� �ζ������� �ؼ��ϴ� ���)
    ret = foo();  // inline �� ����� ��� ret = 5; �� ������� ����.

    printf("Output is : %d\n", ret);
    return 0;
}
/*
 disabled �� call foo Ȯ�� ����
 only inline �� call foo�� ���� �� �ص� �ִ�. �ᱹ inline�� ������ �� �ִ� �� �ƴϴ�. /* https://learn.microsoft.com/en-us/cpp/build/reference/ob-inline-function-expansion?view=msvc-170 */