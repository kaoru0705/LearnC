/////////////////////////////////////
// 성적 등급 판정
// 강원대학
// 학번: 202534-361442
// 이름: 강동훈
/////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printGrade(double score);

int main(void) {
    double score;

    printf("=== 성적 등급 판정 프로그램 ===\n");
    while (1) {
        printf("점수를 입력하세요 (0 ~ 100): ");
        scanf("%lf", &score);

        // 점수 범위 검증
        if (score < 0.0 || score > 100.0) {
            printf("잘못된 점수입니다. 0 ~ 100 사이의 값을 입력하세요.\n");
            while (getchar() != '\n') continue;
            continue;
        }

        printGrade(score);
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

void printGrade(double score) {
    printf("당신의 성적: ");

    if (score >= 97.5)
        printf("A+ (합격)\n");
    else if (score >= 95)
        printf("A (합격)\n");
    else if (score >= 90)
        printf("A- (합격)\n");
    else if (score >= 87.5)
        printf("B+ (합격)\n");
    else if (score >= 85)
        printf("B (합격)\n");
    else if (score >= 80)
        printf("B- (합격)\n");
    else if (score >= 77.5)
        printf("C+ (합격)\n");
    else if (score >= 75)
        printf("C (합격)\n");
    else if (score >= 70)
        printf("C- (합격)\n");
    else if (score >= 67.5)
        printf("D+ (합격)\n");
    else if (score >= 65)
        printf("D (합격)\n");
    else if (score >= 60)
        printf("D- (합격)\n");
    else
        printf("F (불합격)\n");
}