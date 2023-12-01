/* inline 함수(작은 함수가 여러 차례 반복적으로 사용될 때 실행속도를 빠르게 끌어올릴 수 있는 함수) */
#include <stdio.h>

/*
    Function call has overhead(함수를 호출할 때는 함수가 실제로 수행하는 업무 외에 추가적으로 더 붙는 일들이 있다.)
    - set up the call(호출 준비), pass arguments(call by value가 기본. argument를 보내주면 복사를 하게 됨. 포인터를 보내주더라도 주소값을 복사한다), jump to the function code(함수는 코드가 남아있고 extern linkage같은 경우는 여러 파일 여러 translation unit에서 함수를 접근해서 함수코드를 가져다가 실행하는 구조), and return
    이런 오버헤드를 없앨 수 있는 첫 번째 방법이 매크로였다. 코드를 복사 붙여넣기하면 함수가 만들어지는 게 아니라 기능만 수행함 함수 호출 오버헤드가 없음
    그것 보다는 
    inline function specifier
    - Suggests inline replacements(컴파일러에게 제안하는 것. 따라서 컴파일러가 꼭 따를 필요는 없다)
    - inline functions should be short(기능이 큰 함수에는 인라인을 적용하지 않는 게 일반적이다. 오버헤드가 기능이 수행하는 거에 비해 무시할만 하기 때문)
    - A function with internal linkage can be made inline (GCC, clang) inline함수는 internal linkage인 게 일반적이어야 한다. VS는 다 됨
    - You can't take its address 말그대로 in line. 코드에다 복사 붙여넣기 해주는 게 기본 원리(프로그래머가 함수 콜 오버헤드를 거치지 않는 것을 기대). 그러므로 다른 함수들과 달리 주소를 못 가져옴
    function pointer같은 경우는 메모리 어딘가에 function이 자리를 잡고 있어서다.
*/

//inline static int foo() {  // GCC, clang /* https://www.onlinegdb.com/online_c_compiler */
inline int foo()
{
    return 5;
}

// Driver code
int main(void)
{
    int ret;

    // inline function call
    // [Properites]-[C/C++]-[All Options]에서 (기본은 default) inline 상태를 Disabled로 바꾼 후 breaking point를 찍고 'alt + 8' 을 눌러서 어셈블리 확인해보기. 끝난 후에는 Only _inline으로 돌려놓기(Any suitable 은 우리가 inline으로 안 해도 컴파일러가 알아서 판단해서 인라인으로 해석하는 기능)
    ret = foo();  // inline 이 적용된 경우 ret = 5; 와 어셈블리가 같다.

    printf("Output is : %d\n", ret);
    return 0;
}
/*
 disabled 시 call foo 확인 가능
 only inline 시 call foo가 없음 난 해도 있다. 결국 inline은 강제할 수 있는 게 아니다. /* https://learn.microsoft.com/en-us/cpp/build/reference/ob-inline-function-expansion?view=msvc-170 */