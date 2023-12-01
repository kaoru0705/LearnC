/* ��ü(Object)�� �ĺ���(Identifier) L-value�� R-value */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        5.9 ����
        Object
        - "An object is simply a block of memory that can store a value." (KNK p.487) c���� �޸� ���� = object
        - Object has more developed meaning in C++ and Object Oriented Programming(OOP) OOP���� ����, Ȯ��� ����

        Identifiers
        - Names for variables, functions, macros, and other entities(�����ͺ��̽� ��� ���⼱ �������� �͵�). (KNK p.25) �̸�
    */

    int var_name = 3;  // creates an object called 'var_name'

    int* pt = &var_name;  // pt is an identifier
    *pt = 1;  // *pt is not an identifier. *pt designates(�����ϴ�) an object

    int arr[100];  // arr is an identifier. Is arr an object?(No. arr�� �迭�� ù ��° ������ �ּҸ� ��Ÿ�� ������ ����ü�� �޸� ������ ������ �ʱ� ����)
    arr[0] = 7;  // arr[0] is not an identifier(expression�� ���ؼ� 0�� index�� ����Ű�� �޸𸮸� ������ �� �ִ�), but an object

    /*
        lvalue is an expression 'referring'(���� �� �ٸ� �̸�ó�� ����Ѵ�) to an object. (K&R p.197)

        L-Value : left side of an assignment object��
        R-Value : right side, variable, constant, expressions (KNK p.67)
    */

    var_name = 3;  //modifiable lvalue(���� �̸� �� ��ü�� �޸� ������ �ƴϸ� ���� �̸��� ���������� ����Ű��(refer) �ִ� �޸� �������ٰ� 3�̶�� ���� �����سִ� ��) expression 3 sequence points(full expression)������ ����� 
    int temp = var_name;  // ������ lvalue, rvalue ��� �� �� ������ object�� rvalue�� ���� ���� �ڱⰡ ���� ���� �����ؼ� �Ѱ��ֱ⸸ �� ���̴�
    temp = 1 + 2;  // 1 + 2�� �޸𸮰����� ���� �ִ� �� �ƴ϶� �׳� expressions object�� �ƴ� cpu�� ���� ����ؼ� ���� �ӽ� �������(��������)�� https://blog.naver.com/oddish0513/222632469583

    pt = &var_name;
    int* ptr = arr;
    *pt = 7;  // *pt is not an identifier but an modifiable lvalue expression.

    int* ptr2 = arr + 2 * var_name;  // address rvalue
    *(arr + 2 * var_name) = 456;  // indirection�� �������ν� modifiable lvalue expression

    const char* str = "Constant string";  //str is a modifiable lvalue.
    str = "Second string";  // "Constant string" = "Second string"  // impossible(�׳� ���̴�. object�� �������� �ʴ´�.)
    //str[0] = 'A';  // Error
    //puts(str);

    char str2[] = "string in an array";
    str2[0] = 'A';  // OK

    /*
        Identifiers have scope.
        Objects have storage duration ������Ʈ�� �޸𸮿� ��ġ�ϴ� �� �������� �������� ��ġ�� �� ���ӱⰣ
        �ĺ��ڴ� ������Ʈ�� �̸� ���� �̸��� �ٲ� ���� �ְ� ������ ���� ���� �ִ�
        Variables and functions have one of the followin linkages(����) �����Ϸ��� Ư¡:
            external linkage, internal linkage, or no linkage.
    */

    return 0;
}