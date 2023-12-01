/* RGBA ���� ��Ʈ ����ũ ��������  */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
/* https://www.websitecodetutorials.com/code/css/master-hex-to-rgba-color-chart.php */
#define BYTE_MASK 0xff

int main(void)
{
	unsigned int rgba_color = 0x66CDAAFF; // �����̳ʳ� �������ڰ� ���� ���� �� ��� rgb�� �� ���� ����.
	// 4 bytes, medium aqua marine	(102, 205, 170, 255) (r, g, b, a)

	unsigned char red, green, blue, alpha; // �̷��� ���� ���� �����ؼ� �ٷ�� ���� ����. ����ó�� ��� ��

	//Use right shift >> operator
	alpha = rgba_color & BYTE_MASK;	// ���� ���¼ҽ��� ���̴� ����
	blue = (rgba_color >> 8 & BYTE_MASK);
	green = (rgba_color >> 16 & BYTE_MASK);
	red = (rgba_color >> 24 & BYTE_MASK);

	printf("(R, G, B, A) = (%hhu, %hhu, %hhu, %hhu)\n",
		red, green, blue, alpha);

	return 0;
}