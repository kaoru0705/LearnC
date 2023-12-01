/* calloc(), realloc() */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 10;

    int* ptr = NULL;

    //ptr = (int*)malloc(sizeof(int) * n);  // �޸𸮸� �ʱ�ȭ������ �ʴ´�(0�� �ƴ� �ٸ� ����� �ʱ�ȭ�� �� �ǵ��� �ִ� ��� ������ �� ����� ȿ�����̴�)
    ptr = (int*)calloc(n, sizeof(int));  // contiguous(�����ϴ�) allocation ����� Į��: malloc() �Լ��� �Ű������� �ٸ���. �Դٰ� �Ҵ��� �޸𸮸� 0���� �ʱ�ȭ���ش� size��ŭ�� �����ϴ� �޸𸮰� n�� �ִ�. ���������δ� ������ ���ؼ� ó���ϰ��� 
    if (!ptr) exit(1);

    for (int i = 0; i < n; ++i)
        printf("%d ", ptr[i]);
    printf("\n");

    /*
        realloc() KNK p. 422k real allocation �ٽ� �Ҵ� 100�� ���� �����ϸ� 200��¥�� �޸𸮸� �Ҵ�ް� 100����� �����ϰ� 100��ġ �޸𸮸� �ݳ��ϴ� ������ �ѹ��� ó���Ѵ�.
        - doesn't initialize the bytes added �߰��� ����Ʈ�� �ʱ�ȭ���� ����
        - returns NULL if can't enlarge the memory block �� �̻� �߰����� �� ���ٸ� NULL
        - If first argument is NULL, it behaves like malloc()
        - if second argument is 0, it frees the memory block
    */

    for (int i = 0; i < n; ++i)
        ptr[i] = i + 1;

    n = 20;

    int* ptr2 = NULL;
    ptr2 = (int*)realloc(ptr, n * sizeof(int));
    //ptr = (int*)realloc(ptr, n * sizeof(int));  // �ǹ������� �̷��� ����ؼ� ��ġ �����Ͱ� ����Ű�� �޸𸮰� �þ ��ó�� ����� ���� �ִ�.  �̷��� ����� ��� �Ʒ����� if (!ptr2) else ptr = NULL�� �Է��ϸ� �� �ȴ�

    printf("%p %p\n", ptr, ptr2); // ���� ���� ������ ���� �ٸ��� ���´�. ��ħ �޸𸮰����� �� �ʿ��ѵ� �ٷ� �ڿ��� ����ִٸ� ���� �� �ִ�. 

    printf("%d\n", ptr[0]);

    if (!ptr2)
        exit(1);
    else
        ptr = NULL;

    for (int i = 0; i < n; ++i)
        printf("%d ", ptr2[i]);  // copies data
    printf("\n");

    free(ptr2);

    return 0;
}