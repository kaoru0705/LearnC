//#pragma once  // �������
/*
    ������尡 ���� ����� �ߺ� include ����
    - A.h�� B.h�� include �ϰ� main.c ���� A.h�� B.h�� ��� include �Ѵٸ� main.c ������ A.h�� B.h�� ���ؼ� �� �� �� include �Ǵ� ���°� �ȴ�
    - header guard �� include guard ��� �Ҹ���
    - �ڱ� �����θ� include �ϴ� ��쵵 ������ �� �ִ�(���ó�� �ݺ��ؼ� �����θ� include �ϹǷ� VS������ ��� includes itself
    �����Ϸ������� fatal error C1014: too many include files: depth = 1024
 */

 // ������尡 ǥ���� �Ǳ� ���� ���̴� ���: #ifndef, #define, #endif ����
#ifndef __MY_FUNCTIONS__
#define __MY_FUNCTIONS__

typedef struct {
    char name[100];
    int age;
} patient_info;

#endif