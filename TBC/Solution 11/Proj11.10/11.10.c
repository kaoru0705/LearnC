/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Command-Line Arguments */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
- ���־� ��Ʃ��� ���� ��

*���� �ַ�ǿ� ���� ������Ʈ���� .exe ������ �ش� �ַ�� ������ ��ġ�� ���͸��� Debug ����(Debug ����� ���)�� ����ȴ�
*.exe ������ �����Ǵ� ��ġ: ex) F:\repos\Solution 11\Debug\Proj11.10.exe [Solution Explorer���� �ش� ������Ʈ�� ��Ŭ��]-[Properties]-[General]-[Output Directory] $=����(SolutionDir = .sln file ��ġ)$(Configuraton = debug or release? x64debug x64 release?)\���⿡ ����
intermediate directory: ������ �� �߰��߰��� ����ϴ� ���ϵ��� �����ϴ� ��ġ
*.exe ���� �̸�: //-[General]-[Target Name(������Ʈ �̸��� �����ϴ�)]
* Configuration Type: .exe
* �⺻������ visual studio�� �ַ���� ������ �� ���� ������Ʈ�� exe������ �� ���� ��Ƶд�. �׷��� open containing folder- debug�� exe������ ����
*��� ������Ʈ���� .exe ���� �����Ű��: 1.��θ� ������ ���ϸ� �Է�  /  2. Ž����� ã�� ���� �������� �巡�� �� ���
*�����Ϳ��� ����� �μ� �����ϴ� ���: [Solution Explorer���� �ش� ������Ʈ�� ��Ŭ��]-[Properties]-[Debugging]-[Command Arguments]
* 
*/

// ����ڰ� ���α׷��� �����ų �� main() �Լ��� �μ��� �Է��� �� �ִ�
// ���� �־��ٱ�? �ü����. ���ݱ����� �μ� ���� �� ���������µ� ���α׷��� �����ų �� ����� Ȥ�� ���α׷��Ӱ� �־��� �� �ִ�.
// �⺻������ ���������� ��θ� ������ �̸��� �μ��� ���޵ȴ�. ���α׷��� �����ų �� �ü���� �ڿ� �ٿ��ִ� arguments���� ������
// main() �Լ��� �μ��� �ƿ� ���ų� �ִٸ� �Ʒ��� ������ �ؼ��ϵ��� �ü���� c�� �����
// �ƿ� ���ٸ� ���� command-line arguments�� ���� ������ ���ɾ���. �ü������ �������� ������
// command-line argument�� ���� �̷� ������ �־��ּ���
int main(int argc, char* argv[])
{
    int count;
    printf("The command line has %d arguments:\n", argc);

    for (count = 0; count < argc; count++)
        printf("Arg %d : %s\n", count, argv[count]);

    return 0;
}