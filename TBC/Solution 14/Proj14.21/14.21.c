/* Function Pointers �Լ� �������� ���� */
/*
	void (*pf1)() = f1; void (*pf1)() = &f1; �� �� ����
	���������δ� �Լ��� �̸� ��ü(ex)f1)�� ������, �Լ���� �� � �޸� ������ ����� �ְ� �����ų �� �� �ּҿ� �ִ� �ڵ带 �����Ų�ٴ� ���� �̸� ��ü�� �ּ�
	���������� (*pf1)(); (pf1)(); �� �� ���� �̸���ü�� �����ʹ� ���ڵ� �ȴ�
	���� ���� �츮�� ���α׷��� �ۼ��ϰ� ������ �ϸ� ���������� ��������� �ϵ��ũ�� ����ȴ�.
	�츮�� �ü������ ���������� �����ش޶�� ��û�ϸ� ���α׷� ��ü�� �޸𸮿� �����ؼ� �÷��ش�. �׸��� �� �ڵ� ��ü�� ����Ǵ� ���� TEXT Segment (Read Only)
	���������� function pointer ��ü�� ���ÿ� ����
	���α׷��Ӵ� �Լ��� �̸��� �̿��ؼ� ���α׷��� �ۼ������� �����Ϸ��� �̸�(�ĺ���)���� �޸𸮿����� �ּҷ� �����Ѵ�.
	��, �Լ��� �����Ų�ٴ� ���� �޸𸮿��� �Լ��� �ּ� ��ġ�� ����Ǿ� �ִ� ���ɾ���� ���������� �����Ѵٴ� �ǹ̴�

*/