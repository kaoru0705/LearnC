/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �������� �迭�� 2���� �迭 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// �迭�� �����ʹ� ����ϴ�. �׷��� ������ ���� �ִ�. �����Ҵ��� �� �Ǽ��� �� �ִ� �κ�
// ����(element)
int main()
{
    /* Two of 1D arrays */
    //int arr0[3] = { 1, 2, 3 };
    //int arr1[3] = { 4, 5, 6 };

    //int* parr[2] = { arr[0], arr[1] };  // an array of pointers int* pointer�� ��� �� �ִ� �޸𸮰����� �� ���� Ȯ���� �迭, * > []
    ////��ǻ� * parr[2] = {parr1* = arr = &arr0[0], parr2*}
    ////arr[0] ������ �迭���� ù ��° index�� ���Ե� �迭, ���� ������ ���� ù ��° ������ ������(�޸��� �ּ�)
    //
    //for (int j = 0 ; j < 2; ++j) { // arr0 arr1�̶�� for���� �� ���� ��� �ǳ� parr�� �̿��ؼ� ���� for������ �ϳ��� ������ ��ġ ���߹迭ó��
    //    for (int i = 0; i < 3; ++i)
    //        printf("%d(==%d, %d, %d) ", parr[j][i], *(parr[j] + i), *(*(parr + j) + i), (*(parr + j))[i]);
    //    // parr[j]�� �迭�̰� �迭�� ����ִ� �� �����ʹ� �迭�� ���° ���ҿ��� i ���ϰ� indirection *(parr[j] + i) ���� ������ ����
    //    // parr �迭�� �̸��� ������ó�� ��밡���ϹǷ� ����������ó�� ��� *(*(parr + j) + i) arr[2][3] *(*(arr + 2) + 3)
    //    // (*(parr + j))[i]) �⺻������ parr�� �迭�̱� ������ �̷��Ե� ���� 
    //    // ���ſ��� []�� �̿��� ���ٺ��� ������ ��� ������ ���� �� �����ٴ� ���� �־����� �ֱٿ��� �̰ɷ� �������� �� ū �ǹ̴� ����
    //    printf("\n");
    //}
    //printf("\n");


    /* 2D arrays are arrays of 1D arrays */
    //int arr[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

    //int *parr0 = arr[0]; // arr[0] == &arr[0][0]
    //int *parr1 = arr[1];

    //printf("%zu %zu\n", sizeof arr[0], sizeof arr[1]); // 12 12

    //for (int i = 0; i < 3; ++i)
    //    printf("%d ", parr0[i]);
    //printf("\n");

    //for (int i = 0; i < 3; ++i)
    //    printf("%d ", parr1[i]);
    //printf("\n");


    /* arrays of pointers work like a 2D array */
    int arr[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

    //int* parr[2] = { arr[0], arr[1] };  // �Ʒ��� ���� �ǹ�
    int* parr[2];   // parr �����͸� ���� �� �ִ� 8byte �޸𸮰����� ù ��° �ּҸ� ����Ű�� �ȴ�.
    parr[0] = arr[0];
    parr[1] = arr[1];

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 3; ++i)
            printf("%d %d %d %d %d\n",
                arr[j][i], parr[j][i], *(parr[j] + i), *(*(parr + j) + i), (*(parr + j))[i]);
        //�����Ҵ��� ����� ��� *(*(parr + j) + i)�� ���� ��
        //������ �迭�� �����Ϸ��� 2�������� ���� �;��ϴ� �� ������ �����Ҵ��� OS�κ��� �Ҵ���� �� ��·�ų� �⺻������ �������̱� ������
        printf("\n");
    }
    printf("\n");

    ///*
    //   Notes
    //   - parr[0] and parr[1] do not point valid memory by default �������� �迭�� ���Ҵ� �������̱� ������ �����Ⱚ ����
    //   - &parr[0] != &arr[0] but parr[0] == arr[0]
    //   - &parr[0] != parr[0] but &arr[0] == arr[0]
    //*/

    //printf("%p\n", parr);
    //printf("%p\n", &parr[0]); // different with parr[0] ������ �迭 ��ü�� �ּ�, �������� �迭�� ù ��° ������ parr[0] �̳��� �ּҴ�? parr
    //printf("%p\n", parr[0]); // ����Ű�� �ִ� �ּ�
    //// �迭�� �̸��� ù ��° ������ �ּ�
    //printf("%p\n", arr);  // �迭�� ��ġ ù ��° ������ �ּ��� ��ó��(&arr[0]) ����� �� �ִ�. �׷��� �ּҸ� ������ �� �ִ� ������ ������ ���� ������ ������ �ִ� �� �ƴ϶� C �������� arr[0]�� �ּҸ� ����� �� �ְ� ���ִ� ���� ���̴� ��鿡 ������ �迭�� ��������� ���� �ִ�. �㳪 parr�� �翬�� �� ���� �ִ�.
    //printf("%p\n", &arr[0]);  // address of array name is equal to the address of the first
    //printf("%p\n", arr[0]); // arr[0]�� &arr[0][0]�� ����
    //printf("%p\n", &arr[0][0]);
    //printf("%p\n", &arr);
    //printf("%zu %zu %zu %zu\n", sizeof(&arr), sizeof(arr), sizeof(&arr[0]), sizeof(arr[0])); // 4, 24, 4, 12 or 8, 24, 8, 12

    /* Array of string of diverse lengths example */ //�������� �迭�� ����ϴ� ������ �ϳ� ���ڿ�
    char* name[] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie" };
    //name�̶�� charŸ���� �������� �迭�� ���Ҵ� A�� ����� ��ġ J�� ����� ��ġ ...��
    const int n = sizeof(name) / sizeof(char*); // x86 16 / 4 
    //name�� ������� name�� ���ҵ��� ����Ű���ִ� �޸𸮰����� ����� �� �� ����. ���� ���� �� �� ����. �ݸ鿡 aname��? ����
    for (int i = 0; i < n; ++i)
        printf("%s at %u\n", name[i], (unsigned)name[i]);  // Use llu in x64 build
    // Null ���� ����. ���� ����ŭ �ּҰ� ���̰� �� ����? �ü�� �����Ϸ��� �ֵ��ϴ� ����
    //printf("%c\n", *name[i]); A J M C
    printf("\n");

    char aname[][15] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie", "Jafar" };

    const int an = sizeof(aname) / sizeof(char[15]); // sizeof(char[15]) size�� ��Ȯ�ϰ� �� �� �ִ�.

    for (int i = 0; i < an; ++i) // ������ ����� ���缭 �޸𸮰� �����ƴ�.
        printf("%s at %u\n", aname[i], (unsigned)&aname[i]);  // Use ull in x64 build
    printf("\n");

	return 0;
}