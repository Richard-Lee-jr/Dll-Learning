#pragma once

#ifdef DLL1_API
#else
#define DLL1_API _declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

namespace DLL1API
{
	//�Ӷ�̬���е�������
	int DLL1_API _stdcall add(int a, int b);

	int DLL1_API _stdcall sub(int a, int b);

}

#ifdef __cplusplus
};
#endif


//�Ӷ�̬���е�����
class DLL1_API Point
{
public:
	
	void output(int x, int y);

	void test();
};

//ֻ�������и����Ա����
//class Point
//{
//public:
//	DLL1_API void output(int x, int y);
//	void test();
//};