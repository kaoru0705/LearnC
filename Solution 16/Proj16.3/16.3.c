/*  #define ��ũ�� */
#include <stdio.h>

/*
    Preprocessor directives(��ó�� ������) begins with #(hash) symbol at the beginning of a line
*/

/*
    Macro
    - An instruction that represents a sequence of instructions in abbreviated(����) form ���� ���� ��ɾ �����Ǿ� �ִ� ���� �ϳ��� ��ɾ�� ���
*/

/*
#define         SAY_HELLO        printf("Hellow, world!");

Preprocessor    Macro (name)     body (or replacemnet list)
directive

Macro expansion: ��ũ�� name�� body�� ��ü�Ǵ� ������ ��Ī
*/

/*
    Object-like macros vs Function-like macros(c���� ���� ��������� ������ c++���� ���� ���ɼ�)

#define ONE 1
#define SQUARE(X) X*X
*/

#define PI 3.141592          // Symbolic, or manifest(�����), constants //manifest�� ��� ��ܶ�� �����ε� ���� ������ ���� manifested file)
#define GRAVITY 9.8          // ��ó���Ⱑ GRAVITY�� 9.8�� ��ü�ϱ� ������ �����Ϸ��� 9.8�� �޾Ƶ��ϻ� GRAVITY�� �� �� ����

#define THREE 3
#define MESSAGE "The great glory in living lies not in never falling, \
but in rising every time we fall." // 16.2 ����

#define NINE THREE*THREE // ��ũ�ο��� ��ũ�� �������� ���� ��ũ�� ��� �ּ�ȭ�ϴ� ���� ���� c++������ ������ ��� �� ��
#define SAY_HELLO printf("Hello, world!\n");
#define FORMAT "Number is %d.\n"

# define WITH_BLANK 1    // ��ũ�� ���� �� �� ĭ ���

#define MY_CH 'Z'
#define MY_ST "Z"            // Z\0

#define LIMIT 20
const int LIM = 50;
static int arr1[LIMIT];
//static int arr2[LIM]       // clang, C++�� ��. ������ �� ���·� ���� �� c�� �����Ϸ��� ���� �ٸ� c�� ����
const int LIM2 = 2 * LIMIT;
//const int LIM3 = 2 * LIM;  // clang, C++ �̰� �� �Ǵ� ����?
/*
The idea behind this requirement is to have all static storage duration object initialized at compile time.
The compiler prepares all static data in pre-initialized form so that it requires no additional initializing code at run time.
I.e. when the compiled program is loaded, all such variables begin their lives in already initialized state.

The C standard clearly prohibits initialization of global objects with non-constant values. The Section 6.7.8 of the C99 standard says:
All the expressions in an initializer for an object that has static storage duration shall be constant expressions or string literals.

The definition of an object with static storage duration
An object whose identifier is declared with external or internal linkage, or with the storage-class specifier static has static storage duration.
Its lifetime is the entire execution of the program and its stored value is initialized only once, prior to program startup.
*/

/*
    Tokens

#define SIX 3*2
#define SIX 3 * 2
#define SIX 3     *    2 // �����Ϸ��� �ǹ̴������� ��ó���⿡���� �̰��� ��� �ؼ����� �ָ���. �����Ϸ� Ÿ�Կ� ���� �ٸ�
*/

/* Redefining Constants */
// #define�� ������ ���� ���������� �ٸ� ������Ͽ� #define�� ���ǵǾ� �ִ� ��� �� ��������� include�ϸ� �ش� ������Ͽ� �ִ� #define�� �Բ� �鿩�´� �׷� ��쿡 redefine�� �Ǳ⵵ �Ѵ�. �ٸ� ��������� include�� �� ���� �� �ִ��� �� �� �ֱ� ������
// ���� ������ ���� ���� ���� #define �� ��� �߻����� ������ ����� �ٸ��ٸ�(token������ ���� �� �ٸ��ٸ�) ��� �߻���Ų��
#define SIX 2*3
#define SIX 2*3 // ok ��ó������ �� �ϳ� ����� �ǰ���
//#undef SIX                // ���α׷��Ӱ� �ǵ������� redefine �ϴ� ��� #undef�� ���� �� ������ ����� #define�� ��ȿȭ�Ѵ�
//#define SIX 2 * 3         // WARNING

int main(void)
{
    int n = THREE;      // �⺻������ replacement������ �̷��Ը� �����ϸ� ���� �� �ִ�

    SAY_HELLO;              // NOTE: the additional ;(VS�� ��ũ�ο��������� �����ݷ��� Ȯ�������� �ʱ� ������ �����ݷ��� �ߺ��Ǵ��� �̷��� ǥ���ϱ⵵ �Ѵ�)
    n = NINE;               // SAY_HELLO�� ; ��� ������ �� ��(�̷��� ���� ��� ���� ����.)  n�� �鿩������ �׷��� 
    printf(FORMAT, n);      // �������α׷��ֿ����� �̷��� �ϵ��ڵ��� ������ �ʴ´�.
    printf("%s\n", MESSAGE);     // replaced
    printf("SAY_HELLO NINE\n");  // Not replaced // ���ڿ� �ȿ��� ����

    const int a = 5;
    const int a2 = a * 10;

    return 0;
}
