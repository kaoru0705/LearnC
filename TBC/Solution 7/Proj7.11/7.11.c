/* 중요한 프로젝트는 책꽂이를 해라 */
/* 최대, 최소, 평균 구하기 예제 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <float.h>

int main()
{
	float max = -FLT_MAX;
	float min = FLT_MAX;
	float sum = 0.0f;
	float input;
	int n = 0;

	while (scanf("%f", &input) == 1)
	{
		if (input < 0.0f || input > 100.0f)
			continue;

		max = (input > max) ? input : max;
		min = (input < min) ? input : min;
		sum += input;

		//TODO: ignore negative values

		n++;	// Count number of inputs
	}

	if (n > 0)
		printf("min = %f, max = %f, ave = %f\n", min, max, sum / n);
	else
		printf("No input\n");


	return 0;
}