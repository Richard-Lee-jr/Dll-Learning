#include <stdio.h>
#pragma comment(lib, "D:\\vs2010_application\\CTest\\CTest\\CTest\\Dll1.lib")
#include "Dll1.h"

int main()
{
	//����û��ͨ��Dll1.h�������ĺ���������
	//�����������Dll1����������������ʵ��ǰ��extern "C" �޶����� ע��CҪ��д
	printf("2 + 3 = %d\n", add(2, 3));
	printf("5 - 2 = %d\n", sub(5, 2));

	//system("pause");
	return;
}

