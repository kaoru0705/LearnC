/* ���̺귯�� */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
//debug ����� �� debug������ ����� lib, dll������ ����ؾ� �ǰ� release�� ���� �������� ��������� ��ġ�� ����
#include "C:\Users\shkdh\Desktop\repos\TBC\Solution 16\Library_A\MyLibrary.h" // �̷� ������(MyLibrary.h - right click - Copy Full Path)���ٴ� �����(���� ���̺귯���� �����ϰų� ������ ���� lib�� ������� ���� �����ϹǷ� ����� ���忡���� �ڱⰡ ����ϱ� ���� ���� �����ؼ� ���)�� ���� ����Ѵ�
//#include <MyLibrary.h>  // [Configuration Properties]-[C/C++]-[General]-[Additional Include Directories]�� MyLibrary.h ������ ������ �ּҸ� �Է�
/*
1>main.obj : error LNK2019: unresolved external symbol say_hello referenced in function main
1>main.obj : error LNK2019: unresolved external symbol say_world referenced in function main
1>C:\Users\shkdh\Desktop\repos\Solution 16\x64\Debug\Library_B.exe : fatal error LNK1120: 2 unresolved externals
*/
int main(void)
{
    // [Configuration Properties]-[Linker]-[General]-[Additional Library Directories]�� ex)C:\Users\shkdh\Desktop\repos\TBC\Solution 16\x64\Debug ������ �ּҸ� �Է��ؾ� ��ŷ ������ �߻����� �ʴ´�
    // [Configuration Properties]-[Linker]-[Input]-[Additional Dependencies]�� ������ .lib������ Ȯ���ڱ��� �Է��Ѵ�(ex. Library.lib;) �̹� ���̺귯�� ���ϵ��� ��û���� ���� ���� Ȯ���� �� �ִ�. ���п� ���ϰ� �̿밡��
    // �����ζ� exe���ϱ��� �ڼ��� ���� �ִ�.
    say_hello();
    say_world();

    return 0;
}
