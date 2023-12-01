/* ���� �Ҵ� �޸𸮿� ���� ���� �з� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int g = 123;

void func()
{
	int i = 123;
	printf("Local variable		\t%lld\n", (long long)&i);
}

int main()
{
	// visual studio c�� �����ϱ� ���⼺�� ����ѵ� �ణ �ٸ��� ���´�. GCC�� ����ϴ� ����
	const char* message = "Banana";

	void (*f_ptr)() = func; // address of a funciton �Լ� �����͸� ������ ���� �Լ� �����Ϳ� ����� �Լ��� ��ȯ�� �ڷ���, �Ű����� �ڷ����� ������ ��ġ�ؾ� �մϴ�.

	printf("Local pointer		\t%lld\n", (long long)&message); // stack
	printf("Function pointer	\t%lld\n", (long long)&f_ptr); // stack
	printf("String data		\t%lld\n", (long long)message); // rodata text segment
	printf("Function address	\t%lld\n", (long long)f_ptr); // �Լ���ü�� ���α׷� text segment
	printf("Function address	\t%lld\n", (long long)main); 
	printf("Global variable		\t%lld\n", (long long)&g); // data segment

	func();

	int* ptr = (int*)malloc(100 * sizeof(int));
	if (!ptr) exit(EXIT_FAILURE);

	printf("Allocated memory	\t%lld\n", (long long)ptr); // heap segment �����Ҵ� �޸𸮴� heap�� Ư���� �ٸ� ����������� �޸� �����̶� �� �ڵ����� �������ִ� �� �ƴϰ� �������� ��������� �Ѵ�
	

	free(ptr);
	return 0;
}