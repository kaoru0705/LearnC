/*  #include�� ��� ���� �츮�� ���� ���� ����ϴ� ��ó�� ������ preprocessor directive�� include */
#include <stdio.h>                 // <> : �����Ϸ��� �̹� �˰��ִ� ��ġ. ǥ�� ���̺귯�� �Ǵ� ������ �������� ���̺귯��. �㳪 ǥ�ض��̺귯�� Ȥ�� �ܺο��� ���̺귯���� ���� ���µ� �� ���̺귯���� �Ϲ������� ����ϱ⸸ �� �� <>�� �Ϲ���
#include "my_functions.h"          // "" : �Ϲ������� ��ü ����/������ ���̺귯���� ��� "" �� containing folder�� �� ���� �ִ�.
#include "my_structures.h"
#include "my_headers/my_macros.h"  // path. �����(�����ε� ����) \(windows������ �̰� ����) / �� �� ���� "my_headers"��� ���� �ȿ� ����
//#include "C:\
//  ....."        // ������ ������� ���� �����ؼ� ���� ������ �㳪 �̷��� ���� ����� ������ ���� ���� ����ΰ� �Ϲ���
//#include "my_macros.h" //VS�� ��� [Properties]-[C/C++]-[Additional include Directories] ���� .(���� ���丮��� ��)/(���� ���͸�)my_headers/ or my_headers��� ������
//// ��ó���� �����Ϸ��� additional include directories�� �Ǿ��ִ� �������� ã�´�. �Ǽ��� ��Ÿ���� error
//#include <my_macros.h> ��ó�� �߰� ��� ������ ��� �̰͵� ��
// ��������� �����̵Ǵ� �κ��� ������ �� Ư�� ������ ��� �� �� ��� ���� ���� ����
extern int status;

int main(void)
{
#include "hello_world.h"  // #include�� ��ó���Ⱑ ��������� �ҽ��ڵ带 ���� �ٿ��ֱ��ϴ� ����̹Ƿ� ��������� ������ printf("Hello, world from a header file.\n");�� �ٲ��
                          // �㳪 �Լ��ȿ� include�� �� ��̻�� �� �Ŵ�. ���� �̷��� �� ��
    printf("PI = %f\n", PI);

    printf("%p %d\n", &status, status);  // status�� �ּҴ� �Ʒ��� ����(=���� ������Ʈ��)

    print_status();                      // status�� �ּҴ� ���� ����(=���� ������Ʈ��)

    printf("%d\n", multiply(51, 2));

    printf("main()\n");
    printf("Static function address %p\n", multiply);  // �Ʒ� print_address()�� ��°��� �ٸ��� static�� file scope�� �ٸ���
    printf("Static variable address %p\n", &si);       // �Ʒ� print_address()�� ��°��� �ٸ���

    print_address();

    patient_info james = { "James Bone", 45 }, michael = { "Michael Jobs", 50 };

    return 0;
}