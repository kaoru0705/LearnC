/* ���̺귯�� */
// [Configuration Properties]-[General]-[Configuration Type]���� Static library ���� �� �����ϸ�(���� �� �ϸ� �ü���� main.c���� ã���� �ϹǷ� ���� �߻� ����) .lib������ �����ȴ�(Debug/Release ��� �� �� �����ϱ�)
// Static Library �ۼ��� ���α׷��� ���̺귯���� �ٷ� ������ �ȴ�. Dynamic Library ���α׷� ��ü�� ���̺귯���� ������ �ִ� �� �ƴ϶� ������ �� �������� �׶��׶� ������ ��
// 1>Library_A.vcxproj -> C:\Users\shkdh\Desktop\repos\Solution 16\x64\Debug\Library_A.lib
// 1>Library_A.vcxproj -> C:\Users\shkdh\Desktop\repos\Solution 16\x64\Release\Library_A.lib
// Debug/Release ��忡 ���� ��������� ���������� .lib �����̳� .dll ������ �޶�����
#include "MyLibrary.h"

#include <stdio.h> // library. �������� ����� å�� �����ϱ� ���� '�����Ѵ�'�� �ǹ�

void say_hello()
{
    printf("Hello.\n");
}

void say_world()
{
    printf("World\n");
}