/* printf()�� �⺻���� ���� */
#include <stdio.h> //#���� ���� = preprocessor = ���α׷��� ������ ���� �ƴϰ� �������ϱ� ���� ����
// linker�� ���߿� printf�� ������ ������ �κ��� ���ļ� exe���Ͽ� �־��ش�.

int main() 
{
/*	//print formatted ������ �����.
	printf("\"\'The truth\' is ... \nI am Ironman.\"\n");
	//\n escape sequence �����Ϸ��� �ѱ��� �ѱ��� �о�ٰ� \�� ������ ��� �����ϸ� \n �ϳ��� ���ڷ� �ν��Ѵ�. �帧�� ����� escape sequence
	//What's printf's output? see you later �Լ��μ��� �����?
*/
	int x = 1, y = 2, z;
	z = x + y;

	printf("The answer is %i", z); // i is integer d is decimal
	printf("\a");//����� alarm �Ҹ��� ���� �͵� ���
	
	return 0;
}