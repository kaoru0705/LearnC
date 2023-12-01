/* 중요한 프로젝트는 책꽂이를 해라*/
/* Selection Sort 선택정렬 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/* 실물에서는 라이브러리를 쓰니 평생 한 번만 함 */
/*
	https://www.geeksforgeeks.org/selection-sort/

	Youtube search "Selection Sort", "CS50
*/

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(int);

	printArray(arr, n);

	selectionSort(arr, n);	// ascending order

	printArray(arr, n);

	return 0;
}
/* My answers */
//void selectionSort(int arr[], int n)
//{
//	int min_idx = 0;
//	for (int i = 0; i < n - 1; i++)
//	{
//		min_idx = i;
//
//		for (int j = min_idx + 1; j < n; j++)
//		{
//			if (arr[min_idx] > arr[j])
//				min_idx = j;
//		}
//		swap(&arr[i], &arr[min_idx]);
//	}
//
//}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	//One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)	//Note n - 1
	{
		// Find the minimum element in unsorted array
		//TODO: fill blanks(s)
		min_idx = i;

		for (j = i + 1; j < n; j++)	//Note i + 1
		{
			//TODO: fill blanks(s)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}

		// Swap the found minimum element with the first element
		//TODO: fill blanks(s)
		swap(&arr[min_idx], &arr[i]);
	}
}

/* My answers == Professor */
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
