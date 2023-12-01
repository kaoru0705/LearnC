/* 중요한 프로젝트는 책꽂이를 해라*/
/* 문자열의 포인터를 정렬하기 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp()

void swap(char** xp, char** yp);  // 이중포인터 사용은 optional
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main()
{
    char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" }; //  문자열 자체를 정렬해버리면 계속 값이 복사되니 답 없다.
    int n = sizeof(arr) / sizeof(arr[0]);

    printStringArray(arr, n);

    selectionSort(arr, n);  // ascending order

    printStringArray(arr, n);

    return 0;
}

void swap(char** xp, char** yp)
{
    char* temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void printStringArray(char* arr[], int size)
{
    for (int i = 0; i < size; i++)
        puts(arr[i]);
    printf("\n");
}

void selectionSort(char* arr[], int n)
{
	int i, j, min_idx;

	//One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)	//Note n - 1
	{
		// Find the minimum element in unsorted array
		min_idx = i;

		for (j = i + 1; j < n; j++)	//Note i + 1
		{
			if (strcmp(arr[min_idx], arr[j]) == 1)
				min_idx = j;
			/* Professor */
			/*if (strcmp(arr[j], arr[min_idx]) < 0)
				min_idx = j;*/
		}

		// Swap the found minimum element with the first element
		
		/*char* temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;*/
		
		swap(&arr[min_idx], &arr[i]);
	}
}