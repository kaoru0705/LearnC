/////////////////////////////////////
// �µ� ��ȯ��
// ��������
// �й�: 202534-361442
// �̸�: ������
/////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void convertTemperature();

int main(void) {
    printf("=== �µ� ��ȯ�� ���α׷� ===\n");
    printf("1. ���� �� ȭ��\n");
    printf("2. ���� �� �̺�\n");
    printf("3. ȭ�� �� ����\n");
    printf("4. ȭ�� �� �̺�\n");
    printf("5. �̺� �� ����\n");
    printf("6. �̺� �� ȭ��\n");
    printf("=============================\n");
    while (1) {
        convertTemperature();
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

void convertTemperature() {
    double temp, result;
    int choice;

    printf("���ϴ� ��ȯ ��ȣ�� �����ϼ���: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 6) {
        printf("��ȯ�� �µ��� �Է��ϼ���: ");
        scanf("%lf", &temp);
    }
    else {
        printf("�߸��� �����Դϴ�.\n");
        return;
    }

    // ���� ����
    if (choice == 1) {
        // ���� �� ȭ��
        result = temp * 9 / 5 + 32;
        printf("%.2lf C = %.2lf F\n", temp, result);
    }
    else if (choice == 2) {
        // ���� �� �̺�
        result = temp + 273.15;
        printf("%.2lf C = %.2lf K\n", temp, result);
    }
    // ȭ�� ����
    else if (choice == 3) {
        // ȭ�� �� ����
        result = (temp - 32) * 5 / 9;
        printf("%.2lf F = %.2lf C\n", temp, result);
    }
    else if (choice == 4) {
        // ȭ�� �� �̺�
        result = (temp - 32) * 5 / 9 + 273.15;
        printf("%.2lf F = %.2lf K\n", temp, result);
    }
    // �̺� ����
    else if (choice == 5) {
        // �̺� �� ����
        result = temp - 273.15;
        printf("%.2lf K = %.2lf C\n", temp, result);
    }
    else if (choice == 6) {
        // �̺� �� ȭ��
        result = (temp - 273.15) * 9 / 5 + 32;
        printf("%.2lf K = %.2lf F\n", temp, result);
    }
    else {
        printf("�߸��� �����Դϴ�.\n");
    }
}