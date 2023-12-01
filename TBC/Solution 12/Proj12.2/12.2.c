/* 객체(Object)와 식별자(Identifier) L-value와 R-value */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        5.9 참조
        Object
        - "An object is simply a block of memory that can store a value." (KNK p.487) c언어에서 메모리 공간 = object
        - Object has more developed meaning in C++ and Object Oriented Programming(OOP) OOP에선 발전, 확장된 개념

        Identifiers
        - Names for variables, functions, macros, and other entities(데이터베이스 용어 여기선 여러가지 것들). (KNK p.25) 이름
    */

    int var_name = 3;  // creates an object called 'var_name'

    int* pt = &var_name;  // pt is an identifier
    *pt = 1;  // *pt is not an identifier. *pt designates(지명하다) an object

    int arr[100];  // arr is an identifier. Is arr an object?(No. arr은 배열의 첫 번째 원소의 주소를 나타낼 뿐이지 그자체가 메모리 공간을 갖지는 않기 때문)
    arr[0] = 7;  // arr[0] is not an identifier(expression을 통해서 0번 index가 가리키는 메모리를 접근할 순 있다), but an object

    /*
        lvalue is an expression 'referring'(참조 또 다른 이름처럼 사용한다) to an object. (K&R p.197)

        L-Value : left side of an assignment object다
        R-Value : right side, variable, constant, expressions (KNK p.67)
    */

    var_name = 3;  //modifiable lvalue(변수 이름 그 자체는 메모리 공간이 아니며 변수 이름이 내부적으로 가리키고(refer) 있는 메모리 공간에다가 3이라는 값을 복사해넣는 것) expression 3 sequence points(full expression)끝나고 사라짐 
    int temp = var_name;  // 변수는 lvalue, rvalue 모두 될 수 있지만 object가 rvalue로 사용될 때는 자기가 지닌 값을 복사해서 넘겨주기만 할 뿐이다
    temp = 1 + 2;  // 1 + 2는 메모리공간을 갖고 있는 게 아니라 그냥 expressions object가 아님 cpu가 값을 계산해서 대입 임시 저장공간(레지스터)에 https://blog.naver.com/oddish0513/222632469583

    pt = &var_name;
    int* ptr = arr;
    *pt = 7;  // *pt is not an identifier but an modifiable lvalue expression.

    int* ptr2 = arr + 2 * var_name;  // address rvalue
    *(arr + 2 * var_name) = 456;  // indirection을 붙임으로써 modifiable lvalue expression

    const char* str = "Constant string";  //str is a modifiable lvalue.
    str = "Second string";  // "Constant string" = "Second string"  // impossible(그냥 값이다. object로 간주하지 않는다.)
    //str[0] = 'A';  // Error
    //puts(str);

    char str2[] = "string in an array";
    str2[0] = 'A';  // OK

    /*
        Identifiers have scope.
        Objects have storage duration 오브젝트는 메모리에 위치하는 거 언제부터 언제까지 위치할 지 지속기간
        식별자는 오브젝트의 이름 역할 이름이 바뀔 수도 있고 심지어 없을 수도 있다
        Variables and functions have one of the followin linkages(연결) 컴파일러의 특징:
            external linkage, internal linkage, or no linkage.
    */

    return 0;
}