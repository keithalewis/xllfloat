// Author: jc5302
// remainder of the floating point division operation
// Rename this file to xllfmod.cpp and implement XLL.FMOD which calls fmod
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

AddIn xai_fmod(
	Function(XLL_DOUBLE, L"?xll_fmod", L"XLL.FMOD")
	.Arg(XLL_DOUBLE, L"x", L"is the numerator.")
	.Arg(XLL_DOUBLE, L"y", L"is the denominator.")
	.FunctionHelp(L"the remainder of x divided by y")
	.Category(L"XLL")
	.Documentation(LR"(
        The remainder of x divided by y.
    )")
);

double WINAPI xll_fmod(double x, double y)
{
#pragma XLLEXPORT

	return fmod(x, y);
}