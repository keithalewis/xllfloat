// Author: zf2209
// larger of two floating point values
// Rename this file to xllfmax.cpp and implement XLL.FMAX which calls fmax
// Add documentation and a test function that runs in debug mode.

#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY _T("Float")
#endif

using namespace xll;

static AddIn xai_fmax(
	Function(XLL_DOUBLE, _T("?xll_fmax"), _T("FMAX"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a floating point number"))
	.Arg(XLL_DOUBLE, _T("y"), _T("is a floating point number"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns larger of two floating point values of x and y by calling XLL.FMAX()"))
	.Documentation(LR"(
        The fmax functions return a floating-point value that is the larger between the input floating point values x and y. 
        There is no error return.
    )")
);
double WINAPI
xll_fmax(double x, double y)
{
#pragma XLLEXPORT

	return std::max(x, y);
}

#if _DEBUG

xll::test test_xll_fmax([]() {
	double presult;
	double numer = 0.2;
	double denom = 0.1;
	presult = xll_fmax(numer, denom);
	ensure(presult == 0.2);
	});

#endif // _DEBUG