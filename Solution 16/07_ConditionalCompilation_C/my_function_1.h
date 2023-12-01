//#pragma once
#ifndef MY_FUNCTION_1
#define MY_FUNCTION_1

#include <stdio.h>

static void my_function() // static 이기에 .h 파일에서 정의할 수 있다 16.6 ref
{  
    printf("my_function_1.h");
}

#endif
