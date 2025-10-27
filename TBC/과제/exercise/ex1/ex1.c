/////////////////////////////////////
// 계산기 만들기
// 강원대학
// 학번: 202534-361442
// 이름: 강동훈
/////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>   // sqrt(), pow() 사용을 위해 필요

void calculator();

int main(void) {
    printf("=== 계산기 프로그램 ===\n");
    printf("사용 가능한 연산자: +  -  *  /  ^(제곱)  r(제곱근)\n");
    printf("형식 예시: 2 + 3 또는 9 r\n\n");
    while (1) {
        calculator();
        while (getchar() != '\n') continue;
        printf("프로그램 계속하시려면 아무 키나 입력하세요.\n");
        printf("프로그램 종료: 0 입력\n");
        char command;
        scanf("%c", &command);
        if (command == '0') break;
        while (getchar() != '\n') continue;
    }
    return 0;
}

void calculator() {
    
    double num1, num2, result;
    char operator;

    printf("계산 입력: ");
    scanf("%lf", &num1);

    scanf(" %c", &operator); // 공백 엔터 무시

    if (operator == 'r') {
        if (num1 < 0) {
            printf("음수의 제곱근은 계산할 수 없습니다.\n");
            return;
        }
        result = sqrt(num1);
        printf("%.2lf의 제곱근 = %.2lf\n", num1, result);
        return;
    }

    scanf("%lf", &num2);

    switch (operator) {
    case '+':
        result = num1 + num2;
        printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
        break;

    case '-':
        result = num1 - num2;
        printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
        break;

    case '*':
        result = num1 * num2;
        printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
        break;

    case '/':
        if (num2 == 0) {
            printf("0으로 나눌 수 없습니다.\n");
            break;
        }
        result = num1 / num2;
        printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
        break;

    case '^':
        result = pow(num1, num2);
        printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
        break;

    default:
        printf("지원하지 않는 연산자입니다.\n");
        break;
    }
}