#pragma once

#ifdef DLL2_API
#else
#define DLL2_API _declspec(dllimport)
#endif

class DLL2_API Shape
{
public:
	int GetType();

	void shapeTest();
};