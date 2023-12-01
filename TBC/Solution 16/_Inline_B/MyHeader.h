// 일반적으로 인라인 함수는 헤더파일에 모아 놓는다
#pragma once

#include <stdio.h>

inline static int hello()
{
    return 123;
}
