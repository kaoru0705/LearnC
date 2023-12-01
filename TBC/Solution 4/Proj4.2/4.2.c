/* sizeof ������ */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h> // malloc()

struct MyStruct
{
	int i;
	float f;
	char c;
};

int main()
{
	/* 1. sizeof basic types */

	int a = 0;
	unsigned int int_size1 = sizeof a; // sizeof�� unsigned�� 
	unsigned int int_size2 = sizeof(int); // sizeof�� �Լ��� ��ó�� �������� ������
	unsigned int int_size3 = sizeof(a);

	size_t int_size4 = sizeof(a); //size_t �ý��ۿ� ���� sizeof�� �˷��ִ� ���� �ڷ����� unsigned int�� �ƴ� ��찡 ���� �� �־
	// �̽ļ��� ���̱� ���� size_t ��� ���� �߼�
	size_t float_size = sizeof(float);

	printf("Size of int type is %u bytes. \n", int_size1);
	printf("Size of int type is %zu bytes.\n", int_size4);// size_t �� �ش��ϴ� ���������� %zu sizeof �������� ��ȯ���� �ڷ���
	printf("Size of float type is %zu bytes.\n", float_size);

	/* 2. sizeof arrays */

	int int_arr[30]; // int_arr[0] = 1024; ... 30���� �޸� ������ ��ǥ�ϴ� �޸��� �ּ� �� �� �ּ� 
	int *int_ptr = NULL;
	int_ptr = (int*)malloc(sizeof(int) * 30); // int_ptr[0] = 1024; ...
	//120byte �޸� ������ �Ҵ��ϰ� �� �޸� ������ ��ǥ�ϴ� ù ��° �ּҸ� �Ҵ����

	printf("Size of array = %zu bytes\n", sizeof(int_arr));//30*4��� �����Ʊ� ������ int_arr�� �ּҶ�� �����ϴ� �� ���� 
	printf("Size of pointer = %zu bytes\n", sizeof(int_ptr)); //�����Ҵ��̶� ��������� ���������� �𸣱⶧���� int_ptr�޸𸮸� ����Ѵ�.

	// int_arr�� �������� �� 120byte�� ������ ���� compile time
	// int_ptr�� �ϴ� ������ �ϰ� ���߿� �޸� ������ �󸶳� �Ҵ������ runtime�� �����ȴ�.
	// �������� sizeof(int)*30���� �����ֱ� ������ �����Ϸ� ���忡���� �갡 ��ǥ�� ������ �޸𸮻���� �󸶰� ���� �𸥴�.

	/* 3. sizeof character array */

	char c = 'a'; //���� 97�� �ٲ㼭 �����
	char string[10]= "1234567890"; // maximally 9 character + '/0' (null character)
	// in C language ���ڸ� ������ �� ������ �迭�� �� ĳ���͸� �߰��� �ǿ������� ���ڿ��� ó���ϱ� ���ؼ��� ����� ��ħǥ�� �ʿ�
	// string[10] = "1234567890" �̷��� �ϰ� %c�� �ϸ� ���� �㳪 %s�� �ϸ� ������� ��µ�
	printf("%s\n", string);

	size_t char_size = sizeof(char);
	size_t str_size = sizeof(string);

	printf("Size of char type is %zu bytes.\n", char_size);
	printf("Size of string type is %zu bytes.\n", str_size);

	///* 4. sizeof structure */

	printf("%zu\n", sizeof(struct MyStruct)); // int float 8bytes char 4byte? �ù߳�� �̰� ���߿� ���� ������

	return 0;
}