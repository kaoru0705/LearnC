/* �پ��� ���� �����ڵ� �׸��� ����� �ڵ� Ȯ�ι� */
/* https://en.cppreference.com/w/c/language/operator_precedence */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/*
		+=, -=, *=, /=, %=
	*/

	int i = 1024;

	i = i + 10; // line 14 15�� ���̴� ����. ���� å������ +=�� �� Ư����Ȳ���� �����ٴ� ��Ⱑ �־�����... �Ȱ���.
	i += 10;	// 'ctrl k' + 'g' go to disassembly�� ���غ��� debug -> windows -> dissassembly
	//	����� ����ȭ�� �Ű澲�� �ͺ��� ��ǻ�� ������ �������� �˰��� ���θ� �ϴ� �� �߼���.
	// assembly����
	// �ð� ����
	/*
		0042177C  mov         eax,dword ptr [i]  
		0042177F  add         eax,0Ah  
		00421782  mov         dword ptr [i],eax 

		00421785  mov         eax,dword ptr [i]
		00421788  add         eax,0Ah
		0042178B  mov         dword ptr [i],eax
	*/

	i %= 4;

	i = i * (1 + 2);
	i *= 1 + 2;
	i *= (1 + 2);	// Check precedence ��κ� ��ȣ�� ġ�� �ʴ´�.

	for (int i = 0; i < 10; i += 2)
		;

	return 0;
}