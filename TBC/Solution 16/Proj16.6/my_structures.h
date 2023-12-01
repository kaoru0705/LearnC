//#pragma once  // 헤더가드
/*
    헤더가드가 없는 경우의 중복 include 예시
    - A.h를 B.h가 include 하고 main.c 에서 A.h와 B.h를 모두 include 한다면 main.c 에서는 A.h가 B.h를 통해서 한 번 더 include 되는 형태가 된다
    - header guard 는 include guard 라고도 불린다
    - 자기 스스로를 include 하는 경우도 방지할 수 있다(재귀처럼 반복해서 스스로를 include 하므로 VS에서는 경고 includes itself
    컴파일러에서는 fatal error C1014: too many include files: depth = 1024
 */

 // 헤더가드가 표준이 되기 전에 쓰이던 방식: #ifndef, #define, #endif 조합
#ifndef __MY_FUNCTIONS__
#define __MY_FUNCTIONS__

typedef struct {
    char name[100];
    int age;
} patient_info;

#endif