#pragma once

#ifdef DLL1_API
#else
#define DLL1_API _declspec(dllimport)
#endif

//#ifdef __cplusplus
//extern "C"
//{
//#endif

//从动态库中导出函数
int DLL1_API _stdcall add(int a, int b);

int DLL1_API _stdcall sub(int a, int b);

void DLL1_API _stdcall test();
//
//#ifdef __cplusplus
//};
//#endif





//从动态库中导出类
//class DLL1_API Point
//{
//public:
//	void output(int x, int y);
//	void test();
//};

//只导出类中个别成员函数
//class Point
//{
//public:
//	DLL1_API void output(int x, int y);
//	void test();
//};