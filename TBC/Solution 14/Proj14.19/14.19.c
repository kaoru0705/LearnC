/* 열거형 연습문제 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>   // strcmp (HINT!)
#include <stdbool.h>  // C99

enum spectrum { red, orange, yellow, green, blue };
const char* colors[] = { "red", "orange", "yellow", "green", "blue" };

#define LEN 30

int main(void)
{
    char choice[LEN] = { 0, };
    enum spectrum color;
    bool color_is_found = false;
    /* My poor answers */
    /*while (1) //ENUM 자체를 모르는 새끼가 할 수 있는 코드 color를 쓰질 않았다.
    {
        printf("Input a color name (empty line to quit):\n");
        scanf("%[^\n]%*c", choice);
        if (strcmp(choice, colors[red]) == 0)
        {
            printf("Red roses\n");
            color_is_found = true;
        }
        else if (strcmp(choice, colors[orange]) == 0)
        {
            printf("Orange\n");
            color_is_found = true;
        }
        else if (strcmp(choice, colors[yellow]) == 0)
        {
            printf("Yellow\n");
            color_is_found = true;
        }
        else if (strcmp(choice, colors[green]) == 0)
        {
            printf("Green\n");
            color_is_found = true;
        }
        else if (strcmp(choice, colors[blue]) == 0)
        {
            printf("Blue\n");
            color_is_found = true;
        }
        else if (choice[0] == NULL)
        {
            printf("Goodbye!\n");
            break;
        }
        if (color_is_found == false)
            printf("Please try different color %s\n", choice);

        color_is_found = false;
        choice[0] = NULL;
    }*/

    while (1)
    {
        printf("Input a color name (empty line to quit)\n");

        if (scanf("%[^\n]%*c", choice) != 1) // \n만 입력하면 choice에 아무 것도 입력이 되지 않았으니 break된다.
            break;

        for (color = red; color <= blue; color++)
        {
            if (strcmp(choice, colors[color]) == 0)
            {
                color_is_found = true;
                break;
            }
        }


        if (color_is_found)
        {
            switch (color)
            {
            case red:
                puts("Red roses\n");
                break;
            case orange:
                puts("Oranges are delicious\n");
                break;
            case yellow:
                puts("Yellow sunflowers\n");
                break;
            case green:
                puts("Green apples\n");
                break;
            case blue:
                puts("Blue ocean\n");
                break;
            }
        }
        else
            printf("Please try different color %s.\n", choice);
        color_is_found = false;
    }
    puts("Goodbye!");

    return 0;
}