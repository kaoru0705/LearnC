/*  ��ó���� �غ��ϴ� ���� �ܰ� Translation Phases ��ó������ ù �ܰ�� �� �� �ִ� �����ܰ迡 ���� �˾ƺ���*/
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>

int main(void)
{
	/*
		Program written in C
		
		Translating �����Ϸ��� ������ �� �ִ� ���� ���� �ٲ��ִ� ����
		translating�� ��ó������ ���Ե� ���� Ȥ�� �и��ؼ� �����Ϸ� �տ� �Ͼ�� �������� ���� �� �ִ�.
		Preprocessing
		Compiling
		Linking
		
		Executable
	*/

	/*
		International characters �����ܰ��� �ٱ������ ���������� �����Ϸ��� ������ �� �ִ� ������������ �ٲ��� translation�ܰ迡�� ó��
	*/

	puts("�ȳ��ϼ���? �ѱ��� ����մϴ�.\n");

	/*
		Trigraph Sequences
		- Some keyboards don't provide all the symbols used in C. ���� Ű������� �̷� Ű�� ��� ������ �̷��� ���
		- Three-character sequences
		
		Trigraph		Replacement
		??=				#
		??/				\
		??'				^
		??(             [
        ??)             ]
        ??!             |
        ??<             {
        ??>             }
        ??-             ~
		
		/Zc:trigraphs trigraphs�� ����ؼ� ������ �ض� - �������ض�? translation�ε�? �� ���� ��Ʋ� �������̶� �� ���ǿ��� �׷���.
	// VS�� ��� [Properties]-[C/C++]-[Command Line]-[Additional Options]�� /Zc:trigraphs �� �߰��ؾ� ��� ����
    */
    
    int arr[3] = { 1, 2, 3 };
    printf("arr??(0??) == %d\n", arr??(0??));
    //printf("arr[0] == %d\n", arr[0]);

    /*
        Digraphs
        - Two-character sequences

        Digraph         Equivalent
        <:              [
        :>              ]
        <%              {
        %>              }
        %:              #
    */

    printf("arr<:1:> == %d\n", arr<:1:>); // �տ� �κ��� []�� �� �ٲ���
    printf("arr[1] == %d\n", arr[1]);

    /* Two physical lines vs One logical line ���������δ� �� �� �������δ� �� �� physical�̶�� ���� ���� ���δ�. �����п��� */
    printf("This is a very very very very very very \
very very very very very long long long long long long line.\n"); // \���� �κ��� ������ ������  ��ĭ�� ���ܼ� �̷��� ������� �Ѵ�

    /*
        Tokens ������ �׷�,  �Է��� �ڵ带 ��ū�̶�� ������ �ɰ� �����Ϸ� ������ �� �ڼ��ϰ� ���� ���
        - Groups separated from each other by spaces, tabs, or line breaks
        Whitespace characters -> a single space
    */

    int/*a variable to count a number*/n = 1;  // �ּ��� �ϳ��� �� ĭ �ϳ��� �����ܰ迡�� �ٲ��ֱ⿡ �� �ڵ�� �������ȴ� 
    //// �㳪 �̷��� ���� �ּ��� �ſ� �� ����. �������� ������ ��Ȥ �̷��� �ڷ��� �� Ȥ�� ������տ� �ٴ� ����� �ִ�.
    int /*a variable to count a number*/ n = 1;  // �ּ��� �����ؼ� �ڷ����� ������ ���̿� �� ĭ�� 3������ �̸� �������ϱ� ���ϵ��� �� ĭ �ϳ��� �ٽ� �����ȴ�.
    //int n = 1;

    return 0;
}
