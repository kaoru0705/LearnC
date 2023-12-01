/* 제논의 역설 시뮬레이션 예제 */
// 아킬레우스와 거북이의 경주 무한등비급수
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/*
		Simulation of a Moving Object
		
		- Speed = 1.0 m/s
		- dt = 1.0 s
		- Distance traveled during dt = Speed * dt
		
		- Step 1 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m
		- Step 2 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m + 1.0m = 2.0 m
		- Step 3 : 1.0 m/s * 1.0 s = 1.0 m, dist = 2.0 m + 1.0m = 3.0 m
		- ... ...
	*/
	/* my poor answer
	for (double time = 1.0, dt = 0.0; time <= 10.0; dt = time * 1.0)
	{
		printf("Elapsed time = %.10fs, ", time);
		printf("Distance = %.10fm\n", dt);
		time += 1.0;
	}*/

	const double speed = 1.0;
	const unsigned repeat_max = 10;

	double dt = 1.0;		// delta t
	double time = 0.0;		// Elapsed time Elapse 흐르다 경과하다 
	double dist = 0.0;		// Distance

	for (unsigned i = 0; i < repeat_max; i++)
	{
		dist += speed * dt; // dst = dist + speed * dt;
		time += dt;

		printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, dist);

	}
	/*
		Zeno's Paradox
		
		- Step 1 : 1.0 * 1.0 = 1.0, 1.0
		- Step 2 : 1.0 * 0.5 = 0.5, 1.0 + 0.5 = 1.5
		- Step 3 : 1.0 * 0.25 = 0.25, 1.5 + 0.25 = 1.75
		... ...	
	*/
	dt = 1.0;		// delta t
	time = 0.0;		// Elapsed time
	dist = 0.0;		// Distance

	for (unsigned i = 0; i < repeat_max; i++)
	{
		dist += speed * dt;
		time += dt;

		printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, dist);

		dt *= 0.1; // dt /= 2.0; 곱하기가 나누기보다 빠르다.
	}

	//Note: infinite geometric series 무한등비급수

	return 0;
}