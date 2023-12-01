/* 중요한 프로젝트는 책꽂이를 해라*/
/* 2차원 배열 연습문제 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MONTHS 12
#define YEARS 3

int main()
{
	double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
	double year2017[MONTHS] = { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
	double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };
	
	/*
	1. Use 2D array
	2. Print data
	3. Calculate and print yearly avaerage temperatures of 3 years
	4. Calculate and print monthly average temperatures for 3 years
	*/ //tests

	/*my answer*/
	
	//double* year1618[YEARS] = {year2016, year2017, year2018}; // 시발년아 2차원 배열이 아니잖아.

	//int i, j;
	//for (j = 0; j < YEARS; j++)
	//{
	//	for (i = 0; i < MONTHS; i++)
	//	{
	//		printf("%+.1f ", *(year1618[j] + i));
	//		//printf("%+.1f ", year1618[j][i]); // year1618[0] == year2016, *(year2016 + 1) == year2016[1]
	//	}
	//	printf("\n");
	//}
	

	double temp_data[YEARS][MONTHS] = {
		{ -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 },
		{ -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 },
		{ -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 }
	};
    printf("[Temperature Data]\n");
    printf("Year index : ");
    for (int m = 0; m < MONTHS; ++m) {
        printf("\t%d", m + 1);
    }
    printf("\n");

    for (int y = 0; y < YEARS; ++y) {
        printf("Year %d     : ", y);
        for (int m = 0; m < MONTHS; ++m) {
            printf("\t%.1f", temp_data[y][m]);
        }
        printf("\n");
    }
    printf("\n");

    printf("[Yearly average temperature of 3 years]\n");
    for (int y = 0; y < YEARS; ++y) {
        double avg_temp = 0.0;
        for (int m = 0; m < MONTHS; ++m) {
            avg_temp += temp_data[y][m];
        }
        avg_temp /= (double)MONTHS;
        printf("Year %d : average temperature = %.1f\n", y, avg_temp);
    }
    printf("\n");

    printf("[Monthly average temperature of 3 years]\n");
    printf("Year index\t:");
    for (int i = 0; i < MONTHS; ++i) {
        printf("\t%d", i + 1);
    }
    printf("\n");

    printf("Average temps  :  ");
    for (int m = 0; m < MONTHS; ++m) {
        double avg_temp = 0.0;
        for (int y = 0; y < YEARS; ++y) {
            avg_temp += temp_data[y][m];
        }
        avg_temp /= (double)YEARS;
        printf("\t%.1f", avg_temp);
    }

    printf("\n");

	return 0;
}