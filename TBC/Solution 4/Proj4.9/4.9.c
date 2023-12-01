//printf()�Լ��� arguments(����)�� �ؼ��ϴ� ����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// printf ����(argument)�� �����̶�� �ٸ� �޸𸮰������� ���簡 �ȴ�. float���ڴ� double �� ��ȯ
// conversion specifier�� �ؼ�(interpret)�ϴ� ��ɿ� �����. ����� ��� ���� �ؼ��ϴ� �������� 8byte¥���� 4byte��ŭ �ؼ��ؼ� ����
int main()
{
	float	n1 = 1.5f;	// 4 bytes
	double	n2 = 1.5;	// 8 bytes
	int		n3 = 1024;	// 4 bytes

	printf("%f %f %d\n\n", n1, n2, n3); //printf�� ����ϱ� ���ؼ� ���ڵ��� �Ϸķ� �����Ǵ� ������ ��򰡿� ����ȴ�.

	//Note the warnings in output window	
	printf("%d %d %d\n\n", 1.5f, 1.5, n3);		// 4, 4, 4 (N, N, N) ���ÿ��� 8����Ʈ�� 4����Ʈ�� ������ ��â ����.
	printf("%lld %lld %d\n\n", n1, n2, n3);	// 8, 8, 4 (N, N, Y)
	// �´µ� �ε��Ҽ��� ������� ����� �����͸� ������ integer�� ��ȯ�ؼ� �ؼ��Ϸ� �ϴ� �̻��� ���ڰ� ���� type�� �� �¾Ƽ�
	// 1.5 float -> double 0 011 1111 1111 1��51�� = 4609434218613702656 -> float�� float���� 4����Ʈ 0�� ���� �Ÿ�? 1.5�� ���ʿ� �ȳ�������?
	// float������ ���� �־ ���������δ� double�� ����ȯ
	printf("%f %d %d\n\n", n1, n2, n3);		// 8, 4, 4 (Y, N, N)
	printf("%f %lld %d\n\n", n1, n2, n3);	// 8, 8, 4 (Y, N, Y)  type�� �� �¾Ƽ�

	return 0;
}