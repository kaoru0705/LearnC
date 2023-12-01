/* �޸� �ٸ��� alignof, alignas */
/* https://www.onlinegdb.com/online_c_compiler code�� VS������ ������ �ȵȴ�. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdalign.h> // c++ style alignas, alignof ���� _Alignof �̰����� stadalign.h�� ���Խ�Ű�� alignof ����

int main()
{
    /* ���� ����ϴ� �����Ϸ��� clang���� gcc���� �����ϴ� �ڵ� */
#ifdef __clang_major__
    printf("clang detected version %d.%d\n", __clang_major__, __clang_minor__);
#endif

#ifdef __GNUC__
    // note that clang 3.7 declares itself as a gcc 4.2"
    printf("gcc deteceted version %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif

    printf("Alignment of char = %zu\n", alignof(char)); // 1bytes, alignof align�� �� ����Ʈ �������� ����� �ϴ°��� �˷���
    printf("alignof(float[10]) = %zu\n", alignof(float[10])); // 4bytes
    printf("alignof(struct{char c; int n;}) = %zu\n",
        alignof(struct { char c; int n; })); // 4bytes

    double dx;
    char ca;
    char cx;
    double dz;
    char cb;
    //char _Alignas(double) cz; // �̰� �����ϸ� &cz % 8�� 0�� ���´�. alignas align�ϴ� ����� �ٲ���
    //char alignas(16) cz;
    char cz;

    /*printf("char alignment: %zd\n", _Alignof(char));
    printf("double alignment: %zd\n", _Alignof(double));*/
    printf("char alignment: %zd\n", alignof(char));
    printf("double alignment: %zd\n", alignof(double));

    printf("&dx: %p %lld\n", &dx, (long long)&dx % 8); // 8�� ��� �ּڰ��� alignment�� ���缭 �ǰ� �ִ�.
    printf("&ca: %p %lld\n", &ca, (long long)&ca % 8);
    printf("&cx: %p %lld\n", &cx, (long long)&cx % 8);
    printf("&dz: %p %lld\n", &dz, (long long)&dz % 8); // 8�� ��� ���� ��������
    printf("&cb: %p %lld\n", &cb, (long long)&cb % 8);
    printf("&cz: %p %lld\n", &cz, (long long)&cz % 8);

    unsigned char alignas(long double) c_arr[sizeof(long double)]; // �迭�� ���� ���� alilgn�� ����� ���� �ִ�.



    return 0;
}
