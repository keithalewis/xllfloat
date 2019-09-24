// Author: zl2776
// computes cubic root (3√x)
// Rename this file to xllcbrt.cpp and implement XLL.CBRT which calls cbrt
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"
#include <cmath>

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

AddIn xai_cbrt(
	Function(XLL_DOUBLE, L"?xll_cbrt", L"XLL.CBRT")
	.Arg(XLL_DOUBLE, L"x", L"is the value at which to evaluate the cubic root.")
	.Category(L"XLL")
	.Documentation(LR"(
        Evaluates the cubic root of x.
    )")
);
double WINAPI
xll_cbrt(double x)
{
#pragma XLLEXPORT 
	return std::cbrt(x);
}

#ifdef _DEBUG

xll::test test_xll_cbrt([]() {
	double x = -27;
	double y = 0;
	ensure(xll_cbrt(x) == -3);
	ensure(xll_cbrt(y) == 0);
	});

#endif // _DEBUG