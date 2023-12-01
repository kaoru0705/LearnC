/* 중요한 프로젝트는 책꽂이를 해라*/
/* Loop 도우미 continue & break */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/* continue */
	//for (int i = 0; i < 10; ++i)
	//{
	//	if (i == 5)
	//		continue;

	//	printf("%d ", i);

	//	/*if (i != 5)
	//		printf("%d ", i);*/	// continue는 없다고 해서 구현을 못 하는 일은 많지 않다.
	// // 문맥차이 허나 5는 넘기겠다와 5가 아닐 때만 출력하겠다는 뉘앙스가 다르다. continue가 직관적임 쉽게 받아 들일 수 있음
	// // 알고리즘이 복잡하거나 어려운 거 옛날부터 배워온 물리법칙 수학공식 것의 일반적인 형태에 부합하는 알고리즘을 짤 때는
	// // 흐름을 직관적으로 유지가능 보조적인 수단
	//}

	/* break */
	/*for (int i = 0; i < 10; ++i)
	{
		if (i == 5)
			break;

		printf("%d ", i);
	}*/

	/* while and continue */
	/*int count = 0;
	while (count < 5)
	{
		int c = getchar();
		if (c == 'a')
			continue;
		putchar(c);
		count++;
	}*/

	/* for and continue */
	/*for (int count = 0; count < 10; ++count)
	{
		int c = getchar();
		if (c == 'a')
			continue;
		putchar(c);
	}*/

	/* continue as a placeholder */
	//while (getchar() != '\n')
	//	continue;	// continue; = ;
	//// placeholder 하는 건 없는데 자리를 차지하고 여기에 뭔가 들어갈 수 있다는 걸 보여줌
	//// 여러 곳에서 많이 쓰임
	//// 달랑 null statement ; 이거 적는 것보다 주의력을 확보 가능

	/* Need to use continue ? */
	//char c;
	//while ((c = getchar()) != '\n')
	//{	// 두 가지 관점
	//	//	//if (c != 'a')
	//	//	putchar(c);	// 이게 간결하긴 함
	//	if (c == 'a')	// 일반적으로는 출력을 하는데 수행하지 않을 조건을 걸러내기 위해서 continue를 쓴 거다
	//		// c == a일 경우에는 뒤에 부분을 수행하지 않는다라고 코드로서 표현하기 위해 쓴 거라고
	//		// 복잡하거나 기능을 추가할 게 있는 경우 a가 아니라 다른 글자에도 거르도록 업그레이드가 될 경우
	//		// continue를 사용하는 게 더 보기 좋다.
	//		// 실무에서 뭘 사용할지 고민이 된다.
	//		continue;
	//	putchar(c);
	//}

	/* break */

	/*char c;
	while ((c = getchar()) != '.')
	{
		putchar(c);
	}*/

	//while (1) // 위에도 잘 쓰지만 이렇게 구현하는 경우가 더 많다. 조건에 여러 가지 기능을 함께 수행해서 헷갈릴 가능성이 있다.
	//		// 한 곳에는 한 가지 기능만 하는 것이 요즘 추세 while문일 땐 이렇 패턴을 더 많이 씀
	//		// 무슨 일이 있으면 그만둬 이게 직관적으로 이해하기 더 쉽다.
	//{
	//	char c = getchar();

	//	if (c == '.')
	//		break;
	//	putchar(c);
	//}
	//// main loop game server while(1) break

	for (int i = 0; i < 10; i++) // one loop break;
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 5)
				break;

			printf("(%d %d)", i, j);
		}

		printf("\n");
	}
	return 0;
}