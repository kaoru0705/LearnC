/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ���ڿ�(Strings)�� �����ϴ� ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MESSAGE "A symbolic string constant"  // ���ڿ��� ��ȣ�� ����� ���� ����
#define MAXLENGTH 81

int main() {
    char words[MAXLENGTH] = "A string in an array";  // �Ź� ���� �迭�� ��Ȯ�� ũ�⸦ �˱�� ����� ������ �˳��ϰ� �����Ѵ�
    const char* pt1 = "A pointer to a string";  // ������ �迭�� �ڱⰡ ���� �ִ� �޸� ����maxlength*char�� ���ڿ��� �����ϰ� �ִ� �� ���� �� �����ʹ� � �޸� ������ �ִ� ���ڿ��� ù ��° �ּҸ� ����Ű�� ���� ���̴�

    puts("Puts() adds a newline at the end:");  // puts(const char *_Buffer) add \n at the end ���ڿ��� �迭�� �������� ù ��° �ּҸ� �����ͷ� �ѱ� �� �ִ�.
    puts(MESSAGE);
    puts(words);  // warning(�迭�� �Ϻθ� �ʱ�ȭ�߱� ����) Using uninitialized memory null���� 21���ڸ� �ʱ�ȭ�ؼ�
    puts(pt1);
    words[3] = 'p';  // OK(�迭�̱� ������ �迭�� ���ҿ� �����ϴ� ������� ���ڿ��� �Ϻθ� �ٲ� �� �ִ�)
    puts(words);    //null�� ã�� ������ �� �д´�.
    //pt1[8] = 'A';  // Error(�����ϸ� �� �Ǵ� ���� �����ϰ� �ֱ� ����. ���ʿ��� ������ �� const�� �����ϸ� �������� ������ ��Ÿ�� ���� �߻�. ���� �Ǽ��� �����ϱ� ���� const�� �ٿ��� ������ ��ü�� �� �ǵ��� ����� �� ����)
    // [����] �б� ���� �޸𸮿� ����� �������� ���� �ٲٷ��� �õ��ϸ� �ü���� �ߴܽ�ŵ�ϴ�. 
    //  �迭�� �б�/���Ⱑ ��� ������ �޸𸮸� ����մϴ�.
    // ���ڿ� ���ͷ��� ���α׷��� �Ϻ��̱� ������ �б� ���� �޸𸮿� ����Ǿ� �ֽ��ϴ�.

    //char greeting[50] = "Hello, and How are you today!";
    char greeting[50] = "Hello, and"" How are" " you"
        " today!";  // ����ǥ�� ������ ���ڿ��� ���� ���� �ִ�(���ٰ� ����)

    printf("\" To be, or not to be\" Hamlet said.\n");  // ū����ǥ�� ����ϴ� ���

    printf("%s, %p, %c\n", "We", "are", *"excellent programmers");
    // ���ڿ��� �迭�� �־ �ʱ�ȭ�� �� �ִٸ� "are"�� �ּҴ� ù ���ڰ� ����� �ּ� %s

    const char m1[15] = "Love you!";

    for (int i = 0; i < 15; ++i)
        printf("%d ", (int)m1[i]);  // Note the null characters(�迭�� �ʱ�ȭ���� �ʰ� ���� �κ��� �����Ϸ��� null character�� �ʱ�ȭ���ֱ⵵ �Ѵ�)
    printf("\n");

    const char m2[15] = { 'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '!', '\0' };  // ������ �迭(���ڿ��� ������� �������� null character�� �߰��ؾ� �Ѵ� null character�� ���� �����Ϸ��� �˾Ƽ� �ʱ�ȭ ���ش�.)

    for (int i = 0; i < 15; ++i)
        printf("%d ", (int)m2[i]);
    printf("\n");

    const char m3[] = "Love you, too!";  // �迭 ũ�⸦ �����Ϸ��� ������ �����ϴ� ���. �����Ϸ��� �� ���� null character�� �ڵ����� �߰����ش�

    int n = 8;
    char cookies[1] = { 'A', }; // �迭�� ���̿� ���ؼ��� unsigned integer
    char cakes[2 + 5] = { 'A', };
    char pies[2 * sizeof(long double) + 1] = { 'A', };  // sizeof�� ������ ������ ���� ���� �㳪 �Ǽ��� ���� �� �ȴ�.
    //char crumbs[n];  // VLA  in 10.17

    char truth[10] = "Truth is ";
    if (truth == &truth[0]) puts("true!");
    if (*truth == 'T') puts("true!");
    if (*(truth + 1) == truth[1]) puts("true!");
    if (truth[1] == 'r') puts("true!");

    return 0;
}