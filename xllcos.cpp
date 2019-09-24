// Author: yl4419
// computes cosine (cos(x))
// Rename this file to xllcos.cpp and implement XLL.COS which calls cos
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddIn xai_cos(
	Function(XLL_DOUBLE, _T("?xll_cos"), _T("XLL.COS"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a floating point number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Compute cos(x)"))
	.Documentation(LR"(
        This function calculates the value of cos(x) 
    )")
);

double WINAPI
xll_cos(double x)
{
#pragma XLLEXPORT


	return cos(x);
}

#if _DEBUG

xll::test test_xll_cos([]() {
	double presult;
	double x = 0;
	presult = xll_cos(x);
	ensure(presult == 1);
	});

#endif // _DEBUG