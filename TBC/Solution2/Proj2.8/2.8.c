/* Keywords(�ܾ��� ����)& Reserved Identifiers(�����Ϸ��� ���� �̸� ���Ŵϱ� ���α׷��ӵ��� ������� ���ʼ� �̸� ������ �Ǿ��ִ� �����) */
// ������ �̸��� �ٲ� �� �ִ�.
/* https://en.cppreference.com/w/c/keyword */
/* Ű���� ������ ���� �Լ������� ������� ����. */
#include <stdio.h>
#include <stdbool.h>

int main() 
{
	//int printf = 1; keyword�� ���������� ���� ����. 
	//int _Bool; //�̰� �� ���� �ȵǰ� �ڷ����� �� �� ����
	//int bool = 2; // cpppreference ���� stdbool.h�� �����ϴ� ���� ������ �ȴ�. ������ ����� �����ϴ� ���� ����� �� ����
	_Bool a = true;
	bool b = false;
	// if preprocessor if���� #if? #if�� ��ó����?
	printf("Hello World!"); //printf�� ���������� ����ϸ� ���⼭ ������ ����.

	return 0;
}