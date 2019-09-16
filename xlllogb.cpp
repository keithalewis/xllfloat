// Author: yz3632
// extracts exponent of the number
// Rename this file to xlllogb.cpp and implement XLL.LOGB which calls logb
// Add documentation and a test function that runs in debug mode.


#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_logb(
	FunctionX(XLL_DOUBLE, _T("?xll_logb"), _T("LOGB"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is a double number "))
	.Category(CATEGORY)
	.FunctionHelp(_T("Returns the exponent of x"))
	.Documentation(LR"(
        Return the exponent of a number.
    )")
);
double WINAPI
xll_logb(double x)
{
#pragma XLLEXPORT
	double s;
	s = logb(x);
	return s;
}

#if _DEBUG

xll::test test_xll_logb([]() {
	double result;
	double x = 4;
	result = xll_logb(x);
	ensure(result == 2);
});
#endif