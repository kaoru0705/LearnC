/* printf()의 기본적인 사용법 */
#include <stdio.h> //#으로 시작 = preprocessor = 프로그램이 시작할 때가 아니고 컴파일하기 전에 동작
// linker가 나중에 printf가 실제로 구현된 부분을 합쳐서 exe파일에 넣어준다.

int main() 
{
/*	//print formatted 형식을 맞춘다.
	printf("\"\'The truth\' is ... \nI am Ironman.\"\n");
	//\n escape sequence 컴파일러가 한글자 한글자 읽어가다가 \를 만나고 잠깐 멈짓하며 \n 하나의 글자로 인식한다. 흐름을 벗어나서 escape sequence
	//What's printf's output? see you later 함수로서의 출력은?
*/
	int x = 1, y = 2, z;
	z = x + y;

	printf("The answer is %i", z); // i is integer d is decimal
	printf("\a");//경고음 alarm 소리를 내는 것도 출력
	
	return 0;
}