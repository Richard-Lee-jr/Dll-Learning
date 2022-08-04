#define DLL2_API _declspec(dllexport)
#include "Dll2.h"

#include <windows.h>
#include <tchar.h>
#include "Dll1.h"

int Shape::GetType()
{
	/*TCHAR buf[20] = { 0 };
	_stprintf_s(buf, _T("x = %d, y = %d"), x, y);*/
	OutputDebugString(_T("\n ShapeGetType \n\n"));

	PointB ptB;
	ptB.output(3, 8);
	ptB.pointBTest();

	return 0;
}

void Shape::shapeTest()
{
	OutputDebugString(_T("\n shapeTest \n\n"));
}