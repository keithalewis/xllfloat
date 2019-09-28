// Author: fq2145
// arc tangent, using signs to determine quadrants
// Rename this file to xllatan2.cpp and implement XLL.ATAN2 which calls atan2
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_atan2(
	FunctionX(XLL_DOUBLE, _T("?xll_atan2"), _T("XLL.ATAN2"))
	.Arg(XLL_DOUBLE, _T("y"), _T("is the numerator."), _T("0.5"))
	.Arg(XLL_DOUBLE, _T("x"), _T("is the denominator."), _T("5"))
	.Category(CATEGORY)
	.FunctionHelp(_T("Computes the arctan of y/x"))
	.Documentation(LR"(
Computes the arctangent of two double values, and stores an integer double value with the sign 
and its approximate quadrants in a location that's specified in a parameter.
	)")
);
double WINAPI
xll_atan2(double y, double x)
{
#pragma XLLEXPORT
	double se;
	
	se = atan2(y, x);

	return se;
}

#ifdef _DEBUG


xll::test test_xll_ATAN2([]() {
	double presult;
	double y = 0.5;
	double x = 5;
	presult = xll_atan2(y, x);
	ensure(presult == 0.099668652491162024);
	});

#endif // _DEBUG
