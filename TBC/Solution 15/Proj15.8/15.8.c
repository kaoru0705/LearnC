/* RGBA 색상 비트 마스크 연습문제  */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
/* https://www.websitecodetutorials.com/code/css/master-hex-to-rgba-color-chart.php */
#define BYTE_MASK 0xff

int main(void)
{
	unsigned int rgba_color = 0x66CDAAFF; // 디자이너나 웹개발자가 많이 보게 됨 사실 rgb를 더 많이 본다.
	// 4 bytes, medium aqua marine	(102, 205, 170, 255) (r, g, b, a)

	unsigned char red, green, blue, alpha; // 이렇게 따로 따로 저장해서 다루는 경우는 없다. 위에처럼 묶어서 씀

	//Use right shift >> operator
	alpha = rgba_color & BYTE_MASK;	// 종종 오픈소스에 보이는 패턴
	blue = (rgba_color >> 8 & BYTE_MASK);
	green = (rgba_color >> 16 & BYTE_MASK);
	red = (rgba_color >> 24 & BYTE_MASK);

	printf("(R, G, B, A) = (%hhu, %hhu, %hhu, %hhu)\n",
		red, green, blue, alpha);

	return 0;
}