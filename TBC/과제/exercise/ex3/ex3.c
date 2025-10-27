/////////////////////////////////////
// ���� ��� ����
// ��������
// �й�: 202534-361442
// �̸�: ������
/////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printGrade(double score);

int main(void) {
    double score;

    printf("=== ���� ��� ���� ���α׷� ===\n");
    while (1) {
        printf("������ �Է��ϼ��� (0 ~ 100): ");
        scanf("%lf", &score);

        // ���� ���� ����
        if (score < 0.0 || score > 100.0) {
            printf("�߸��� �����Դϴ�. 0 ~ 100 ������ ���� �Է��ϼ���.\n");
            while (getchar() != '\n') continue;
            continue;
        }

        printGrade(score);
        while (getchar() != '\n') continue;
        printf("���α׷� ����Ͻ÷��� �ƹ� Ű�� �Է��ϼ���.\n");
        printf("���α׷� ����: 0 �Է�\n");
        char command;
        scanf("%c", &command);
        if (command == '0') break;
        while (getchar() != '\n') continue;
    }

    return 0;
}

void printGrade(double score) {
    printf("����� ����: ");

    if (score >= 97.5)
        printf("A+ (�հ�)\n");
    else if (score >= 95)
        printf("A (�հ�)\n");
    else if (score >= 90)
        printf("A- (�հ�)\n");
    else if (score >= 87.5)
        printf("B+ (�հ�)\n");
    else if (score >= 85)
        printf("B (�հ�)\n");
    else if (score >= 80)
        printf("B- (�հ�)\n");
    else if (score >= 77.5)
        printf("C+ (�հ�)\n");
    else if (score >= 75)
        printf("C (�հ�)\n");
    else if (score >= 70)
        printf("C- (�հ�)\n");
    else if (score >= 67.5)
        printf("D+ (�հ�)\n");
    else if (score >= 65)
        printf("D (�հ�)\n");
    else if (score >= 60)
        printf("D- (�հ�)\n");
    else
        printf("F (���հ�)\n");
}