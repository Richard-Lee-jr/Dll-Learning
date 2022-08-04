#pragma once

#ifdef TMP_API
#else
#define TMP_API _declspec(dllimport)
#endif

//#ifdef __cplusplus
//extern "C"
//{
//#endif
//
//void TMP_API _stdcall tmpTest();
//
//
//#ifdef __cplusplus
//};
//#endif
//
//class TMP_API Tmp
//{
//public:
//	void tmpTmp();
//};