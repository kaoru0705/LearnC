#include "Turboc.h"

#define QS 1600
#define putchxy(x,y,ch) { gotoxy(x,y);_putch(ch); } // _putch() in conio.h cursor에 출력하고 출력한 문자를 반환함 

void InitStage(int stage);
BOOL MoveSnake();
void ProcessKey();
int getchcon(int x, int y);
void waitanykey();

typedef struct tag_Point {
    int x, y;
}tag_Point;

tag_Point snake[QS];
tag_Point now;
int head, tail;
int inctail;
typedef enum tag_Dir { LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 }tag_Dir;
tag_Dir dir;

int life;
int maxnumber;
int speed;
int multi;
int stage;

void main()
{
    int number;
    int ch;
    int x, y;

    life = 5;
    randomize();
    setcursortype(NOCURSOR);
    for (;;)
    {

        InitStage(stage);

        gotoxy(0, 23); printf("스테이지 : %d", stage + 1);

        gotoxy(20, 23); printf("남은 뱀 : %d", life);

        for (number = 0; number < maxnumber; number++)
        {
            gotoxy(40, 23); printf("남은 먹이 : %d ", maxnumber - number);
            gotoxy(60, 23); printf("꼬리 길이 : 2 ");
            // 공백인 자리에 새로운 숫자를 생성한다.
            do
            {

                x = random(80);
                y = random(22);
            } while (getchcon(x, y) != ' ');

            gotoxy(x, y); printf("%d", random(9) + 1);

            // 게임 시작 직후이면 잠시 대기하며 스테이지 조정 기회를 준다

            if (number == 0)
            {
                ch = _getch();  // _getch() buffer가 없음 입력한 키 그대로 입력됨 입력된 값을 콘솔창에 보여주지는 않음 _getche() 메아리 입력한 값도 같이 보여줌
                /* 0xE0 확장키 개념 : fn 과 같은 키를 확장키라고 합니다. 확장키로 입력 받았을 경우 한 번 더 입력을 받아야 합니다. 근데 확장키를 입력이 되지도 않는다.  */
                if (ch == 0xE0) 
                    _getch();
                else
                {
                    if (ch == 27) // esc
                    {
                        setcursortype(NORMALCURSOR);
                        exit(0);
                    }

                    if (tolower(ch) == 'n')
                    {
                        stage = (stage == 4 ? 0 : stage + 1);
                        break;
                    }

                    if (tolower(ch) == 'p')
                    {
                        stage = (stage == 0 ? 4 : stage - 1);
                        break;
                    }
                }
            }

            // 뱀 이동 루프
            if (MoveSnake() == TRUE)
            {
                if (--life == 0)
                {
                    gotoxy(12, 20);
                    puts("게임이 끝났습니다. 그만 놀고 열심히 공부하세요.");
                    return;
                }
                delay(1500);
                break;
            }
        }

        if (number == maxnumber)
        {
            gotoxy(12, 20);
            puts("축하합니다. 아무 키나 누르시면 다음 스테이지로 갑니다.");
            waitanykey();
            stage++;
        }
    }
}

// 스테이지 초기화
void InitStage(int stage)
{
    int i;

    clrscr();
    snake[0].x = 5; snake[0].y = 5;
    snake[1].x = 6; snake[1].y = 5;
    snake[2].x = 7; snake[2].y = 5;
    gotoxy(5, 5); puts("##S");
    head = 2;
    tail = 0;
    inctail = 0;
    now.x = 7;
    now.y = 5;
    dir = RIGHT;

    // 바깥의 벽을 그린다.
    for (i = 0; i < 80; i++)
    {
        putchxy(i, 0, 'M');
        putchxy(i, 22, 'M');
    }
    for (i = 0; i < 23; i++)
    {
        putchxy(0, i, 'M');
        putchxy(79, i, 'M');
    }

    // 스테이지별로 장애물을 적당히 그리고 난이도를 조절한다.
    switch (stage)
    {
    case 0:
        maxnumber = 5; speed = 150; multi = 3;
        for (i = 30; i <= 50; i++) { putchxy(i, 11, 'M'); }
        break;
    case 1:
        maxnumber = 10; speed = 100; multi = 5;
        for (i = 20; i <= 60; i++) { putchxy(i, 7, 'M'); putchxy(i, 14, 'M'); }
        break;
    case 2:
        maxnumber = 15; speed = 80; multi = 6;
        for (i = 20; i < 60; i++) { putchxy(i, 11, 'M'); }
        for (i = 6; i <= 16; i++) { putchxy(40, i, 'M'); }
        break;
    case 3:
        maxnumber = 20; speed = 60; multi = 7;
        for (i = 20; i < 60; i++)
        {

            if (i < 30 || i > 50)
            {
                putchxy(i, 7, 'M');
                putchxy(i, 14, 'M');
            }
        }
        for (i = 7; i < 15; i++) { putchxy(20, i, 'M'); putchxy(60, i, 'M'); }
        break;
    case 4:
        maxnumber = 1970; speed = 50; multi = 9;
        break;
    }
}

// 뱀을 이동시킨다. 죽었으면 TRUE를 리턴한다.
BOOL MoveSnake()
{
    int headch;
    int len;
    int prev;

    for (;;)
    {
        gotoxy(60, 23);
        len = head - tail; // IniStage() head = 2 tail = 0;
        if (len < 0) len += QS;
        printf("꼬리 길이 : %d ", len);
        ProcessKey();

        switch (dir)
        {
        case LEFT:
            now.x--;
            break;
        case RIGHT:
            now.x++;
            break;
        case UP:
            now.y--;
            break;
        case DOWN:
            now.y++;
            break;
        }

        // 머리 한칸 진행
        head = (head == QS - 1 ? 0 : head + 1);
        snake[head] = now;

        // 꼬리 한칸 진행. 단 늘어나고 있는 중이면 그 자리에 있는다.
        if (inctail == 0)   // 처음은 0
        {
            tail = (tail == QS - 1 ? 0 : tail + 1); // tail도 마찬가지로 배열 끝으로 갔으면 다시 리셋 

        }
        else
        {
            inctail--;
        }

        // 머리를 그리기 전에 머리 위치의 문자를 미리 읽어 놓아야 한다.
        headch = getchcon(now.x, now.y);
        putchxy(snake[head].x, snake[head].y, 'S'); 
        prev = (head == 0 ? QS - 1 : head - 1); // head == 0이라는 것은 head가 마지막 배열까지 가서 처음으로 돌아온 것 그전 값은 QS-1이라는 것
        putchxy(snake[prev].x, snake[prev].y, '#');
        prev = (tail == 0 ? QS - 1 : tail - 1); // head == 0와 마찬가지 tail-1 부분을 공백으로 바꿔줘야 한 칸 이동한 셈이 됨
        putchxy(snake[prev].x, snake[prev].y, ' ');

        // 현재 위치가 공백이 아니면 어딘가에 부딪힌 것임
        if (headch != ' ')
        {
            break;
        }
        delay(speed);
    }

    // 벽이나 자기 꼬리에 부딪쳤으면 죽은 것임
    if (headch == 'M' || headch == '#')
    {
        return TRUE;
    }

    // 먹은 숫자의 multi 배만큼 꼬리를 늘린다. 늘어나고 있는 중이라면 누적된다.
    inctail += (headch - '0') * multi;
    return FALSE;
}

// 키 입력을 처리한다.
void ProcessKey()
{
    int ch;

    if (!_kbhit()) // _kbhit() in conio.h 사용자가 키를 누르면 1 아니면 0을 반환
    {
        return;
    }

    ch = _getch();

    if (ch == 0xE0 || ch == 0)
    {
        ch = _getch();
        switch (ch)
        {
        case LEFT:
            // 진행 반대 방향으로는 전환할 수 없다.
            if (dir != RIGHT) dir = LEFT;
            break;
        case RIGHT:
            if (dir != LEFT) dir = RIGHT;
            break;
        case UP:
            if (dir != DOWN) dir = UP;
            break;
        case DOWN:
            if (dir != UP) dir = DOWN;
            break;
        }
    }
    else
    {
        switch (tolower(ch))
        {
        case 27:
            setcursortype(NORMALCURSOR);
            exit(0);
        case ' ':
            waitanykey();
            break;
        }
    }
}

// 화면의 x,y위치에 있는 문자를 조사한다.
int getchcon(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    TCHAR Char;
    DWORD dwRead;
    ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), &Char, 1, Cur, &dwRead);
    return Char;
}

// 임의의 키 하나가 눌러질 때까지 대기한다.
void waitanykey()
{
    int ch;
    ch = _getch();
    if (ch == 0xE0 || ch == 0)
    {
        _getch();
    }
}