/* 중요한 프로젝트는 책꽂이를 해라*/
/* else와 if의 짝짓기 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int number;
	scanf("%d", &number);

	/*if (number == 1)
		printf("One");
	else if (number == 2)
		printf("Two");
	else if (number == 3)
		printf("Three");*/

	//if (number == 1)
	//	printf("One");
	//else
	//	if (number == 2)
	//		printf("Two");
	//	else
	//		if (number == 3)
	//			printf("Three"); // Indenting 보통 이렇게는 안 쓴다. 
	
	// minimum 127 levels of nestings else if를 최소 127개는 보장해준다. 근데 교수님은 10개 이상도 잘 안 쓴다고 함

	/*if (number > 5)
	{
		if (number < 10)
			printf("Larger than 5 smaller than 10\n");
		else
			printf("Larger than or equal to 10\n");
	}
	else
		printf("Less than or equal to 5");*/

	// Compilers ignore indenting
	// else는 indenting과 상관없이 가까이에 있는 if에 붙는다. 헷갈릴 여지가 있는 경우는 중괄호를 쳐라
	
	
	//if (number > 5)
	//	if (number < 10)
	//		printf("Larger than 5 smaller than 10\n");
	//else
	//	printf("Less than or equal to 5"); // 이건 낚시다. compiler가 알아서 indenting해서 두 번째 if에 맞춘다.

	

	return 0;
}