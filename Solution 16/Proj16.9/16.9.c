/*  #pragma ������ (�����Ϸ����� ���ϰ� �������ش޶�� �����Ϸ����� ���� ����� �� �ִ� ��ó�� ������ pragma)*/
#include <stdio.h> // f12�� �������� #pragma once, ifndef INCSTDIO endif�� �� ���� ������带 ��� ����ߴ�.

/*
#pragma tokens (ex: once) // �����Ϸ����� pragma�� �����Ǵ� ������ �ٸ���. https://learn.microsoft.com/en-us/cpp/preprocessor/pragma-directives-and-the-pragma-keyword?view=msvc-170
*/

//#pragma pack(1)     // 1����Ʈ�� ��ŷ(= �е��� ���� ����� �ǹ�)
_Pragma("pack(1)")  // VS������ ��� �� �� destringizing : remove first and last ", \" -> " ���� ���� pragma ������ ���� ��ū�� ���ڿ��� �� �� ���� ���ڿ��� ��ó���Ⱑ �����ϴ� �������� destringizing
//"pack(1)"�� #pragma �ڿ� �Ű��ְ�  -> #prgma pack(1)
//#define PACK1 _Pragma("pack(1)")  // �ƴ� �� ���� ���ڵ�ó�� ��? ��ũ�θ� ���� �� �ִ�.
//PACK1

//#pragma warning( disable : 4477 ) //4477�� ���� �� �ִ�.
//#pragma warning( error : 4477 ) // warning�� erroró�� ó���ض�

struct s {
    int i;
    char ch;
    double d;
};

int main(void)
{
    struct s A;
    printf("Size of A is : %zd", sizeof(A)); // z�� ���ָ� c4477 warning
}