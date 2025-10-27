/////////////////////////////////////
// ¿Âµµ º¯È¯±â
// °­¿ø´ëÇÐ
// ÇÐ¹ø: 202534-361442
// ÀÌ¸§: °­µ¿ÈÆ
/////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void convertTemperature();

int main(void) {
    printf("=== ¿Âµµ º¯È¯±â ÇÁ·Î±×·¥ ===\n");
    printf("1. ¼·¾¾ ¡æ È­¾¾\n");
    printf("2. ¼·¾¾ ¡æ ÄÌºó\n");
    printf("3. È­¾¾ ¡æ ¼·¾¾\n");
    printf("4. È­¾¾ ¡æ ÄÌºó\n");
    printf("5. ÄÌºó ¡æ ¼·¾¾\n");
    printf("6. ÄÌºó ¡æ È­¾¾\n");
    printf("=============================\n");
    while (1) {
        convertTemperature();
        while (getchar() != '\n') continue;
        printf("ÇÁ·Î±×·¥ °è¼ÓÇÏ½Ã·Á¸é ¾Æ¹« Å°³ª ÀÔ·ÂÇÏ¼¼¿ä.\n");
        printf("ÇÁ·Î±×·¥ Á¾·á: 0 ÀÔ·Â\n");
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

    printf("¿øÇÏ´Â º¯È¯ ¹øÈ£¸¦ ¼±ÅÃÇÏ¼¼¿ä: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 6) {
        printf("º¯È¯ÇÒ ¿Âµµ¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
        scanf("%lf", &temp);
    }
    else {
        printf("Àß¸øµÈ ¼±ÅÃÀÔ´Ï´Ù.\n");
        return;
    }

    // ¼·¾¾ °ü·Ã
    if (choice == 1) {
        // ¼·¾¾ ¡æ È­¾¾
        result = temp * 9 / 5 + 32;
        printf("%.2lf C = %.2lf F\n", temp, result);
    }
    else if (choice == 2) {
        // ¼·¾¾ ¡æ ÄÌºó
        result = temp + 273.15;
        printf("%.2lf C = %.2lf K\n", temp, result);
    }
    // È­¾¾ °ü·Ã
    else if (choice == 3) {
        // È­¾¾ ¡æ ¼·¾¾
        result = (temp - 32) * 5 / 9;
        printf("%.2lf F = %.2lf C\n", temp, result);
    }
    else if (choice == 4) {
        // È­¾¾ ¡æ ÄÌºó
        result = (temp - 32) * 5 / 9 + 273.15;
        printf("%.2lf F = %.2lf K\n", temp, result);
    }
    // ÄÌºó °ü·Ã
    else if (choice == 5) {
        // ÄÌºó ¡æ ¼·¾¾
        result = temp - 273.15;
        printf("%.2lf K = %.2lf C\n", temp, result);
    }
    else if (choice == 6) {
        // ÄÌºó ¡æ È­¾¾
        result = (temp - 273.15) * 9 / 5 + 32;
        printf("%.2lf K = %.2lf F\n", temp, result);
    }
    else {
        printf("Àß¸øµÈ ¼±ÅÃÀÔ´Ï´Ù.\n");
    }
}