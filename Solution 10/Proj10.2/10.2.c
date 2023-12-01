/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �迭�� �⺻���� ����� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MONTHS 12	// symbolic constant, macro = symbolic constant�� macro�μ� �����ߴٶ�� ���ϱ⵵ ��
/*
1. �迭�� ����� ���ÿ� �ʱ�ȭ ���� ������ ���� �ѹ��� �ʱ�ȭ�� �Ұ���(for�� �̿��ؾ���)

2. �迭�� �� &�迭��[0]�� ���� �ּҸ� ǥ���ϴ� ����̴�, ������ sizeof�� ���� �ٸ���

3. �迭�� �ε����� �߸��ϴ��� ����� �ȴ�.(��Ÿ�ӿ���)

4.�迭�� #define�� const �� ���� �����ϴ�.

5. �迭�� �κ������� �ʱ�ȭ ��Ű�� ������ 0���� ���Եȴ�.

6. arr[10]={ 1, 2, [5]=3} ������ �����ؼ� �ʱ�ȭ �����ϴ� ( [5]�� 3 ����)

7. Variable-Length Array(VLA) �� C11 ���� optional �ϴ�.(vs2019�� ���Ƴ�)

*/

int main()
{
	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; //48byte ����� ���ÿ� �ʱ�ȭ

	/* Basic usage */
	//for (int i = 0; i < MONTHS; ++i)
	//	printf("%d ", high[i]); // �迭�� ����  for������ ó�������ϴ�.
	//printf("\n");

	//float avg = 0.0;
	//for (int i = 0; i < MONTHS; ++i)
	//	avg += high[i];
	//printf("Average = %f\n", avg / (float)MONTHS);

	//high[0] = 1; //index�� ���� ����ó�� ���
	//high[1] = 2;
	//high = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; // not working ������ ������ ���ÿ� �ʱ�ȭ �Ұ���
	//high[12] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; // not working
	// ���������� for������ �ʱ�ȭ�� ��κ� script file���� ���� ������ �迭�� ���� �� �ʱ�ȭ �迭�� ����� ���� ���Ͽ� ����

	/* Addresses */
	//printf("%p %p\n", high, &high[0]); //high�� ��ġ ������ó�� �۵�, ��ü ��ǥ�ϴ� �ּ��� ù ��° �ּҴ�.
	//for (int i = 0; i < MONTHS; ++i)
	//	printf("%lld\n", (long long)&high[i]); //x64�� �ּ��� ũ�Ⱑ 8byte�̹Ƿ� longlong���� casting�ϴ� �� ����. (long long)�� �� ���� ��� �˰� ���
	//printf("\n");

	/* Compiler doesn't check whether indices are valid/ */
	//high[12] = 4; // Error Runtime error ����� �Ǵϱ� ���� visual studio ���� ���
	//high[-1] = 123; // runtime Error
	// C��� ��ü�� ���α׷��Ӹ� �ϴ´ٴ� �� �⺻ ö��
	// �����Ϸ��� üũ���� �� �ִ� �㳪 �Ź� üũ�ϸ� �ʹ� ��������. Ư�� �����Ϳ����� ȿ���������� �� ��
	/* Visual Studio�� �ִ� IntelliSense�� �˾Ƽ� ���� ���
	C++�� STL�� �̿��ϰų� �ٸ� ���鿡 �ִ� ������ �̿��ϸ� ��Ÿ�ӿ����� ������ ����� �� �ִ�.
	������ �׷��� �ϸ� �����ս��� ���ϵȴ�. ū �����͸� �ٷ�� �о߿����� �̷� ������ �Һ�Ǵ� �ð��� ��ü �����ս��� ū ������ ��ġ�Ƿ� ��������� �Ѵ�.*/
	// runtime error�� �۵������� ���� ������ �� �ſ� ������ �ȴ�.

	/* const and array */
	/*const int temp = 0;
	temp = 4;*/
	/*const int low[12] = { -7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5 };
	low[0] = 123;*/

    /* When array is not initialized */
    //static int not_init[4];  // storage class(�ʱ�ȭ�� �� ���൵ �ڵ����� 0���� �ʱ�ȭ�ȴ�)
    //int not_init[4];  // ���α׷��Ӱ� ���Ŀ� �ʱ�ȭ�� ���̶�� �����ϰ� �����Ⱚ�� �־�д�
    //for (int i = 0; i < 4; ++i)
    //    printf("%d\n", not_init[i]);  // �迭�� �ʱ�ȭ���� ������ �����Ⱚ�� ��µȴ�(�����Ⱚ�� �ü��, �����Ϸ�, �����/������ ��� � ���� �ٸ���)

    /* Partially initialized */
    //int insuff[4] = { 2, 4 };  // �迭�� �κ������� �ʱ�ȭ�� ��쿡�� ���α׷��Ӱ� ���⿡�� �ʱ�ȭ�� �ǵ��� �ִٰ� �����ϰ� �������� �ڵ����� 0���� �ʱ�ȭ�Ѵ�
    //for (int i = 0; i < 4; ++i)
    //    printf("%d\n", insuff[i]);

    /* Overlly initialized */
    //int over[2] = { 2, 4, 8, 16 };  // Compile Error

    /* Omitting size */
    //const int power_of_twos[] = { 1, 2, 4, 8, 16, 32, 64 };  // ������ ������ ������ ���� �ʾƵ� �����Ϸ��� �ڵ����� ���� ������ŭ �迭�� �����Ѵ� ���α׷��Ӱ� �Ǽ��� Ȯ�� �پ��
    //printf("%d\n", sizeof(power_of_twos)); // ����: ����� �� ����, ���� �����Ҵ��� �� �۵��ȵ�
    //printf("%d\n", sizeof(int));
    //printf("%d\n", sizeof(power_of_twos[0]));

    //for (int i = 0; i < sizeof power_of_twos / sizeof power_of_twos[0]; ++i)  // �迭�� ũ�⸦ ������ ���� �� �� �ִ� ���
    //    printf("%d ", power_of_twos[i]);

    /* Designated initializers */
	//int days[MONTHS] = { 31, 28,[4] = 31, 30, 31,[1] = 29 };  // ��°�: 31 29 0 0 31 30 31 0 0 0 0 0(������ �� �� ���Ҵ� ��� 0���� ä������)
	//for (int i = 0; i < MONTHS; ++i)
	//	printf("%d ", days[i]);

    /* Specifying array sizes */
    //int arr1[MONTHS];  // Symbolic integer constant index = ���� ������
    //double arr2[123];  // Literal integer constant
    //float arr3[3 * 4 + 1];  // ������ Ÿ�ӿ� �̸� ����ؼ� ���� Ȯ���� �� �ֱ� ������ ��� ����
    //float arr4[sizeof(int) + 1];  // ������ Ÿ�ӿ� ���� Ȯ���Ǳ⿡ ��� ����
    ////float arr5[-10];  // No
    ////float arr6[0];  // No
    ////float arr7[1.5];  // No
    //float arr8[(int)1.5];  // Yes


    /* ������ �̿��ؼ� �迭 ����� �����ϴ� ��� */
    //int n = 8;
    //float arr9[n];  // Variable-Length array is optional from C11(C99������ �ʼ������� C11���ʹ� ���û����� �Ǿ���. ���־� ��Ʃ��� �����Ϸ��� �����ϰ� ���� �ʴ�. ���� �Ȱ��� ����� �����Ҵ��� �̿��ϸ� ������ �� �ִ�)
	// �ٸ� �����Ϸ��� ������ ��쵵 �ִ�.
	
	return 0;
}