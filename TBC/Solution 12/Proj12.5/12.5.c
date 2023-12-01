/* Automatic Variables �ڵ� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    Automatic storage class
    - Automatic storage duration(�̷��� �̸��� �ڵ�����), block scope, no linkage(�޸𸮿� �ִ� ���� �ϴ� ������ ���� ����)
    �ڵ������� ���ϰڳ�? ���� ����� �� ���ؾ� ��
    - Any variable declared in a block or function header
*/

void func(int k);  // automatic variable in function header

int main() //Note: main() is a function
{  
    //auto int a;  // keyword auto : a storage class specifier(auto Ű����� ���� �����ϸ� ������������ �����ϱ� ���� ���̱⵵ �Ѵ�. ��κ� �� ����. ��, C++������ auto Ű���尡 ���� �ٸ� �ǹ̸� ���ϱ⿡ �����ؾ� �Ѵ�)
    //a = 1024;
    //printf("%d\n", a);     // What happens if uninitialized?(BSS ���׸�Ʈ�� ����� ����/���������� ��� ó�� �� ���� �ʱ�ȭ�ϸ� �Ǳ⿡ �����Ϸ��� �ڵ����� �ʱ�ȭ���ش�. ������ ���ÿ� ����ϰ� �峪��� �ڵ��������� �Ź� 0���� �ʱ�ȭ�ϱ⿡�� ����� �߻��ϹǷ� �ʱ�ȭ���� ���� �ڵ������� ���� ��� �ڵ����� �ʱ�ȭ������ �ʰ� ������ �߻���Ų�� c++������ ������ �ؼ� ����)
    //auto int b = a * 3;    // What happens if uninitialized?()

    int i = 1;
    int j = 2;

    printf("i %lld\n", (long long)&i);

    {
        int i = 3;  // �ٱ� �ĺ��� name hiding ���� �־ �θ��Ⱑ �ָ���
        printf("i %lld\n", (long long)&i);

        int ii = 123;

        // j is visible here(������ �������� ���� ���� j�� ������ �Ʒ��� �׿��ִ� �����̱� ����)
        printf("j = %d\n", j);
    }

    // ii is not visible here
    
    //stack frame main�̶�� main �Լ� ��ü�� �ʿ��� �޸� �׾ȿ��� ������ push pop�Ǵ� ������ ���� �ڷᱸ�� 12.5 ����
    /*
        ���⼭ ���ϴ� ���� �������� �� 12.1 ���� ������ �޸� ���̾ƿ� �� �ϳ��� ���� �޸𸮿� ���� ����Ͻ� ���Դϴ�! (�޸� ������ �̸��� '����'�� ��) 
        main �Լ��� ����� ���� �Լ��� ���࿡ �ʿ��� �޸𸮴� �� ���� �޸𸮿� ��ġ�ϰ� �Ǳ� �����Դϴ�.
        �ٵ� �� �޸� ���� �� �ڷᱸ�� ����ó�� �۵��ϴ� �͵� �½��ϴ� ���� �׷��⿡ �����Բ��� ������ push pop �� ����Ͻ� ������ ���Դϴ�. 
        ���� �� main �Լ� �ȿ��� func ��� �Լ��� ȣ���ߴٸ� main �Լ����� func �� ȣ���ϱ� �������� �޸� �� ���� func �����ϴµ� �ʿ��� �޸𸮵��� ���Դϴ�.(���� �����̴ϱ�)
        �׸��� func ȣ���� ������ func �����ϴµ� �ʿ��� �޸𸮵��� ������ �ٽ� main �Լ� �޸𸮰� top �� �˴ϴ�. �� �ڷᱸ���μ��� ������ ������ �Ȱ����ϴ�.
    */

    printf("i %lld\n", (long long)&i);  // which i?

    for (int m = 1; m < 2; m++)
        printf("m %lld\n", (long long)&m);  // no block?(for�� �ڿ� �� ��������� �� ���� ���� �� ������ ���� m�� �������� �� ���� ���� ���ѵȴ�

    func(5);  // cannot see any of the variables defined so far(������ ����� ���� i,j�� func() �Լ��� �������� ������, func() �Լ��� body�� ������� �Ѿ�� ���� stack frame ��ü�� �޶����⿡ i,j�� ������ �� ����)
    
    for (int m = 3; m < 4; m++)
    {
        printf("m %lld\n", (long long)&m);  // block?
    }

    return 0;
}

void func(int k)
{
    int i = k * 2;
    // do something with i and k
    printf("i %lld\n", (long long)&i);
}