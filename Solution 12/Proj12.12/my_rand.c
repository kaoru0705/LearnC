static unsigned int next = 1;	// next란 변수는 여기서만 쓰겠다 밖에서는 건드리지 마라 my_srand 같은 함수로만 바꿀 수 있고 직접 접근해서 쓸 수 없게 막아버려라 라는 뜻 

int my_rand()
{
	next = next * 1103515245 + 1234;
	next = (unsigned int)(next / 65536) % 32768;

	return next;
}

void my_srand(unsigned int seed)
{
	next = seed;
}