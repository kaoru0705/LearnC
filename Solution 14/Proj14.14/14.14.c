/* 구조체 파일 입출력 연습문제 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 101

struct book
{
    char name[SLEN];
    char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);
void write_books_bin(const char* filename, const struct book* books, int n);
struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** books_dptr, int* n);
void read_books_bin(const char* filename, struct book** books_dptr, int* n);

int main(void)
{
    int temp;
    int n = 3;

    struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);

    if (!my_books)
    {
        printf("Malloc failed");
        exit(1);
    }

    my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
    my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
    my_books[2] = (struct book){ "The Odyssey", "Homer" };

    print_books(my_books, n);
    printf("\nWriting to a file.\n");
    write_books("books.txt", my_books, n);
    //write_books_bin("books.dat", my_books, n);  // 바이너리 출력 binary format의 단점 파일의 내용을 수정할 수 없다.
    free(my_books);
    n = 0;
    printf("Done.\n");

    printf("\nPress any key to read data from a file.\n\n");
    temp = _getch();
    //temp = getchar();

    my_books = read_books("books.txt", &n);
    //read_books_bin("books.dat", &my_books, &n);  // 바이너리 입력
    //read_books2("books.txt", &my_books, &n);
    print_books(my_books, n);
    free(my_books);
    n = 0;

    return 0;
}

void print_books(const struct book* books, int n)
{
    for (int i = 0; i < n; i++)
        printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books[i].name, books[i].author);
}

void write_books(const char* filename, const struct book* books, int n)
{
    FILE* fw = fopen(filename, "w");
    
    fprintf(fw, "%d\n", n);

    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%s\n", books[i].name); // fprintf(fw, "%s\n%s\n", books[i].name, books[i].author); 교수님은 이렇게함
        fprintf(fw, "%s\n", books[i].author);
    }

    fclose(fw);
}

/* my poor answer, professor 번갈아 */
//struct book* read_books(const char* filename, int* n)
//{
//    FILE* fr = fopen(filename, "r"); // read면 파일이 없을 때 런타임에러가 나므로 없애줘야지!
//
//    fscanf(fr, "%d", n); // fscanf(fr, "%d ", n); 이렇게 하면 fgetc(fr)를 안 적어도 된다. 빈칸이 n 다음에 엔터를 흡수해줌 fscanf는 %d라도 포인터(n)를 받는다? 미친놈아 scanf까먹었냐 원래 값을 입력하려면 포인터로 받을 수밖에 없다.
//    fgetc(fr);
//
//    char* find;
//    struct book* books = (struct book*)malloc(sizeof(struct book) * (*n));
//
//    if (books == '\0')
//        exit(1);
//
//    for (int i = 0; i < *n; i++)
//    {
//        fgets(books[i].name, SLEN, fr); //c6385 calloc으로 하면 없어진다. 인텔리센스 오류일 수도 있댄다. ㅈ까라 난 틀리지 않았따.
//        find = strchr(books[i].name, '\n'); // 엔터를 널로 바꿈
//        *find = '\0';
//        fgets(books[i].author, SLEN, fr);
//        find = strchr(books[i].author, '\n');
//        *find = '\0';
//    }
//    
//    fclose(fr);
//
//    return books;
//}

struct book* read_books(const char* filename, int* n_ptr)
{
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        fputs("Can't open file.", stderr);
        exit(1);
    }

    int flag;
    flag = fscanf(file, "%d%*c", n_ptr);  // Remove last '\n' % *을 적으면 입력받은 데이터를 없앴다. 4.10c 마지막에 엔터를 없앰

    if (flag != 1) {
        printf("File read failed.");
        exit(1);
    }

    struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr);  // calloc() 12.16 contiguous allocation 데이터를 0으로 초기화해줌

    if (!books) {
        printf("Calloc() failed.");
        exit(1);
    }

    for (int i = 0; i < *n_ptr; ++i) {
        flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author); // 14.8 [^\n] \n전까지 받아라 %*c 그리고 이걸로 \n를 없앰

        if (flag != 2) {
            printf("File read failed.");
            exit(1);
        }
    }

    fclose(file);

    return books; // 메모장에서 n에 해당하는 수를 기본 3보다 크게 했을 때 반환되면 3칸짜리 동적할당인 my_books에 어떻게 정상적으로 들어가는가? 그전에 free했잖아.  ㅋㅋㅋ 헷갈리지 마라. my_books = books; 구조체가 아니라 구조체 포인터다. 값을 옮긴 게 아니다. 주소값을 옮겼을 뿐이다.
}

//void read_books2(const char* filename, struct book** books_dptr, int* n) //Note: double pointer
//{
//    FILE* fr = fopen(filename, "r");
//    fscanf(fr, "%d", n);
//    fgetc(fr);
//    char* find;
//    *books_dptr = (struct book*)malloc(sizeof(struct book) * (*n));
//
//    if (*books_dptr == '\0')
//        exit(1);
//
//    for (int i = 0; i < *n; i++)
//    {
//        fgets((*books_dptr)[i].name, SLEN, fr);
//        find = strchr((*books_dptr)[i].name, '\n');
//        *find = '\0';
//
//        fgets((*books_dptr)[i].author, SLEN, fr);
//        find = strchr((*books_dptr)[i].author, '\n');
//        *find = '\0';
//    }
//
//    fclose(fr);
//}

void read_books2(const char* filename, struct book** books_dptr, int* n_ptr)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fputs("Can't open file.", stderr);
        exit(1);
    }

    int flag;
    flag = fscanf(file, "%d%*c", n_ptr);

    if (flag != 1) {
        printf("File read failed.");
        exit(1);
    }

    struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr);

    if (!books) // 이걸 안 적으면 C6011 error
    {
        printf("Calloc() failed.");
        exit(1);
    }

    for (int i = 0; i < *n_ptr; i++) {
        flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);

        if (flag != 2) {
            printf("File read failed.");
            exit(1);
        }
    }

    fclose(file);

    *books_dptr = books; //books_dptr == &my_books *books_dptr == my_books

}

//void write_books_bin(const char* filename, const struct book* books, int n)
//{
//    FILE* fw = fopen(filename, "wb");
//
//    fwrite(&n, sizeof(int), 1, fw);
//
//    for (int i = 0; i < n; i++)
//    {
//        fwrite(books[i].name, sizeof(char), SLEN, fw);
//        fwrite(books[i].author, sizeof(char), SLEN, fw);
//    }
//
//    fclose(fw);
//}
// 

// 대부분 바이너리를 사용한다. 텍스트 포맷을 꼭 쓰지 말라는 게 아니다. 텍스트 포맷을 사용하는 게 유리한 경우도 많다. 허나 데이터의 양이 많고 입출력 속도가 중요하고 편리성을 생각하면 바이너리가 유리

void write_books_bin(const char* filename, const struct book* books, int n)
{
    FILE* fp = fopen(filename, "wb");  // Binary

    if (fp == NULL) {
        fputs("Can't open file.", stderr);
        exit(1);
    }

    fwrite(&n, sizeof(n), 1, fp);
    // 바이너리 포맷으로 구조체 멤버를 저장할 때는 메모리 통째로 저장한다 더 간단해졌다.
    fwrite(books, sizeof(struct book), n, fp);

    fclose(fp);
}

//void read_books_bin(const char* filename, struct book** books_dptr, int* n_ptr) {
//    FILE* file = fopen(filename, "rb");
//    if (file == NULL) {
//        fputs("Can't open file.", stderr);
//        exit(1);
//    }
//
//    fread(n_ptr, sizeof(int), 1, file);
//
//    *books_dptr = (struct book*)malloc(sizeof(struct book) * (*n_ptr));
//
//    if (!*books_dptr)
//    {
//        printf("Malloc() failed.");
//        exit(1);
//    }
//
//    for (int i = 0; i < *n_ptr; i++) {
//        fread((*books_dptr)[i].name, sizeof(char), SLEN, file);
//        fread((*books_dptr)[i].author, sizeof(char), SLEN, file);
//    }
//
//    fclose(file);
//
//}

void read_books_bin(const char* filename, struct book** books_dptr, int* n_ptr)
{
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL) {
        fputs("Can't open file.", stderr);
        exit(1);
    }

    fread(n_ptr, sizeof(*n_ptr), 1, fp);

    struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr);

    if (!books) {
        printf("Calloc() failed.");
        exit(1);
    }

    fread(books, sizeof(struct book), *n_ptr, fp); // 이렇게 데이터를 통째로 읽을 수 있다. GOAT

    fclose(fp);

    *books_dptr = books;

}
