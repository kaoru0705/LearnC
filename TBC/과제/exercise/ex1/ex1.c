/////////////////////////////////////
// ���� �����
// ��������
// �й�: 202534-361442
// �̸�: ������
/////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>   // sqrt(), pow() ����� ���� �ʿ�

void calculator();

int main(void) {
    printf("=== ���� ���α׷� ===\n");
    printf("��� ������ ������: +  -  *  /  ^(����)  r(������)\n");
    printf("���� ����: 2 + 3 �Ǵ� 9 r\n\n");
    while (1) {
        calculator();
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

void calculator() {
    
    double num1, num2, result;
    char operator;

    printf("��� �Է�: ");
    scanf("%lf", &num1);

    scanf(" %c", &operator); // ���� ���� ����

    if (operator == 'r') {
        if (num1 < 0) {
            printf("������ �������� ����� �� �����ϴ�.\n");
            return;
        }
        result = sqrt(num1);
        printf("%.2lf�� ������ = %.2lf\n", num1, result);
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
            printf("0���� ���� �� �����ϴ�.\n");
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
        printf("�������� �ʴ� �������Դϴ�.\n");
        break;
    }
}