static unsigned int next = 1;	// next�� ������ ���⼭�� ���ڴ� �ۿ����� �ǵ帮�� ���� my_srand ���� �Լ��θ� �ٲ� �� �ְ� ���� �����ؼ� �� �� ���� ���ƹ����� ��� �� 

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