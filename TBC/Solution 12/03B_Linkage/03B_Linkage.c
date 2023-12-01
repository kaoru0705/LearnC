#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// file�� �������� �̷����� �ּ� �����̴�(translation(�������� �������) unit)
// �⺻������ ���� �ٸ� .c ������ ���� �������ؼ� �����Ǵ� .o ���ϵ��� ������ ������ �� �� ������ ��Ŀ�� ���� ���� ����� �� �ִ�

/*
    Linkage

    Variables with block scope, function scope, or function prototype scope
    - No linkage

    File scope variables
    - External or internal linkage
*/

// ��� translation unit�̵� ��밡���ϱ� ������ global variable
int el;         // File scope with external linkage (global variable)
static int il;  // File scope with internal linkage(�� file�ȿ����� �� �� �ִ�.) (Ű����μ��� static�� �̺����� ������ ���� scope�� ������)

void testLinkage();  // �ٸ� ���Ͽ� ���ǵǾ� �ִ� �Լ��� ����ϱ� ���� ������Ÿ���� �����ؾ� �Ѵ�(��ŷ)

int main() {
    el = 1024;

    testLinkage();

    printf("%d\n", el);

    return 0;
}