/* ����ü ���� ����� �������� */
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
    //write_books_bin("books.dat", my_books, n);  // ���̳ʸ� ��� binary format�� ���� ������ ������ ������ �� ����.
    free(my_books);
    n = 0;
    printf("Done.\n");

    printf("\nPress any key to read data from a file.\n\n");
    temp = _getch();
    //temp = getchar();

    my_books = read_books("books.txt", &n);
    //read_books_bin("books.dat", &my_books, &n);  // ���̳ʸ� �Է�
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
        fprintf(fw, "%s\n", books[i].name); // fprintf(fw, "%s\n%s\n", books[i].name, books[i].author); �������� �̷�����
        fprintf(fw, "%s\n", books[i].author);
    }

    fclose(fw);
}

/* my poor answer, professor ������ */
//struct book* read_books(const char* filename, int* n)
//{
//    FILE* fr = fopen(filename, "r"); // read�� ������ ���� �� ��Ÿ�ӿ����� ���Ƿ� ���������!
//
//    fscanf(fr, "%d", n); // fscanf(fr, "%d ", n); �̷��� �ϸ� fgetc(fr)�� �� ��� �ȴ�. ��ĭ�� n ������ ���͸� ������� fscanf�� %d�� ������(n)�� �޴´�? ��ģ��� scanf��Ծ��� ���� ���� �Է��Ϸ��� �����ͷ� ���� ���ۿ� ����.
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
//        fgets(books[i].name, SLEN, fr); //c6385 calloc���� �ϸ� ��������. ���ڸ����� ������ ���� �ִ��. ����� �� Ʋ���� �ʾҵ�.
//        find = strchr(books[i].name, '\n'); // ���͸� �η� �ٲ�
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
    flag = fscanf(file, "%d%*c", n_ptr);  // Remove last '\n' % *�� ������ �Է¹��� �����͸� ���ݴ�. 4.10c �������� ���͸� ����

    if (flag != 1) {
        printf("File read failed.");
        exit(1);
    }

    struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr);  // calloc() 12.16 contiguous allocation �����͸� 0���� �ʱ�ȭ����

    if (!books) {
        printf("Calloc() failed.");
        exit(1);
    }

    for (int i = 0; i < *n_ptr; ++i) {
        flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author); // 14.8 [^\n] \n������ �޾ƶ� %*c �׸��� �̰ɷ� \n�� ����

        if (flag != 2) {
            printf("File read failed.");
            exit(1);
        }
    }

    fclose(file);

    return books; // �޸��忡�� n�� �ش��ϴ� ���� �⺻ 3���� ũ�� ���� �� ��ȯ�Ǹ� 3ĭ¥�� �����Ҵ��� my_books�� ��� ���������� ���°�? ������ free���ݾ�.  ������ �򰥸��� ����. my_books = books; ����ü�� �ƴ϶� ����ü �����ʹ�. ���� �ű� �� �ƴϴ�. �ּҰ��� �Ű��� ���̴�.
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

    if (!books) // �̰� �� ������ C6011 error
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

// ��κ� ���̳ʸ��� ����Ѵ�. �ؽ�Ʈ ������ �� ���� ����� �� �ƴϴ�. �ؽ�Ʈ ������ ����ϴ� �� ������ ��쵵 ����. �㳪 �������� ���� ���� ����� �ӵ��� �߿��ϰ� ������ �����ϸ� ���̳ʸ��� ����

void write_books_bin(const char* filename, const struct book* books, int n)
{
    FILE* fp = fopen(filename, "wb");  // Binary

    if (fp == NULL) {
        fputs("Can't open file.", stderr);
        exit(1);
    }

    fwrite(&n, sizeof(n), 1, fp);
    // ���̳ʸ� �������� ����ü ����� ������ ���� �޸� ��°�� �����Ѵ� �� ����������.
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

    fread(books, sizeof(struct book), *n_ptr, fp); // �̷��� �����͸� ��°�� ���� �� �ִ�. GOAT

    fclose(fp);

    *books_dptr = books;

}
