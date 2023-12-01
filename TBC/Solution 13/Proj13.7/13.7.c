/* ��Ÿ ����� �Լ��� ungetc(), fflush(), setvbuf() */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	ungetc() https://modoocode.com/49
	ǥ�� �Է� ���۸� �鿩�� ���鼭 �����ϴ� ���
	https://www.youtube.com/watch?v=-23JdCHXuVc&list=PLNfg4W25Tapyl6ahul_8VS_8Tx3_egcTI&index=29
*/
int main()
{
	FILE* fp;
	int ch;

	/* ungetc() */ // getc() �Ųٷ� �� �� ���� �а� �� ���ڸ� ���ۿ� ����
	fp = fopen("input.txt", "r");

	ch = fgetc(fp);
	printf("%u\n", ftell(fp));
	fputc(ch, stdout); // _Placeholder = 0x0128c079
	printf("\n%u\n", ftell(fp));
	ungetc((int)'A', fp);		// ���ۿ� ch�� �־���� try another characters ungetc((int)'A', fp); 'H'�� �о���δ��� ���ۿ��� ������ ���ڸ�(��Ʈ���� ���������� ���ڰ� �о�鿩���� �ڸ���)���� 'A'�� �� ���� ��ġ ǥ���ڰ� �����Ͽ� ���� ��ġ�� ����Ű�� �Ѵ�. �׷��� 'A'�� ���� ���� ����ϰ� 'e'�� ���� ���� ����ϰ�

	printf("%u\n", ftell(fp));

	ch = fgetc(fp);		// ���ۿ� ch�� ���������� ����  _Placeholder = 0x0128c078
	fputc(ch, stdout);	// _Placeholder = 0x0128c079

	ch = fgetc(fp);
	fputc(ch, stdout);	// _Placeholder = 0x0128c07a

	fclose(fp);

	/* setvbuf() */ // ���Լ��� ��Ȯ�ϰ� �����ϴ� ���� �⺻ ���Ǹ� ���  ���ݱ����� ���Ǵ� ���۸� ������ ������ ���� ����

	//// change the settings of buffer setvbuf ���ۿ� ä���ִ� �Լ��� �ƴ϶� ���۸� ����� �������ִ� �Լ�
	//fp = fopen("input.txt", "r");

	//char buffer[32] = { '\0', }; // setvbuf() use this array as a buffer
	//setvbuf(fp, buffer, _IOFBF, sizeof(buffer)); // _IOLBF (Line �ϳ��� ���ۿ� ������ ���� read�� �� ������ �����), _IOFBF (FULL buffer) , _IONBF �̰� �Ẹ�� (N no)
	//for (int i = 0; i < sizeof(buffer); ++i)
	//	printf("%hhd", buffer[i]); // null ���
	//printf("\n");

	//ch = fgetc(fp); // Read just only a single character �и��� �� ���ڸ� �о��µ�? ���۰� �� á��
	//// ���۶�� ���� �� ���α׷��� ������ ������ ��� ���� ������ ����Ǹ� �̸� ���ۿ� �־� ���´�. ���Ͽ��� ���� ���� �ͺ��� ���ۿ��� ���� ���� �ξ� ������. �״����� fget() ���� �� �̿��ϸ� ���۷κ��� �� ���ڸ� �������ų� ���� ���ڸ� ���� ���� �� ���� ������ �̸� ä��
	//
	//// dump buffer
	//for (int i = 0; i < sizeof(buffer); ++i)
	//	printf("%c", buffer[i]);
	//printf("\n");

	//fclose(fp);


	/* fflush() */

	//// flush ���� Writing a large amount of data ���ۿ� �׿��ִ� �����͸� �� ���������� �ǹ������� ���� ���� �� ���� �ִ�.
	//// ex) wrting�� �����Ͱ� �ʹ� ���Ƽ� writing�϶�� ����� �����µ� ���α׷��� OS�� ���� ���ϴ� ���忡�� ���ۿ� �ִ� �����͸� ��ó �����̳� ���÷��̳� ��Ʈ������ �Ϻ��ϰ� ����� �� �ϴ� ��찡 ���� �� �ִ�.
	//// �׶� �ݵ�� �� ����ض� buffer�� �� ������. �̰Ŵ�.
	//fflush(fp);

	return 0;
}