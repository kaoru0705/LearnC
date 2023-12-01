/* scanf() 함수의 기본적인 사용법 */

//#define _CRT_SECURE_NO_WARNINGS // define macro
//project right click -  properties에서 바꿀 수도 있다. preprocessor부분에 자료구조 알고리즘을 배우게 되면 Configuration Release 모드까지 해야 된다.
//microsoft visual studio에서만 붙임
//주로 project setting에서 바꾸는 것을 권장
#include <stdio.h>

int main() 
{
	int i = 0;

	scanf("%d", &i);// & : ampersand scan formatted 어떻게 입력받을지 formatting 하고 있음
	//&변수의 주소를 넘겨줘서 사용자가 콘솔창에 입력한 값을 해당 주소 메모리 값에 덮어씀(사실 c언어에서 변수 자체를 넘겨주는것은 없음)
	// scanf의 몸체가 변수 i에 직접 접근할 수가 없다. 그래서 주소를 넘김 알지?
	// (scanf가 다른 주소의 값까지 바꿀까 봐 해킹으로 window는 권장하지 않음)
	// 왜 이렇게 하는가? c 문법에서는 함수의 출력은 하나밖에 안된다. scanf는 여러 개의 입력을 받고 값을 바꿀 수 있음 출력으론 불가능
	// c언어가 나왔을 당시에는 당연한 것이었음
	// scanf에 입력했을 때 printf 전에 이미 값은 바뀌어 있다. 안되는 경우는 나중에 알려주겠다.

	printf("Value is %d\n", i);//print formatted 출력을 어떻게 할지 formatting하고 있음

	return 0;
}