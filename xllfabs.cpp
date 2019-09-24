// Author: yc3744
// absolute value of a floating point value (|x|)
// Rename this file to xllfabs.cpp and implement XLL.FABS which calls fabs
// Add documentation and a test function that runs in debug mode.
#include "xllfloat.h"

#ifndef CATEGORY
#define CATEGORY "Float"
#endif

using namespace xll;

static AddInX xai_fabs(
	FunctionX(XLL_DOUBLE, _T("?xll_fabs"), _T("XLL.FABS"))
	.Arg(XLL_DOUBLE, _T("num"), _T("is a floating point number."))
	.Category(CATEGORY)
	.FunctionHelp(_T("Compute the absolute value of a floating point number."))
	.Documentation(LR"(
Computes the absolute value of a floating point number, and return an floating point value with
the sign to be positive and its magnitude to be the same as the input.
	)")
);

double WINAPI
xll_fabs(double num)
{
#pragma XLLEXPORT

	return fabs(num);
}

#ifdef _DEBUG

xll::test test_xll_fabs([]() {
	double presult;
	double num = -10.56;
	presult = xll_fabs(num);
	ensure(presult == 10.56);
	});

#endif 

// _DEBUG