/* for is flexible */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/*
		for(initialize; test; update)
			statement
	*/

	/*for (int i = 10; i > 0; i--)
		printf("%d ", i);*/

	/*for (int i = 0; i < 100; i = i + 8)
		printf("%d ", i);*/

	/*for (char c = 'A'; c <= 'Z'; c++)
		printf("%c ", c);*/

	/*for (int i = 0; i * i < 10; i++)
		printf("%d ", i);*/

	for (int x = 1, y = 5; y <= 20; y = (++x * 3) + 10)	//���� �ٸ� �ڷ����� �ȵ� int x = 1, char y = 5; �ǰڳ�?
		printf("%d ", x);

	//for (double d = 100.0; d < 300.0; d = d * 1.1)	// approximity math.h 6.4
	//	printf("%f\n", d);

	//int i, n;
	//n = 2;
	//for (i = 2; n < 10; /* left blank */)
	//{
	//	n = n * i;
	//	printf("%d\n", n);
	//}

	//for (;;)	// while(1)
	//	printf("I love you! ");

	//int i = 0;
	//for (printf("Let's go!\n"); i != 7; scanf("%d", &i)) // �̰� ���� ���ϴ�. �̷� Ʈ���� �� ���� �� ����. �ڵ忡�� �ⱳ �θ��� ����. �� �Ƿ��� �˰��򿡼� ���´�.
	//	;// null statement

	return 0;
}