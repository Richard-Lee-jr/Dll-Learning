#define DLL1_API _declspec(dllexport)
#include "Dll1.h"

//#ifdef __cplusplus
//extern "C"
//{
//#endif
//
//int DLL1_API _stdcall add(int a, int b)
//{
//	return a + b;
//}
//
//int DLL1_API _stdcall sub(int a, int b)
//{
//	return a - b;
//}
//
//#ifdef __cplusplus
//};
//#endif


#include <windows.h>
#include <tchar.h>
#include "tmp.h"

//�Ӷ�̬���е�����: ���Զ������������г�Ա����
void PointB::output(int x, int y)
{
	TCHAR buf[20] = { 0 };
	_stprintf_s(buf, _T("\n x = %d, y = %d \n\n"), x, y);
	OutputDebugString(buf);
}


//ֻ�������и����Ա����
//DLL1_API void Point::output(int x, int y)
//{
//	TCHAR buf[20] = { 0 };
//	_stprintf_s(buf, _T("x = %d, y = %d"), x, y);
//	OutputDebugString(buf);
//}

void PointB::pointBTest()
{
	OutputDebugString(_T("\n pointBTest \n\n"));
}