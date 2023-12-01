/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �������� ȣȯ�� Compatibility */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{

    /* Pointer Compatibility */

    //int n = 5;
    //double x;
    //x = n;          // no error(promotion)
    //int* p1 = &n;
    //double* pd = &x;
    ////pd = p1;  // warning(incompatible type) compile���� warning�� error �ٲ� �� �ִ�.
    ////pd = (double*) p1;  // �۵������� �̷��� ����� ��� �ּ����� ��Ȳ�� �����ϴ� �� ���� �㳪 �ڵ��Ƿ��� �ǽɵȴ�.
    //// in c++ dynamic casting static casting�� ������ ����ȯ�ϴ� ��찡 ���� �׷��� �������� ����

    //// ������ �����͸� ����ϴ� ���� �� ���� ����. ���������� �׷� �� �ִ� �Ŵ�. ����� ���� �����ϴ� �� �߿���
    //// ������ ������ �����͸� ���Ϸ��� ȸ����

    //int* pt;
    //int(*pa)[3];  // int�� 3��¥�� ���Ҹ� ���� �迭�� ���� ������ ���� pa�� �����ϴ� �ڵ�(�迭 ������ �ƴԿ� ����)
    //int ar1[2][3] = { 3, };
    //int ar2[3][2] = { 7, };
    //int** p2;  // a pointer to a pointer

    //pt = &ar1[0][0];  // pointer-to-int 1���� �迭�ε� ������ �迭 ���� ���� 10.5
    ////pt = ar1[0];    // pointer-to-int(���ٰ� ���� �ǹ�)
    ////pt = ar1;       // warning(error. �� ��� 2���� �迭�� �迭���� int(*)[3] Ÿ���̴�)
    //// 2�����迭(2���� �迭�� ��ǥ�ϴ� �ּ� ar1)�̶� �׳������Ϳ��� ���� �� ����. �̷��Ա��� compatible���� �ʴ�.

    //// �����͸� �̿��� ������ �迭�� ��� ���ҿ� ������ �� �ִ�(������ �迭�̶� �޸𸮴� 1�������� �����Ǿ� �ֱ� ����)
    //for (int i = 0; i < 6; i++) // �ٸ� ������pt�� ������� ���Ұ� �� ������ �� �� ����. 6?
    //    printf("%d ", *(pt + i)); // or printf("%d ", pt[i]);

    //pa = ar1;         // pointer-to-int[3] pa = ���Ұ� 3��¥���� �迭�� ������, ar1 = ���Ұ� 3��¥���� �迭�� �迭 �׷��� ����
    ////pa = ar2;       // warning or error arr2[3][2] ���Ұ� 2��¥���� �迭�� ������
    //p2 = &pt;         // pointer-to-int *
    //*p2 = ar2[0];     // pointer-to-int
    ////p2 = ar2;       // warning C4047: '=': 'int **' differs in levels of indirection from 'int (*)[2]'
    //
    ////if ((p2 != ar2) && (pt == *ar2)) // �迭���� ������ ������ ������ ���� �ִ� �� �ƴϴ�. 
    ////    printf("You're right!\n");
                    
                    
    //Notes
    // pointer to ??? dereferencing *�� ���� �� ???�� ���;� ��
    // - p2: pointer to pointer to int == p2 = &pt, pt = &ar2[0][0] = ar2[0] = pointer to int
    // - ar2: a pointer to array-of-two-ints ����(int)�� 2��¥���� �迭�� ���� ������(�ּ�), *ar2 = ar2[0]
    // - ar2[0]: pointer-to-int ���ҿ� ���� ������ *ar2[0] = ar2[0][0]

    /* Pointer and const */

    //int x = 20;
    //const int y = 23;
    //int* p1 = &x;
    //const int* p2 = &y;			// *p2 = 123; ���ϰ���. indirection�ϰ� �� ���� �ȵ� �� p2�� const ������ ���� ���ٲٴ� �� 
    ////�� p2 ��ü�� ���ٲٴ°� �ƴ϶� indirection�� ���ٲٰ� �ϴ°�.
    //const int** pp2 = &p1;
    ////p1 = p2;  // warning (error)  - ���� ����(��������!) *p1 = 7; printf("%d", y);

    ////*p2 = 123; // error in 10.10 const int* p2 = &y ����
    //p2 = p1; //�̰� ����. p2 ��ü�� ���ٲٰ��ϰ�ʹٸ�?? cont int* const p2 �� �����������
    //    
    //int x2 = 30;
    //int* p3 = &x2;
    //*pp2 = p3;		// ���������Ϳ��� const int** pp2 ���� pp2�� indirection �ٲܼ� ����. **p2 = 5; �̰� �� �ٲ� ���� ������ int* const * pp2 = &p1; const int** dereferncing 2�� �� �� ���ڴ�.
    //pp2 = &p1; // int** const pp2 = &p1;

    /* const �̷������� �׳� �ƿ� �������� compiler�� ����� �ֵ� ������ �ʵ�*/
    //{
    //    const int** pp2;
    //    int* p1;
    //    const int n = 13;
    //    pp2 = &p1;		// const?
    //    *pp2 = &n;		// p1 = &n, sets p1 to point at n
    //    *p1 = 10;		// change n
    //}

    /* c const and c++ const */
    //{
    //    const int y;
    //    const int* p2 = &y;
    //    int* p1;
    //    p1 = p2; //warning (error in cpp) cpp�� const �� �����ϰ� ����
    //    *p1 = 5;
    //}

	return 0;
}