/* Namespace �̸�����(��Ī����) �����ϱ� */
#define _CRT_SECURE_NO_WANRINGS

#include <stdio.h>

int iamfunction()
{
    return 0;
}


int main(void)
{
    /*
        namespace
        - Identify parts of a program in which a name is recognized
        - You can use the same name for one variable and one tag. structure, union�� ī�װ��� �ٸ��� ������ ���������� ���� �㳪 c������ �׷���. ������ �Լ��� �̸��� ��ġ�� �� �ȴ�.
        - C++: use 'namespace' to use the same identifiers in the duplicated scopes �� �������� �� �̸��� �� ���� ���� �� ���� Ŀ�ٶ� ���α׷��� ���� ��� �����̸��� �ߺ��Ǵ� ��찡 ���� �߻�
     */

    int myname = 123;
    {
        int myname = 345;                           // ������ �ٱ��� myname�� name hiding�Ѵ�
        //double myname = 3.14;                     // ERROR(�ڷ����� �ٸ����� ������ ������������ ���� �̸�(�ĺ���)�� ����� �� ����
    }

    struct rect { double x; double y; };            // struct�� �±װ� rect�� ���

    //int rect = 123;  // OK in C (NOT OK in C++) ����ü �̸��� rect�� ���� ��� �׷��� ���� �㳪 �������� ����
    struct rect rect = { 1.1, 2.2 };                // struct rect and rect(struct rect's variable name) are in different categories

    /*
     typedef struct rect rect;
     rect rect = { 1.1, 2.2 };                      // NOT OK(�����Ϸ� ���忡�� ���� �� ���� ������ �� ���⿡ �Ұ���)
     */

     //int iamfunction = iamfunction();             // ������ �Լ��� ���� �̸��� ����� �� ���� error C2063: 'iamfunction': not a function �̹� iamfunction�� ���� �ֱ� ������ iamfunction() ���̸��� �Լ��� ����Ű�� �Ŷ�� �ν��� �� ����.

     /*
         Namespace pollution (KNK p.465) a�� b�� �ٲٴ� �� �� �ǰ� c�� �ٲٴ� �� �� �ȴ�. ���� ����
         - Names in different files accidentally conflicting with each other
         - C������ ���������� �ּҷ� ����ϰų� static���� �����ϴ� ������� ���� ����
     */

     //printf("%d\n", a);                            // other.c �� a, b, c, d, e, f��� �̸��� ������ ������ִٸ� �������� ���� translation unit�� �ٸ��� ������ ������ �߻����� ������ ��ŷ ���� �߻�,
     // �� ������ ������ �̸��� �ٸ� ������ �̹� ���̰� �ִ� ��찡 ����. ������ ������ �̸��� ���� ������ �ȿ� ���ֳ��� �̸��� ������ �� �ִ�.
     // �������� �� ���ٴ� ���� ���� ����
     // �ٸ� ���� namespace���� ��� ������ ����
                                                     // error LNK2005: _a already defined in 14.20.obj
    return 0;
}