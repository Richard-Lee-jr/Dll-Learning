#include <stdio.h>
#pragma comment(lib, "D:\\vs2010_application\\CTest\\CTest\\CTest\\Dll1.lib")
#include "Dll1.h"

int main()
{
	//这里没法通过Dll1.h中声明的函数名调用
	//解决方法：在Dll1导出函数的声明和实现前加extern "C" 限定符， 注意C要大写
	printf("2 + 3 = %d\n", add(2, 3));
	printf("5 - 2 = %d\n", sub(5, 2));

	//system("pause");
	return;
}

